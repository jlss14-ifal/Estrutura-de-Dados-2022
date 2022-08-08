
#include <stdio.h>
#include "Produto.h"
#include "Lista.h"

typedef struct {
	Lista *listaInicio;
	Lista *listaFim;
} ManutencaoProdutos;


ManutencaoProdutos* criarManutencaoProdutos();

int cadastrarProduto(ManutencaoProdutos* manutencaoProdutos, int codigo, char* descricao, float preco, int quantidade);

Produto* consultarProduto(ManutencaoProdutos* manutencaoProdutos, int codigo, int* quantidadeComparacoes);

int existemProdutos(ManutencaoProdutos* manutencaoProdutos);

void exibirProdutos(ManutencaoProdutos* manutencaoProdutos);

int atualizarProduto(ManutencaoProdutos* manutencaoProdutos, int codigo, char* descricao, float preco, int quantidade);

