
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

static int naoAtendidos = 0, atendidos = 0;
static Fila* ultimaDaFila = NULL;


int retornaNaoAtendidos() {
	return naoAtendidos;
}

int retornaAtendidos() {
	return atendidos;
}

Fila* retornaUltimaDaFila() {
	return ultimaDaFila;
}

Fila* gerarSenha() {
	
	Fila *no = (Fila*) malloc(sizeof(Fila));
	no->senha = naoAtendidos + atendidos + 1;
	no->proximo = NULL;
	
	if (ultimaDaFila != NULL)
		if (ultimaDaFila->senha > atendidos) // Se o ultimo ja foi antendido
			ultimaDaFila->proximo = no;

	ultimaDaFila = no;

	naoAtendidos++;

	return no;
	
}

Fila* atenderPessoa(Fila** inicio) {

	if (naoAtendidos == 0)
		return NULL;

	naoAtendidos--;
	atendidos++;

	*inicio = (*inicio)->proximo;

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

