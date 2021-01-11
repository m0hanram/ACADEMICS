
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax,7000
mov cx,0

jmp compare

compare: 
    shr ax,1
    jnc increment

increment:
    inc ax
    inc cx
    cmp ax,8000
    jle compare

ret




