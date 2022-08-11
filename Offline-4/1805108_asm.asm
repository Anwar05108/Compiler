.model small
.stack 100h

.data

.code

MAIN PROC
MOV AX, @DATA
MOV DS, AX
label_0: 
	mov ax, temp_0
	cmp ax, 0
	je label_1
jmp label_0
label_1: 
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
