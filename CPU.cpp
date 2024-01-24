#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "CPU.h"

BYTE Memory::Read(WORD Address) {
    return (BYTE) 0x44;
}

void Memory::init() {
    return;
}

void CPU::Reset(Memory mem) {
    this->PC = mem.Read(0xFFFC);

    A,X,Y = (BYTE) 0;
    CF = 0, ZF = 0, ID = 0, DM = 0, BC = 0, OF = 0, NF = 0;

    this->SP = (BYTE) 0;
    SP-=3;
    
    mem.init();
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
    std::cout << "SP: " << (int)SP << std::endl;
    std::cout << "PC: " << (int)PC << std::endl;
    std::cout << "-----" << std::endl;
};

void CPU::Log(std::string s) {
    std::cout << "Cycle: " << Cycle << std::endl;
    std::cout << s << std::endl;
};

void CPU::Step(Memory mem) {
    Decode(mem.Read(PC));
    PC++;
}