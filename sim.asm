START
MOV SP, 0
MOV BP, 0
MAIN:
MOV R1,0
MOV R1,1
LT R1,R1
MOV R1,3
MOV [R1],R0
MOV R1,1
MOV R2,0
MOV R2,1
ADD R1,R2
GE R1,R2
MOV R1,3
MOV [R1],R0
MOV R1,0
MOV R0,R1
HALT