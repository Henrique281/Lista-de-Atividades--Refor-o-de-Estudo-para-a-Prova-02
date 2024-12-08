# 1. Busca Binária (Binary Search)

## Descrição

A **Busca Binária** é um algoritmo eficiente utilizado para realizar buscas em **listas ordenadas**. O algoritmo divide a lista ao meio a cada iteração, comparando o valor central com o elemento alvo. Dependendo da comparação, a busca continua na metade superior ou inferior da lista. Sua complexidade é **O(log n)**, o que o torna muito eficiente em listas grandes.

## Requisitos

A lista precisa estar **ordenada**, pois o algoritmo utiliza a comparação do valor central para determinar a direção da busca. Se a lista não for ordenada, o algoritmo não funcionará corretamente.

## Exemplo

Considerando a lista ordenada `[1, 3, 5, 7, 9]`, ao procurar o número **7**, o algoritmo segue os seguintes passos:
1. Verifica o número central, **5**.
2. Como **7** é maior que **5**, a busca é redirecionada para a metade superior da lista.
3. A busca continua na lista `[7, 9]`, onde o número central agora é **7**, que é o alvo.

A Busca Binária encontra o número **7** rapidamente, realizando apenas duas comparações.

[Código](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/Aplica%C3%A7%C3%A3o_busca/Aplica%C3%A7%C3%A3o_Pr%C3%A1tica_Busca.c)


---

# 2. Busca por Interpolação (Interpolation Search)

## Descrição

A **Busca por Interpolação** é uma melhoria da **Busca Binária**, mas só é eficiente quando a lista está **ordenada** e os **elementos são distribuídos de maneira relativamente uniforme**. Em vez de dividir a lista ao meio, como na Busca Binária, ela utiliza uma fórmula de interpolação para estimar a posição do elemento alvo. A complexidade do algoritmo pode ser **O(log log n)** em casos ideais, mas no pior caso, pode ser **O(n)**, especialmente quando os dados estão desbalanceados.

## Vantagens

Em listas com distribuição uniforme, a **Busca por Interpolação** pode ser mais rápida que a **Busca Binária**, pois utiliza uma estimativa mais precisa para localizar o elemento. Contudo, se os dados não estiverem uniformemente distribuídos, o desempenho da Busca por Interpolação pode ser pior que o da Busca Binária.

## Exemplo

Dada uma lista de inteiros entre 1 e 100 e a busca pelo número **47**, a **Busca por Interpolação** tentaria estimar a posição do **47** com base nos valores mínimo e máximo da lista, em vez de começar do meio. Essa abordagem pode resultar em uma busca mais eficiente quando os dados estão uniformemente distribuídos.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_busca/busca_interpolacao.c)

---

# 3. Busca por Saltos (Jump Search)

## Descrição

A **Busca por Saltos** divide a lista em **blocos de tamanho fixo** e, a partir da primeira posição, realiza uma busca linear para encontrar o bloco que contém o valor desejado. Em seguida, realiza uma busca linear dentro do bloco. A complexidade do tempo de execução é **O(√n)**, onde **n** é o número de elementos na lista.

## Escolha do "salto"

O tamanho ideal do salto é **√n**, onde **n** é o tamanho da lista. Esse tamanho de salto minimiza o número de saltos necessários e torna a busca linear dentro do bloco mais eficiente, garantindo que o algoritmo opere de forma otimizada.

## Exemplo

Se a lista tiver **100 elementos** e o tamanho do "salto" for **10**, o algoritmo irá verificar os elementos nas posições **0, 10, 20, 30,** e assim por diante, até encontrar o bloco correto. Após localizar o bloco, a busca linear é realizada dentro dele para encontrar o valor alvo.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_busca/busca_jump.c)

---

# 4. Busca Exponencial (Exponential Search)

## Descrição

A **Busca Exponencial** começa verificando a posição **1**, depois **2**, **4**, **8**, **16**, e assim por diante, dobrando o índice a cada passo até ultrapassar o valor procurado ou alcançar o final da lista. Após isso, o algoritmo realiza uma **busca binária** entre o último índice válido e o anterior. A complexidade do algoritmo é **O(log n)**.

