.ORIG x3000

; Gets player post and stores in player locaon vars;
GETP
ST R0, P_X
ST R1, P_Y
ST R2, P_Z

;|p_x - g_x| + |P_y - G_y| + |P_z-G_z|

; NOT DR, SR
; Not Flips each bit in the source register then -1
; -SR - 1
; Then add 1 to DR to get negative
; Then add DR, "negative value" to other register

; Loads R0 with Goal X value
LD R0, G_X
; Gets negative Goal X
NOT R4, R0
ADD R4, R4, #1
; Loads Players X value into R0
LD R0, P_X
; Adds negative to positive value, getting differance from goal
ADD R5, R0, R4
; Stores computed value register 5 into Differance X
ST R5, D_X

LD R0, G_Y
NOT R4, R0
ADD R4, R4, #1
LD R0, P_Y
ADD R5, R0, R4
ST R5, D_Y

LD R0, G_Z
NOT R4, R0
ADD R4, R4, #1
LD R0, P_Z
ADD R5, R0, R4
ST R5, D_Z


; Checks if D_X is negative, if so makes positive and adds to R7
LD R0, D_X
BRz DONEX
BRp DONEX

NOT R0, R0
ADD R0, R0, #1
ADD R7, R0, #0

DONEX
ADD R7, R0, #0

; Checks if D_Y is negative, if so makes positive and adds to R7
LD R0, D_Y
BRz DONEY
BRp DONEY

NOT R0, R0
ADD R0, R0, #1
ADD R7, R7, R0

DONEY
ADD R7, R7, R0

; Checks if D_Z is negative, if so makes positive and adds to R7
LD R0, D_Z
BRz DONEZ
BRp DONEZ

NOT R0, R0
ADD R0, R0, #1
ADD R7, R7, R0

DONEZ
ADD R7, R7, R0

ST R7, ACT_DIST

LD R1, GOAL_DIST
NOT R0, R7
ADD R0, R0, #1
ADD R6, R0, R1

LD R4, GOAL_DIST
LD R5, ACT_DIST


BRzp POS
BRn NEG

NEG
LEA R0, OUTBOUNDS
CHAT
REG
HALT

POS
LEA R0, INBOUNDS
CHAT
REG
HALT

; R4, Goal Dist, R5, Act Dist, R6, Differance

INBOUNDS .STRINGZ "The player is within distance of the goal"
OUTBOUNDS .STRINGZ "The player is outside the goal bounds"

; Player Location
P_X   .FILL #0
P_Y   .FILL #0
P_Z   .FILL #0

; Predefined goal constants
G_X   .FILL #5
G_Y   .FILL #5
G_Z   .FILL #5

; Differances
D_X   .FILL #0
D_Y   .FILL #0
D_Z   .FILL #0

; Goal distance
GOAL_DIST .FILL #10
ACT_DIST  .FILL #0
.END
