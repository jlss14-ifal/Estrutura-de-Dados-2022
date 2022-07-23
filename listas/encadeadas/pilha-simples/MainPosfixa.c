
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pilha.h"

typedef struct posfixa {
	Pilha *p;
}Posfixa;

char* pilhaParaChar(Pilha **p) {

	int i = 0, quantidade = quantidadeDeConteudo(*p);

	char* saida = (char*) malloc(sizeof(char) * quantidadeDeConteudo(*p));

	for (i = 0; quantidade > i; i++)
		saida[i] = pop(p)->x;

	return saida;

}

int charPonteiroLen(char* ponteiro) {

	  // calculate size in bytes
  	int arraySize = sizeof(ponteiro);
  	int intSize = sizeof(ponteiro[0]);

  	// length
  	int length = arraySize / intSize;

	return length;

}

void pushTudo(Posfixa *pos, char *parte) {

	int i;

	int tamanhoParte = charPonteiroLen(parte)-1;

	for (i = 0; tamanhoParte > i; i++) {
		if (pos->p == NULL)
			pos->p = push(pos->p, parte[i]);
		else
			push(pos->p, parte[i]);
	}

	printf("\nEstado da pilha = %i\n", visualizarPilha(pos->p));

}

int ehLetra(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char* transformacaoPosfixa(char* infixa, int **i, int max) {

	Posfixa *pos;
	pos->p = NULL;
	int j = (int) *i;

	printf("ok");

	for (;max > j; j++) {
		
		if (infixa[j] == '(') { // Inicio da recursividade

			j++;
			*i = j;
	printf("ok");
			char* array = transformacaoPosfixa(infixa, i, max);
	printf("ok");
			j = (int) *i;
			pushTudo(pos, array);

		} else if (infixa[j] == ')') { // Fim da recursividade

			*i = j;

			return pilhaParaChar(&pos->p);

		} else if (ehLetra(infixa[j])) {

			*i = j;

			if (pos->p == NULL)
				pos->p = push((pos->p), infixa[j]);
			else
				push((pos->p), infixa[j]);

		}

		printf("j = %i && max = %i\n", j, max);

	}
	
	return pilhaParaChar(&pos->p);

}

int main()
{

	char array[] = {'(', 'A', '+', 'B', '*', 'C', ')'};
	int *i = 0;

	printf("\nTransformacao = %s\n", transformacaoPosfixa(array, &i,  8 ));

	return 0;

}
