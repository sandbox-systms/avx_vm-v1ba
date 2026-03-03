section .text 
global _start
extern load_program
extern cpu_run
; ==============================================================
; Programa principal
; ==============================================================

_start:
    ; carrega o programa na memoria 
    call cpu_run

    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; status: 0
    syscall 