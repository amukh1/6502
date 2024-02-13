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
    cpu.mem = std::make_unique<Memory>();
    std::string filename = argv[1];
    std::ifstream infile(filename, std::ios::binary);
    infile.seekg(0, std::ios::end);
    size_t size = infile.tellg();
    infile.seekg(0, std::ios::beg);
    // memory.data = new BYTE[(int)std::pow(2,16)*sizeof(BYTE)];
    // malloc enough memory for 64KB OF DATA.
    cpu.mem->data = std::vector<BYTE>(std::pow(16,4));
    // infile.read((char*)(memory.data+0x8000), size);
    char* buffer = new char[size];
    infile.read(buffer, size);
    infile.close();

    std::fill(cpu.mem->data.begin(), cpu.mem->data.end(), 0);

    for(int i = 0; i < size; i++) {
        cpu.mem->data[i+0x8000] = buffer[i];
    }
    cpu.Reset(cpu.mem);
    // std::cout << cpu._BRK << std::endl;
    // std::cout << "---------------------------------------" << std::endl;
    cpu.Log();
    while(cpu.BR == 0) {
        cpu.Step(cpu.mem);
        cpu.Log();
    }
    // dump memory into file memory.bin
    std::ofstream outfile("memory.bin", std::ios::binary);
    outfile.write((char*)cpu.mem->data.data(), (int)(65536 * sizeof(unsigned char)));
    outfile.close();
    // free(memory.data);
    return 0;
}