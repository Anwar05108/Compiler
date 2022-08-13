.model small
.stack 100h

.data

.code

MAIN PROC
MOV AX, @DATA
MOV DS, AX
mov ax, temp_0
	cmp ax, 0
	je label_0
jmp label_1
label_0: 
label_1: 
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
