// #include <stdlib.h>
// #include <stdint.h>
// #include "./include/6502.h"

void testm(char a, char b) {
    *(char*)0x10 = a;
    *(char*)0x11 = b;
}

void tests(char s) {
    *(char*)0x10 = s;
}

// char x;
int main() {
    char x;
    x = 2;
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