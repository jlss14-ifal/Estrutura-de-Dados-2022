
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FilaClinica.h"

int leEntradaNumerica(char *strEntrada, int tamanho, int* opcao) {

	memset(strEntrada, 0, tamanho);	
	scanf("%s", strEntrada);

	return sscanf(strEntrada, "%d", opcao);
		
}

int main()
{

	int opcao;
	Fila *auxiliar;
	FilaClinica *clinica = criarClinica();
	char entrada[1]; // A entrada eh composta de apenas um algarismo

	/* VISUALIZANDO */
			        
	while (1) {
		

		printf("\n|----------------------------------|");
		printf("\n| Escolha o que fazer:             |");
		printf("\n|----------------------------------|");
		printf("\n| 1 - Gerar senha;                 |");
		printf("\n| 2 - Atender pessoa;              |");
		printf("\n| 3 - Visualizar fila;             |");
		printf("\n| 4 - Numero de pessoas antendidas;|");
		printf("\n| 5 - Sair.                        |");
		printf("\n|----------------------------------|\n");
	
	// ENTRADA
	
		printf("\nDigite um numero: ");
		leEntradaNumerica(entrada, 1, &opcao);	

	// MENU

		switch (opcao) {
		
			case 1:

				gerarSenha(clinica);

				auxiliar = retornarUltimoDaFila(clinica->primeiro);

				if (auxiliar != NULL) printf("Nova senha gerada: %i\n", auxiliar->senha);

			break;

			case 2:

				if (atenderPessoa(clinica) == NULL) 
					printf("A fila esta vazia!");

			break;

			case 3:

				printf("\nPessoas a serem atendidas: \n");
				if (visualizarFilaClinica(clinica) == 1)
					printf("A fila esta vazia!\n");

			break;

			case 4:

				printf("\nQuantidade de atendimentos realizados eh %i\n", (clinica->atendidos));

			break;

			case 5:

				printf("\nSaindo...\n");
				exit(0);

			break;

			default:
				printf("\n\nOpcao invalida: %i \n\n", opcao);
			
		}

	}
	
	return 0;

}

