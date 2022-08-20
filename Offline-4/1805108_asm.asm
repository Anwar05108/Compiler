.model small
.stack 100h

.data

print_var dw ?
i1_1 dw ?
j1_1 dw ?
k1_1 dw ?
ll1_1 dw ?
temp_0 dw ?
temp_1 dw ?
temp_2 dw ?
temp_3 dw ?
temp_4 dw ?
temp_5 dw ?
temp_6 dw ?
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
;for loop
 ; assignment expression:i=0
	mov ax,0
	mov i1_1, ax
label_2: 
 ; Relational Operation: i<6
	mov ax, i1_1
	cmp ax, 6
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
 ; println(i)
	mov ax, i1_1
	mov print_var , ax
	call println
; increment: i++
	mov ax ,i1_1
	mov temp_1, ax
	inc i1_1
jmp label_2
label_3: 
 ; assignment expression:k=4
	mov ax,4
	mov k1_1, ax
 ; assignment expression:ll=6
	mov ax,6
	mov ll1_1, ax
;while loop
label_6: 
 ; Relational Operation: k>0
	mov ax, k1_1
	cmp ax, 0
	jg label_5
	mov ax, 0
	mov temp_2, ax
	jmp label_4
label_5:
	mov ax, 1
	mov temp_2, ax
label_4:
	mov ax, temp_2
	cmp ax, 0
	je label_7
 ; assignment expression:ll=ll+3
	mov ax, ll1_1
	add ax, 3
	mov temp_3, ax
	mov ax,temp_3
	mov ll1_1, ax
; decrement: k--
	mov ax,k1_1
	mov temp_4, ax
	dec k1_1
jmp label_6
label_7: 
 ; println(ll)
	mov ax, ll1_1
	mov print_var , ax
	call println
 ; println(k)
	mov ax, k1_1
	mov print_var , ax
	call println
 ; assignment expression:k=4
	mov ax,4
	mov k1_1, ax
 ; assignment expression:ll=6
	mov ax,6
	mov ll1_1, ax
;while loop
label_8: 
; decrement: k--
	mov ax,k1_1
	mov temp_5, ax
	dec k1_1
	mov ax, temp_5
	cmp ax, 0
	je label_9
 ; assignment expression:ll=ll+3
	mov ax, ll1_1
	add ax, 3
	mov temp_6, ax
	mov ax,temp_6
	mov ll1_1, ax
jmp label_8
label_9: 
 ; println(ll)
	mov ax, ll1_1
	mov print_var , ax
	call println
 ; println(k)
	mov ax, k1_1
	mov print_var , ax
	call println
	pop bp
	push 0
MOV AX, 4C00h
INT 21h
MAIN ENDP
END MAIN
