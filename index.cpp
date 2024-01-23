#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "CPU.h"

int main() {
    CPU cpu;
    Memory memory;
    freopen("logs.txt", "w", stdout);
    cpu.Reset(memory);
    std::cout << "---------------------------------------" << std::endl;
    cpu.Log();
    cpu.Step(memory);
}