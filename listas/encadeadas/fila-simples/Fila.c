
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

Fila* retornarUltimoDaFila(Fila *inicio) {
	
	if (inicio == NULL)
		return NULL;

	Fila *atual = inicio;

	while ((atual->proximo) != NULL) // Enquanto auxiliar nao for o ultimo(ou seja, seu proximo igual a NULL)
		atual = atual->proximo;

	return atual;

}

Fila* adicionarNaFila(Fila *inicio, int senha) {
	
	Fila *auxiliar = NULL, *no = (Fila*) malloc(sizeof(Fila));
	no->senha = senha;
	no->proximo = NULL;

	if (inicio != NULL) {
	
		auxiliar = retornarUltimoDaFila(inicio);
		auxiliar->proximo = no;

	}

	return no;

}

// Essa funcao so pode ser acessada por Fila.c pois nao esta em Fila.h
Fila* retornarPenultimoDaFila(Fila *inicio) {
	
	if (inicio == NULL)
		return NULL;

	Fila *anterior = NULL, *atual = inicio;

	while ((atual->proximo) != NULL) { // Enquanto o proximo nao for NULL(ou seja, "atual" eh o ultimo)
		anterior = atual;
		atual = atual->proximo;
	}
	return anterior;

}

Fila* removerDaFila(Fila** inicio) {

	if (inicio == NULL)
		return NULL;

	Fila *penultimo = retornarPenultimoDaFila(*inicio), *removido = *inicio;

	if (penultimo != NULL) {

		removido = penultimo->proximo;
		penultimo->proximo = NULL;
	
	} else
		*inicio = NULL;

	return removido;

}

int visualizarFila(Fila *inicio) {
	
	if (inicio == NULL)
		return 1;

	Fila *auxiliar = inicio;

	while (auxiliar != NULL) {
		printf("\n%d", auxiliar->senha);
		auxiliar = auxiliar->proximo;
	}
	printf("\n");

	return 0;

}

