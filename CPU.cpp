#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>
#include <cstdio>
#include <fstream>

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
    // std::cout << sizeof(data)/sizeof(BYTE) << std::endl;
    if(Address > 0xFFFF) {
        std::cout << "Address out of range" << std::endl;
        return;
    } else if(Address == 0xFFFB) {
        if(Data == 0x00) {
            return;
        }else if(Data == 0x80 || Data == 0x81) {
            // printing the address from (FFFC,FFFD) to (0xFFFE,0XFFFF) to the console.
            WORD start = (data[0xFFFC]<<8) | data[0xFFFD];
            // WORD end = (data[0xFFFE]<<8) | data[0xFFFF];
            bool end = false;

            // std::cout << "Printing from " << start << " to " << end << std::endl;

            // should be in ascii format
            int i = start;
            while(end == false) {
                // std::cout << (char)data[i];
                // std output prints to logs file, print out to console
                std::printf((Data == 0x80) ? "%c" : "%d", data[i]);
                i++;
                if(data[i] == 0x00) {
                    end = true;
                    if(Data == 0x81) {
                        std::cout << std::endl;
                    }
                }
            }
        }
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

void CPU::Reset(std::unique_ptr<Memory>& mem) {
    this->PC = (mem->Read(0xFFFD)<<8) | mem->Read(0xFFFC);

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
    std::ofstream outfile("logs.txt", std::ios::app);
    outfile << "------------------" << std::endl;
    outfile << "Cycle: " << Cycle << std::endl;
    outfile << "A: " << (int)A << std::endl;
    outfile << "X: " << (int)X << std::endl;
    outfile << "Y: " << (int)Y << std::endl;
    outfile << "N: " << N << std::endl;
    outfile << "V: " << V << std::endl;
    outfile << "BRK: " << BR << std::endl;
    outfile << "B: " << B << std::endl;
    outfile << "D: " << D << std::endl;
    outfile << "I: " << I << std::endl;
    outfile << "Z: " << Z << std::endl;
    outfile << "C: " << C << std::endl;
    outfile << "SP: " << (int)SP << std::endl;
    outfile << "PC: " << (int)PC << std::endl;
    outfile << "-----" << std::endl;
    outfile.close();
};

void CPU::Log(std::string s) {
    std::cout << "Cycle: " << Cycle << std::endl;
    std::cout << s << std::endl;
};

void CPU::Step(std::unique_ptr<Memory>& mem) {
    std::string op = Decode(mem->Read(PC));
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
    }else if(op == "JMP") {
        JMP(mem);
    }else if(op == "JSR") {
        JSR(mem);
    }else if(op == "RTS") {
        RTS(mem);
    }else if(op == "RTI") {
        RTI(mem);
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
        // std::cout << "NOP" << std::endl;
        // PC++;
    }

    PC++;
}

void CPU::BRK(std::unique_ptr<Memory>& mem) {
    BR = 1;
}

