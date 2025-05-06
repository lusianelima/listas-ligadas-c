# Projeto de Listas Encadeadas em C

Este repositório contém a implementação de diversas operações em **listas encadeadas**, tanto **simplesmente encadeadas** quanto **duplamente encadeadas**, com a linguagem C. As funções abordam diversos problemas comuns envolvendo listas encadeadas, demonstrando como manipulá-las de forma eficiente.

## Questões Implementadas

### 1. **Contagem de Células**
   Função que conta o número de células em uma lista encadeada. Ela percorre toda a lista, incrementando o contador a cada célula até o final da lista.

### 2. **Busca**
   Função que busca um elemento na lista. A função percorre a lista até encontrar o valor desejado e retorna um ponteiro para a célula correspondente, ou `NULL` se o valor não for encontrado.

### 3. **Copiar Vetor para Lista**
   Função que converte um vetor (array) de inteiros em uma lista simplesmente encadeada. A função percorre o vetor e insere cada valor em uma nova célula da lista.

### 6. **Concatenar Listas**
   Função para concatenar duas listas encadeadas. Ela percorre ambas as listas e as conecta, formando uma única lista com os elementos de ambas.

### 7. **Inversão de Lista**
   Função que inverte a ordem dos elementos de uma lista encadeada. A lista é percorrida e os ponteiros das células são trocados para inverter a direção dos links entre elas.

### 8. **Verificar Igualdade**
   Função que verifica se duas listas encadeadas são idênticas. Ela percorre ambas as listas simultaneamente e compara os elementos correspondentes. Retorna `true` se as listas forem iguais, e `false` caso contrário.

### 9. **Inserir em Lista Ordenada**
   Função que insere um elemento em uma lista encadeada de forma ordenada (em ordem crescente). A função encontra a posição correta para inserção e mantém a ordem da lista intacta.

### 11. **Remover por Posição**
   Função que remove o i-ésimo item de uma lista encadeada. A função percorre a lista até a posição desejada, ajusta os ponteiros dos elementos vizinhos e remove a célula, liberando a memória.

## Como Usar

### Requisitos

- Compilador C (por exemplo, GCC) para compilar o código.

### Passos para Compilação

1. **Clone o repositório** para a sua máquina local:

   ```bash
   git clone https://github.com/seu-usuario/repositorio.git
2. **Navegue até o diretório do projeto:**
   
   ```bash
   cd repositorio
   ```
3. **Compile o código com o comando:**

   ```bash
   gcc -o lista_encadeada lista_encadeada.c
4. Execute o programa:

   ```bash
    ./lista_encadeada

### **Testando as Funções**
  Cada uma das funções descritas acima foi implementada no código, com exemplos no arquivo main(). Para testar uma função, basta seguir os exemplos dentro do main() ou criar suas próprias entradas para testar as funcionalidades.

  
Desenvolvido por **Lusiane Lima**  
🔗 Repositório: (https://github.com/lusianelima/listas-ligadas-c)
