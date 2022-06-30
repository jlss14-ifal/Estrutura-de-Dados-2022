
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fila.h"

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

	int opcao;
	Fila *inicio = NULL, *auxiliar;
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

				if (inicio == NULL) // Se a lista esta vazia
					inicio = gerarSenha();
				else
					gerarSenha();

				auxiliar = retornaUltimaDaFila();
				printf("Nova senha gerada: %i\n", auxiliar->senha);

			break;

			case 2:

				if (atenderPessoa(&inicio) == NULL) 
					printf("A fila esta vazia!");

			break;

			case 3:

				printf("\nPessoas a serem atendidas: \n");
				if (visualizarFila(inicio) == 1)
					printf("A fila esta vazia!\n");

			break;

			case 4:

				printf("\nQuantidade de atendimentos realizados eh %i\n", retornaAtendidos());

			break;

			case 5:

				printf("\nSaindo...\n");
				return 0;

			break;

			default:
				printf("\n\nOpcao invalida: %i \n\n", opcao);
			
		}

	}
	
	return 0;

}

