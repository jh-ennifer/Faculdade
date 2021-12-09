/*Apresenta o aluno destaque utilizando o método de maxHeap
As partes de minha autoria no código são:
-A sobrecarga do operador >
-A classe Heap*/

#include <iostream> // Pode usar varias coisas prontas
#include <vector>   // mas é preciso completar a classe
#include <limits>   // classe Heap. É permitido fazer
#include <string>   // alteracoes na classe Heap.
#include <stdexcept>

class Atividade
{
public:
    int nota;
    int tentativas;
};

class Aluno
{
public:
    Aluno();
    Aluno(unsigned matr, const std::string &n);
    ~Aluno();
    void InserirAtividade(const Atividade &a);
    std::string Nome() const { return nome; }
    unsigned Matricula() { return matricula; }
    float Media() const;
    int Tentativas() const;

protected:
    unsigned matricula;
    std::string nome;
    std::vector<Atividade> vetAtividades;
};

Aluno::Aluno()
    : matricula(0), nome(), vetAtividades()
{
}

Aluno::Aluno(unsigned matr, const std::string &n)
    : matricula(matr), nome(n), vetAtividades()
{
}

Aluno::~Aluno()
{
}

void Aluno::InserirAtividade(const Atividade &a)
{
    vetAtividades.push_back(a);
}

float Aluno::Media() const
{
    float soma = 0.0f;
    unsigned nroAtividades = unsigned(vetAtividades.size());
    for (unsigned i = 0; i < nroAtividades; ++i)
        soma += float(vetAtividades.at(i).nota);
    return soma / float(nroAtividades);
}

int Aluno::Tentativas() const
{
    int tentativas = 0;
    unsigned nroAtividades = unsigned(vetAtividades.size());
    for (unsigned i = 0; i < nroAtividades; ++i)
        tentativas += vetAtividades[i].tentativas;
    return tentativas;
}

bool operator>(const Aluno &a1, const Aluno &a2)
{
    bool result;

    if (a1.Media() == a2.Media())
    {
        if (a1.Tentativas() < a2.Tentativas())
        {
            result = true;
        }
        else if (a1.Tentativas() > a2.Tentativas())
        {
            result = false;
        }
        else
        {
            if (a1.Nome() < a2.Nome())
            {
                result = true;
            }
            else
            {
                result = false;
            }
        }
    }
    else if (a1.Media() < a2.Media())
        result = false;
    else
        result = true;

    return result;
}

typedef Aluno TDado;

class Heap
{
    // classe Heap (max-heap, o maior fica na raiz/inicio)
public:
    // Criar heap sem dados e com capacidade informada
    Heap(int cap);
    // Destruttor
    ~Heap();
    // Inserir um dado na heap
    void Inserir(const TDado &d);
    // Consulta a raiz
    TDado Raiz();
    // Retira e retorna a raiz
    TDado Retirar();
    // Verifica se a heap está vazia
    bool Vazia();

protected:
    void ArrumarDescendo(int i);
    void ArrumarSubindo(int i);
    inline int Direito(int i);
    inline int Esquerdo(int i);
    inline int Pai(int i);
    int mCapacidade;
    int mTamanho;
    TDado *mVetDados;
};

using namespace std;

Heap::Heap(int cap)
{
    mCapacidade = cap;
    mVetDados = new TDado[mCapacidade];
    mTamanho = 0;
}

Heap::~Heap()
{
    delete[] mVetDados;
}

void Heap::ArrumarDescendo(int i)
{
    int maior = i;
    int direita = Direito(i);
    int esquerda = Esquerdo(i);

    if ((esquerda < mTamanho) and (mVetDados[esquerda] > mVetDados[maior]))
    {
        maior = esquerda;
    }

    if ((direita < mTamanho) and (mVetDados[direita] > mVetDados[maior]))
        maior = direita;

    if (maior != i)
    {
        swap(mVetDados[i], mVetDados[maior]);
        ArrumarDescendo(maior);
    }
}

void Heap::ArrumarSubindo(int i)
{
    int pai = Pai(i);

    if (mVetDados[i] > mVetDados[pai])
    {
        swap(mVetDados[i], mVetDados[pai]);
        ArrumarSubindo(pai);
    }
}

int Heap::Pai(int i)
{
    return (i - 1) / 2;
}

int Heap::Esquerdo(int i)
{
    return 2 * i + 1;
}

int Heap::Direito(int i)
{
    return 2 * i + 2;
}

TDado Heap::Raiz()
{
    if (mTamanho == 0)
    {
        cerr << "Heap vazia nao tem raiz." << endl;
        return TDado();
    }
    return mVetDados[0];
}

TDado Heap::Retirar()
{
    if (mTamanho == 0)
    {
        cerr << "Impossivel retirar de heap vazia." << endl;
        return TDado();
    }
    TDado raiz = mVetDados[0];
    swap(mVetDados[0], mVetDados[mTamanho - 1]);
    mTamanho--;
    ArrumarDescendo(0);
    return raiz;
}

bool Heap::Vazia()
{
    if (mTamanho == 0)
        return true;
    else
        return false;
}

void Heap::Inserir(const TDado &d)
{
    if (mTamanho == mCapacidade)
    {
        cerr << "Impossivel inserir em heap cheio.\n";
        return;
    }
    mVetDados[mTamanho] = d;
    ArrumarSubindo(mTamanho);
    mTamanho++;
}

int main()
{
    unsigned qtdeAlunos;
    cin >> qtdeAlunos;
    unsigned qtdeAtividades;
    cin >> qtdeAtividades;
    Heap heap(qtdeAlunos);
    Atividade atividade;
    string nome;
    unsigned matricula;
    for (unsigned i = 0; i < qtdeAlunos; ++i)
    {
        cin >> matricula >> nome;
        Aluno aluno(matricula, nome);
        for (unsigned i = 0; i < qtdeAtividades; ++i)
        {
            cin >> atividade.nota >> atividade.tentativas;
            aluno.InserirAtividade(atividade);
        }
        heap.Inserir(aluno);
    }
    Aluno alunoDestaque(heap.Retirar());
    cout << '[' << alunoDestaque.Matricula() << "] " << alunoDestaque.Nome() << endl;
    return 0;
}
