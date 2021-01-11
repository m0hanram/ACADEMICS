
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov bx,[1100h]
mov cx,bx
mov [1300h],cx

ret




