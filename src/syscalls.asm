section .text
global sys_print 

sys_print:
    mov rax, 1
    mov rdi, 1
    mov rsi, rbx
    mov rdx, 1 
    syscall 
    ret 