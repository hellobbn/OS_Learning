; asmsyntax=nasm
global loader			; the entry symbol for ELF

; Kernel stack
KERNEL_STACK_SIZE equ 4096			; Size of stack in bytes

; Call a C function
extern sum_of_three					; The function sum_of_three is defined elsewhere

MAGIC_NUMBER 	equ 0x1BADB002		; Magic number for GRUB
FLAGS			equ 0x0				; Multiboot flag
CHECKSUM		equ -MAGIC_NUMBER	; Calculate checksum: (magic number + checksum + flag = 0)

section .text			; Start of the text (code) section
align 4					; 4 byte aligned
dd MAGIC_NUMBER			; Write the magic number
dd FLAGS				; Write the flags
dd CHECKSUM				; Write the checksum

loader:					; The loader label (entry point)
	mov esp, kernel_stack + KERNEL_STACK_SIZE			; Point esp to the start of the stack
	push dword 3					; Argument 3
	push dword 2					; Argument 2
	push dword 1					; Argument 1
	call sum_of_three				; Call the function, the result will be in eax
.loop:
	jmp .loop						; Forever loop

section .bss
align 4					; Align at 4 bytes
kernel_stack:			; Label points to the beginning of memory
	resb KERNEL_STACK_SIZE			; Reserve stack for the kernel
