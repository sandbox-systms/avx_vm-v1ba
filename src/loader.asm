section .text 
global loader_program 
extern memory 

load_program:
    mov rsi, rdi
    mov rdi, memory
    mov rcx, 256
    rep movsb
    ret