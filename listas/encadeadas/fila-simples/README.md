
# Fila simples

## Enunciado

Uma das estruturas de dados bastante utilizadas em Computação é a Fila. Ela tem a característica que inserção de elementos é realizada no final, e a remoção de elementos é realizada no início. Utilizando os conceitos e implementação de listas simplesmente encadeadas trabalhados em sala, implemente uma Fila de senhas (a senha será gerada pelo sistema) para atendimento em uma clínica médica (não é necessário tratar a prioridades). Na sua aplicação deverá ter o seguinte menu:

1 - Gerar senha (gerar um número e inserir na fila)

2 - Atender pessoa (exibir o número e remover da fila)

3 - Visualizar fila (exibe o número de pessoas a serem atendidas)

4 - Consultar atendimentos realizados (exibir o número de pessoas que foram atendidas)

5 - Sair

## Notas

### 1
Para evitar de "print infinito" quando é digitado algo diferente de algarismo em 'scanf("%i", &entrada)', foi criada a função (em Main.c) 'leEntradaNumerica(char *strEntrada, int tamanho, int *saida)' para tratar desses erros.

