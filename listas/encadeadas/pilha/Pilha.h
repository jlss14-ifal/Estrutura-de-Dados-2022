
#include <stdio.h>

typedef struct pilha {
	char x;
	struct pilha *proximo;
} Pilha;

Pilha* criarPilha(Pilha *p);

Pilha* push(Pilha *inicio, char x); // Adicionar na pilha

Pilha* pop(Pilha** inicio); // Remove da pilha

int estaVazia(Pilha *p); // Retorna 1 se a pilha esta vazia e 0, caso contrario

int visualizarPilha(Pilha* inicio);

Pilha* top(Pilha *inicio); // Exibe o topo da pilha, ou seja, o ultimo

