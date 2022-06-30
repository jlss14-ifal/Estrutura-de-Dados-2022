
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include <string.h>
#include <ctype.h>

int arrayIsDigit(char *array, int *saida) {
	
	int i;
	const int len = strlen(array);

	for (i = 0; i < len; i++)
		if (!isdigit(array[i])) 
			return 1;

	if (sscanf(array, "%i", saida) == EOF) // Se a conversao da entrada esta incorreta
		return 1;

	return 0;

}

void leEntradaNumerica(char *strEntrada, int tamanho, int *saida) { // Alternativa melhor ao scanf

	do {

		memset(strEntrada, 0, sizeof(strEntrada)); // Inicia todas as posicoes com 0
		fgets(strEntrada, (tamanho + 2), stdin); // Soma 2 contado o \n
		strEntrada[strcspn(strEntrada, "\n")] = '\0'; // Troca todos os \n por \0

	} while (arrayIsDigit(strEntrada, saida) != 0); // Caso o que tenha sido digitado nao seja um digito

}

int main()
{

	int indice, valor, opcao;
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
		printf("\nObs: Limite de caracteres a serem digitados.");
		printf("\n");

	// ENTRADA
	
		printf("\nDigite um numero: ");
		
		leEntradaNumerica(strEntrada, 1, &opcao);
		
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
				leEntradaNumerica(strEntrada, 1, &valor);

				auxiliar = procurarElementoPorValor(l, valor);
 
				if (auxiliar == NULL)
					printf("\nValor nao encontrado.\n");
				else
					printf("\nValor encontrado\n");

			break;

			case 3: // Procurar por indice

				printf("\nDigite o indice para procurar na lista: ");
				leEntradaNumerica(strEntrada, 1, &indice);

				auxiliar = procurarElementoPorIndice(l, indice);
	
				if (auxiliar == NULL)
					printf("\nValor nao encontrado.\n");
				else
					printf("\nValor encontrado\n");

			break;

			case 4: // Inserir em posicao especifica

				printf("\nDigite o indice para inserir: ");
				leEntradaNumerica(strEntrada, 1, &indice);

				printf("\nDigite o novo valor para inserir na lista: ");
				leEntradaNumerica(strEntrada, 1, &valor);
		
				auxiliar = inserirElementoPorIndice(&l, valor, indice);

				if (auxiliar == NULL)
					printf("\nIndice invalido!\n");
	
			break;

			case 5: // Inserir no inicio

				printf("\nDigite o novo valor para inserir na lista: ");
				leEntradaNumerica(strEntrada, 1, &valor);
	
				auxiliar = inserirElementoPorIndice(&l, valor, (quantidadeElementos(l)-1));

			break;

			case 6: // Inserir no fim

				printf("\nDigite o novo valor para inserir na lista: ");
				leEntradaNumerica(strEntrada, 1, &valor);
	
				l = inserirElemento(l, valor);

			break;

			case 7: // Remover por indice

				printf("\nDigite o indice para remover: ");
				leEntradaNumerica(strEntrada, 1, &indice);

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
				return 0;
			
			break;

			default: // Padrao
				printf("\n\nOpcao invalida: %i \n\n", opcao);
			
		}

	}

	return 0;

}

