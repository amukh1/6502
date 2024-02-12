#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>

#include "CPU.h"

BYTE Memory::Read(WORD Address) {
    if(Address > 0xFFFF) {
        std::cout << "Address out of range" << std::endl;
        return (BYTE) 0;
    }else if(Address == 0xFFFC) {
        return (BYTE) 0x00;
    }else if(Address == 0xFFFD) {
        return (BYTE) 0x80;
    } else {
    // return (BYTE) *(data + Address);
    return data[Address];
    }
}

void Memory::Write(WORD Address, BYTE Data) {
    std::cout << sizeof(data)/sizeof(BYTE) << std::endl;
    if(Address > 0xFFFF) {
        std::cout << "Address out of range" << std::endl;
        return;
    }else if(Address == 0xFFFC) {
        return;
    }else if(Address == 0xFFFD) {
        return;
    } else {
        // *(data + Address) = Data;
        data[Address] = Data;
    }
}

void Memory::init() {
    // data = (BYTE*)malloc(std::pow(16,4)*sizeof(BYTE));
    return;
}

void CPU::Reset(Memory mem) {
    this->PC = (mem.Read(0xFFFD)<<8) | mem.Read(0xFFFC);

    A = 0;
    X = 0;
    Y = 0;
    
    N = 0, V = 0, BR = 0, B = 0, D = 0, I = 0, Z = 0, C = 0;

    this->SP = (BYTE) 0;
    SP-=3;
    
    // mem.init();
    FillMatrix();
}

void CPU::Log() {
    std::cout << "------------------" << std::endl;
    std::cout << "Cycle: " << Cycle << std::endl;
    std::cout << "A: " << (int)A << std::endl;
    std::cout << "X: " << (int)X << std::endl;
    std::cout << "Y: " << (int)Y << std::endl;
    std::cout << "N: " << N << std::endl;
    std::cout << "V: " << V << std::endl;
    std::cout << "BRK: " << BR << std::endl;
    std::cout << "B: " << B << std::endl;
    std::cout << "D: " << D << std::endl;
    std::cout << "I: " << I << std::endl;
    std::cout << "Z: " << Z << std::endl;
    std::cout << "C: " << C << std::endl;
    std::cout << "SP: " << (int)SP << std::endl;
    std::cout << "PC: " << (int)PC << std::endl;
    std::cout << "-----" << std::endl;
};

void CPU::Log(std::string s) {
    std::cout << "Cycle: " << Cycle << std::endl;
    std::cout << s << std::endl;
};

void CPU::Step(Memory mem) {
    std::string op = Decode(mem.Read(PC));
    if(op == "BRK") {
        BRK(mem);
    }else if(op == "LDA") {
        LDA(mem);
    }else if(op == "LDX") {
        LDX(mem);
    }else if(op == "LDY") {
        LDY(mem);
    }else if(op == "STA") {
        STA(mem);
    }else if(op == "STX") {
        STX(mem);
    }else if(op == "STY") {
        STY(mem);
    }else if(op == "TAX") {
        TAX(mem);
    }else if(op == "TAY") {
        TAY(mem);
    }else if(op == "TSX") {
        TSX(mem);
    }else if(op == "TXA") {
        TXA(mem);
    }else if(op == "TXS") {
        TXS(mem);
    }else if(op == "TYA") {
        TYA(mem);
    }else if(op == "PHA") {
        PHA(mem);
    }else if(op == "PHP") {
        PHP(mem);
    }else if(op == "PLA") {
        PLA(mem);
    }else if(op == "PLP") {
        PLP(mem);
    }else if(op == "ASL") {
        ASL(mem);
    }else if(op == "LSR") {
        LSR(mem);
    }
    // else if(op == "ROL") {
    //     ROL(mem);
    // }
    // else if(op == "ROR") {
    //     ROR(mem);
    // }
    else if(op == "AND") {
        AND(mem);
    }
    
    else if(op == "NOP") {
        std::cout << "NOP" << std::endl;
        PC++;
    }

    PC++;
}

void CPU::BRK(Memory mem) {
    BR = 1;
}

