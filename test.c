// #include <stdio.h>
// #include <6502.h>
#include <stdlib.h>
#include <stdint.h>
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

char x;
char* y;
char c;
uint16_t z;
uint16_t addr_y;
char* s;
int main() {
    // x = 12; // <-- not allocating
    // *(char*)0x00 = 2;

    x = 12;
    c = 6;
    *(char*)0x10 = x;

    y = &x;

    *(uint16_t*)0x14 = (uint16_t)y;
    z = *(uint16_t*)((uint16_t)0x0200);
    // z = *(uint16_t*)((uint16_t)y);
    addr_y = (uint16_t)y;
    *(uint16_t*)0x14 = addr_y;
    z = **(uint16_t**)0x14;
    __A__ = 0x02;
    __asm__("LDA #$12");
    __asm__("LDX #$34");
    // s = "hello";
    z = __AX__;
    // *(char*)0x00 = __A__;
    // __asm__("STA $01");

    
    // x = 3;
    // *(char*)0x14 = *y;



    // __asm__("LDA _x");
    // __asm__("STA $05"); 

    // char y = 7;
    // *(char*)0x00 = y;


    // *(char*)0x00 = 16;


    // *(char*)0x00 = x; // <-- may be an error with expr parsing, but also x doesnt exist.




    

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