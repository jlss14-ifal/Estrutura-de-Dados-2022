
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pilha.h"

int ehUmNumeroOuLetra(char c) {
	return (isalpha(c) || isdigit(c));
}

int ehUmOperador(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int retornaPrecedencia(char c) {
	if (c == '+' || c == '-')
	       return 1;
	if (c == '*' || c == '/')
		return 2;
	if (c == '^')
		return 3;
	return 0;
}

void novaExpressao(int *i, int *posicaoSaida, char *array, char *saida) {

	int j = *i;
	Pilha *operadores = criarPilha();

	if (ehUmOperador(array[j]))
		saida[(*posicaoSaida)++] = array[j++];

	while (array[j] != ')') {

		if (ehUmNumeroOuLetra(array[j]))
			saida[(*posicaoSaida)++] = array[j];

 		else if (ehUmOperador(array[j])) {
			
			if (estaVazia(operadores) != 1) // Se a pilha nao estiver vazia
				if (retornaPrecedencia(array[j]) <= retornaPrecedencia(top(operadores)->conteudo)) // Se procedencia: do atual <= topo da pilha
					saida[(*posicaoSaida)++] = pop(&operadores); // desenpilha a do topo
			
			push(&operadores, array[j]);

		}
		else if (array[j] == '(') { // Se encontrar uma expessao dentro de outra entre parenteses
			
			*i = ++j;
			novaExpressao(i, posicaoSaida, array, saida);
			j = (*i);
			
			// Esvazia operadores, se ouverem
			while (estaVazia(operadores) != 1)
				saida[(*posicaoSaida)++] = pop(&operadores);

		}

		j++;	
	}
	
	// Esvazia operadores, se ouverem
	while (estaVazia(operadores) != 1)
		saida[(*posicaoSaida)++] = pop(&operadores);

	*i = j;

}

char* infixaParaPosfixa(char *array) {

	int i, posicaoSaida = 0, tamanho = (int) strlen(array);

	char *saida = (char*) malloc(sizeof(char) * tamanho);

	for (i = 0; tamanho > i; i++) {
		
		if (array[i] == '(')
			continue;
		else if (ehUmNumeroOuLetra(array[i]))
			novaExpressao(&i, &posicaoSaida, array, saida);
		else
			printf("\nEh um caracter estranho: \"%c\"!\n", array[i]);
	
	}

	return saida;
}

void fazTeste(char *array, char *resultadoCorreto) {
	
	char *saida = infixaParaPosfixa(array);

	printf("\nEntrada  = [%s]", array);
	printf("\nSaida    = [%s]\n", saida);
	printf(  "Resposta = [%s]\n", resultadoCorreto);

	if (strncmp(saida, resultadoCorreto, strlen(resultadoCorreto)) == 0) 
		printf("\nSao iguais.\n");
	else 
		printf("\nNao sao iguais.\n");

}

int main()
{

	char array1[] = {'(', 'A', '+', 'B', '*', 'C', ')', '\0'}, 
	     resultadoCorreto1[] = "ABC*+\0";
	
	char array2[] = {'(', 'A', '*', '(', 'B', '+', 'C', ')', '/', 'D', '-', 'E', ')', '\0'}, 
	     resultadoCorreto2[] = "ABC+*D/E-\0";
	
	char array3[] = {'(', 'A', '+', 'B', '*', '(', 'C', '-', 'D', '*', '(', 'E', '-', 'F', ')', '-', 'G', '*', 'H', ')', '-', 'I', '*', 'J', ')', '\0'}, 
	     resultadoCorreto3[] = "ABCDEF-*-GH*-*+IJ*-\0";

	char array4[] = {'(', 'A', '+', 'B', '*', 'C', '/', '(', 'D', '-' ,'E', ')', ')', '\0'},
	     resultadoCorreto4[] = "ABC*DE-/+\0";

	fazTeste(array1, resultadoCorreto1);
	fazTeste(array2, resultadoCorreto2);
	fazTeste(array3, resultadoCorreto3);
	fazTeste(array4, resultadoCorreto4);

	return 0;

}
