#include <stdio.h>
#include <stdlib.h>

extern int get_token(FILE *f, char*);

int parse(FILE *f) {
    char buffer[32];
    int token; 

    token = get_token(f, buffer);
    if (token != 1 ) return -1;
    int left = atoi(buffer);

    token = get_token(f, buffer);
    if (token != 2) return -1;

    token = get_token(f, buffer);
    if (token != 1) return -1;
    int right = atoi(buffer);

    return left + right;
}
/*Este código é responsável por analisar uma expressão simples de adição. 
Ele lê um número, seguido por um operador de adição, e depois outro número. Se a estrutura da expressão for correta, ele retorna a soma dos dois números. 
Caso contrário, ele retorna -1 para indicar um erro de análise. 
Esta função depende da função get_token para obter os tokens do arquivo, e utiliza a função ''atoi'' para converter as strings numéricas em inteiros.*/