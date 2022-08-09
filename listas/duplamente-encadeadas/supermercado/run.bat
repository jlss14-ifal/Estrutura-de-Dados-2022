:: Compila Produto.c
gcc Produto.c -o Produto.o -c
:: Compila Lista.c
gcc Lista.c -o Lista.o -c
:: Compila ManutencaoProdutos.c
gcc ManutencaoProdutos.c -o ManutencaoProdutos.o -c
:: Compila Main.c
gcc Main.c -o Main.o -c
:: Cria executavel chamado "Main" com Lista.o ManutencaoProdutos.o Main.o
gcc -o Main Produto.o Lista.o ManutencaoProdutos.o Main.o
:: Executa "Main"
Main.exe
