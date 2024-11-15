#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <memory>

using _BIT = bool;
using WORD = unsigned short;
using BYTE = unsigned char;

struct Memory {
    BYTE Read(WORD Address);
    void Write(WORD ADDRESS, BYTE Data);
    std::vector<BYTE> data; // needs to hold 64KB of data
    void init();
};


struct CPU {
    WORD PC = 0xFFFC; // program counter
    BYTE SP = (BYTE) 0; // stack counter
    BYTE A, X, Y; // registers
    // _BIT CF, ZF, ID, DM, BC, OF, NF, _BRK;
    _BIT N, V, BR, B, D, I, Z, C; // flags
    
    int Cycle = 0;

    int Ticks = 0;

    std::map<int, std::string> Matrix;

    void Tick(int n);
    void Reset(std::unique_ptr<Memory>& mem);
    void Log();
    void Log(std::string s);
    std::string Decode(BYTE opcode);
    void Step(std::unique_ptr<Memory>& mem);
    void Start(std::unique_ptr<Memory>& mem);
    void FillMatrix();

    std::unique_ptr<Memory> mem;


    // operations
    void ADC(std::unique_ptr<Memory>& mem);
    void AND(std::unique_ptr<Memory>& mem);
    void ASL(std::unique_ptr<Memory>& mem);
    void BCC(std::unique_ptr<Memory>& mem);
    void BCS(std::unique_ptr<Memory>& mem);
    void BEQ(std::unique_ptr<Memory>& mem);
    void BIT(std::unique_ptr<Memory>& mem);
    void BMI(std::unique_ptr<Memory>& mem);
    void BNE(std::unique_ptr<Memory>& mem);
    void BPL(std::unique_ptr<Memory>& mem);
    void BRK(std::unique_ptr<Memory>& mem);
    void BVC(std::unique_ptr<Memory>& mem);
    void BVS(std::unique_ptr<Memory>& mem);
    void CLC(std::unique_ptr<Memory>& mem);
    void CLD(std::unique_ptr<Memory>& mem);
    void CLI(std::unique_ptr<Memory>& mem);
    void CLV(std::unique_ptr<Memory>& mem);
    void CMP(std::unique_ptr<Memory>& mem);
    void CPX(std::unique_ptr<Memory>& mem);
    void CPY(std::unique_ptr<Memory>& mem);
    void DEC(std::unique_ptr<Memory>& mem);
    void DEX(std::unique_ptr<Memory>& mem);
    void DEY(std::unique_ptr<Memory>& mem);
    void EOR(std::unique_ptr<Memory>& mem);
    void INC(std::unique_ptr<Memory>& mem);
    void INX(std::unique_ptr<Memory>& mem);
    void INY(std::unique_ptr<Memory>& mem);
    void JMP(std::unique_ptr<Memory>& mem);
    void JSR(std::unique_ptr<Memory>& mem);
    void LDA(std::unique_ptr<Memory>& mem);
    void LDX(std::unique_ptr<Memory>& mem);
    void LDY(std::unique_ptr<Memory>& mem);
    void LSR(std::unique_ptr<Memory>& mem);
    void NOP(std::unique_ptr<Memory>& mem);
    void ORA(std::unique_ptr<Memory>& mem);
    void PHA(std::unique_ptr<Memory>& mem);
    void PHP(std::unique_ptr<Memory>& mem);
    void PLA(std::unique_ptr<Memory>& mem);
    void PLP(std::unique_ptr<Memory>& mem);
    void ROL(std::unique_ptr<Memory>& mem);
    void ROR(std::unique_ptr<Memory>& mem);
    void RTI(std::unique_ptr<Memory>& mem);
    void RTS(std::unique_ptr<Memory>& mem);
    void SBC(std::unique_ptr<Memory>& mem);
    void SEC(std::unique_ptr<Memory>& mem);
    void SED(std::unique_ptr<Memory>& mem);
    void SEI(std::unique_ptr<Memory>& mem);
    void STA(std::unique_ptr<Memory>& mem);
    void STX(std::unique_ptr<Memory>& mem);
    void STY(std::unique_ptr<Memory>& mem);
    void TAX(std::unique_ptr<Memory>& mem);
    void TAY(std::unique_ptr<Memory>& mem);
    void TSX(std::unique_ptr<Memory>& mem);
    void TXA(std::unique_ptr<Memory>& mem);
    void TXS(std::unique_ptr<Memory>& mem);
    void TYA(std::unique_ptr<Memory>& mem);
    void WAI(std::unique_ptr<Memory>& mem);
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