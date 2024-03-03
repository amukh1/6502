// #include <stdio.h>
// #include <6502.h>
#include <stdlib.h>
#include <stdint.h>
#include "./include/6502.h"

#pragma bss-name(push, "BSS")

void printChar(char c) {
    // get the address of the char
    int x = (int)&c;
    __asm__("NOP");
}

int frog() {
    __asm__("LDA #70");
    __asm__("STA $01");
    __asm__("LDA #$00");
    __asm__("STA $FFFC");
    __asm__("LDA #$01");
    __asm__("STA $FFFD");

    __asm__("LDA #$80");
    __asm__("STA $FFFB");
    return 0;
}

void printStr(char* s) {
    // syscall operands
    *(char*)0xFFFC = (uint16_t)s >> 8;
    *(char*)0xFFFD = (char)s & 0xFF;

    // syscall
    *(char*)0xFFFB = 0x80;
}

char x;
char* y;
char* s;
int main() {
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

    return 0;
}