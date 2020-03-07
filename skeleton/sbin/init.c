#include <fcntl.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/syscall.h>

int open(const char *file, int oflag, ...) {
  register int v0 asm("v0") = __NR_open;
  register const char *a0 asm("a0") = file;
  register int a1 asm("a1") = oflag;
  asm volatile("syscall" ::"r"(v0), "r"(a0), "r"(a1));
  return v0;
}

int close(int fd) {
  register int v0 asm("v0") = __NR_close;
  register int a0 asm("a0") = fd;
  asm volatile("syscall" ::"r"(v0), "r"(a0));
  return v0;
}

int write(int fd, const char *buf, int len) {
  register int v0 asm("v0") = __NR_write;
  register int a0 asm("a0") = fd;
  register const char *a1 asm("a1") = buf;
  register int a2 asm("a2") = len;
  asm volatile(
      "syscall" ::"r"(v0), "r"(a0), "r"(a1), "r"(a2));
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

void __start() {
  for (const char *p = "Hello, njumips World\n"; *p; p++) {
    _putc(*p);
  }
  nemu_trap();
  while (1)
    ;
}
