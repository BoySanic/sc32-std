#ifndef SC32_HW_H
#define SC32_HW_H

typedef struct {
    volatile char term;  // Offset 0x00 (0x400001)
    volatile char kb;    // Offset 0x01 (0x400002)
} SC32_IO_TypeDef;
#define SC32_IO ((SC32_IO_TypeDef *)0x400001)

#endif
