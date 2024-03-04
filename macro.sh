cc65 -Oirs -r  test.c -o test.s    
ca65  test.s -o test.o
ca65 startup.s -o startup.o
ld65 -C test.cfg startup.o test.o -o test c64.lib
# decompile test > test.decompile
da65 test -o test.decompile.asm