#include <stdio.h>

int main() {
  volatile int *p = (volatile int *)0xb0000000;
  *p = 0;
}
