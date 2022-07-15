
#include <stdio.h>
#include "Fila.h"

typedef struct filaClinica {

	int atendidos;
	int naoAtendidos;
	Fila *primeiro;

} FilaClinica;

FilaClinica* criarClinica();

void gerarSenha(FilaClinica *clinica);

Fila* atenderPessoa(FilaClinica *clinica);

int visualizarFilaClinica(FilaClinica *clinica);

