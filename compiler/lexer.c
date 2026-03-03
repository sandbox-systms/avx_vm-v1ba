#include <stdio.h>
#include <ctype.h>

int get_token(FILE *f, char *buffer) {
    int c = fgetc(f);
    if (c == EOF) {
        return 0; 
    }

    if (isdigit(c)) {
        int i = 0;
        while (isdigit(c)) {
            buffer[i++] = c;
            c = fgetc(f);
        } 
        buffer[i] = '\0';
        ungetc(c, f);
        return 1;
    }
    if (c == '+' ){
        buffer[0] = '+';
        buffer[1] = '\0';
        return 2;
    }
    return 0; 
}
/*
Este bloco de código é responsável por ler um token de um arquivo. 
Ele verifica se o próximo caractere é um dígito ou um operador de adição e armazena o token em um buffer.
O código retorna 1 para números, 2 para o operador de adição e 0 para outros casos, incluindo o fim do arquivo. 
Isto é uma função simples de análise léxica que pode ser usada para interpretar expressões matemáticas básicas.
*/
