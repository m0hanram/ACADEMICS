
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

DATA SEGMENT

fullword db 'alphabets';
substring db 'bet';

DATA ENDS

CODE SEGMENT
    
lea si,fullword;
lea di,substring;
mov dx,9;
mov cx,3;
mov al,0;

cmp dx,cx;
jl finish;

search:
    mov bl,[si];
    mov bh,[di];
    cmp bl,bh;
    je nextcheck;
    jne incnext;
    
incnext:
    inc si;
    dec dx;
    cmp dx,0h
    je finish;
    jmp search;
    
nextcheck:
    mov sp,si;
    add sp,1h;
    cld;
    repe cmpsb
    je found;
    jne curnotfound;
    
curnotfound:
    mov si,sp;
    dec dx;
    lea di,substring;
    jmp search;
    
found:
    mov al,1;
    jmp finish;
                   

finish:
CODE ENDS
ret