## Combinação com Busca por Saltos e Busca Binária

A **Busca Exponencial** combina a "expansão" de índices (semelhante ao **Jump Search**) com a busca binária para localizar a posição exata do elemento. Essa combinação torna a busca mais eficiente em listas grandes.

## Exemplo

Suponha que você esteja procurando o número **67** em uma lista crescente. O algoritmo começaria verificando os índices **1, 2, 4, 8, 16,** e assim por diante, até encontrar um índice maior que **67**. Após localizar o intervalo correto, a busca binária é aplicada entre os índices onde o número poderia estar.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_busca/busca_Exponencial.c)

---

# 5. Ternary Search

## Descrição

O **Ternary Search** é uma variação do **Binary Search**, onde a lista é dividida em **três partes** ao invés de duas. O algoritmo compara o elemento com **dois pontos de divisão** e decide em qual terço a busca continuará. A complexidade do algoritmo é **O(log₃ n)**, o que pode ser ligeiramente melhor que o Binary Search em algumas situações.

## Exemplo

Em uma lista ordenada, ao invés de comparar o valor com o **elemento central** como na busca binária, o **Ternary Search** divide a lista em três partes e realiza **duas comparações** a cada iteração para decidir qual parte da lista a busca deve continuar.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_busca/busca_ternaria.c)

---

# 6. Shell Sort

## Descrição

O **Shell Sort** é uma generalização do **Insertion Sort**. Ele ordena a lista por **intervalos** que diminuem progressivamente até que a lista esteja ordenada. A eficiência do algoritmo depende da **sequência de intervalos** utilizada. As versões mais comuns das sequências de intervalo são: **Shell**, **Knuth** e **Hibbard**.

## Escolha da Sequência de Intervalo

A sequência de intervalos afeta a eficiência do algoritmo. **Sequências mais eficientes** reduzem a quantidade de comparações necessárias, tornando o algoritmo mais rápido. O **Shell Sort** é geralmente mais eficiente que o **Insertion Sort** em listas grandes.

## Exemplo

Suponha que você tenha uma lista de **tamanho 10**. A sequência de intervalos pode começar com **5**, depois **3**, e, finalmente, **1**. O algoritmo aplica o **Insertion Sort** nos subgrupos definidos por esses intervalos, reduzindo os intervalos até que a lista esteja totalmente ordenada.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_ordena%C3%A7%C3%A2o/shell_sort.c)

---

# 7. Merge Sort
**Merge_Sort**

## Descrição

O **Merge Sort** é um algoritmo de ordenação eficiente baseado no princípio de **"dividir para conquistar"**. Ele divide a lista em duas metades, ordena recursivamente e as combina para formar a lista ordenada. Sua complexidade é **O(n log n)**.

## Exemplo

Dada a lista `[38, 27, 43, 3, 9, 82, 10]`, o Merge Sort:

1. Divide a lista em duas metades.
2. Ordena cada metade recursivamente.
3. Mescla as sublistas ordenadas para obter a lista final `[3, 9, 10, 27, 38, 43, 82]`.

## Vantagens

- Complexidade **O(n log n)**.
- Estável (mantém a ordem dos elementos iguais).

## Desvantagens

- Requer **espaço adicional** para armazenar as sublistas.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_ordena%C3%A7%C3%A2o/merge_sort_tipoInt.c)

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_ordena%C3%A7%C3%A2o/merge_sort_tipoString.c)

---

# 8. Selection Sort
**Selection_Sort**

## Descrição

O **Selection Sort** é um algoritmo simples que encontra o menor (ou maior) elemento em uma lista e o coloca na posição correta. Esse processo é repetido até que a lista esteja ordenada. Sua complexidade é **O(n²)**, tornando-o ineficiente para listas grandes.

## Exemplo

Para ordenar `[29, 10, 14, 37, 13]`, o **Selection Sort**:

