
#include <stdio.h>

typedef struct pilha {
	char conteudo;
	struct pilha *proximo;
} Pilha;

Pilha* criarPilha(Pilha *p);

Pilha* push(Pilha **atual, char conteudo); // Adicionar na pilha

char pop(Pilha** atual); // Remove da pilha

int estaVazia(Pilha *p); // Retorna 1 se a pilha esta vazia e 0, caso contrario

int visualizarPilha(Pilha* atual);

Pilha* top(Pilha *atual); // Exibe o topo da pilha, ou seja, o ultimo adicionado

