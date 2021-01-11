
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov si,500h;
mov di,600h;
mov al,5;
mov ah,0;
mov dl,0;
mov [501h],0;
mov [501h],10;
mov [502h],20;
mov [503h],30;
mov [504h],40;


jmp same_order;

same_order:
    mov bl,[si];
    mov [di],bl;
    inc si;
    inc di;
    inc ah;
    cmp al,ah;
    jge same_order;

mov di,800h;
     
reverse_order:
   dec si;
   mov bl,[si];
   mov [di],bl;
   inc di;
   dec al;
   cmp al,0;
   jge reverse_order;

ret




