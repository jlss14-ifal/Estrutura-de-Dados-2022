
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

Pilha* criarPilha() {

	Pilha *inicio = (Pilha*) malloc(sizeof(Pilha));
	inicio->conteudo = '\0';
	inicio->proximo = NULL;

	return inicio;

}


Pilha* top(Pilha *atual) { // Exibe o topo da pilha, ou seja, o ultimo
	
	if (atual == NULL)
		return NULL;

	return atual;

}

Pilha* push(Pilha **atual, char conteudo) { // Adicionar na pilha
	
	Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
	novo->conteudo = conteudo;
	novo->proximo = NULL;

	if (atual != NULL)
		novo->proximo = *atual;

	*atual = novo;

	return novo;

}

char pop(Pilha** atual) { // Remove da pilha

	if (atual == NULL)
		return '\0';

	Pilha *penultimo = (*atual)->proximo, *removido = *atual;

	*atual = (*atual)->proximo;

	char conteudo = removido->conteudo;
	
	free(removido);

	return conteudo;

}

int estaVazia(Pilha *atual) { // Retorna 1 se a pilha esta vazia e 0, caso contrario

	if (atual == NULL || atual->conteudo == '\0')
		return 1;

	return 0;

}

int visualizarPilha(Pilha* atual) {

	if (atual == NULL)
		return 1;

	Pilha *auxiliar = atual;

	printf("\n---INICIO---");
	while (estaVazia(auxiliar) != 1) {
		printf("\n[%c]", auxiliar->conteudo);
		auxiliar = auxiliar->proximo;
	}
	printf("\n---FIM------");

	return 0;

}

int tamanhoPilha(Pilha* atual) {

	int tamanho = 0;

	Pilha *auxiliar = atual;

	while (estaVazia(auxiliar) != 1) {
		tamanho++;
		auxiliar = auxiliar->proximo;
	}

	return tamanho;

}

