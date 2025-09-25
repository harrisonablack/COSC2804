.ORIG x3000

; Store player position
GETP
ST R0, P_X
ST R1, P_Y
ST R2, P_Z

LD R0, NUMBER_TO_CONVERT
LEA R1, MASKS           ; Lea loads R1 with address of first mask, "pointer"
AND R2, R2, #0          ; Sets r2 with loop, to loop 16 times
ADD R2, R2, #16

LOOP
LDR R3, R1, #0
AND R4, R0, R3
BRz ZBIT

LD

HALT
NUMBER_TO_CONVERT .FILL #237

P_X     .FILL #0
P_Y     .FILL #0
P_Z     .FILL #0

MASKS   .FILL x8000
        .FILL x4000
        .FILL x2000
        .FILL x1000
        .FILL x0800
        .FILL x0400
        .FILL x0200
        .FILL x0100
        .FILL x0080
        .FILL x0040
        .FILL x0020
        .FILL x0010
        .FILL x0008
        .FILL x0004
        .FILL x0002
        .FILL x0001
ONE     .FILL x0031          ; '1'
ZERO    .FILL x0030          ; '0'
.END
