# Compila Fila.c
ccache gcc Fila.c -o Fila.o -c
# Compila Main.c
ccache gcc Main.c -o Main.o -c
# Cria executavel chamado "Main" com Fila.o Main.o
ccache gcc -o Main Fila.o Main.o
# Executa "Main"
./Main
