#include <stdio.h>
//#include "Lista.h"
//#include "Produto.h"

int fazComparacaoProduto(void* elemento1, void* elemento2) {
	return ((Produto*)elemento1)->codigo > ((Produto*)elemento2)->codigo;
}

void fazTroca(Lista* item1, Lista* item2) {
	void* temporario = item1->elemento;
	item1->elemento = item2->elemento;
	item2->elemento = temporario;
}

// Ordenacao bolha (Bubblesort)

int ordenacaoBubble(Lista* inicio, int* quantidade) {
	
	if (inicio == NULL || listaQuantidadeElementos(inicio) < 2)
		return 0;

	Lista* atual = inicio;

	while (atual != NULL && (atual->prox) != NULL) {
		
		if (fazComparacaoProduto(atual->elemento, (atual->prox)->elemento)) {
			fazTroca(atual, atual->prox);
			(*quantidade)++; 
		}

		atual = atual->prox;
	}

	return 1;
}

// Ordenacao rapida (Quicksort)

Lista* fazParticao(Lista *inicio, Lista* fim, int* quantidade) {
	Lista* pivo = fim;
	Lista* anterior = inicio->ante,
		*auxiliar = inicio;

	while (auxiliar != (fim->ante)) 
		if (fazComparacaoProduto(auxiliar->elemento, pivo->elemento)) {
			anterior = anterior->prox;
			fazTroca(anterior->elemento, auxiliar->elemento);
			(*quantidade)++;
		}
	
	if (fazComparacaoProduto((anterior->prox)->elemento, pivo->elemento)) {
		fazTroca((anterior->prox)->elemento, fim->elemento);
		(*quantidade)++;
	}

	return anterior->prox;
}

void execucaoQuick(Lista *pivo, Lista *inicio, Lista *fim, int* quantidade) {

	if (fazComparacaoProduto(fim->elemento, inicio->elemento)) {
		Lista* particao = fazParticao(inicio, fim, quantidade);
		execucaoQuick(pivo, inicio, particao->ante, quantidade);
		execucaoQuick(pivo, particao->prox, fim, quantidade);
	}

}

void ordenacaoQuick(Lista* inicio, Lista* fim, int* quantidade) {

	if (inicio == NULL || listaQuantidadeElementos(inicio) < 2)
		return;

	Lista *pivo = inicio;
	execucaoQuick(pivo, inicio, fim, quantidade);

}

