# REO 02

### Sobre
O código desenvolvido nesse reo, tinha o objetivo de calcular o [Coeficiente de Pearson](https://www.questionpro.com/blog/pt-br/correlacao-de-pearson/) (a fórmula se encontra no final do arquivo), e os valores utilizados para o cálculo eram provenientes de arquivos. O objetivo da atividade era explorar o [paradigma imperativo](https://pt.wikipedia.org/wiki/Programação_imperativa).

> ✔ Status: Finalizado

### Requisitos:
📍 Para rodar a aplicação é necessário primeiro ter Python instaldo na máquina.
#### Windows
[Dowload Python](https://www.python.org/downloads/)
#### Linux
- Primeiro verifique se já não está instalado:
```bash
    $ which Python
```
```bash
    $ which Python3
```
- Caso não tenha é possível instalar utilizando o comando:
```bash
    $ sudo apt-get install python3
 ```
 📍 Após a instalação é necessário estar dentro de um diretório que contenha o código e um arquivo .txt; Esse arquivo precisa conter pares de valores X e Y separados por vírgula (o repositório já contem um arquivo disponível para teste).
 <br>
 📍 Dentro do diretório indicado basta digitar o comando abaixo no terminal (adaptando os nomes para os nomes dos seus arquivos) que em seguida o resultado será apresentado. O comando é o mesmo tanto para Windows quanto para Linux
 ```bash
     $ python3 programa.py arquivoDeEntrada.txt
 ```
 ##
 ### Fórmula do coeficiente de Pearson
![image](https://user-images.githubusercontent.com/66702089/145122893-a9675b0d-929e-48f5-8126-4365d7c57767.png)
