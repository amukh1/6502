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
    memory.init();
    std::string filename = argv[1];
    std::ifstream infile(filename, std::ios::binary);
    infile.seekg(0, std::ios::end);
    size_t size = infile.tellg();
    infile.seekg(0, std::ios::beg);
    memory.data = new char[(int)std::pow(2,16)];
    infile.read(memory.data+0x8000, size);
    infile.close();
    freopen("logs.txt", "w", stdout);
    cpu.Reset(memory);
    // std::cout << cpu._BRK << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    cpu.Log();
    while(cpu._BRK == 0) {
        cpu.Step(memory);
        cpu.Log();
    }
    // dump memory into file memory.bin
    std::ofstream outfile("memory.bin", std::ios::binary);
    outfile.write(memory.data, (int)std::pow(2,16));
    outfile.close();
    free(memory.data);
    return 0;
}