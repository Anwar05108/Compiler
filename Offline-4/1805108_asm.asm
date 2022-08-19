.model small
.stack 100h

.data

print_var dw ?
temp_0 dw ?
x dw ?
temp_1 dw ?
temp_2 dw ?
temp_3 dw ?
a dw ?
b dw ?
temp_4 dw ?
e dw ?
c dw ?
d dw ?
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
	POP e
	PUSH BP
	mov ax, 2
	mov bx, e
	imul bx
	mov temp_0, ax
	pop bp
	push temp_0
	PUSH BP
	RET
f ENDP
g PROC 
	POP BP
	POP d
	POP c
	PUSH BP
	push ax
	push bx
	push cx
	push dx
	push 
	call f
	pop temp_1
	pop dx
	pop cx
	pop bx
	pop ax
	mov ax, temp_1
	add ax, 
	mov temp_2, ax
	mov ax, temp_2
	add ax, 
	mov temp_3, ax
	mov ax,temp_3
	mov x, ax
	pop bp
	push x
	PUSH BP
	RET
g ENDP
MAIN PROC
MOV AX, @DATA
MOV DS, AX
	mov ax,1
	mov a, ax
	mov ax,2
	mov b, ax
	push ax
	push bx
	push cx
	push dx
	push a
	push b
	call g
	pop temp_4
	pop dx
	pop cx
	pop bx
	pop ax
	mov ax,temp_4
	mov a, ax
	mov ax, a
	mov print_var , ax
	call println
	pop bp
	push 0
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
