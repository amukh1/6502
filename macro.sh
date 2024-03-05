cc65  test.c -o test.s
ca65  test.s -o test.o
ca65 startup.s -o startup.o
ld65 startup.o test.o none.lib  -o test -C test.cfg
# decompile test > test.decompile
da65 test -o test.decompile.asm