#include "bits/stdc++.h"

std::map<std::string, int> x = {
    {"BRK,", 0x00},
    {"NOP,", 0xEA},

    {"LDA,IMMD,", 0xA9},
    {"LDA,ZP,", 0xA5},

    {"LDX,IMMD,", 0xA2},
    {"LDX,ZP,", 0xA6},

    {"LDY,IMMD,", 0xA0},
    {"LDY,ZP,", 0xA4},

    {"STA,ABS,", 0x8D},
    {"STA,ZP,", 0x85},

    {"STX,ABS,", 0x8E},
    {"STX,ZP,", 0x86},

    {"STY,ABS,", 0x8C},
    {"STY,ZP,", 0x84},

    {"TAX,", 0xAA},
    {"TAY,", 0xA8},

    {"TSX,", 0xBA},
    {"TXA,", 0x8A},

    {"TXS,", 0x9A},
    {"TYA,", 0x98},

    {"PHA,", 0x48},
    {"PHP,", 0x08},
    
    {"PLA,", 0x68},
    {"PLP,", 0x28},

    {"AND,IMMD,", 0x29},
    {"AND,ZP,", 0x25},

    {"EOR,IMMD,", 0x49},
    {"EOR,ZP,", 0x45},
};

std::string dataTypeDecode(std::string data) {
    if(data[0] == '#') {
        return "IMMD";
    } else if(data[0] == '$') {
        return "ZP";
    } else if(data[0] == '0' && data[1] == 'x') {
        return "IMMD";
    } else {
        return "ABS";
    }
}

int dataDecode(std::string data) {
    if(data[0] == '#') {
        return std::stoi(data.substr(1));
    } else if(data[0] == '$') {
        return std::stoi(data.substr(1), nullptr, 16);
    } else if(data[0] == '0' && data[1] == 'x') {
        return std::stoi(data.substr(2), nullptr, 16);
    } else {
        return std::stoi(data);
    }
}



int main(int argc, char** argv) {
    char* filename = argv[1];
    freopen(filename, "r", stdin);

    // clear file argv[2]
    std::ofstream ofs;
    ofs.open(argv[2], std::ofstream::out | std::ofstream::trunc);
    ofs.close();


    std::string line;
    std::vector<std::string> lines;
    while(std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    for(auto& line : lines) {
        std::vector<std::string> bytes;
        std::stringstream ss(line);
        std::string byte;
        while(std::getline(ss, byte, ' ')) {
            bytes.push_back(byte);
        }
        
        std::string opstring = bytes[0];
        std::string opcode;
        if(bytes.size() == 2)
        opcode = opstring + "," + dataTypeDecode(bytes[1]) + ",";
        else
        opcode = opstring + ",";
        
        // write to file (binary)
        std::ofstream out(argv[2], std::ios::binary | std::ios::app);
        out.write((char*)& x[opcode], 1);

        if(bytes.size() == 2) {
        int y = dataDecode(bytes[1]);
        out.write((char*)& y, 1);
        }
        out.close();
    }
}