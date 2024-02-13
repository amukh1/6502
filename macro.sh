cc65 -O  test.c
ca65  test.s
ld65  -o test -C test.cfg test.o startup.o c64.lib
# decompile test > test.decompile
# da65 test -o test2.s