
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista* criarLista() {

	Lista* inicio = (Lista*) malloc(sizeof(Lista));
	inicio->elemento = NULL;
	inicio->ante = NULL;
	inicio->prox = NULL;

	return inicio;

}

int listaEstaVazia(Lista* inicio) {

	if (inicio == NULL)
		return 1;

	if ((inicio->elemento) == NULL && (inicio->ante) == NULL && (inicio->prox) == NULL)
		return 1;

	return 0;
}

int listaQuantidadeElementos(Lista *inicio) {
	
	if (listaEstaVazia(inicio))
		return 0;

	int quantidade = 0;

	Lista *auxiliar = inicio;
		    
	while (auxiliar != NULL && (auxiliar->elemento) != NULL) {
		quantidade++;
		auxiliar = auxiliar->prox;
	}
		        
	return quantidade;
			    
}

void listaVisualizar(Lista *inicio, 
		void visualizar(void* elemento1)) {

	if (listaEstaVazia(inicio))
		return;

	Lista *auxiliar = inicio;

	while (auxiliar != NULL && (auxiliar->elemento) != NULL) {
		printf("\n");
		visualizar(auxiliar->elemento);
		auxiliar = auxiliar->prox;
	}
 
}

Lista* listaProcurarElementoPor(Lista *inicio, 
				int condicao(void* elemento1, void* elemento2), 
				void* procurado, 
				int* quantidadeComparacoes) {

	if (listaEstaVazia(inicio))
		return NULL;

	if (procurado == NULL || condicao == NULL) {
		(*quantidadeComparacoes) = 0;
		return NULL;
	}

	int quantidade = 0;

	Lista *auxiliar = inicio;
		    
	while (auxiliar != NULL && (auxiliar->elemento) != NULL) {
		
		quantidade++;
		
		if (condicao(auxiliar->elemento, procurado)) {
			(*quantidadeComparacoes) = quantidade;
			return auxiliar;
		}
		
		auxiliar = auxiliar->prox;
	
	}
	
	(*quantidadeComparacoes) = quantidade;
	
	return NULL;

}

Lista* listaInserirElemento(Lista *inicio, void* elemento) {

	if (inicio == NULL)
		return NULL;

	Lista *no = (Lista*) malloc(sizeof(Lista)), *auxiliar = inicio;
	no->elemento = elemento;
	no->prox = NULL;

	while ((auxiliar->prox) != NULL)
		auxiliar = auxiliar->prox;

	no->ante = auxiliar; // Aponta para novo penultimo
	auxiliar->prox = no; // Aponta para ultimo

	return no;
			    
}

Lista* listaRemoverElementoPor(Lista *inicio, 
				int condicao(void* elemento1, void* elemento2), 
				Lista *atual) {

	int quantidadeComparacoes = 0;
	
	Lista *encontrado = listaProcurarElementoPor(inicio, condicao, atual, &quantidadeComparacoes);

	if (encontrado == NULL)
		return NULL;

	Lista *anterior = encontrado->ante; // Elemento anterior do que sera removido
	anterior->prox = encontrado->prox; // Reaponta proximo do anterior para proximo do removido

	return encontrado;

}

