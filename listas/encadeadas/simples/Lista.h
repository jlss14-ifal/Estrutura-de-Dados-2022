
#include <stdio.h>

typedef struct lista {
	int info;
	struct lista *prox;
} Lista;

void visualizar(Lista *l);

int quantidadeElementos(Lista *l);

Lista* procurarElementoEspecifico(Lista *l, int valor, int *indice, Lista **anterior, Lista **atual);

Lista* procurarElementoPorValor(Lista *l, int valor);

Lista* procurarElementoPorIndice(Lista *l, int indice);

Lista* inserirElemento(Lista *l, int valor);

Lista* inserirElementoPorIndice(Lista **l, int indice, int valor);

Lista* removeElemento(Lista **l, Lista *anterior, Lista *atual);

Lista* removeElementoPorValor(Lista **l, int valor);

Lista* removeElementoPorIndice(Lista **l, int indice);


