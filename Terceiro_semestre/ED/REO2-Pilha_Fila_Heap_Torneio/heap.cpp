//Heap: maxheap
#include <cstdlib>
#include <iostream>

using namespace std;

class Heap
{
private:
    int mTamanho;
    int *dadosHeap;
    int mCapacidade;
    int retornaPai(int indice);
    int retornaDireita(int indice);
    int retornaEsquerda(int indice);
    void constroiHeap(); //heapify()
    void corrigeSubindo(int indice);
    void corrigeDescendo(int indice);

public:
    ~Heap();
    Heap(int capacidade);
    Heap(int vetDados[], int tam);
    void imprime();
    int espiaRaiz();
    int retiraRaiz();
    void insere(int dado);
};

int Heap::retornaPai(int indice)
{
    return (indice - 1) / 2;
}

int Heap::retornaDireita(int indice)
{
    return 2 * indice + 2;
}

int Heap::retornaEsquerda(int indice)
{
    return 2 * indice + 1;
}

void Heap::constroiHeap()
{
    for (int i = (mTamanho / 2) - 1; i >= 0; i--)
        corrigeDescendo(i);
}

void Heap::corrigeSubindo(int indice)
{
    int pai = retornaPai(indice);
    if (dadosHeap[indice] > dadosHeap[pai])
    {
        swap(dadosHeap[indice], dadosHeap[pai]);
        corrigeSubindo(pai);
    }
}

void Heap::corrigeDescendo(int indice)
{
    int maior = indice;
    int direita = retornaDireita(indice);
    int esquerda = retornaEsquerda(indice);

    if ((esquerda < mTamanho) and (dadosHeap[esquerda] > dadosHeap[maior]))
        maior = esquerda;

    if ((direita < mTamanho) and (dadosHeap[direita] > dadosHeap[maior]))
        maior = direita;

    if (maior != indice)
    {
        swap(dadosHeap[indice], dadosHeap[maior]);
        corrigeDescendo(maior);
    }
}

Heap::~Heap()
{
    delete[] dadosHeap;
}

Heap::Heap(int capacidade)
{
    mCapacidade = capacidade;
    dadosHeap = new int[mCapacidade];
    mTamanho = 0;
}

Heap::Heap(int vetDados[], int tamanho)
{
    mCapacidade = tamanho;
    dadosHeap = new int[tamanho];

    for (int i = 0; i < tamanho; i++)
        dadosHeap[i] = vetDados[i];
    mTamanho = tamanho;
    constroiHeap();
}

void Heap::imprime()
{
    //metodo implementado apenas para fins didáticos pois é um quebra de estrutura
    for (int i = 0; i < mTamanho; i++)
        cout << dadosHeap[i] << " ";
    cout << endl;
}

int Heap::espiaRaiz()
{
    return dadosHeap[0];
}

int Heap::retiraRaiz()
{
    if (mTamanho == 0)
    {
        cout << "Erro ao retirar raiz" << endl;
        exit(EXIT_FAILURE);
    }
    int raiz = dadosHeap[0];
    swap(dadosHeap[0], dadosHeap[mTamanho - 1]);
    mTamanho--;
    corrigeDescendo(0);
    return raiz;
}

void Heap::insere(int dado)
{
    if (mTamanho == mCapacidade)
    {
        cout << "Erro ao inserir dado!" << endl;
        exit(EXIT_FAILURE);
    }
    dadosHeap[mTamanho] = dado;
    corrigeSubindo(mTamanho);
    mTamanho++;
}

int main()
{
    int op;
    int dado;
    int capacidade = 0;

    cout << "Insira a capacidade do heap: ";
    cin >> capacidade;
    int vetDados[capacidade];
    for (int i = 0; i < capacidade; i++)
    {
        cout << "Insira o " << i + 1 << "o elemento do vetor: ";
        cin >> vetDados[i];
        cout << endl;
    }
    Heap *maxHeap = new Heap(vetDados, capacidade);

    cout << "1. Inserir dados no heap;" << endl;
    cout << "2. Imprimir dados do heap;" << endl;
    cout << "3. Espiar a raiz do heap;" << endl;
    cout << "4. Retornar a raiz do heap;" << endl;
    cout << "5. Sair;" << endl;
    cin >> op;

    do
    {
        switch (op)
        {
        case 1:
            cout << "Insira o dado desejado: ";
            cin >> dado;
            cout << endl;
            maxHeap->insere(dado);
            break;

        case 2:
            cout << "Dados do heap:" << endl;
            maxHeap->imprime();
            break;

        case 3:
            cout << "Raiz do Heap: " << maxHeap->espiaRaiz() << endl;
            break;

        case 4:
            cout << "Raiz removida do Heap: " << maxHeap->retiraRaiz() << endl;
            break;
        default:
            break;
        }
        cout << "1. Inserir dados no heap;" << endl;
        cout << "2. Imprimir dados do heap;" << endl;
        cout << "3. Espiar a raiz do heap;" << endl;
        cout << "4. Retornar a raiz do heap;" << endl;
        cout << "5. Sair;" << endl;
        cin >> op;
    } while (op != 5);

    return 0;
}