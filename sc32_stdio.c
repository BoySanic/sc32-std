#include "sc32_stdio.h"
#include "sc32_unistd.h"


void sc32_putc(char c) {
    sc32_write(1, &c, 1); // Pass to file descriptor 1 (stdout)
}

char sc32_getc(void) {
    char c;
    sc32_read(0, &c, 1);  // Read from file descriptor 0 (stdin)
    return c;
}

void sc32_print_hex(uintptr_t val) {
    char hex[] = "0123456789ABCDEF";
    sc32_prints("0x");
    for (int i = 7; i >= 0; i--) {
        sc32_putc(hex[(val >> (i * 4)) & 0xF]);
    }
}

void sc32_print_dec(uintptr_t val) {
  uint32_t divisor = 1000000000;
  while (divisor > 0) {
    if (divisor <= val) {
      uint32_t digit = (val / divisor) % 10;
      digit += 48; // Get ASCII character
      sc32_putc((unsigned char)digit);
    }
    divisor /= 10;
  }
}
void sc32_prints(const char *s) {
    size_t len = 0;
    while (s[len]) {
      len++;
    }

    sc32_write(1, s, len); 
}

char* sc32_readline(void) {
    size_t buf_size = 16;
    size_t str_size = 0;
    char *buf = malloc(buf_size);
    char input;

    do {
        input = sc32_getc();
        if (input == '\n' || input == '\r') {
            input = '\0';
        }

        if (str_size >= buf_size) {
            buf_size += 16;
            buf = realloc(buf, buf_size);
        }
        sc32_putc(input);
        buf[str_size++] = input;
    } while (input != '\0');

    return buf;
}
