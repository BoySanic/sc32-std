#include "sc32_unistd.h"
#include "sc32_hw.h"

int sc32_write(int fd, const char *buf, size_t count) {
    if (fd != 1 && fd != 2) return -1;

    for (size_t i = 0; i < count; i++) {
        SC32_IO->term = buf[i];
    }
    return count;
}

int sc32_read(int fd, char *buf, size_t count) {
    if (fd != 0) return -1;

    for (size_t i = 0; i < count; i++) {
        buf[i] = SC32_IO->kb;
    }
    return count;
}
