
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pilha.h"

int leEntradaNumerica(char *strEntrada, int tamanho, int* opcao) {

	memset(strEntrada, 0, tamanho);	
	scanf("%s", strEntrada);

	return sscanf(strEntrada, "%d", opcao);
		
}

int main()
{

	int opcao;
	Pilha *auxiliar;
	Pilha *inicio = NULL; //= criarPilha(inicio);
	char entrada[1], caractere; // A entrada eh composta de apenas um algarismo

	/* VISUALIZANDO */
			        
	while (1) {
		

		printf("\n|----------------------------------|");
		printf("\n| Escolha o que fazer:             |");
		printf("\n|----------------------------------|");
		printf("\n| 1 - Push;                        |");
		printf("\n| 2 - Pop;                         |");
		printf("\n| 3 - Visualizar Pilha;            |");
		printf("\n| 4 - Top;                         |");
		printf("\n| 5 - Sair.                        |");
		printf("\n|----------------------------------|\n");
	
	// ENTRADA
	
		printf("\nDigite um numero: ");
		leEntradaNumerica(entrada, 1, &opcao);	

	// MENU

		switch (opcao) {
		
			case 1:

				printf("\nDigite um caracter: ");
				scanf(" %c", &caractere);

				if (inicio == NULL)
					inicio = push(inicio, caractere);
				else
					push(inicio, caractere);

			break;

			case 2:

				if (pop(&inicio) == NULL) 
					printf("A Pilha esta vazia!");

			break;

			case 3:

				printf("\nPessoas a serem atendidas: \n");
				if (visualizarPilha(inicio) == 1)
					printf("A Pilha esta vazia!\n");

			break;

			case 4:

				printf("\nTopo da pilha: %c\n", top(inicio));

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
