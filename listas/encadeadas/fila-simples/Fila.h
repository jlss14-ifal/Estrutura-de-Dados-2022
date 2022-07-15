
#include <stdio.h>

typedef struct fila {
	int senha;
	struct fila *proximo;
} Fila;

Fila* adicionarNaFila(Fila *inicio, int senha);

Fila* removerDaFila(Fila** inicio);

int visualizarFila(Fila* inicio);

Fila* retornarUltimoDaFila(Fila *inicio);

