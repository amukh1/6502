#include "bits/stdc++.h"

int main(int argc, char** argv) {
    char* filename = argv[1];
    freopen(filename, "r", stdin);

    std::string line;
    std::vector<std::string> lines;
    while(std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    int lastOpcode = 0;
    std::ofstream outfile("program.bin", std::ios::binary);
    for(int i = 0; i<lines.size(); i++) {
        if(lines[i][0] == '#') {
            // treat as hex
            std::string hex = lines[i].substr(1, lines[i].size()-1);
            int num = std::stoi(hex, nullptr, 16);
            outfile.write((char*)&num, 1);
        }else if(lines[i][0] == '$') {
            // treat as hex, address
            // change last byte that was an opcode to take address instead of immd
            // first remove last opcode byte
            outfile.seekp(lastOpcode, std::ios::beg);
            if(lines[lastOpcode] == "LDA") {
                outfile.write("\xA5", 1);
            }else if(lines[lastOpcode] == "LDX") {
                outfile.write("\xA6", 1);
            }else if(lines[lastOpcode] == "LDY") {
                outfile.write("\xA4", 1);
            }else if(lines[lastOpcode] == "STA") {
                outfile.write("\x85", 1);
            }else if(lines[lastOpcode] == "STX") {
                outfile.write("\x86", 1);
            }else if(lines[lastOpcode] == "STY") {
                outfile.write("\x84", 1);
            }else {
                std::cout << "Invalid operand" << std::endl;
                return 0;
            }
            std::string hex = lines[i].substr(1, lines[i].size()-1);
            int num = std::stoi(hex, nullptr, 16);
            outfile.write((char*)&num, 1);
        }else {
            lastOpcode = i;
            // treat as opcode
            if(lines[i] == "BRK") {
                outfile.write("\x00", 1);
            }else if(lines[i] == "NOP") {
                outfile.write("\xEA", 1);
            }else if(lines[i] == "LDA") {
                outfile.write("\xA9", 1);
            }else if(lines[i] == "LDX") {
                outfile.write("\xA2", 1);
            }else if(lines[i] == "LDY") {
                outfile.write("\xA0", 1);
            }else if(lines[i] == "STA") {
                outfile.write("\x8D", 1);
            }else if(lines[i] == "STX") {
                outfile.write("\x8E", 1);
            }else if(lines[i] == "STY") {
                outfile.write("\x84", 1);
            }else {
                std::cout << "Invalid opcode" << std::endl;
                return 0;
            }
        }
    }
}