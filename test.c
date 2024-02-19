// #include <stdio.h>

int fish(int x) {
    return x;
}

int frog(int x) {
    fish(7);
    return x;
}

int main() {
    // printf("h");
    // int a = 16;
    frog(6);
    return 16;
}