1. Encontra o menor valor **10** e troca com o primeiro elemento.
2. Repite o processo para o restante da lista: `[29, 10, 14, 37, 13] → [10, 29, 14, 37, 13]`, e assim por diante, até que a lista esteja ordenada.

## Vantagens

- Simples de implementar.

## Desvantagens

- Complexidade **O(n²)**, ineficiente para listas grandes.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_ordena%C3%A7%C3%A2o/selection_sort.c)

---

# 9. Bucket Sort
**Bucket_Sort**

## Descrição

O **Bucket Sort** divide os elementos em intervalos chamados de "baldes". Cada balde é ordenado separadamente e, em seguida, os resultados são combinados. É mais eficiente para listas com valores distribuídos uniformemente em um intervalo fixo. Sua complexidade média é **O(n + k)**, onde **n** é o número de elementos e **k** é o número de baldes.

## Exemplo

Para ordenar `[0.42, 0.32, 0.63, 0.53, 0.51]`, o **Bucket Sort**:

1. Divide os elementos em baldes.
2. Ordena cada balde individualmente.
3. Combina os resultados ordenados.

## Vantagens

- Eficiente para listas com distribuição uniforme.

## Desvantagens

- Desempenho depende da distribuição dos dados.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_ordena%C3%A7%C3%A2o/bucket_sort.c)

---

# 10. Radix Sort
**Radix_Sort**

## Descrição

O **Radix Sort** é um algoritmo de ordenação não comparativo que ordena os números por seus dígitos, começando pelo menos significativo até o mais significativo. Ele pode ser aplicado em qualquer base (como base 10 ou base 2) e tem complexidade **O(nk)**, onde **n** é o número de elementos e **k** é o número de dígitos.

## Exemplo

Para ordenar `[170, 45, 75, 90, 802, 24, 2, 66]`, o **Radix Sort**:

1. Ordena os números com base no primeiro dígito.
2. Depois ordena com base no segundo dígito, e assim por diante.

## Vantagens

- Eficiente para números inteiros ou strings de comprimento fixo.
- Não utiliza comparações diretas entre os elementos.

## Desvantagens

- Pode ser ineficiente para listas muito grandes com muitos dígitos.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_ordena%C3%A7%C3%A2o/radix_sort.c)

---

11. Quick Sort
Quick_Sort

Descrição: O Quick Sort é um algoritmo eficiente de ordenação baseado na estratégia "dividir para conquistar". Ele escolhe um pivô, particiona a lista em torno desse pivô e recursivamente ordena as sublistas. A complexidade média é O(n log n), mas no pior caso pode ser O(n²).

Escolha do pivô: O desempenho do Quick Sort depende da escolha do pivô. Se o pivô for escolhido de maneira eficiente (como o pivô médio ou o pivô aleatório), o algoritmo pode ter bom desempenho mesmo em listas grandes.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/algoritimos_ordena%C3%A7%C3%A2o/quick_sort.c)

---

# 12 Comparação de Algoritmos de Busca

Abaixo está uma tabela comparativa dos tempos de execução de **Binary Search**, **Interpolation Search**, **Jump Search** e **Exponential Search** em listas de tamanhos diferentes.

| Tamanho da Lista | **Binary Search (O(log n))** | **Interpolation Search (O(log log n))** | **Jump Search (O(√n))** | **Exponential Search (O(log n))** |
|------------------|-----------------------------|---------------------------------------|-------------------------|-----------------------------------|
| 1.000            | 10 ms                       | 10 ms                                 | 30 ms                   | 10 ms                             |
| 10.000           | 14 ms                       | 13 ms                                 | 100 ms                  | 14 ms                             |
| 100.000          | 17 ms                       | 15 ms                                 | 316 ms                  | 17 ms                             |
| 1.000.000        | 20 ms                       | 16 ms                                 | 1.000 ms                | 20 ms                             |
| 10.000.000       | 23 ms                       | 17 ms                                 | 3.162 s                 | 23 ms                             |

### Explicação dos Algoritmos:

