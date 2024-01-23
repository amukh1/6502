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
    Matrix[0x01] = "ORA";
    Matrix[0x02] = "NOP";
    Matrix[0x03] = "NOP";
    Matrix[0x04] = "NOP";
    Matrix[0x05] = "ORA";
    Matrix[0x06] = "ASL";
    Matrix[0x07] = "NOP";
    Matrix[0x08] = "PHP";
    Matrix[0x09] = "ORA";
    Matrix[0x0A] = "ASL";
    Matrix[0x0B] = "NOP";
    Matrix[0x0C] = "NOP";
    Matrix[0x0D] = "ORA";
    Matrix[0x0E] = "ASL";
    Matrix[0x0F] = "NOP";
    Matrix[0x10] = "BPL";
    Matrix[0x11] = "ORA";
    Matrix[0x12] = "NOP";
    Matrix[0x13] = "NOP";
    Matrix[0x14] = "NOP";
    Matrix[0x15] = "ORA";
    Matrix[0x16] = "ASL";
    Matrix[0x17] = "NOP";
    Matrix[0x18] = "CLC";
    Matrix[0x19] = "ORA";
    Matrix[0x1A] = "NOP";
    Matrix[0x1B] = "NOP";
    Matrix[0x1C] = "NOP";
    Matrix[0x1D] = "ORA";
    Matrix[0x1E] = "ASL";
    Matrix[0x1F] = "NOP";
    Matrix[0x20] = "JSR";
    Matrix[0x21] = "AND";
    Matrix[0x22] = "NOP";
    Matrix[0x23] = "NOP";
    Matrix[0x24] = "BIT";
    Matrix[0x25] = "AND";
    Matrix[0x26] = "ROL";
    Matrix[0x27] = "NOP";
    Matrix[0x28] = "PLP";
    Matrix[0x29] = "AND";
    Matrix[0x2A] = "ROL";
    Matrix[0x2B] = "NOP";
    Matrix[0x2C] = "BIT";
    Matrix[0x2D] = "AND";
    Matrix[0x2E] = "ROL";
    Matrix[0x2F] = "NOP";
    Matrix[0x30] = "BMI";
    Matrix[0x31] = "AND";
    Matrix[0x32] = "NOP";
    Matrix[0x33] = "NOP";
    Matrix[0x34] = "NOP";
    Matrix[0x35] = "AND";
    Matrix[0x36] = "ROL";
    Matrix[0x37] = "NOP";
    Matrix[0x38] = "SEC";
    Matrix[0x39] = "AND";
    Matrix[0x3A] = "NOP";
    Matrix[0x3B] = "NOP";
    Matrix[0x3C] = "NOP";
    Matrix[0x3D] = "AND";
    Matrix[0x3E] = "ROL";
    Matrix[0x3F] = "NOP";
    Matrix[0x40] = "RTI";
    Matrix[0x41] = "EOR";
    Matrix[0x42] = "NOP";
    Matrix[0x43] = "NOP";
    Matrix[0x44] = "NOP";
    Matrix[0x45] = "EOR";
    Matrix[0x46] = "LSR";
}

void CPU::Decode(BYTE opcode) {
    std::cout << Matrix[opcode] << std::endl;
}