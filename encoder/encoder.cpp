#include "bits/stdc++.h"

int main() {
     std::ofstream file("../program.bin", std::ios::binary);

    char* data = (char*) malloc((int)std::pow(2,15) * sizeof(char));
    data[0] = 0xA9; // LDA
    data[1] = 0x01; // #1
    data[2] = 0xA2; // LDX
    data[3] = 0x02; // #2
    data[4] = 0xA0; // LDY
    data[5] = 0x03; // #3
    data[6] = 0x8D; // STA
    data[7] = 0x00; // $0x0000
    data[8] = 0xA4; // LDY
    data[9] = 0x00; // $0x0000
    data[10] = 0x8A;
    data[11] = 0x48;


    for (int i = 0; i < 12; i++) {
        file.write(data+i, 1);
    }
    file.close();
    return 0;
}