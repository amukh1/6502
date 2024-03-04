#include <stdlib.h>
#include <stdint.h>
#include "./include/6502.h"

#pragma bss-name(push, "BSS")

void test(char a, char b) {
    *(char*)0x10 = a;
    *(char*)0x11 = b;
}

void test2(char a) {
    *(char*)0x12 = a;
}

int main() {
    char y;
    char z;
    y = 6;
    test2(y);
    z = 4;
    test2(z);
    test(y,z);
    return 0;
}

/*

x = 6;
    *(char*)0x0210 = 0x12;

    y = (char*)0x0211;

    *y = 0x13;

    s = (char*)"Hello World!\n";

    // syscall operands
    *(char*)0xFFFC = (uint16_t)s >> 8;
    *(char*)0xFFFD = (char)s & 0xFF;

    // syscall
    *(char*)0xFFFB = 0x80;
    
*/