void CPU::LDA(Memory mem) {
    if(mem.Read(PC) == 0xA9) {
        BYTE operand = mem.Read(PC+1);
        A = operand;
        PC++;
    }else if(mem.Read(PC) == 0xA5) {
        BYTE operand = mem.Read(mem.Read(PC+1));
        A = operand;
        PC++;
    }else if(mem.Read(PC) == 0xAD) { // absolute
        // address is 1 WORD. So, we need to read 2 bytes
        // WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        WORD address = (mem.Read(PC+1)<<4) | mem.Read(PC+2);
        BYTE operand = mem.Read(address);
        A = operand;
        PC++;
    }

    if(A == 0) {
        Z = 1;
    }else if(A < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::LDX(Memory mem) {
    if(mem.Read(PC) == 0xA2) {
        BYTE operand = mem.Read(PC+1);
        X = operand;
        PC++;
    }else if(mem.Read(PC) == 0xA6) {
        BYTE operand = mem.Read((WORD)mem.Read(PC+1));
        X = operand;
        PC++;
    } else if(mem.Read(PC) == 0xAE) { // absolute
            WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        BYTE operand = mem.Read((WORD)address);
        X = operand;
        PC++;
    }

    if(X == 0) {
        Z = 1;
    }else if(X < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::LDY(Memory mem) {
    if(mem.Read(PC) == 0xA0) {
        BYTE operand = mem.Read(PC+1);
        Y = operand;
        PC++;
    } else if(mem.Read(PC) == 0xA4) {
        BYTE operand = mem.Read((WORD)mem.Read(PC+1));
        Y = operand;
        PC++;
    } else if(mem.Read(PC) == 0xAC) { // absolute
        WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        BYTE operand = mem.Read((WORD)address);
        Y = operand;
        PC++;
    }

    if(Y == 0) {
        Z = 1;
    }else if(Y < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::STA(Memory mem) {
    if(mem.Read(PC) == 0x8D) {
        WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        mem.Write((WORD)address, A);
        PC++;
    }else if(mem.Read(PC) == 0x85) {
        mem.Write((WORD)mem.Read(PC+1), A);
        PC++;
    }
    std::cout << "STA" << std::endl;
}

void CPU::STX(Memory mem) {
    if(mem.Read(PC) == 0x8E) {
        WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        mem.Write((WORD)address, X);
        PC++;
    }else if(mem.Read(PC) == 0x86) {
        mem.Write((WORD)mem.Read(PC+1), X);
        PC++;
    }else return;
}

void CPU::STY(Memory mem) {
    if(mem.Read(PC) == 0x84) {
        WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        mem.Write((WORD)address, Y);
        PC++;
    }else if(mem.Read(PC) == 0x8C) {
        mem.Write((WORD)mem.Read(PC+1), Y);
        PC++;
    }else return;
}

void CPU::TAX(Memory mem) {
    X = A;

    if(X == 0) {
        Z = 1;
    }else if(X < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::TAY(Memory mem) {
    Y = A;

    if(Y == 0) {
        Z = 1;
    }else if(Y < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::TSX(Memory mem) {
    X = SP;

    if(X == 0) {
        Z = 1;
    }else if(X < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::TXA(Memory mem) {
    A = X;

    if(A == 0) {
        Z = 1;
    }else if(A < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::TXS(Memory mem) {
    SP = X;
}

void CPU::TYA(Memory mem) {
    A = Y;

    if(A == 0) {
        Z = 1;
    }else if(A < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::PHA(Memory mem) {
    mem.Write((WORD)SP, A);
    SP--;
}

void CPU::PHP(Memory mem) {
    BYTE PS = 0;
    // fill processor status
    PS = (N << 7) | (V << 6) | (BR << 4) | (B << 3) | (D << 2) | (I << 1) | (Z << 0);
    mem.Write((WORD)SP, PS);
    SP--;
}

void CPU::PLA(Memory mem) {
    A = mem.Read((WORD)(++SP));
    // clear that value
    mem.Write((WORD)SP, 0);

    if(A == 0) {
        Z = 1;
    }else if(A < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::PLP(Memory mem) {
    BYTE PS = mem.Read((WORD)(++SP));
    mem.Write((WORD)SP, 0);
    // fill processor status
    N = (PS >> 7) & 1;
    V = (PS >> 6) & 1;
    BR = (PS >> 4) & 1;
    B = (PS >> 3) & 1;
    D = (PS >> 2) & 1;
    I = (PS >> 1) & 1;
    Z = (PS >> 0) & 1;
}

// ASL
void CPU::ASL(Memory mem) {
    if(mem.Read(PC) == 0x0E) { // ASL absolute
        WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        BYTE operand = mem.Read(address);
        mem.Write(address, operand << 1);

        C = operand >> 7;
        if((operand<<1) == 0) {
            Z = 1;
        }else if((operand<<1) < 0) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }

        PC++;
    }else if(mem.Read(PC) == 0x06) { // ASL zero page
        WORD address = (WORD)mem.Read(PC+1);
        BYTE operand = mem.Read(address);
        mem.Write(address, operand << 1);

        C = operand >> 7;
        if((operand<<1) == 0) {
            Z = 1;
        }else if((operand<<1) < 0) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }

        PC++;
    }else if(mem.Read(PC) == 0x0A) { // ASL accumulator
        C = A >> 7;
        A = A << 1;

        if(A == 0) {
            Z = 1;
        }else if(A < 0) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }
    }
}

void CPU::LSR(Memory mem) {
    if(mem.Read(PC) == 0x4E) {
        WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        BYTE operand = mem.Read(address);
        mem.Write(address, operand >> 1);

        C = operand >> 7;
        if((operand<<1) == 0) {
            Z = 1;
        }else if((operand<<1) < 0) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }

        PC++;
    }else if(mem.Read(PC) == 0x46) {
        WORD address = (WORD)mem.Read(PC+1);
        BYTE operand = mem.Read(address);
        mem.Write(address, operand >> 1);

        C = operand >> 7;
        if((operand<<1) == 0) {
            Z = 1;
        }else if((operand<<1) < 0) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }

        PC++;
    }else if(mem.Read(PC) == 0x4A) {
        C = A & 0x01;
        A = A >> 1;

        if(A == 0) {
            Z = 1;
        }else if(A < 0) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }
    }
}

// do ROL AND ROR later

void CPU::AND (Memory mem) {
    if(mem.Read(PC) == 0x29) {
        BYTE operand = mem.Read(PC+1);
        A = A & operand;
        PC++;
    }else if(mem.Read(PC) == 0x25) {
        BYTE operand = mem.Read(mem.Read(PC+1));
        A = A & operand;
        PC++;
    }else if(mem.Read(PC) == 0x2D) {
        WORD address = (mem.Read(PC+1)<<8) | mem.Read(PC+2);
        BYTE operand = mem.Read((WORD)address);
        A = A & operand;
        PC++;
    }

    if(A == 0) {
        Z = 1;
    }else if(A < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

// skip BIT, EOR, ORA

// ADC

// JMP, JSR, RTS, RTI

void CPU::JMP(Memory mem) {
    if(mem.Read(PC) == 0x4C) {
        PC = (mem.Read(PC+2)<<8) | mem.Read(PC+1);
    }else if(mem.Read(PC) == 0x6C) {
        PC = (mem.Read(PC+2)<<8) | mem.Read(PC+1);
    }
}

void CPU::JSR(Memory mem) {
    WORD address = (mem.Read(PC+2)<<8) | mem.Read(PC+1);
    mem.Write((WORD)SP, (PC+2) >> 8);
    SP--;
    mem.Write((WORD)SP, (PC+2) & 0xFF);
    SP--;
    PC = address;
}

void CPU::RTS(Memory mem) {
    PC = (mem.Read((WORD)SP+1)<<8) | mem.Read((WORD)SP);
    // clear that value
    mem.Write((WORD)SP, 0);
    SP++;
    PC++;
}

void CPU::RTI(Memory mem) {
    BYTE PS = mem.Read((WORD)SP);
    // clear that value
    mem.Write((WORD)SP, 0);
    SP++;
    N = (PS >> 7) & 1;
    V = (PS >> 6) & 1;
    BR = (PS >> 4) & 1;
    B = (PS >> 3) & 1;
    D = (PS >> 2) & 1;
    I = (PS >> 1) & 1;
    Z = (PS >> 0) & 1;
    PC = (mem.Read((WORD)SP+1)<<8) | mem.Read((WORD)SP);
    SP++;
}