
#include <stdlib.h>

typedef struct {
	int codigo;
	char* descricao;
	float preco;
	int quantidade;
} Produto;

Produto* criarProduto(int codigo, char* descricao, float preco, int quantidade); 

void produtoVisualizar(Produto* produto);

