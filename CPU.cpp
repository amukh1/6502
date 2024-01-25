#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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
    return (BYTE) data[Address];
    }
}

void Memory::Write(WORD Address, BYTE Data) {
    if(Address > 0xFFFF) {
        std::cout << "Address out of range" << std::endl;
        return;
    }else if(Address == 0xFFFC) {
        return;
    }else if(Address == 0xFFFD) {
        return;
    } else {
    data[Address] = Data;
    }
}

void Memory::init() {
    for(int i = 0; i < (int)std::pow(2,16); i++) {
        // data[0x00] = 0x00;
    }
    return;
}

void CPU::Reset(Memory mem) {
    this->PC = (mem.Read(0xFFFD)<<8) | mem.Read(0xFFFC);

    A,X,Y = (BYTE) 0;
    CF = 0, ZF = 0, ID = 0, DM = 0, BC = 0, OF = 0, NF = 0;

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
    std::cout << "CF: " << CF << std::endl;
    std::cout << "ZF: " << ZF << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "DM: " << DM << std::endl;
    std::cout << "BC: " << BC << std::endl;
    std::cout << "OF: " << OF << std::endl;
    std::cout << "NF: " << NF << std::endl;
    std::cout << "BRK: " << _BRK << std::endl;
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
    }
    
    PC++;
}

void CPU::BRK(Memory mem) {
    _BRK = 1;
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
    }else return;
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
    }else return;
}

void CPU::LDY(Memory mem) {
    if(mem.Read(PC) == 0xA0) {
        BYTE operand = mem.Read(++PC);
        Y = operand;
    } else if(mem.Read(PC) == 0xA4) {

    }
}

void CPU::STA(Memory mem) {
    if(mem.Read(PC) == 0x8D) {
        mem.Write((WORD)mem.Read(PC+1), A);
        PC++;
    }else if(mem.Read(PC) == 0x85) {
        mem.Write((WORD)mem.Read(PC+1), A);
        PC++;
    }else return;
}

void CPU::STX(Memory mem) {
    if(mem.Read(PC) == 0x8E) {
        mem.Write((WORD)mem.Read(PC+1), X);
        PC++;
    }else if(mem.Read(PC) == 0x86) {
        mem.Write((WORD)mem.Read(PC+1), X);
        PC++;
    }else return;
}

void CPU::STY(Memory mem) {
    if(mem.Read(PC) == 0x84) {
        mem.Write((WORD)mem.Read(PC+1), Y);
        PC++;
    }else if(mem.Read(PC) == 0x8C) {
        mem.Write((WORD)mem.Read(PC+1), Y);
        PC++;
    }else return;
}