.model small
.stack 100h

.data

i dw ?
a dw ?
j dw ?
temp_0 dw ?
temp_1 dw ?
.code

MAIN PROC
MOV AX, @DATA
MOV DS, AX
	mov ax,0
	mov , ax
label_2: 
	mov ax, 
	cmp bx, 10
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
	je label_3
	mov ax,
	mov , ax
	mov ax ,
	mov temp_1, ax
	inc
jmp label_2
label_3: 
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
