
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov si,600h;
mov di,700h;
mov bp,800h;
mov dl,0;

mov 2[si],10;
mov 3[si],-2;

positive:
    mov al,[si];
    mov [di],al;
    inc si;
    inc di;
    jmp start;
    
negative:
    mov al,[si];
    mov [bp],al;
    inc si;
    inc bp;
    jmp start;
    
start:
    cmp [si],0;
    jl negative;
    jg positive;
    inc dl;
    inc si;
    cmp si,610h;
    jl start;

ret




