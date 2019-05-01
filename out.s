; asmsyntax=nasm
global outb			; Make the label outb visible outside the file

; outb - send a byte to an I/O port
; stack: [esp + 8] the data byte
;        [esp + 4] the I/O port
;        [esp    ] return address
outb:
	mov al, [esp + 8]	; Move the data to be sent to al
	mov dx, [esp + 4]	; Move the address of the I/O port to dx
	mov dx, al			; Send the data to the I/O port
	ret					; return to the calling function 
