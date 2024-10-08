# A Busca Mágica pela Substring Perdida

No reino encantado, onde a magia permeia todas as coisas, uma antiga profecia revelou a existência de uma poderosa substring, capaz de conceder imenso poder a quem a dominasse. A sua missão, como jovem aprendiz de magia, é encontrar essa substring perdida dentro de palavras místicas, utilizando os algoritmos de casamento de strings aprendidos em sala de aula.

---
## Input
1. A primeira linha de entrada contém uma string de tamanho **N**, a segunda linha contém uma string de tamanho **M**, a terceira linha contém um inteiro **K**: o número de 'queries'.

2. Após isso, a entrada possui **K** linhas descrevendo os 'queries'. Cada linha contém dois inteiros **A** e **B**: o intervalo começa em **A** e termina em **B**.

## Output
Para cada 'querie', a saída deve imprimir **sim** caso a substring esteja presente e **não** caso contrário.

---

## Sistema de Diretório
O nosso trabalho foi organizado no seguinte sistema de arquivos:

+ **src/**: pasta contendo todos os "**.c**".
+ **include/**: pasta contendo todos os "**.h**".
+ **obj/**: pasta contendo todos os "**.o**".
+ **bin/**: pasta onde o executável ficará.
+ **data/**: pasta onde será gerado o **saida.txt**. *NAO DEVE SER APAGADA*.
+ **doc/**: pasta onde está a documentação do trabalho.

---

## Compilação e Execução

O nosso trabalho contém um **Makefile** para o programa ser compilado pelo usuário. Para executá-lo, você deve escrever em seu terminal o seguinte comando na pasta principal do projeto:

``` sh
$ make 
```

Depois disso, os arquivos serão gerados e enviadas para as pastas antes descritas. Para executar o programa, você deve rodar o seguinte comando:

``` sh
$ ./bin/tp3 <estratégia> entrada.txt
```

Em *<estratégia>* você pode selecionar entre as seguintes opções implementadas:
* **F** ou **f**: Forca bruta;
* **B** ou **b**: Boyer-Moore-Horspool;
* **K** ou **k**: Knuth-Morris-Pratt;

---

**Integrantes do trabalho:**
+ Nome - Github
+ Braian Melo - *BraianMelo*
+ Gustavo Campos - *GustavoH-C*