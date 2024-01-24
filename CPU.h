#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using BIT = bool;
using WORD = unsigned short;
using BYTE = unsigned char;

struct Memory {
    BYTE Read(WORD Address);
    BIT Write(WORD ADDRESS);
    char* data;
    void init();
};


struct CPU {
    WORD PC = 0xFFFC;
    BYTE SP = (BYTE) 0;
    BYTE A, X, Y;
    BIT CF, ZF, ID, DM, BC, OF, NF;
    
    int Cycle = 0;

    int Ticks = 0;

    std::map<int, std::string> Matrix;

    void Tick(int n);
    void Reset(Memory mem);
    void Log();
    void Log(std::string s);
    std::string Decode(BYTE opcode);
    void Step(Memory mem);
    void Start(Memory mem);
    void FillMatrix();


    // operations
    void ADC(Memory mem);
    void AND(Memory mem);
    void ASL(Memory mem);
    void BCC(Memory mem);
    void BCS(Memory mem);
    void BEQ(Memory mem);
    void BIT(Memory mem);
    void BMI(Memory mem);
    void BNE(Memory mem);
    void BPL(Memory mem);
    void BRK(Memory mem);
    void BVC(Memory mem);
    void BVS(Memory mem);
    void CLC(Memory mem);
    void CLD(Memory mem);
    void CLI(Memory mem);
    void CLV(Memory mem);
    void CMP(Memory mem);
    void CPX(Memory mem);
    void CPY(Memory mem);
    void DEC(Memory mem);
    void DEX(Memory mem);
    void DEY(Memory mem);
    void EOR(Memory mem);
    void INC(Memory mem);
    void INX(Memory mem);
    void INY(Memory mem);
    void JMP(Memory mem);
    void JSR(Memory mem);
    void LDA(Memory mem);
    void LDX(Memory mem);
    void LDY(Memory mem);
    void LSR(Memory mem);
    void NOP(Memory mem);
    void ORA(Memory mem);
    void PHA(Memory mem);
    void PHP(Memory mem);
    void PLA(Memory mem);
    void PLP(Memory mem);
    void ROL(Memory mem);
    void ROR(Memory mem);
    void RTI(Memory mem);
    void RTS(Memory mem);
    void SBC(Memory mem);
    void SEC(Memory mem);
    void SED(Memory mem);
    void SEI(Memory mem);
    void STA(Memory mem);
    void STX(Memory mem);
    void STY(Memory mem);
    void TAX(Memory mem);
    void TAY(Memory mem);
    void TSX(Memory mem);
    void TXA(Memory mem);
    void TXS(Memory mem);
    void TYA(Memory mem);
    void WAI(Memory mem);

};

/*
    WORD AB;
    BYTE DB;
    BIT BE;
    BIT IRQB;
    BIT MLB;
    BIT NMIB;
    BIT NC;
    BIT PHI10;
    BIT PHI2;
    BIT PHI20;
    BIT RDY;
    BIT RESB;
    BIT RWB;
    BIT SOB;
    BIT SYNC;
    BIT VDD;
    BIT VPD;
    BIT VSS;
    */