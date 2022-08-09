
# Listas encadeadas simples

## Enunciado

Utilizando os conceitos de listas simplesmente encadeadas, implemente uma estrutura que represente uma lista para manipular caracteres, crie um menu com as seguintes opções a serem disponibilizadas ao usuário:

1 - Inserir elemento no início da lista

2 - Exibir quantidade de elementos da lista

3 - Exibir lista

4 - Procurar elemento na lista

5 - Inserir elemento no final da lista

6 - Remover elemento do início da lista

7 - Remover elemento da lista (em qualquer posição)

8 - Inserir um elemento após uma posição x especificada pelo usuário.

9 - Finalizar

Cada item acima, com exceção de 9 que finalizará o programa, deverá ser implementado numa função no programa.

E neste endereço tem uma animação para ajudar a entender o passo a passo de inserção e remoção em listas: [link](https://portaldoprofessor.fct.unesp.br/projetos/cadilag/apps/structs/lista_desord_simples.php)

## Notas

### 1
Para evitar de "print infinito" quando é digitado algo diferente de algarismo em 'scanf("%i", &entrada)', foi criada a função (em Main.c) 'leEntradaNumerica(char *strEntrada, int tamanho, int *saida)' para tratar desses erros.

### 2
Por fins de conveniência/didática, as opções da resposta está:

0 - visualizar lista;

1 - exibir quantidade de elementos;

2 - procurar por valor;

3 - procurar por indice;

4 - inserir em uma posicao especifica;

5 - inserir do inicio;

6 - inserir do final;

7 - remover em uma posicao especifica;

8 - remover do inicio;                

9 - remover do fim;

10 - finalizar.

### 3
Para executar:
- No Windows:
	- Execute o arquivo "run.bat".
- No Linux:
	- Execute o arquivo "run.sh".
