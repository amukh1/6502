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