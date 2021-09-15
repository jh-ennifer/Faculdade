//Pilha encadeada
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
    void empilhar(int dado);
    int desempilhar();
};

Pilha::Pilha()
{
    mTopo = NULL;
    mTamanho = 0;
}

Pilha::~Pilha()
{
    cout << "Deletando a pilha..." << endl;
    while (mTamanho > 0)
        desempilhar();
}

void Pilha::empilhar(int dado)
{
    noh *novo = new noh(dado);
    novo->mProximo = mTopo;
    mTopo = novo;
    mTamanho++;
    cout << "Dado " << mTopo->mDado << " empilhado com sucesso" << endl;
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

int main()
{
    int dado;
    Pilha pilha;
    int tamPilha;

    cout << "Insira o tamanho da pilha: ";
    cin >> tamPilha;

    //Inserção de dados na pilha
    for (int i = 0; i < tamPilha; i++)
    {
        cout << endl;
        cout << "Insira o " << i + 1 << "o dado da pilha: ";
        cin >> dado;
        pilha.empilhar(dado);
    }
    //Impressão de dados
    cout << endl
         << "Pilha criada:" << endl;
    for (int i = 0; i < tamPilha; i++)
        cout << pilha.desempilhar() << endl;

    return 0;
}