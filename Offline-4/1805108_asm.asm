.model small
.stack 100h

.data

print_var dw ?
a1_1 dw ?
temp_0 dw ?
a1_2 dw ?
b1_2 dw ?
x1_2 dw ?
temp_1 dw ?
temp_2 dw ?
temp_3 dw ?
a1_3 dw ?
b1_3 dw ?
temp_4 dw ?
.code

println proc near
	push ax
	push bx
	push cx
	push dx

	mov ax, print_var
	or ax, ax
	jge end_if_1
	push ax
	mov dl, '-'
	mov ah, 2
	int 21h
	pop ax
	neg ax

end_if_1:
	xor cx,cx
	mov bx,10d

loop_1:
	xor dx, dx
	div bx
	push dx
	inc cx
	or ax,ax
	jne loop_1
	mov ah, 2

loop_2:
	pop dx
	or dl, 30h
	int 21h
	loop loop_2

	mov dl, 0dh
	mov ah, 2
	int 21h

	mov dl, 0ah
	mov ah, 2
	int 21h

	pop dx
	pop cx
	pop bx
	pop ax
	ret

println endp

f PROC 
	POP BP
	POP a1_1
	PUSH BP
	mov ax, 2
	mov bx, a1_1
	imul bx
	mov temp_0, ax
	pop bp
	push temp_0
	mov ax,9
	mov a1_1, ax
	PUSH BP
	RET
f ENDP
g PROC 
	POP BP
	POP b1_2
	POP a1_2
	PUSH BP
	push ax
	push bx
	push cx
	push dx
	push a1_2
	call f
	pop temp_1
	pop dx
	pop cx
	pop bx
	pop ax
	mov ax, temp_1
	add ax, a1_2
	mov temp_2, ax
	mov ax, temp_2
	add ax, b1_2
	mov temp_3, ax
	mov ax,temp_3
	mov a1_1, ax
	pop bp
	push a1_1
	PUSH BP
	RET
g ENDP
MAIN PROC
MOV AX, @DATA
MOV DS, AX
	mov ax,1
	mov a1_1, ax
	mov ax,2
	mov temp_0, ax
	push ax
	push bx
	push cx
	push dx
	push a1_1
	push temp_0
	call g
	pop temp_4
	pop dx
	pop cx
	pop bx
	pop ax
	mov ax,temp_4
	mov a1_1, ax
	mov ax, a1_1
	mov print_var , ax
	call println
	pop bp
	push 0
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
