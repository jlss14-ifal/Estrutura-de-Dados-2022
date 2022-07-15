# Compila Fila.c
ccache gcc Fila.c -o Fila.o -c
# Compila FilaClinica.c
ccache gcc FilaClinica.c -o FilaClinica.o -c
# Compila Main.c
ccache gcc Main.c -o Main.o -c
# Cria executavel chamado "Main" com Fila.o Main.o
ccache gcc -o Main Fila.o FilaClinica.o Main.o
# Executa "Main"
./Main
