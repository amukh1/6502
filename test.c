// #include <stdio.h>
// #include <6502.h>
#include <stdlib.h>
#include <stdint.h>
#include "./include/6502.h"

#pragma bss-name(push, "BSS")


// unsigned char cd = 0x02;

int fish(int x) {
    return x;
}

void printChar(char c) {
    // get the address of the char
    int x = (int)&c;
    __asm__("NOP");
}

int frog() {
    __asm__("LDA #70");
    __asm__("STA $00");
    __asm__("LDA #$00");
    __asm__("STA $FFFC");
    __asm__("LDA #$00");
    __asm__("STA $FFFD");

    __asm__("LDA #$80");
    __asm__("STA $FFFB");
    return 0;
}

char x;
char c;
char* y;
char* s;
int main() {
    x = 4;

    // x = 12;
    // c = 6;
    // y = &c;
    // *(char*)0x03 = *y;
    

    return 16;
}