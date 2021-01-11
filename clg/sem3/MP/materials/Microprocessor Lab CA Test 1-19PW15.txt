
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

data segment
    fullstring db 'ALPHAB'; data byte is used to allocate space to store the string   
    substring db 'LPH'; again db is used to store the substring    
data ends

code segment
    lea si,fullstring; here we dont know the address 
                     ;in which our string was stored
                     ;so we use Load Effective Address
                     ;to move the starting address of string into si 
    
    lea di,substring; here the same way we are storing
                    ; the starting address to di 
    mov dx,6; storing the lenght of fullstring
    mov cx,3; storing the lenght of substring
    cmp cx,dx; checking the length of the 2 strings
    jg finish; if substing > fullstring it is not possible case
    je samestring; if both are equal they should be the same words
    jl search; if substring<fullstring we have to check 
    
samestring:
    cld;
    repe cmpsb; repeat and compare string byte is used to check whether the strings are equal it will work till cx becomes 0, that is till length of substring
    je success; if all the letters are same then it is same strings
    jne failure; if a single letter does not match also they are different strings
    
search:
    mov bl,[si]; we are loading the ascii value to a bl register for comparing
    mov bh,[di];  we are loading the ascii value to a bh register for comparing
    cmp bl,bh; comparing the ascii values of the bl and bh
    je nextcheck; if they are equal then check the next 2 letters
    jne nextinc; if not increment the full string by one letter and check again
    
nextinc:
    inc si; increment to next letter
    dec dx; we finished checking the previous letter so decrement the size of full string 
    cmp dx,0000h; if all letters of full string is checked then finish
    je failure;
    jmp search; if not then loop to search
    
nextcheck:
    mov cx,3;
    mov sp,si; we are storing the address value of si so that incase if it is not same then we can again go back and cj=heck the next letters 
    add sp,0001h; increment to next letter sice we checked the previous letter
    cld; cld is done to clear the direction flag so that our repeat will go on increamenting
    repe cmpsb  ; check for the other letters if same then succes else fail
    jne movenext; 
    jmp success;
    
movenext:
    mov si,sp;
    dec dx;
    lea di,substring; in case one or two letter matches and others dont match then check again for remaining letter in fullstring 
    jmp search;

failure:
    mov al,00h; if fail then make al 0 signaling notfound 
    jmp finish;
    
success:
    mov al,01h; if success make al 1 signaling found
    jmp finish;
        
finish:
    code ends;
    end;
ret




