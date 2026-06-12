#ifndef SC32_UNISTD_H
#define SC32_UNISTD_H

#include <stddef.h>

// Low-level byte streams. Returns number of bytes processed.
int sc32_write(int fd, const char *buf, size_t count);
int sc32_read(int fd, char *buf, size_t count);

#endif
