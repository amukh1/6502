cc65 -O -t c64 test.c
ca65 -t c64 test.s
ld65 -t c64 -o test test.o c64.lib