
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov [1203h],20;
mov [1207h],20;
mov [1245h],20;
mov al,20;
mov dx,0;
mov bx,1200h;

jmp start;

increment:
    inc dx;
    inc bx;
    jmp continue;
    
start:
    cmp al,[bx];
    je increment;
    inc bx;

continue:
    cmp bx,1250h;
    jle start;

ret




