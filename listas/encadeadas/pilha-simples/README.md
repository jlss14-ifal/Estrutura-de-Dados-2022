
# Pilha simples

## Enunciado

Pilha é uma lista linear onde as operações de inserção e remoção são realizadas num mesmo extremo, denominado topo. As pilhas
podem ser implementadas com vetor ou listas encadeadas.

Utilizando listas encadeadas ou vetores, implemente um programa em C, com as funções básicas de manipulação da pilha. As funções são definidas abaixo:

- Pilha* criar(Pilha *p) - alocar memória e inicializar a pilha
- void push(Pilha *p, char x) - inserir um elemento na pilha
- char top (Pilha *p) - exibir o elemento do topo da pilha
- char pop(Pilha *p) – remover o elemento do topo da pilha
- int estaVazia(Pilha *p) – retorna 1 se a pilha está vazia e 0, caso contrário 

E utilizando o tipo pilha criado, implemente uma função que leia uma string em notação infixa e apresente a notação pósfixa equivalente.

## Notas 
### 1
Nessa pilha coloquei também a função "tamanhoPilha(Pilha)" para saber o tamanho da pilha.
 
### 2
Para executar:
- No Windows:
	- Execute o arquivo "run.bat".
- No Linux:
	- Execute o arquivo "run.sh".
