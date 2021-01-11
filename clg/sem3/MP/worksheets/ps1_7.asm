
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax,10;
mov bx,20;
mov cx,30;
mov dx,40;
mov si,50;
mov di,60;

jmp start;

start:
    ax_and_bx:
    cmp ax,bx;
    jge bx_and_cx;
    xchg ax,bx;
    jmp start;
    
    bx_and_cx:
    cmp bx,cx;
    jge cx_and_dx;
    xchg bx,cx;
    jmp start;
    
    cx_and_dx:
    cmp cx,dx;
    jge dx_and_si;
    xchg cx,dx;
    jmp start;
    
    dx_and_si:
    cmp dx,si;
    jge si_and_di;
    xchg dx,si;
    jmp start;
    
    si_and_di:
    cmp si,di;
    jge finish;
    xchg si,di;
    jmp start;

finish:   


ret




