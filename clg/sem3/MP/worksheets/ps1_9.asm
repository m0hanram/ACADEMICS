
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax,5
mov cx,0
mov si,500h
mov di,600h

copy:
    mov bl,[si]
    mov [di],bl
    inc di
    inc si
    inc cx
    cmp cx,ax
    jl copy

ret




