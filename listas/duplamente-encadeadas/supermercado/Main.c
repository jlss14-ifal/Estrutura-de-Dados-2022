
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ManutencaoProdutos.h"
#include "ListaOrdenacao.c"

int leEntrada(char* strEntrada, int tamanho, const char* tipoEntrada, void* saida) {

	memset(strEntrada, '\0', tamanho);

	scanf("%s", strEntrada);

	return sscanf(strEntrada, tipoEntrada, saida);

}

void perguntaDadosProduto(char* temporario, int* codigo, char* descricao, float* preco, int* quantidade, int ignorarCodigo) {
	
	if (!ignorarCodigo) {

		printf("\nDigite o código:\n");
		leEntrada(temporario, 50, "%d", codigo);

	}

	memset(descricao, '\0', 50);
	printf("\nDigite a descrição:\n");
	leEntrada(temporario, 50, "%s", descricao);

	printf("\nDigite o preço:\n");
	leEntrada(temporario, 50, "%f", preco);

	printf("\nDigite a quantidade:\n");
	leEntrada(temporario, 50, "%d", quantidade);

}

void main() {

	int opcao = 0, codigo = 0, quantidade = 0, quantidadeComparacoes = 0, quantidadeTrocas = 0;
	float preco = 0.0;
	char *temporario = (char*) malloc(sizeof(char) * 50), 
	     *descricao = (char*) malloc(sizeof(char) * 50);
	ManutencaoProdutos* manutencaoProdutos = criarManutencaoProdutos();

	while (1) {
	
		printf("\n--------------Escolha----------------");
		printf("\n|1 – Cadastrar produto;             |");
		printf("\n|2 – Exibir produtos por código;    |");
		printf("\n|3 – Consultar produto;             |");
		printf("\n|4 – Atualizar dados de um produto; |");
		printf("\n|5 – Sair.                          |");
		printf("\n-------------------------------------\n");

		printf("\nOpcao: ");
		leEntrada(temporario, 50, "%d", &opcao);
		printf("\n");

		switch (opcao) {
		
			case 1:
				
				printf("\n---Novo Produto---\n");	

				printf("\nDigite o código:\n");
				leEntrada(temporario, 50, "%d", &codigo);

				if (consultarProduto(manutencaoProdutos, codigo, &quantidadeComparacoes) != NULL) {
					printf("\n-------------------------------");
					printf("\n|Código já cadastrado!        |");
					printf("\n-------------------------------\n");
					quantidadeComparacoes = 0;
					continue;
				}			
				
				perguntaDadosProduto(temporario, &codigo, descricao, &preco, &quantidade, 1);

				if (cadastrarProduto(manutencaoProdutos, codigo, descricao, preco, quantidade)) {
					printf("\n---------------------");
					printf("\n|Produto cadastrado!|");
					printf("\n---------------------\n");
				} else {
					printf("\n-------------------------------");
					printf("\n|Produto/código já cadastrado!|");
					printf("\n-------------------------------\n");
				}
			break;

			case 2:

				if (!existemProdutos(manutencaoProdutos)) {
					printf("\n---------------------");
					printf("\n|A lista está vazia!|");
					printf("\n---------------------\n");
					continue;
				}

				printf("\nOrdenar com:\n	1 - Bolha(Bubble sort);\n	2 - Rápida(Quick sort).\n\nResposta: ");
				leEntrada(temporario, 50, "%d", &opcao);

				printf("\nProdutos cadastrados:\n");

				if (opcao)
					ordenacaoBubble((manutencaoProdutos->listaInicio), &quantidadeTrocas);
				else
					ordenacaoQuick((manutencaoProdutos->listaInicio), (manutencaoProdutos->listaFim), &quantidadeTrocas);
	
				exibirProdutos(manutencaoProdutos);

				printf("\n------------------------------");
				printf("\n|Número de trocas feitas: %i.|", quantidadeTrocas);
				printf("\n------------------------------\n");

				quantidadeTrocas = 0;

			break;

			case 3:

				if (!existemProdutos(manutencaoProdutos)) {
					printf("\n---------------------");
					printf("\n|A lista está vazia!|");
					printf("\n---------------------\n");
					continue;
				}
			
				printf("\nDigite o código do produto:\n");
				leEntrada(temporario, 50, "%d", &codigo);

				if (consultarProduto(manutencaoProdutos, codigo, &quantidadeComparacoes) != NULL)
					printf("Produto encontrado.\nForam feitas %i comparações.\n", quantidadeComparacoes);
				else
					printf("Produto não encontrado!\nForam feitas %i comparações.\n", quantidadeComparacoes);

				quantidadeComparacoes = 0;

			break;

			case 4:

				if (!existemProdutos(manutencaoProdutos)) {
					printf("\n---------------------");
					printf("\n|A lista está vazia!|");
					printf("\n---------------------\n");
					continue;
				}

				printf("\n---Atualizar Produto---\n");


				printf("\nDigite o código:\n");
				leEntrada(temporario, 50, "%d", &codigo);

				if (consultarProduto(manutencaoProdutos, codigo, &quantidadeComparacoes) == NULL) {
					printf("\n-------------------------------");
					printf("\n|Código incorreto/inexistente!|");
					printf("\n-------------------------------\n");
					quantidadeComparacoes = 0;
					continue;
				}

				perguntaDadosProduto(temporario, &codigo, descricao, &preco, &quantidade, 1);
				
				if (atualizarProduto(manutencaoProdutos, codigo, descricao, preco, quantidade)) {
					printf("\n---------------------");
					printf("\n|Produto atualizado!|");
					printf("\n---------------------\n");
				} else {
					printf("\n------------------------------------------");
					printf("\n|Produto não atualizado!                 |");
					printf("\n|Verifique sua entrada e tente novamente.|");
					printf("\n------------------------------------------\n");
				}
			
			break;

			case 5:
				printf("\n-----------");
				printf("\n|Saindo...|");
				printf("\n-----------\n");
				return;

			default:
				printf("\n-------------------------");
				printf("\n|Opção inválida: \"%i\".|", opcao);
				printf("\n-------------------------\n");

		}

		scanf("%*[^\n]"); // Limpa buffer de entrada

	}

}

