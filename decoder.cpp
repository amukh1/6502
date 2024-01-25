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

   Matrix[0xA0] = "LDY";
   Matrix[0xA4] = "LDY";

   Matrix[0x8D] = "STA";
   Matrix[0x85] = "STA";

   Matrix[0x8E] = "STX";
    Matrix[0x86] = "STX";

    Matrix[0x84] = "STY";
    Matrix[0x8C] = "STY";
}

std::string CPU::Decode(BYTE opcode) {
    std::cout << Matrix.at((int)opcode) << std::endl;
    return Matrix.at((int)opcode);
}