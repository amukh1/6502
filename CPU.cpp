#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "CPU.h"

BYTE Memory::Read(WORD Address) {
    return (BYTE) 0;
}

void Memory::init() {
    return;
}

void CPU::Reset(Memory mem) {
    this->PC = 0xFFFC;

    A,X,Y = (BYTE) 0;
    CF, ZF, ID, DM, BC, OF, NF = (BIT) 0;

    this->SP = (BYTE) 0;
    SP--;
    
    mem.init();
}

void CPU::Log() {
    std::cout << "Cycle: " << Cycle << std::endl;
    std::cout << "A: " << A << std::endl;
    std::cout << "X: " << X << std::endl;
    std::cout << "Y: " << Y << std::endl;
    std::cout << "CF: " << CF << std::endl;
    std::cout << "ZF: " << ZF << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "DM: " << DM << std::endl;
    std::cout << "BC: " << BC << std::endl;
    std::cout << "OF: " << OF << std::endl;
    std::cout << "NF: " << NF << std::endl;
    std::cout << "SP: " << SP << std::endl;
    std::cout << "PC: " << PC << std::endl;
    std::cout << "-----" << std::endl;
    std::string s = "Hello";
    std::cout << *(&s+2) << std::endl;
};

void CPU::Log(std::string s) {
    std::cout << "Cycle: " << Cycle << std::endl;
    std::cout << s << std::endl;
};