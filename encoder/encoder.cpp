#include "bits/stdc++.h"

int main() {
     std::ofstream file("../program.bin", std::ios::binary);

    char* data = (char*) malloc((int)std::pow(2,15) * sizeof(char));
    data[0] = 0xA9;
    data[1] = 0x01;
    data[2] = 0xA2;
    data[3] = 0x02;
    data[4] = 0xA0;
    data[5] = 0x03;
    // data[6] = 0xA5;
    // data[7] = 0x00;
    data[6] = 0x8D;
    data[7] = 0x00;
    data[8] = 0xA4;
    data[9] = 0x00;


    for (int i = 0; i < 11; i++) {
        file.write(data+i, 1);
    }
    file.close();
    return 0;
}