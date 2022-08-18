.model small
.stack 100h

.data

print_var dw ?
a dw ?
b dw ?
c dw ?
i dw ?
temp_0 dw ?
temp_1 dw ?
temp_2 dw ?
temp_3 dw ?
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

MAIN PROC
MOV AX, @DATA
MOV DS, AX
	mov ax,0
	mov b, ax
	mov ax,1
	mov c, ax
	mov ax,0
	mov i, ax
label_4: 
	mov ax, i
	cmp ax, 4
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
	je label_5
	mov ax,3
	mov a, ax
label_2: 
	mov ax,a
	mov temp_2, ax
	deca
	mov ax, temp_2
	cmp ax, 0
	je label_3
	mov ax ,b
	mov temp_3, ax
	inc b
jmp label_2
label_3: 
	mov ax ,i
	mov temp_1, ax
	inc i
jmp label_4
label_5: 
	mov ax, a
	mov print_var , ax
	call println
	mov ax, b
	mov print_var , ax
	call println
	mov ax, c
	mov print_var , ax
	call println
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
