//Fila circular
#include <iostream>

using namespace std;

class Fila
{
private:
    int mFim;
    int mInicio;
    int *mDados;
    int mTamanho;
    int mCapacidade;

public:
    ~Fila();
    Fila(int capacidade);
    void mostraInfo();
    int desenfileira();
    void enfileira(int dado);
};

Fila::Fila(int capacidade)
{
    mFim = -1;
    mInicio = -1; //Inicio e fim apontam para fora do vetor
    mTamanho = 0;
    mCapacidade = capacidade;
    mDados = new int[mCapacidade];
}

Fila::~Fila()
{
    cout << "Destruindo..." << endl;
    delete mDados;
}

int Fila::desenfileira()
{
    if (mTamanho > 0)
    {
        int aux = mDados[mInicio];
        mTamanho--;
        if (mTamanho <= 0)
        {
            mFim = -1;
            mInicio = -1;
        }
        else
            mInicio = (mInicio + 1) % mCapacidade;
        return aux;
    }
    else
    {
        cout << "Fila vazia" << endl;
        return -1;
    }
}

void Fila::enfileira(int dado)
{
    if (mTamanho < mCapacidade)
    {
        mFim = (mFim + 1) % mCapacidade;
        mDados[mFim] = dado;
        if (mTamanho == 0)
            mInicio++;
        mTamanho++;
        cout << "Dado " << mDados[mFim] << " inserido com sucesso!" << endl;
    }
    else
        cout << "Fila cheia" << endl;
}

void Fila::mostraInfo()
{
    /*Método implementado apenas para fins didáticos, o acesso a elementos medianos de uma fila é uma
    quebra de estrutura*/
    cout << "Tamanho = " << mTamanho << " Capacidade = " << mCapacidade << " Inicio = " << mInicio << " Fim = " << mFim << endl;
    for (int i = 0; i < mTamanho; i++)
        cout << mDados[i] << " ";
    cout << endl;
}

int main()
{
    int dado, tamanho;
    int op;

    cout << "Insira o tamanho da fila: ";
    cin >> tamanho;
    cout << endl;
    Fila fila(tamanho);

    cout << endl << "1. Enfileirar;" << endl;
    cout << "2. Desenfileirar;" << endl;
    cout << "3. Exibir informacoes;" << endl;
    cout << "4. Sair;" << endl;
    cin >> op;
    cout << endl;
    do
    {
        switch (op)
        {
        case 1:
            cout << "Insira o elemento a ser enfileirado: ";
            cin >> dado;
            fila.enfileira(dado);
            break;
        case 2:
            cout << "Dado desenfileirado: " << fila.desenfileira() << endl;
            break;
        case 3:
            cout << "Informacoes da fila: " << endl;
            fila.mostraInfo();
            break;
        default:
            break;
        }
        cout << endl << "1. Enfileirar;" << endl;
        cout << "2. Desenfileirar;" << endl;
        cout << "3. Exibir informacoes;" << endl;
        cout << "4. Sair;" << endl;
        cin >> op;
        cout << endl;
    } while (op != 4);

    return 0;
}