1. **Binary Search**:
   - **Complexidade**: O(log n)
   - **Descrição**: O algoritmo de busca binária divide a lista ao meio a cada iteração, resultando em uma busca muito eficiente em listas grandes.

2. **Interpolation Search**:
   - **Complexidade**: O(log log n) no melhor caso, mas O(n) no pior caso.
   - **Descrição**: A busca por interpolação estima a posição do item com base na distribuição dos dados. É eficiente quando os dados são uniformemente distribuídos.

3. **Jump Search**:
   - **Complexidade**: O(√n)
   - **Descrição**: A Jump Search divide a lista em "blocos" e realiza saltos para reduzir a área de busca, sendo eficaz em listas uniformemente distribuídas.

4. **Exponential Search**:
   - **Complexidade**: O(log n)
   - **Descrição**: A busca exponencial começa a buscar em intervalos exponenciais até encontrar o local adequado para realizar a busca binária.

### Observações:
- O desempenho dos algoritmos pode variar dependendo da distribuição dos dados e do tamanho da lista. Em geral, algoritmos com complexidade O(log n) tendem a ser mais eficientes em listas grandes.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/compara%C3%A7%C3%B5es/Compara%C3%A7%C3%A3o_Algoritmos_busca.c)

---

# 13 Comparação dos Algoritmos de Ordenação

Esta tabela compara os tempos de execução e as características de alguns dos principais algoritmos de ordenação:

| Algoritmo          | Melhor Caso | Caso Médio | Pior Caso | Estabilidade | Complexidade de Tempo (Melhor Caso) | Complexidade de Tempo (Caso Médio) | Complexidade de Tempo (Pior Caso) | Complexidade de Espaço |
|--------------------|-------------|------------|-----------|--------------|-------------------------------------|------------------------------------|-----------------------------------|-------------------------|
| **Bubble Sort**     | O(n)        | O(n²)      | O(n²)     | Estável      | O(n)                                | O(n²)                             | O(n²)                             | O(1)                    |
| **Selection Sort**  | O(n²)       | O(n²)      | O(n²)     | Não Estável  | O(n²)                               | O(n²)                             | O(n²)                             | O(1)                    |
| **Insertion Sort**  | O(n)        | O(n²)      | O(n²)     | Estável      | O(n)                                | O(n²)                             | O(n²)                             | O(1)                    |
| **Merge Sort**      | O(n log n)  | O(n log n) | O(n log n)| Estável      | O(n log n)                          | O(n log n)                        | O(n log n)                        | O(n)                    |
| **Quick Sort**      | O(n log n)  | O(n log n) | O(n²)     | Não Estável  | O(n log n)                          | O(n log n)                        | O(n²)                             | O(log n)                |
| **Heap Sort**       | O(n log n)  | O(n log n) | O(n log n)| Não Estável  | O(n log n)                          | O(n log n)                        | O(n log n)                        | O(1)                    |
| **Radix Sort**      | O(nk)       | O(nk)      | O(nk)     | Estável      | O(nk)                               | O(nk)                             | O(nk)                             | O(n + k)                |
| **Bucket Sort**     | O(n + k)    | O(n + k)   | O(n²)     | Estável      | O(n + k)                            | O(n + k)                          | O(n²)                             | O(n + k)                |

## Descrição dos Algoritmos

- **Bubble Sort**: Ordena a lista repetidamente, trocando elementos adjacentes quando estão na ordem errada. Embora simples, é muito ineficiente para listas grandes.
- **Selection Sort**: Encontra o menor elemento e o coloca na posição correta, repetindo esse processo até ordenar a lista. Apesar de simples, também não é eficiente para listas grandes.
- **Insertion Sort**: Insere cada elemento na posição correta, uma vez de cada vez. Funciona bem para listas pequenas ou parcialmente ordenadas.
- **Merge Sort**: Divide recursivamente a lista em duas metades, ordena cada metade e depois as combina de maneira eficiente. É estável e tem boa performance para listas grandes.
- **Quick Sort**: Divide a lista em partes menores e ordena recursivamente. Embora tenha uma boa média de desempenho, seu pior caso é O(n²), o que o torna menos eficiente em alguns casos.
- **Heap Sort**: Utiliza uma estrutura de dados chamada heap para ordenar os elementos. Tem uma boa complexidade no pior caso e é eficiente para listas grandes, mas não é estável.
- **Radix Sort**: Ordena números por cada dígito, começando pelo menos significativo. É eficiente para listas de números inteiros e pode ser mais rápido que os algoritmos de comparação.
- **Bucket Sort**: Divide a lista em intervalos (baldes) e ordena cada balde separadamente. Funciona bem quando os dados estão distribuídos uniformemente.

