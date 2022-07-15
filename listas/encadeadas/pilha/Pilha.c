
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

Pilha* criarPilha(Pilha *p) {

	return NULL;

}


Pilha* top(Pilha *inicio) { // Exibe o topo da pilha, ou seja, o ultimo
	
	if (inicio == NULL)
		return NULL;

	Pilha *atual = inicio;

	while ((atual->proximo) != NULL) // Enquanto auxiliar nao for o ultimo(ou seja, seu proximo igual a NULL)
		atual = atual->proximo;

	return atual;

}

Pilha* push(Pilha *inicio, char x) { // Adicionar na pilha
	
	Pilha *auxiliar = NULL, *no = (Pilha*) malloc(sizeof(Pilha));
	no->x = x;
	no->proximo = NULL;

	if (inicio != NULL) {
	
		auxiliar = top(inicio);
		auxiliar->proximo = no;

	}

	return no;

}

// Essa funcao so pode ser acessada por Pilha.c pois nao esta em Pilha.h
Pilha* secondTop(Pilha *inicio) {
	
	if (inicio == NULL)
		return NULL;

	Pilha *anterior = NULL, *atual = inicio;

	while ((atual->proximo) != NULL) { // Enquanto o proximo nao for NULL(ou seja, "atual" eh o ultimo)
		anterior = atual;
		atual = atual->proximo;
	}
	return anterior;

}

Pilha* pop(Pilha** inicio) { // Remove da pilha

	if (inicio == NULL)
		return NULL;

	Pilha *penultimo = secondTop(*inicio), *removido = *inicio;

	if (penultimo != NULL) {

		removido = penultimo->proximo;
		penultimo->proximo = NULL;
	
	} else
		*inicio = NULL;

	return removido;

}

int estaVazia(Pilha *p) { // Retorna 1 se a pilha esta vazia e 0, caso contrario

	if (p->proximo)
		return 0;

	return 1;

}

int visualizarPilha(Pilha* inicio) {

	if (inicio == NULL)
		return 1;

	Pilha *auxiliar = inicio;

	while (auxiliar != NULL) {
		printf("\n%d", auxiliar->senha);
		auxiliar = auxiliar->proximo;
	}
	printf("\n");

	return 0;

}



