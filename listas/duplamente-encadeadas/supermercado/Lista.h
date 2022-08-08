
#include <stdio.h>

typedef struct lista {
	void* elemento;
	struct lista *ante;
	struct lista *prox;
} Lista;

Lista* criarLista();

int listaEstaVazia(Lista* inicio);

int listaQuantidadeElementos(Lista *inicio);

void listaVisualizar(Lista *inicio, void visualizar(void* elemento));

Lista* listaProcurarElementoPor(Lista *inicio, 
				int condicao(void* elemento1, void* elemento2), 
				void* procurado, 
				int *quantidadeComparacoes);

Lista* listaInserirElemento(Lista *inicio, void* elemento);

Lista* listaRemoverElementoPor(Lista *inicio, 
				int condicao(void* elemento1, void* elemento2),
				Lista *atual);

