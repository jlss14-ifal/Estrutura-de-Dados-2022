# Compila Pilha.c
gcc Pilha.c -o Pilha.o -c
# Compila Main.c
gcc Main.c -o Main.o -c
# Cria executavel chamado "Main" com Pilha.o Main.o
gcc -o Main Pilha.o Main.o
# Executa "Main"
./Main
