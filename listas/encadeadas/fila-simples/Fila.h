
#include <stdio.h>

typedef struct fila {
	int senha;
	struct fila *proximo;
} Fila;

Fila* gerarSenha();

Fila* atenderPessoa(Fila** inicio);

int visualizarFila(Fila* incio);

int retornaNaoAtendidos();

int retornaAtendidos();

Fila* retornaUltimaDaFila();