## Conclusão

A escolha do algoritmo de ordenação depende do tamanho e da natureza dos dados. Para listas pequenas ou quase ordenadas, algoritmos como **Insertion Sort** podem ser rápidos, enquanto para listas grandes, algoritmos como **Merge Sort** ou **Quick Sort** são mais eficientes. Algoritmos como **Radix Sort** e **Bucket Sort** podem ser ideais para conjuntos de dados com características específicas, como números inteiros em um intervalo limitado.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/compara%C3%A7%C3%B5es/Compara%C3%A7%C3%A3o_algoritmos%20_ordena%C3%A7%C3%A3o.c)

---

# 14 Análise de Complexidade dos Algoritmos de Busca e Ordenação

## Algoritmos de Busca

| Algoritmo             | Melhor Caso | Caso Médio | Pior Caso   | Complexidade de Espaço |
|-----------------------|-------------|------------|-------------|------------------------|
| **Linear Search**      | O(1)        | O(n)       | O(n)        | O(1)                   |
| **Binary Search**      | O(1)        | O(log n)   | O(log n)    | O(1)                   |
| **Interpolation Search**| O(1)        | O(log log n) | O(n)       | O(1)                   |
| **Exponential Search** | O(1)        | O(log n)   | O(log n)    | O(1)                   |

### Explicação sobre Algoritmos de Busca:
- **Melhor Caso**: Descreve o melhor desempenho possível para o algoritmo. Exemplo: em uma lista já ordenada, a busca binária pode encontrar o valor em O(1) de tempo.
- **Caso Médio**: Estima o desempenho médio do algoritmo em situações comuns. Exemplo: a busca linear tem desempenho O(n) no caso médio.
- **Pior Caso**: Representa o pior cenário possível de desempenho. Exemplo: na busca binária, no pior caso, o algoritmo faz log n comparações.
- **Complexidade de Espaço**: Refere-se à quantidade de memória adicional necessária para a execução do algoritmo. A busca binária, por exemplo, utiliza O(1) de espaço.

## Algoritmos de Ordenação

| Algoritmo             | Melhor Caso | Caso Médio | Pior Caso   | Complexidade de Espaço |
|-----------------------|-------------|------------|-------------|------------------------|
| **Bubble Sort**        | O(n)        | O(n²)      | O(n²)       | O(1)                   |
| **Selection Sort**     | O(n²)       | O(n²)      | O(n²)       | O(1)                   |
| **Insertion Sort**     | O(n)        | O(n²)      | O(n²)       | O(1)                   |
| **Merge Sort**         | O(n log n)  | O(n log n) | O(n log n)  | O(n)                   |
| **Quick Sort**         | O(n log n)  | O(n log n) | O(n²)       | O(log n)               |
| **Heap Sort**          | O(n log n)  | O(n log n) | O(n log n)  | O(1)                   |
| **Radix Sort**         | O(nk)       | O(nk)      | O(nk)       | O(n + k)               |

### Explicação sobre Algoritmos de Ordenação:
- **Melhor Caso**: Descreve o melhor desempenho possível para o algoritmo. Por exemplo, no caso do **Insertion Sort**, quando a lista já está ordenada, o desempenho é O(n).
- **Caso Médio**: Estima o desempenho médio em situações comuns. Exemplo: o **Merge Sort** tem uma complexidade de O(n log n) tanto no caso médio quanto no pior caso.
- **Pior Caso**: Representa o pior cenário possível de desempenho. O **Quick Sort**, por exemplo, tem um desempenho O(n²) no pior caso, embora no caso médio seja muito eficiente com O(n log n).
- **Complexidade de Espaço**: Refere-se à quantidade de memória adicional necessária para a execução do algoritmo. Algoritmos como o **Merge Sort** exigem O(n) de espaço adicional, enquanto o **Bubble Sort** usa apenas O(1).

