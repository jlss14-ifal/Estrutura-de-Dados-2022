
#include <stdio.h>
#include <stdlib.h>
#include "FilaClinica.h"

FilaClinica* criarClinica() {

	FilaClinica *clinica = (FilaClinica*) malloc(sizeof(FilaClinica));

	clinica->atendidos = 0;
	clinica->naoAtendidos = 0;
	clinica->primeiro = NULL;

	return clinica;

}

void gerarSenha(FilaClinica *clinica) {

	Fila *auxiliar = adicionarNaFila((clinica->primeiro), ( (clinica->atendidos) + (clinica->naoAtendidos) + 1));

	if ((clinica->primeiro) == NULL)
		clinica->primeiro = auxiliar;

	clinica->naoAtendidos++;

}

Fila* atenderPessoa(FilaClinica *clinica) {

	if ((clinica->primeiro) == NULL)
		return NULL;

	Fila *auxiliar = removerDaFila(&(clinica->primeiro));

	clinica->naoAtendidos--;
	clinica->atendidos++;

	return auxiliar;

}

int visualizarFilaClinica(FilaClinica *clinica) {

	return visualizarFila(clinica->primeiro);

}

