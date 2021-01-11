
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov al, 75
mov ah, 25h
lea dx, cases
int 21h

     


;enter 1 for min
;enter 2 for max
;enter 3 for avg
;enter 4 for swap
;enter 5 for multiply
;enter 6 for divide 

mov ah, 1
int 21h  

mov ah,al 

mov cl,8h
mov dl,4h

int 75
jmp finish  

cases:

cmp ah, '1'

je case1

cmp ah, '2'

je case2  

cmp ah, '3'

je case3

cmp ah, '4'

je case4 


cmp ah, '5'

je case5   

cmp ah, '6'

je case6 
  
case1:
cmp cl,dl
jl min
mov bl,dl
iret
min:
mov bl,cl 
iret

case2:
cmp cl,dl
jg max
mov bl,dl 
iret
max:
mov bl,cl
iret 
  
case3:
add cl,dl
mov ch,00h 
mov ax,cx
mov bl,2
div bl
mov bl,al
iret

case4:
xchg cl,dl
iret   

case5: 

jmp start
multiply:
add bl,cl
jmp l1

start:
mov bl,0h
mov ch,0

l1:
inc ch
cmp ch,dl
jle multiply 
iret

case6: 

jmp start2
divide:
sub cl,dl
cmp cl,0
jl enddivide
inc bl
jmp l2

start2:
mov bl,0h
mov ch,0

l2:
inc ch
cmp ch,dl
jle divide
enddivide: 
iret

finish:

ret






