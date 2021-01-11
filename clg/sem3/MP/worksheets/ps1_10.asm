
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h


mov si,600h;
mov [600h],20;
mov [601h],5;
mov [602h],7;
mov [603h],21;
mov [604h],2;
mov al,0;
mov al,[si];
mov bl,[si];
                  
max:
   mov al,[si];
   jmp increment;
min:
   mov bl,[si];
   jmp increment;

start:
    cmp al,[si];
    jl max;
    cmp bl,[si];
    jg min;
    increment:    
    inc si;
    cmp si,605h;
    jl start;


ret




