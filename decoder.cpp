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

   Matrix[0xA9] = "LDA";
   Matrix[0xA5] = "LDA";

   Matrix[0xA2] = "LDX";
   Matrix[0xA6] = "LDX";
}

std::string CPU::Decode(BYTE opcode) {
    std::cout << Matrix.at((int)opcode) << std::endl;
    return Matrix.at((int)opcode);
}