void CPU::LDA(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0xA9) {
        BYTE operand = mem->Read(PC+1);
        A = operand;
        PC++;
    }else if(mem->Read(PC) == 0xA5) {
        BYTE operand = mem->Read(mem->Read(PC+1));
        A = operand;
        PC++;
    }else if(mem->Read(PC) == 0xAD) { // absolute
        // address is 1 WORD. So, we need to read 2 bytes
        // WORD address = (mem->Read(PC+1)<<8) | mem->Read(PC+2);
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read(address);
        A = operand;
        PC+=2;
    }else if(mem->Read(PC) == 0xBD) { // X-indexed absolute
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read(address + X);
        A = operand;
        PC+=2;
    }else if(mem->Read(PC) == 0xB9) { // Y-indexed absolute
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read(address + Y);
        A = operand;
        PC+=2;
    }else if(mem->Read(PC) == 0xB5) { // X-indexed zero page
        WORD address = (WORD)mem->Read(PC+1);
        BYTE operand = mem->Read((address + X) & 0xFF);
        A = operand;
        PC++;
    }else if(mem->Read(PC) == 0xA1) { // X-indexed indirect
        WORD address = (WORD)mem->Read(PC+1);
        BYTE operand = mem->Read(mem->Read((address + X) & 0xFF) | (mem->Read((address + X + 1) & 0xFF) << 8));
        A = operand;
        PC++;
    }else if(mem->Read(PC) == 0xB1) { // ZP- Y-indexed indirect
        // WORD address = (WORD)mem->Read(PC+1);
        BYTE operand = mem->Read(PC+1);
        WORD address = (mem->Read(operand) | (mem->Read(operand+1) << 8));
        A = mem->Read((WORD)address + Y);
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

void CPU::LDX(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0xA2) {
        BYTE operand = mem->Read(PC+1);
        X = operand;
        PC++;
    }else if(mem->Read(PC) == 0xA6) {
        BYTE operand = mem->Read((WORD)mem->Read(PC+1));
        X = operand;
        PC++;
    } else if(mem->Read(PC) == 0xAE) { // absolute
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read((WORD)address);
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

void CPU::LDY(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0xA0) {
        BYTE operand = mem->Read(PC+1);
        Y = operand;
        PC++;
    } else if(mem->Read(PC) == 0xA4) {
        BYTE operand = mem->Read((WORD)mem->Read(PC+1));
        Y = operand;
        PC++;
    } else if(mem->Read(PC) == 0xAC) { // absolute
        WORD address = (mem->Read(PC+1)<<8) | mem->Read(PC+2);
        BYTE operand = mem->Read((WORD)address);
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

void CPU::STA(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0x8D) { //absolute
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        mem->Write((WORD)address, A);
        PC+=2;
    }else if(mem->Read(PC) == 0x85) { // zero page
        mem->Write((WORD)mem->Read(PC+1), A);
        PC++;
    }else if(mem->Read(PC) == 0x81) { // X-indexed ZP indirect
        BYTE operand = (mem->Read(PC+1)+X) & 0xFF;
        WORD address = (mem->Read(operand) | (mem->Read(operand+1) << 8));
        mem->Write((WORD)address, A);
        PC++;
    }else if(mem->Read(PC) == 0x91) { // ZP- Y-indexed indirect
        BYTE zpAddress = mem->Read(PC+1);
        WORD address = (mem->Read((zpAddress + 1) & 0xFF) << 8) | mem->Read(zpAddress);
        mem->Write(address + Y, A);
        PC++;
    }else if(mem->Read(PC) == 0x95) { // X-indexed zero page
        BYTE address = (BYTE)mem->Read(PC+1);
        mem->Write((WORD)(BYTE)(address + X), A);
        PC++;
    }
    // std::cout << "STA" << std::endl;
}

void CPU::STX(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0x8E) {
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        mem->Write((WORD)address, X);
        PC+=2;
    }else if(mem->Read(PC) == 0x86) {
        mem->Write((WORD)mem->Read(PC+1), X);
        PC++;
    }else return;
}

void CPU::STY(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0x84) {
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        mem->Write((WORD)address, Y);
        PC+=2;
    }else if(mem->Read(PC) == 0x8C) {
        mem->Write((WORD)mem->Read(PC+1), Y);
        PC++;
    }else return;
}

