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
   Matrix[0x8C] = "STY"; // store y register in memory

   Matrix[0xAA] = "TAX";
   Matrix[0xA8] = "TAY";
   Matrix[0xBA] = "TSX"; // transfer stack pointer to x register
   Matrix[0x8A] = "TXA"; // transfer x register to accumulator
   Matrix[0x9A] = "TXS"; // transfer x register to stack pointer
   Matrix[0x98] = "TYA"; // transfer y register to accumulator

   Matrix[0x48] = "PHA"; // push accumulator on stack
   Matrix[0x08] = "PHP"; // push processor status on stack
   Matrix[0x68] = "PLA"; // pull accumulator from stack
   Matrix[0x28] = "PLP"; // pull processor status from stack

}

std::string CPU::Decode(BYTE opcode) {
    std::cout << Matrix.at((int)opcode) << std::endl;
    return Matrix.at((int)opcode);
}