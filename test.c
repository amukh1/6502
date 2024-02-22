// #include <stdio.h>
#include <6502.h>

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

int main() {
    char x = 25;
    // *(char*)0x00 = 2;
    *(char*)0x0a = x;

    

    // __asm__("LDA #$2");
    // __asm__("PHA");
    // __asm__("PLA");
    // __asm__("STA $04");
    // __asm__("PLA");
    // __asm__("STA $05");
    // __asm__("PLA");
    // __asm__("STA $06");

    
    return 16;
}