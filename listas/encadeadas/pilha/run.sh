# Compila Pilha.c
ccache gcc Pilha.c -o Pilha.o -c
# Compila Main.c
ccache gcc Main.c -o Main.o -c
# Cria executavel chamado "Main" com Pilha.o Main.o
ccache gcc -o Main Pilha.o Main.o
# Executa "Main"
./Main
