#include <fcntl.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/syscall.h>

int open(const char *file, int oflag, ...) {
  register int v0 asm("v0") = __NR_open;
  register const char *a0 asm("a0") = file;
  register int a1 asm("a1") = oflag;
  asm volatile("syscall");
  return v0;
}

int close(int fd) {
  register int v0 asm("v0") = __NR_close;
  register int a0 asm("a0") = fd;
  asm volatile("syscall");
  return v0;
}

int write(int fd, const char *buf, int len) {
  register int v0 asm("v0") = __NR_write;
  register int a0 asm("a0") = fd;
  register const char *a1 asm("a1") = buf;
  register int a2 asm("a2") = len;
  asm volatile("syscall");
  return v0;
}

void nemu_trap() {
  volatile int *p = (volatile int *)0xb0000000;
  *p = 0;
}

void _putc(char ch) {
  volatile int *serio = (volatile int *)0xbfe50000;
  while ((serio[2] >> 3) & 1)
    ;
  serio[1] = ch;
}

size_t strlen(const char *s) {
  size_t sz = 0;
  for (; *s; s++) { sz++; }
  return sz;
}

char *printch(char ch, char **s, int *limit_n);
int printdec(unsigned int dec, int base, int width,
    char abs, char flagc, char **s, int *limit_n);
int vprintdec(unsigned int dec, int base, int width,
    char abs, char flagc, char **s, int count,
    int *limit_n);
char *printstr(char *str, char **s, int *limit_n);
void myputc(char c, char **s_h, int *limit_n) {
  if (*s_h == 0)
    _putc(c);
  else if (*limit_n != 1) {
    **s_h = c;
    (*s_h)++;
    (*limit_n)--;
  }
}

int vprintk(
    char *out, int limit, const char *fmt, va_list ap) {
  unsigned int rewid = 0;
  char **s_v = &out;
  int *limit_n = &limit;
  int vargint = 0;
  unsigned int varguint = 0;
  char *vargpch = 0;
  char vargch = 0;
  char flagc = ' ', abs = '+';
  int base, width = -1;
  const char *pfmt = fmt;
  while (*pfmt) {
    if (*pfmt == '%') {
      flagc = ' ';
      width = -1;
      abs = '+';
    reswitch:
      switch (*(++pfmt)) {
      case '-': flagc = '-'; goto reswitch;
      case '0': flagc = '0'; goto reswitch;
      case ' ': flagc = ' '; goto reswitch;
      case '+': flagc = '+'; goto reswitch;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        width = 0;
        char ch;
        while ((ch = *pfmt++) >= '0' && ch <= '9') {
          width = width * 10 + ch - '0';
        }
        pfmt -= 2;
        goto reswitch;
      case '*': width = va_arg(ap, int); goto reswitch;
      case 'c':
        vargch = va_arg(ap, int);
        printch(vargch, s_v, limit_n);
        rewid++;
        break;
      case '%':
        printch('%', s_v, limit_n);
        rewid++;
        break;
      case 'd':
        vargint = va_arg(ap, int);
        base = 10;
        if (vargint < 0) {
          abs = '-';
          varguint = -vargint;
        } else {
          varguint = vargint;
        }
        goto nump;
      case 'u':
        varguint = va_arg(ap, unsigned int);
        base = 10;
        goto nump;
      case 'x':
      case 'X':
        varguint = va_arg(ap, int);
        base = 16;
        goto nump;
      case 'p':
        myputc('0', s_v, limit_n);
        myputc('x', s_v, limit_n);
        varguint = (long)va_arg(ap, void *);
        base = 16;
        goto nump;
      nump:
        rewid += printdec(varguint, base, width, abs, flagc,
            s_v, limit_n);
        break;
      case 's':
        vargpch = va_arg(ap, char *);
        printstr(vargpch, s_v, limit_n);
        rewid += strlen(vargpch);
        break;
      default:;
      }
      pfmt++;
    } else {
      out = printch(*pfmt++, s_v, limit_n);
      rewid++;
    }
  }
  if (out != 0) {
    printch('\0', s_v, limit_n);
    // rewid++;结尾的\0不算在返回值中
  }
  return rewid;
}

int printk(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int r = vprintk(0, 0, fmt, ap);
  va_end(ap);
  return r;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vprintk(out, 0, fmt, ap);
}

char *printch(char ch, char **s, int *limit_n) {
  // if(s==0)_putc(ch);
  // else *s++=ch;
  myputc(ch, s, limit_n);
  return *s;
}

int printdec(unsigned int dec, int base, int width,
    char abs, char flagc, char **s, int *limit_n) {
  int rewid = 0, twid = width;
  if (abs == '-') rewid++;
  if (dec == 0) {
    // myputc('0',s);
    // dec=-1;
    rewid++;
    twid--;
  }
  vprintdec(dec, base, twid, abs, flagc, s, 0, limit_n);
  while (dec > 0) {
    dec = dec / base;
    rewid++;
  }
  if (width > 0 && rewid > width) rewid = width;
  return rewid;
}
int vprintdec(unsigned int dec, int base, int width,
    char abs, char flagc, char **s, int count,
    int *limit_n) {
  if (dec == 0) {
    if (flagc != '-') {
      width++;
      if (abs == '-') width--;
      while (width-- > 1) {
        if (flagc != '+') {
          myputc(flagc, s, limit_n);
        } else {
          myputc(' ', s, limit_n);
        }
      }
      if (flagc == '+')
        myputc(abs, s, limit_n);
      else if (abs == '-')
        myputc('-', s, limit_n);
      else {
        if (width > 0) myputc(flagc, s, limit_n);
      }
      // return width;
    } else if (abs == '-') {
      myputc('-', s, limit_n);
      width--;
    }
    if (count == 0) myputc('0', s, limit_n);
    return width;
  }
  //_putc('0');
  int re = 0; // vprintdec(dec/base,base,width-1,flagc,s+1);
  re = vprintdec(dec / base, base, width - 1, abs, flagc, s,
      count + 1, limit_n);
  if (dec % base > 9)
    myputc(dec % base + 'a' - 10, s, limit_n);
  else
    myputc((char)(dec % base + '0'), s, limit_n);
  if (flagc == '-' && count == 0) {
    while (re-- > 0) myputc(' ', s, limit_n);
  }
  return re;
}

char *printstr(char *str, char **s, int *limit_n) {
  while (*str) { myputc(*str++, s, limit_n); }
  return *s;
}

void __start() {
  printk("Hello World\n");
  int fd = open("/dev/ttyUL0", O_WRONLY);
  printk("Hello World, %d\n", fd);
  int n = write(fd, "Hello, njumips World\n", 21);
  printk("Hello World, %d\n", n);
  close(fd);
  nemu_trap();
  while (1)
    ;
}
