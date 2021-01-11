
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
		lea dx,buffer
		mov ah, 0ah
		int 21h
			
			
		mov bl, buffer[1]
		mov buffer[bx+2], '$'
		lea dx,buffer + 2
		mov ah, 9
		int 21h
ret

    		buffer db 20,?



