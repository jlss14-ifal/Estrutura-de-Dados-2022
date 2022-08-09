# Compila Fila.c
gcc Fila.c -o Fila.o -c
# Compila FilaClinica.c
gcc FilaClinica.c -o FilaClinica.o -c
# Compila Main.c
gcc Main.c -o Main.o -c
# Cria executavel chamado "Main" com Fila.o Main.o
gcc -o Main Fila.o FilaClinica.o Main.o
# Executa "Main"
./Main
