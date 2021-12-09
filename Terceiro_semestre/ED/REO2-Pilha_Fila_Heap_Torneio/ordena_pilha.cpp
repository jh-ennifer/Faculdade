/*Implemente um estrutura de dados do tipo pilha com as operações de empilhar e desempilhar. 
Adicione um método que, utilizando uma pilha auxiliar, faça a ordenação crescente da pilha original, 
com o menor elemento no topo da pilha. Nenhuma outra estrutura pode ser utilizada além da pilha auxiliar.

Entradas:
    Quantidade de elementos a serem armazenados na pilha
    Elementos da pilha
Saídas:
    Elementos da pilha ordenados*/

#include <iostream>

using namespace std;

class noh
{
    friend class Pilha;

private:
    int mDado;
    noh *mProximo;

public:
    noh(int valor);
};

noh::noh(int valor)
{
    mDado = valor;
    mProximo = NULL;
}

class Pilha
{
private:
    int mTamanho;
    noh *mTopo;

public:
    Pilha();
    ~Pilha();
    void ordena();    
    int desempilhar();
    void empilhar(int dado);    
};

Pilha::Pilha()
{
    mTopo = NULL;
    mTamanho = 0;
}

Pilha::~Pilha()
{
    cout << "Destruindo" << endl;
    while (mTamanho > 0)
    {
        desempilhar();
    }
}

void Pilha::empilhar(int dado)
{
    noh *novo = new noh(dado);
    novo->mProximo = mTopo;
    mTopo = novo;
    mTamanho++;
}

int Pilha::desempilhar()
{
    noh *aux = mTopo;
    int dado = aux->mDado;
    mTopo = aux->mProximo;
    delete aux;
    mTamanho--;
    return dado;
}

void Pilha::ordena(){
    Pilha Aux;    
    int maior = 0;
    int elementoCompara = 0;
    int elementosOrdenados = 0;
    int tamanho = mTamanho;
    int desemp = 0;
    cout << "Ordenando..." << endl;
    while(elementosOrdenados < tamanho){
        if (elementosOrdenados == 0){
            maior = desempilhar();
            for(int i=0; i<tamanho-(elementosOrdenados+1); i++){
                elementoCompara = desempilhar();
                if(maior > elementoCompara){
                    Aux.empilhar(elementoCompara);
                }
                else{
                    Aux.empilhar(maior);
                    maior = elementoCompara;
                }
            }            
        }
        else 
        { //Proximas comparações desempilham de aux e armazenam os elementos ordenados na pilha original
            maior = Aux.desempilhar();
            for(int i=0; i<tamanho-(elementosOrdenados+1); i++){
                elementoCompara = Aux.desempilhar();
                if(maior > elementoCompara){
                    empilhar(elementoCompara);
                }
                else{
                    empilhar(maior);
                    maior = elementoCompara;
                }
            }
            for(int i=0; i<tamanho-(elementosOrdenados+1); i++){
                //Desempilha os elementos desordenados de A em aux para a proxima comparação
                desemp = desempilhar();
                Aux.empilhar(desemp);
            }          
        }
        empilhar(maior);
        elementosOrdenados ++;
    }
}

int main()
{
    int dado;
    Pilha pilha;
    int tamPilha;

    cout << "Insira o tamanho da pilha: ";
    cin >> tamPilha;
    cout << endl;

    for (int i = 0; i < tamPilha; i++)
    {
        cout << "Insira o " << i + 1 << "o dado da pilha: ";
        cin >> dado;
        cout << endl;
        pilha.empilhar(dado);
    }

    pilha.ordena();
    cout << endl
         << "Pilha ordenada:" << endl;
    for (int i = 0; i < tamPilha; i++)
        cout << pilha.desempilhar() << endl;

    return 0;
}