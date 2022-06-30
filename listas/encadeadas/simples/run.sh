# Compila Lista.c
ccache gcc Lista.c -o Lista.o -c
# Compila Main.c
ccache gcc Main.c -o Main.o -c
# Cria executavel chamado "Main" com Lista.o Main.o
ccache gcc -o Main Lista.o Main.o
# Executa "Main"
./Main
