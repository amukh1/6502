cc65 -Oirs  test.c -o test.s
ca65  test.s -o test.o
ld65 -C test.cfg test.o startup.o -o test c64.lib
# decompile test > test.decompile
da65 test -o test.decompile.asm