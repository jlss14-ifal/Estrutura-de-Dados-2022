
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Lista.h"

int leEntradaNumerica(char *strEntrada, int tamanho, int* opcao) {

	memset(strEntrada, 0, tamanho);	
	scanf("%s", strEntrada);

	return sscanf(strEntrada, "%d", opcao);
		
}

int main()
{

	int indice =-1 , valor = -1, opcao = -1;
	Lista *l = NULL, *auxiliar;
	char strEntrada[10];

	l = inserirElemento(l, 10);
	l = inserirElemento(l, 11);
	l = inserirElemento(l, 12);
			        
	/* VISUALIZANDO */
			        
	while (1) {
		
		printf("\n|Escolha o que fazer:                   |");
		printf("\n|---------------------------------------|");
		printf("\n| 0 - visualizar lista;                 |");
		printf("\n| 1 - exibir quantidade de elementos;   |");
		printf("\n| 2 - procurar por valor;               |");
		printf("\n| 3 - procurar por indice;              |");
		printf("\n| 4 - inserir em uma posicao especifica;|");
		printf("\n| 5 - inserir do inicio;                |");
		printf("\n| 6 - inserir do final;                 |");
		printf("\n| 7 - remover em uma posicao especifica;|");
		printf("\n| 8 - remover do inicio;                |");
		printf("\n| 9 - remover do fim.                   |");
		printf("\n| 10 - finalizar.                       |");
		printf("\n");

	// ENTRADA

		printf("\nDigite um numero: ");
		leEntradaNumerica(strEntrada, 10, &opcao);

	// MENU

		switch (opcao) {
		
			case 0: // Visualizar

				printf("\n");
				visualizar(l);

			break;

			case 1: // Quantidade de elementos

				printf("\nQuantidade de elementos: %i\n", quantidadeElementos(l));
			
			break;

			case 2: // Procurar por valor

				printf("\nDigite o valor para procurar na lista: ");
				leEntradaNumerica(strEntrada, 10, &valor);

				auxiliar = procurarElementoPorValor(l, valor);

				if (auxiliar == NULL)
					printf("\nValor nao encontrado.\n");
				else
					printf("\nValor encontrado\n");

			break;

			case 3: // Procurar por indice

				printf("\nDigite o indice para procurar na lista: ");
				leEntradaNumerica(strEntrada, 10, &indice);

				auxiliar = procurarElementoPorIndice(l, indice);
	
				if (auxiliar == NULL)
					printf("\nValor nao encontrado.\n");
				else
					printf("\nValor encontrado\n");

			break;

			case 4: // Inserir em posicao especifica

				printf("\nDigite o indice para inserir: ");
				leEntradaNumerica(strEntrada, 10, &indice);

				printf("\nDigite o novo valor para inserir na lista: ");
				leEntradaNumerica(strEntrada, 10, &valor);
		
				auxiliar = inserirElementoPorIndice(&l, valor, indice);

				if (auxiliar == NULL)
					printf("\nIndice invalido!\n");
	
			break;

			case 5: // Inserir no inicio

				printf("\nDigite o novo valor para inserir na lista: ");
				leEntradaNumerica(strEntrada, 10, &valor);
				
				auxiliar = inserirElementoPorIndice(&l, valor, (quantidadeElementos(l)-1));

			break;

			case 6: // Inserir no fim

				printf("\nDigite o novo valor para inserir na lista: ");
				leEntradaNumerica(strEntrada, 10, &valor);
				
				l = inserirElemento(l, valor);

			break;

			case 7: // Remover por indice

				printf("\nDigite o indice para remover: ");
				leEntradaNumerica(strEntrada, 10, &indice);

				auxiliar = removeElementoPorIndice(&l, indice);
		
				if (auxiliar == NULL)
					printf("\nIndice invalido!\n");

			break;

			case 8: // Remover do inicio

				auxiliar = removeElementoPorIndice(&l, (quantidadeElementos(l)-1));
			
				if (auxiliar == NULL)
					printf("i\nA lista esta vazia!\n");

			break;

			case 9: // Remover do fim
	
				auxiliar = removeElementoPorIndice(&l, 0);
	
				if (auxiliar == NULL)
					printf("\nA lista esta vazia!\n");
			
			break;

			case 10: // Sair

				printf("\nSaindo...\n");
				exit(0);
			
			break;

			default: // Padrao
				printf("\n\nOpcao invalida: %i \n\n", opcao);
			
		}

		scanf("%*[^\n]"); // Limpa buffer de entrada

	}

	return 0;

}

