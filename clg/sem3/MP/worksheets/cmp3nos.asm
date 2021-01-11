
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax,30
mov bx,20
mov cx,35
cmp ax,bx
jge lable1
mov dx,bx
jmp end
cmp bx,cx
jge lable2
mov dx,cx
jmp end
lable1:
cmp ax,cx
jge lable3:
mov dx,cx
jmp end
lable2:
mov dx,bx
lable3:
mov dx,ax
end:


ret




