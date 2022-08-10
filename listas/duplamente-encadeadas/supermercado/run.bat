gcc Produto.c -o Produto.o -c
gcc Lista.c -o Lista.o -c
gcc ManutencaoProdutos.c -o ManutencaoProdutos.o -c
gcc Main.c -o Main.o -c
gcc -o Main Produto.o Lista.o ManutencaoProdutos.o Main.o
Main.exe
