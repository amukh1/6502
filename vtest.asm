start:
NOP
NOP
LDA #1
STA 10
LDX 10
STX start+2
LDY start+2
PHA
LDA #2
PHA
LDA #3
PHA 
LDA #4
PLA
PLA
LDX "h"
BRK