#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <memory>

#include "CPU.h"

int main(int argc, char** argv) {
    CPU cpu;
    Memory memory;
    std::string filename = argv[1];
    std::ifstream infile(filename, std::ios::binary);
    infile.seekg(0, std::ios::end);
    size_t size = infile.tellg();
    infile.seekg(0, std::ios::beg);
    memory.data = new char[size];
    infile.read(memory.data, size);
    infile.close();
    freopen("logs.txt", "w", stdout);
    cpu.Reset(memory);
    std::cout << "---------------------------------------" << std::endl;
    cpu.Log();
    for(int i = 0; i < 11; i++) {
        cpu.Step(memory);
        cpu.Log();
    }
    
    return 0;
}