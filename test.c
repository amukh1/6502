// #include <stdio.h>

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
    // char* s = "hello";
    // unsigned int x = (unsigned int)s;
    // unsigned char high_byte = x >> 8;

    // unsigned int y = (unsigned int)s;
    // unsigned char low_byte = y & 0xFF;

    // *(unsigned char*)0x02 = high_byte;
    // *(unsigned char*)0x03 = low_byte;
    // __asm__("LDA $02");
    // __asm__("STA $FFFC");

    // __asm__("LDA $03");
    // __asm__("STA $FFFD");

    // __asm__("LDA #$80");
    // __asm__("STA $FFFB");

    // ------------------
    // *(unsigned char*)0x02 = 0x25;
    // __asm__("NOP");
    unsigned char ae = 0x02;
    // *(unsigned char*)0x01 = ae;
    // __asm__("PLA");
    __asm__("STA $02");
    // __asm__("NOP");

    *(char*)0x02 = 'a'; // char at 0x02

    // now string at 0x05
    // *(char**)0x05 = "h";

    // now store number size 0xFFFF at 0x07
    *(unsigned short*)0x07 = 0x1234;
    // *(unsigned char*)0x09 = ae;

    *(unsigned char*)0x09 = (unsigned char)'h';

    __asm__("LDA $09");
    __asm__("STA $FFFC");

    __asm__("LDA $09+1");
    __asm__("STA $FFFD");

    __asm__("LDA #$80");
    __asm__("STA $FFFB");
    __asm__("NOP");

    return 16;
}