
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax,6000h;
mov si,0h;
mov di,300h;
mov ds,ax;

mov 4[si],20h;
mov 6[si],30h;

start:
    mov ax,0;
    add ax,[si];
    add si,2;
    
    add ax,[si];
    add si,2;
    
    mov [di],ax;
    add di,2;
    
    cmp si,200h;
    jl start;

ret




