.model small
.stack 100h

.data

i: dw ?
a: dw ?
temp_0: dw ?
temp_1: dw ?
temp_2: dw ?
.code

MAIN PROC
MOV AX, @DATA
MOV DS, AX
	mov ax, 
	cmp bx, 
	jl label_1
	mov ax, 0
	mov temp_0, ax
	jmp label_0
label_1:
	mov ax, 1
	mov temp_0, ax
label_0:
mov ax, temp_0
	cmp ax, 0
	je label_2
	mov ax, 
	add ax, 1
	mov temp_1, ax
	mov ax, 
jmp label_3
label_2: 
	mov ax, 
	sub ax, 1
	mov temp_2, ax
	mov ax, 
label_3: 
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
