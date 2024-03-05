cc65  test.c -o test.s
ca65  test.s -o test.o
# ca65 startup.s -o startup.o
ca65 zeropage.s -o zeropage.o
ca65 crt0.s -o crt0.o
ld65 crt0.o zeropage.o test.o -o test -C test.cfg