void CPU::TAX(std::unique_ptr<Memory>& mem) {
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

void CPU::TAY(std::unique_ptr<Memory>& mem) {
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

void CPU::TSX(std::unique_ptr<Memory>& mem) {
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

void CPU::TXA(std::unique_ptr<Memory>& mem) {
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

void CPU::TXS(std::unique_ptr<Memory>& mem) {
    SP = X;
}

void CPU::TYA(std::unique_ptr<Memory>& mem) {
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

void CPU::PHA(std::unique_ptr<Memory>& mem) {
    SP--;
    mem->Write(0x0100 + SP, A);
}

void CPU::PHP(std::unique_ptr<Memory>& mem) {
    BYTE PS = 0;
    // fill processor status
    PS = (N << 7) | (V << 6) | (BR << 4) | (B << 3) | (D << 2) | (I << 1) | (Z << 0);
    SP--;
    mem->Write(0x0100 + SP, PS);
}

void CPU::PLA(std::unique_ptr<Memory>& mem) {
    A = mem->Read((WORD)(++SP));
    // clear that value
    mem->Write((WORD)SP, 0);

    if(A == 0) {
        Z = 1;
    }else if(A < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::PLP(std::unique_ptr<Memory>& mem) {
    BYTE PS = mem->Read((WORD)(++SP));
    mem->Write((WORD)SP, 0);
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
void CPU::ASL(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0x0E) { // ASL absolute
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read(address);
        mem->Write(address, operand << 1);

        C = operand >> 7;
        if((operand<<1) == 0) {
            Z = 1;
        }else if((operand<<1) < 0) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }

        PC+=2;
    }else if(mem->Read(PC) == 0x06) { // ASL zero page
        WORD address = (WORD)mem->Read(PC+1);
        BYTE operand = mem->Read(address);
        mem->Write(address, operand << 1);

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
    }else if(mem->Read(PC) == 0x0A) { // ASL accumulator
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

void CPU::LSR(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0x4E) {
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read(address);
        mem->Write(address, operand >> 1);

        C = operand >> 7;
        if((operand<<1) == 0) {
            Z = 1;
        }else if((operand<<1) < 0) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }

        PC+=2;
    }else if(mem->Read(PC) == 0x46) {
        WORD address = (WORD)mem->Read(PC+1);
        BYTE operand = mem->Read(address);
        mem->Write(address, operand >> 1);

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
    }else if(mem->Read(PC) == 0x4A) {
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

void CPU::AND (std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0x29) {
        BYTE operand = mem->Read(PC+1);
        A = A & operand;
        PC++;
    }else if(mem->Read(PC) == 0x25) {
        BYTE operand = mem->Read(mem->Read(PC+1));
        A = A & operand;
        PC++;
    }else if(mem->Read(PC) == 0x2D) {
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read((WORD)address);
        A = A & operand;
        PC+=2;
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

void CPU::JMP(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0x4C) {
        PC = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
    }else if(mem->Read(PC) == 0x6C) { // INDIRECT ADDRESSING
        WORD given_address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        WORD address = (mem->Read(given_address+1)<<8) | mem->Read(given_address);
        PC = address;
    }
    PC--;
}

void CPU::JSR(std::unique_ptr<Memory>& mem) {
    WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
    mem->Write((WORD)SP, (PC+2) >> 8);
    SP--;
    mem->Write((WORD)SP, (PC+2) & 0xFF);
    SP--;
    PC = address;
    PC--;
}

void CPU::RTS(std::unique_ptr<Memory>& mem) {
    BYTE firstHalf = mem->Read((WORD)++SP);
    mem->Write((WORD)SP, 0);

    BYTE secondHalf = mem->Read((WORD)++SP);
    mem->Write((WORD)SP, 0);

    PC = (secondHalf<<8) | firstHalf; 
    // PC--;
}

void CPU::RTI(std::unique_ptr<Memory>& mem) {
    BYTE PS = mem->Read((WORD)SP);
    // clear that value
    mem->Write((WORD)SP, 0);
    SP++;
    N = (PS >> 7) & 1;
    V = (PS >> 6) & 1;
    BR = (PS >> 4) & 1;
    B = (PS >> 3) & 1;
    D = (PS >> 2) & 1;
    I = (PS >> 1) & 1;
    Z = (PS >> 0) & 1;
    PC = (mem->Read((WORD)SP+1)<<8) | mem->Read((WORD)SP);
    SP++;
}

void CPU::INY(std::unique_ptr<Memory>& mem) {
    Y++;
    if(Y == 0) {
        Z = 1;
    }else if(Y < 0) {
        N = 1;
    }else {
        Z = 0;
        N = 0;
    }
}

void CPU::BNE(std::unique_ptr<Memory>& mem) {
    if(Z == 0) {
        PC = PC + (char)mem->Read(PC+1);
    }
}

void CPU::BEQ(std::unique_ptr<Memory>& mem) {
    if(Z == 1) {
        PC = PC + (char)mem->Read(PC+1);
    }
}

// Compares

void CPU::CMP(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0xC9) {
        BYTE operand = mem->Read(PC+1);
        if(A == operand) {
            Z = 1;
        }else if(A < operand) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }
        PC++;
    }else if(mem->Read(PC) == 0xC5) {
        BYTE operand = mem->Read(mem->Read(PC+1));
        if(A == operand) {
            Z = 1;
        }else if(A < operand) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }
        PC++;
    }else if(mem->Read(PC) == 0xCD) {
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read((WORD)address);
        if(A == operand) {
            Z = 1;
        }else if(A < operand) {
            N = 1;
        }else {
            Z = 0;
            N = 0;
        }
        PC+=2;
    }
}

void CPU::SBC(std::unique_ptr<Memory>& mem) {
    if(mem->Read(PC) == 0xE9) {
        BYTE operand = mem->Read(PC+1);
        A = A - operand;
        PC++;
    }else if(mem->Read(PC) == 0xE5) {
        BYTE operand = mem->Read(mem->Read(PC+1));
        A = A - operand;
        PC++;
    }else if(mem->Read(PC) == 0xED) {
        WORD address = (mem->Read(PC+2)<<8) | mem->Read(PC+1);
        BYTE operand = mem->Read((WORD)address);
        A = A - operand;
        PC+=2;
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

// SEI, CLI

void CPU::SEI(std::unique_ptr<Memory>& mem) {
    I = 1;
}

void CPU::CLI(std::unique_ptr<Memory>& mem) {
    I = 0;
}