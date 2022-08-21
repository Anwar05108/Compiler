.model small
.stack 100h

.data

print_var dw ?
a1 dw ?
b1 dw ?
c1 dw ?
a1_2 dw ?
temp_0 dw ?
a1_3 dw ?
b1_3 dw ?
c1_3 dw ?
temp_1 dw ?
temp_2 dw ?
temp_3 dw ?
i1_4 dw ?
j1_4 dw ?
k1_4 dw ?
l1_4 dw ?
temp_4 dw ?
temp_5 dw ?
temp_6 dw ?
temp_7 dw ?
temp_8 dw ?
temp_9 dw ?
temp_10 dw ?
temp_11 dw ?
temp_12 dw ?
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

func_a PROC 
	POP BP
	PUSH BP
 ; assignment expression:a=7
	mov ax,7
	mov a1, ax
	PUSH BP
	RET
func_a ENDP
; function definition
foo PROC 
	POP BP
	POP a1_2
	PUSH BP
 ; assignment expression:a=a+3
	mov ax, a1_2
	add ax, 3
	mov temp_0, ax
	mov ax,temp_0
	mov a1_2, ax
	pop bp
	push a1_2
	PUSH BP
	RET
foo ENDP
; function definition
bar PROC 
	POP BP
	POP b1_3
	POP a1_3
	PUSH BP
 ; assignment expression:c=4*a+2*b
 ;4
	mov ax, 4
	mov bx, a1_3
	imul bx
	mov temp_1, ax
 ;2
	mov ax, 2
	mov bx, b1_3
	imul bx
	mov temp_2, ax
	mov ax, temp_1
	add ax, temp_2
	mov temp_3, ax
	mov ax,temp_3
	mov a1, ax
	pop bp
	push a1
	PUSH BP
	RET
bar ENDP
MAIN PROC
MOV AX, @DATA
MOV DS, AX
 ; assignment expression:i=5
	mov ax,5
	mov a1, ax
 ; assignment expression:j=6
	mov ax,6
	mov b1, ax
; function call: func_a (  )
	push ax
	push bx
	push cx
	push dx
	push 
	call func_a
	pop temp_4
	pop dx
	pop cx
	pop bx
	pop ax
 ; println(a)
	mov ax, a1
	mov print_var , ax
	call println
 ; assignment expression:k=foo ( i )
; function call: foo ( i )
	push ax
	push bx
	push cx
	push dx
	push a1
	call foo
	pop temp_5
	pop dx
	pop cx
	pop bx
	pop ax
	mov ax,temp_5
	mov c1, ax
 ; println(k)
	mov ax, c1
	mov print_var , ax
	call println
 ; assignment expression:l=bar ( i,j )
; function call: bar ( i,j )
	push ax
	push bx
	push cx
	push dx
	push a1
	push b1
	call bar
	pop temp_6
	pop dx
	pop cx
	pop bx
	pop ax
	mov ax,temp_6
	mov a1_2, ax
 ; println(l)
	mov ax, a1_2
	mov print_var , ax
	call println
 ; assignment expression:j=6*bar ( i,j )+2-3*foo ( i )
; function call: bar ( i,j )
	push ax
	push bx
	push cx
	push dx
	push a1
	push b1
	call bar
	pop temp_7
	pop dx
	pop cx
	pop bx
	pop ax
 ;6
	mov ax, 6
	mov bx, temp_7
	imul bx
	mov temp_8, ax
	mov ax, temp_8
	add ax, 2
	mov temp_9, ax
; function call: foo ( i )
	push ax
	push bx
	push cx
	push dx
	push a1
	call foo
	pop temp_10
	pop dx
	pop cx
	pop bx
	pop ax
 ;3
	mov ax, 3
	mov bx, temp_10
	imul bx
	mov temp_11, ax
	mov ax, temp_9
	sub ax, temp_11
	mov temp_12, ax
	mov ax,temp_12
	mov b1, ax
 ; println(j)
	mov ax, b1
	mov print_var , ax
	call println
	pop bp
	push 0
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
