
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void visualizar(Lista *l) {
	Lista *auxiliar = l;
	        
	while (auxiliar != NULL) {
		printf("%d\n", auxiliar->info);
		auxiliar = auxiliar->prox;
	}
		    
}

int quantidadeElementos(Lista *l) {
	
	int quantidade = 0;
	Lista *auxiliar = l;
		    
	while (auxiliar != NULL) {
		quantidade++;
		auxiliar = auxiliar->prox;
	}
		        
	return quantidade;
			    
}

/*
 * Para procurar, a prioridade eh o indice, se ele for -1 entao procura por valor corespondente
 * */
Lista* procurarElementoEspecifico(Lista *l, int valor, int *indice, Lista **anterior, Lista **atual) {

	int contador = -1, condicao;	
	Lista *auxiliarAnterior = NULL, *auxiliarAtual = l;

	// Encontra item/no por "valor" igual
	while (auxiliarAtual != NULL) {

		contador++;

		condicao = (contador == *indice) // Se o indice corresponde
				|| 
			((*indice == -1) && ((auxiliarAtual->info) == valor)); // Se nao eh para procurar pelo indice mas pelo valor

		if (condicao) {
			*indice = contador;
			*anterior = auxiliarAnterior;
			*atual = auxiliarAtual;
			return auxiliarAtual;
		}

		auxiliarAnterior = auxiliarAtual;
		auxiliarAtual = auxiliarAtual->prox;

	}

	return NULL;

}

Lista* procurarElementoPorValor(Lista *l, int valor) {

	int indice = -1;
	return procurarElementoEspecifico(l, valor, &indice, NULL, NULL);

}

Lista* procurarElementoPorIndice(Lista *l, int indice) {

	int valor = -1;
	return procurarElementoEspecifico(l, valor, &indice, NULL, NULL);

}

Lista* inserirElemento(Lista *l, int valor) {
	
	Lista *no = (Lista*) malloc(sizeof(Lista));
	no->info = valor;
	no->prox = l;
		        
	return no;
			    
}

Lista* inserirElementoPorIndice(Lista **l, int valor, int indice) {

	Lista *auxiliarAnterior = NULL, *auxiliarAtual = *l, *auxiliarNovo;

	auxiliarAtual = procurarElementoEspecifico(*l, -1, &indice, &auxiliarAnterior, &auxiliarAtual);

	if (auxiliarAtual == NULL)
		return NULL;

	auxiliarNovo = inserirElemento(auxiliarAtual->prox, valor);

	auxiliarAtual->prox = auxiliarNovo;

	return auxiliarNovo;

}

Lista* removeElemento(Lista **l, Lista *anterior, Lista *atual) {

	// Se nao ha itens
	if (atual == NULL)
		return NULL;

	// Se for o ultimo adicionado(esta topo da lista)
	if (anterior == NULL) {
		*l = atual->prox;
		return atual;
	} else 
		anterior->prox = atual->prox;

	return atual;

}

Lista* removeElementoPorValor(Lista **l, int valor) {

	Lista *auxiliarAnterior = NULL, *auxiliarAtual = *l;

	int indice = -1;

	procurarElementoEspecifico(*l, valor, &indice, &auxiliarAnterior, &auxiliarAtual);

	return removeElemento(l, auxiliarAnterior, auxiliarAtual);

}

Lista* removeElementoPorIndice(Lista **l, int indice) {

	Lista *auxiliarAnterior = NULL, *auxiliarAtual = *l;

	procurarElementoEspecifico(*l, -1, &indice, &auxiliarAnterior, &auxiliarAtual);

	return removeElemento(l, auxiliarAnterior, auxiliarAtual);

}
