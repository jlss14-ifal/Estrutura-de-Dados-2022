:: Compila Lista.c
gcc Lista.c -o Lista.o -c
:: Compila Main.c
gcc Main.c -o Main.o -c
:: Cria executavel chamado "Main" com Lista.o Main.o
gcc -o Main Lista.o Main.o
:: Executa "Main"
Main.exe