---

# 15 Busca e Ordenação em Strings

## Algoritmos

### 1. Ordenação de Palavras com Merge Sort
- **Como funciona**: Divide a lista em duas metades, ordena e depois mescla.
- **Complexidade**: 
  - Tempo: O(n log n)
  - Espaço: O(n)
 
[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/ordenacao_busca_em_strings/mergeSortWords.c)

### 2. Ordenação de Palavras com Quick Sort
- **Como funciona**: Usa um pivô para dividir a lista, ordenando as palavras em cada lado.
- **Complexidade**:
  - Tempo: O(n log n) (média), O(n²) (pior caso)
  - Espaço: O(log n)
 
[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/ordenacao_busca_em_strings/quickSortWords.c)

### 3. Busca de Palavras com Binary Search
- **Como funciona**: Em uma lista ordenada, compara a palavra com o elemento central e ajusta a busca para a metade relevante.
- **Complexidade**:
  - Tempo: O(log n)
  - Espaço: O(1) (versão iterativa)
   - 
[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/ordenacao_busca_em_strings/binarySearchWords.c)

---

# 16 Aplicação Prática de Busca: Pesquisa de Livro por ISBN

## Funcionalidade

- **Objetivo**: Permite procurar um livro por seu **ISBN** em uma lista ordenada de registros, aplicando o algoritmo de **Binary Search** para otimizar a busca.
  
- **Como Funciona**: A lista de livros é ordenada por ISBN, e o **Binary Search** é usado para dividir a lista e localizar rapidamente o livro desejado. O algoritmo compara o ISBN procurado com o elemento central da lista e ajusta a busca para a metade relevante até encontrar a correspondência.

## Complexidade

- **Binary Search**:
  - Tempo: O(log n)
  - Espaço: O(1) (versão iterativa)
 
[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/Aplica%C3%A7%C3%A3o_busca/Aplica%C3%A7%C3%A3o_Pr%C3%A1tica_Busca.c)

---

# 17 Busca e Ordenação em Dados Reais: Notas de Alunos

## Funcionalidade

- **Objetivo**: Organizar as notas dos alunos de maneira eficiente utilizando o **Bucket Sort** e, posteriormente, realizar uma busca rápida pela nota de um aluno usando o **Interpolation Search**.
  
- **Bucket Sort**: As notas dos alunos são divididas em "baldes" (intervalos de notas), e cada balde é ordenado separadamente. O resultado final é uma lista de notas ordenadas.

- **Interpolation Search**: Após ordenar as notas com o **Bucket Sort**, o **Interpolation Search** é utilizado para procurar uma nota específica de um aluno. O algoritmo é eficiente para listas com valores uniformemente distribuídos, como as notas dos alunos.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/Aplica%C3%A7%C3%A3o_busca/Busca_ordena%C3%A7%C3%A3o_dados_reais.c)

---

# 18 Ordenação Estável e Instável

Na teoria de algoritmos de ordenação, uma **ordenação estável** é aquela que preserva a ordem relativa de elementos com valores iguais. Isso significa que, quando dois elementos possuem o mesmo valor, a ordem em que aparecem na lista original é mantida após a ordenação.

Por outro lado, uma **ordenação instável** pode alterar a ordem relativa de elementos com valores iguais. 

## Algoritmos Estáveis e Instáveis

### Algoritmos Estáveis:
- **Merge Sort**: Esse algoritmo é estável porque, quando duas chaves têm o mesmo valor, a ordem original delas é mantida após a fusão das sublistas.
- **Bubble Sort**: Também é estável, já que, quando encontra dois elementos iguais, não altera sua posição relativa.
- **Insertion Sort**: Mantém a ordem relativa de elementos iguais, sendo um algoritmo estável.

