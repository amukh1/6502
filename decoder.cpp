#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

#include "CPU.h"

// fill matrix
void CPU::FillMatrix() {
   Matrix[0x00] = "BRK";
   Matrix[0xEA] = "NOP";
}

std::string CPU::Decode(BYTE opcode) {
    std::cout << Matrix.at((int)opcode) << std::endl;
    return Matrix.at((int)opcode);
}