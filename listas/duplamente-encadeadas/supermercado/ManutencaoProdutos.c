
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ManutencaoProdutos.h"
 
ManutencaoProdutos* criarManutencaoProdutos() {
	
	ManutencaoProdutos *manutencaoProdutos = (ManutencaoProdutos*) malloc(sizeof(ManutencaoProdutos));
	manutencaoProdutos->listaInicio = criarLista(); // Aponta para o primeiro item da Lista
	manutencaoProdutos->listaFim = NULL;

	return manutencaoProdutos;

}

int compararProdutosPorCodigo(void* produto1, void* produto2) {
	return ((Produto*)produto1)->codigo == ((Produto*)produto2)->codigo;
}

Lista* acharListaProduto(ManutencaoProdutos* manutencaoProdutos, int codigo, int* quantidadeComparacoes) {

	Produto* produto = (Produto*) malloc(sizeof(Produto));
	produto->codigo = codigo;

	Lista* encontrado = listaProcurarElementoPor(
					manutencaoProdutos->listaInicio, 
					&compararProdutosPorCodigo, 
					((void*)produto),
					quantidadeComparacoes
				);

	free(produto);

	return encontrado;

}

Produto* consultarProduto(ManutencaoProdutos* manutencaoProdutos, int codigo, int* quantidadeComparacoes) {

	Lista* encontrado = acharListaProduto(manutencaoProdutos, codigo, quantidadeComparacoes);

	if (encontrado == NULL)
		return NULL;	

	return ((Produto*) encontrado->elemento);

}

int cadastrarProduto(ManutencaoProdutos* manutencaoProdutos, 
			int codigo, 
			char* descricao, 
			float preco, 
			int quantidade) {

	int quantidadeComparacoes = 0;
	
	Produto* encontrado = consultarProduto(manutencaoProdutos, codigo, &quantidadeComparacoes);

	if (encontrado != NULL)
		return 0;

	Produto* produto = criarProduto(codigo, descricao, preco, quantidade); 

        if ((manutencaoProdutos->listaFim) == NULL) { // Caso nao tenha sido cadastrado nenhum produto
	
		Lista* novo = listaInserirElemento(manutencaoProdutos->listaInicio, produto);
		manutencaoProdutos->listaInicio = novo; // Aponta para inicio, se nao existe outro produto
		manutencaoProdutos->listaFim = novo; // Novo fim
	
	} else
		listaInserirElemento(manutencaoProdutos->listaFim, produto);

	return 1;

}
int existemProdutos(ManutencaoProdutos* manutencaoProdutos) {
	return !listaEstaVazia(manutencaoProdutos->listaInicio);
}

void visualizarProduto(void* produto) {
	produtoVisualizar(((Produto*) produto));
} 

void exibirProdutos(ManutencaoProdutos* manutencaoProdutos) {
	listaVisualizar(manutencaoProdutos->listaInicio, &visualizarProduto);
}

int atualizarProduto(ManutencaoProdutos* manutencaoProdutos, 
			int codigo, 
			char* descricao, 
			float preco, 
			int quantidade) {

	int quantidadeComparacoes = 0;

	Produto* encontrado = consultarProduto(manutencaoProdutos, codigo, &quantidadeComparacoes);

	if (encontrado == NULL)
		return 0;

	encontrado->descricao = descricao;
	encontrado->preco = preco;
	encontrado->quantidade = quantidade;

	return 1;
}

int removerProduto(ManutencaoProdutos* manutencaoProdutos, int codigo) {
	
	Produto* produto = (Produto*) malloc(sizeof(Produto));
	produto->codigo = codigo;

	Lista* encontrado =  listaRemoverElementoPor(
					manutencaoProdutos->listaInicio, 
					&compararProdutosPorCodigo, 
					((void*)produto)
				);

	free(produto);

	if (encontrado == NULL)
		return 0;

	// Caso for o primeiro
	if ((manutencaoProdutos->listaInicio) == encontrado)
		manutencaoProdutos->listaInicio = encontrado->ante;

	// Caso for o ultimo
	if ((manutencaoProdutos->listaFim) == encontrado)
		manutencaoProdutos->listaFim = encontrado->ante;

	liberaProduto( ((Produto*) encontrado->elemento) ); 
	free(encontrado); // Libera Lista
	
	return 1;
}