### Algoritmos Instáveis:
- **Quick Sort**: É instável, pois pode trocar elementos com valores iguais e, portanto, pode alterar sua ordem relativa.
- **Selection Sort**: Embora seja eficiente, não é estável, já que pode trocar elementos iguais durante o processo de ordenação.

---

# 19 Análise Visual dos Algoritmos de Ordenação

## Algoritmos Abordados

### 1. **Merge Sort**

![Minha Imagem](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/imagens/Merge%20Sort_step_1.png)


- **Processo**: Divide a lista em sublistas menores e as mescla de forma ordenada.
- **Visualização**: Mostra a divisão da lista e como as sublistas são combinadas até formar a lista ordenada.


### 2. **Quick Sort**

![Minha Imagem](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/imagens/Quick%20Sort_step_1.png)


- **Processo**: Escolhe um pivô e reorganiza os elementos ao seu redor, repetindo o processo nas sublistas.
- **Visualização**: Exibe como o pivô é escolhido e como os elementos são movidos à medida que a lista é ordenada.

### 3. **Selection Sort**

![Minha Imagem](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/imagens/Selection%20Sort_step_1.png)


- **Processo**: Seleciona o menor (ou maior) elemento e o coloca na posição correta, repetindo até ordenar a lista.
- **Visualização**: Demonstra a seleção e troca dos elementos em cada etapa.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/An%C3%A1lise%20_Visual_Algoritmos%20.py)

---

# 20. Desafios de Implementação: Comparação de Algoritmos de Busca e Ordenação

## Funcionalidades

- **Escolha do Algoritmo de Busca**:
  - O usuário pode escolher entre os seguintes algoritmos de busca:
    - **Busca Binária (Binary Search)**: Utiliza a abordagem de divisão e conquista para encontrar um elemento em uma lista ordenada de maneira eficiente.
    - **Busca Linear (Linear Search)**: Realiza a busca de forma sequencial, verificando cada elemento da lista até encontrar o alvo.

- **Escolha do Algoritmo de Ordenação**:
  - O usuário pode selecionar entre diferentes algoritmos de ordenação, como:
    - **Quick Sort**: Um algoritmo eficiente que usa o conceito de pivô para ordenar a lista.
    - **Merge Sort**: Um algoritmo que utiliza a técnica de divisão e conquista para dividir a lista e depois mesclá-la de forma ordenada.
    - **Bubble Sort**: Um algoritmo simples que compara e troca elementos adjacentes para ordená-los.
    - **Selection Sort**: Seleciona o menor ou maior elemento e coloca-o em sua posição correta na lista.

- **Comparações Automáticas**:
  - O programa compara o desempenho dos algoritmos de busca e ordenação, fornecendo uma análise detalhada do tempo de execução de cada algoritmo escolhido.

## Como Funciona

1. **Escolha do Algoritmo**: O usuário escolhe entre os algoritmos de busca ou ordenação disponíveis.
2. **Execução**: O programa executa o algoritmo escolhido e mostra os resultados, como a lista ordenada ou o elemento encontrado.
3. **Comparação de Desempenho**: O programa calcula e exibe o tempo de execução para cada algoritmo, permitindo ao usuário comparar o desempenho de diferentes técnicas.
4. **Análise**: O programa oferece insights sobre qual algoritmo teve o melhor desempenho com base nos dados de entrada.

## Exemplo de Uso

1. O usuário escolhe **Merge Sort** para ordenar uma lista de números.
2. O programa exibe a lista ordenada e o tempo de execução do algoritmo.
3. Em seguida, o usuário escolhe **Binary Search** para procurar um número na lista ordenada.
4. O programa retorna o índice do número e o tempo de execução da busca.

[codigo](https://github.com/Henrique281/Lista-de-Atividades--Refor-o-de-Estudo-para-a-Prova-02/blob/main/Desafio/desafios_implementa%C3%A7%C3%A3o.c)

