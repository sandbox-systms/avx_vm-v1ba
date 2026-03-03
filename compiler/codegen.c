#include <stdio.h>
#include ".../include/isa.inc"

int main(int arg, char **argv) {
    if (argc < 3) return 1;

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "wb");

    int value;
    fscanf(in, "%d", &value);

    fputc(op_load, out);    // opcode para carregar um valor imediato
    fputc(0, out);          // opcode para alterar o estado para "halt
    fputc(value, out);      // valor imediato a ser carregado

    fputc(op_print, out);   // opcode para imprimir o valor de um registrador
    fputc(0, out);          // registrador a ser impresso

    fputc(op_halt, out);    // opcode para alterar o estado para "halt

    fclose(in);
    fclose(out);
    return 0;
}
/*Este código é um exemplo simples de um gerador de código para uma máquina virtual hipotética.
Ele lê um valor inteiro de um arquivo de entrada, gera um código de máquina que carrega esse valor em um registrador
imprime o valor e depois para a execução. O código de máquina é escrito em um arquivo de saída no formato binário.
*/
