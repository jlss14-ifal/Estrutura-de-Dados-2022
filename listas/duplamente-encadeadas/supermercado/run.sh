# Compila Produto.c
ccache gcc Produto.c -o Produto.o -c
# Compila Lista.c
ccache gcc Lista.c -o Lista.o -c
# Compila ManutencaoProdutos.c
ccache gcc ManutencaoProdutos.c -o ManutencaoProdutos.o -c
# Compila Main.c
ccache gcc Main.c -o Main.o -c
# Cria executavel chamado "Main" com Lista.o ManutencaoProdutos.o Main.o
ccache gcc -o Main Produto.o Lista.o ManutencaoProdutos.o Main.o
# Executa "Main"
./Main
