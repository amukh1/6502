#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <fstream>

#include "CPU.h"

// fill matrix
void CPU::FillMatrix() {
   Matrix[0x00] = "BRK";
   Matrix[0xEA] = "NOP";

   Matrix[0xA9] = "LDA";
   Matrix[0xA5] = "LDA";
    Matrix[0xAD] = "LDA";
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

   Matrix[0x0E] = "ASL";
   Matrix[0x06] = "ASL";
   Matrix[0x0A] = "ASL";

    Matrix[0x4E] = "LSR";
    Matrix[0x46] = "LSR";
    Matrix[0x4A] = "LSR";

   Matrix[0x2E] = "ROL";
    Matrix[0x26] = "ROL";
    Matrix[0x2A] = "ROL";

    Matrix[0x6E] = "ROR";
    Matrix[0x66] = "ROR";
    Matrix[0x6A] = "ROR";

    Matrix[0x29] = "AND";
    Matrix[0x25] = "AND";
    Matrix[0x2D] = "AND";

    Matrix[0x49] = "EOR";
    Matrix[0x45] = "EOR";
    Matrix[0x4D] = "EOR";

    Matrix[0x09] = "ORA";
    Matrix[0x05] = "ORA";
    Matrix[0x0D] = "ORA";

    Matrix[0x49] = "CMP";
    Matrix[0xC5] = "CMP";
    Matrix[0xCD] = "CMP";

    Matrix[0xE0] = "CPX";
    Matrix[0xE4] = "CPX";
    Matrix[0xEC] = "CPX";

    Matrix[0xC0] = "CPY";
    Matrix[0xC4] = "CPY";
    Matrix[0xCC] = "CPY";

    Matrix[0xC6] = "DEC";
    Matrix[0xCE] = "DEC";
    Matrix[0xCA] = "DEX";

    Matrix[0x88] = "DEY";
    Matrix[0xE6] = "INC";
    Matrix[0xEE] = "INC";

    Matrix[0xE8] = "INX";
    Matrix[0xC8] = "INY";

    // break jump jsr rti rts
    Matrix[0x00] = "BRK";
    Matrix[0x4C] = "JMP";
    Matrix[0x6C] = "JMP";
    Matrix[0x20] = "JSR";
    Matrix[0x40] = "RTI";
    Matrix[0x60] = "RTS";




}

std::string CPU::Decode(BYTE opcode) {
    // std::cout << Matrix.at((int)opcode) << std::endl;
    try {
    std::ofstream outfile("logs.txt", std::ios::app);
    outfile << Matrix.at((int)opcode) << std::endl;
    outfile.close();
    return Matrix.at((int)opcode);
    } catch (const std::out_of_range& e) {
        std::ofstream outfile("logs.txt", std::ios::app);
        outfile << "Unknown opcode: " << std::hex << (int)opcode << std::endl;
        outfile.close();
        return "Unknown opcode";
    }
}