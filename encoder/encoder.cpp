#include "bits/stdc++.h"

int main() {
     std::ofstream file("../program.bin", std::ios::binary);

    char* data = (char*) malloc(11 * sizeof(char));
    data[0] = 0xA9;
    data[1] = 0x01;
    data[2] = 0xA2;
    data[3] = 0x02;
    for(int i = 4; i<10; i++) {
        data[i] = 0xEA;
    }
    data[10] = 0x00;

    for (int i = 0; i < 11; i++) {
        file.write(data+i, 1);
    }
    file.close();
    return 0;
}