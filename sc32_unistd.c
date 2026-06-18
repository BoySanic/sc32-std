#include "sc32_unistd.h"
#include "sc32_hw.h"
#include "sc32_stdio.h"
#include <errno.h>

int* my_errno = (int*)0x8000FF;

int *__errno_location(void) {
  return my_errno;
}

char* heap = (char *)0x801000;

void* sbrk(intptr_t increment) {
  char * old_heap = heap; 
  if (heap + increment > (char *)(0xFFFFFF - 0x40000) || heap + increment < (char *)0x801000) {
    return (void*)-1;
  }
  heap += increment;
  return (void*)old_heap;
}

int sc32_write(int fd, const char *buf, size_t count) {
    if (fd != 1 && fd != 2) return -1;

    for (size_t i = 0; i < count; i++) {
        *SC32_IO_TERM = buf[i];
    }
    return count;
}

int sc32_read(int fd, char *buf, size_t count) {

    if (fd != 0) return -1;
    for(size_t i = 0; i < count; i++) {
      char key = 0; 
      while((key = *SC32_IO_KB) == 0) {

      }
      buf[i] = key;
    }
  
    return count;
}

int sc32_read_clock() {
    return *SC32_IO_CLK;
}
