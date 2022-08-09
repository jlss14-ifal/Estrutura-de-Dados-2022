
#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

Produto* criarProduto(int codigo, char* descricao, float preco, int quantidade) {

	Produto* produto = (Produto*) malloc(sizeof(Produto));
	produto->codigo = codigo;
	produto->descricao = descricao;
	produto->preco = preco;
	produto->quantidade = quantidade;

	return produto;
}

void produtoVisualizar(Produto* produto) {
	printf("\n------------");
	printf("\nCódigo = %i",     produto->codigo);
	printf("\nDescricao = %s",  produto->descricao);
	printf("\nPreço = %.2f",    produto->preco);
	printf("\nQuantidade = %i", produto->quantidade);
	printf("\n------------\n");
}

void liberaProduto(Produto* produto) {
	free(produto->descricao);
	free(produto);
}

