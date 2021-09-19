//Heap: maxheap
#include <cstdlib>
#include <iostream>

using namespace std;

class Heap{
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

int Heap::retornaPai(int indice){
    return (indice-1)/2;
}

int Heap::retornaDireita(int indice){
    return 2*indice+2;
}

int Heap::retornaEsquerda(int indice){
    return 2*indice+1;
}

void Heap::constroiHeap(){
    for(int i = (mTamanho/2)-1; i >= 0; i--)
        corrigeDescendo(i);
}

void Heap::corrigeSubindo(int indice){

}

void Heap::corrigeDescendo(int indice){
    int maior = i;
    int direita = retornaDireita(indice);
    int esquerda = retornaEsquerda(indice);

    if((esquerda < mTamanho) and (dadosHeap[esquerda] > dadosHeap[i]))
        maior = esquerda;
        
    if((direita < mTamanho) and (dadosHeap[direita] > dadosHeap[i]))
        maior = direita;
    
    if(maior != indice){
        swap(dadosHeap[indice], heap[maior]);
        corrigeDescendo(maior);
    }
}

Heap::~Heap(){
    delete[] dadosHeap;
}

Heap::Heap(int capacidade){
    mCapacidade = capacidade;
    dadosHeap = new int[mCapacidade];
    mTamanho = 0;
}

Heap::Heap(int vetDados[], int tamanho){
    mCapacidade = tamanho;
    dadosHeap = new int[tamanho];

    for(int i = 0; i < tamanho; i++)
        dadosHeap[i] = vetDados[i];
    mTamanho = tamanho;
    arruma();
}

void Heap::imprime(){
//metodo implementado apenas para fins didáticos pois é um quebra de estrutura
}

void Heap::espiaRaiz(){

}

void Heap::retiraRaiz(){

}

void Heap::insere(int dado){

}

int main(){


    return 0;
}