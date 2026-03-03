section .text 
global cpu_run              ; tornar a função cpu_run global para ser chamada de fora
extern memory               ; declarar a variável memory como externa, para ser usada na CPU    
extern sys_print            ; declarar a função sys_print como externa, para ser usada na CPU
; ======================
; loop de execução da CPU
; ======================

cpu_run:                    ; função principal da CPU, responsável por executar as instruções    
    mov rbx, memory

.loop:                      ; loop principal da CPU, onde as instruções são lidas e executadas
    mov al, [rsi]

    cmp al, 0x00
    je .halt

    cmp al, 0x01
    je .load 

    cmp al, 0x02
    je .add

    cmp al, 0x04
    je .print

    inc rsi
    jmp .loop

,load:                      ; instrução de load, que carrega um valor da memória para um registrador
    inc rsi
    mov bl, [rsi]
    inc rsi
    mov cl , [rsi]
    mov [memory + bx], cl
    inc rsi
    jmp .loop

.add:                       ; instrução de add, que soma dois valores da memória e armazena o resultado em outro endereço
                            ; simplificação: apenas soma os valores de memory[0] e memory[1], e armazena em memory[2]
    inc rsi 
    jmp .loop

.print:                     ; instrução de print, que imprime um valor da memória na saída padrão
    inc rsi 
    mov bl, [rsi]
    mov rbx, memory 
    add rbx, rbx
    call sys_print
    inc rsi
    jmp .loop

.halt:                      ; instrução de halt, que encerra a execução da CPU
    ret
