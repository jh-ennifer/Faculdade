/* Jhennifer Rodrigues, 14C
Enunciado 4
Uma organização não governamental (ONG) que acolhe cães e gatos abandonados tem recebido, ao longo dos anos, várias doações, de várias pessoas e instituições, que ficam sensibilizadas com o trabalho desenvolvido.
Entretanto, caso fosse necessário indicar qual instituição que mais apoiou a ONG em valores reais (maior montante recebido), seus dirigentes não teriam como fornecer essa informação. 
Dessa forma, além do registro dos animais, que armazena o nome dado ao animal, a espécie, o local e a data em que foi resgatado, eles também passaram a fazer o cadastro de seus benfeitores, armazenando o nome, o tipo (se pessoa física ou jurídica), e o valor da doação (caso a doação seja em material de limpeza, ração ou outros produtos, é registrado o valor estimado da doação).
Agora é possível cadastrar novos animais, cadastrar novas doações e procurar pelas doações feitas por um determinado benfeitor.
Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e qual o comportamento esperado (os métodos) de cada entidade. Com base nesse planejamento feito, implemente uma solução para esse problema. 
Sua implementação deve ser orientada a objetos, com a definição de cada uma das classes, utilizando as diretivas de visibilidade adequadas, os métodos que representem o comportamento de cada classe e um pequeno programa (main) que as utilize para solucionar o problema apresentado.
*/

#include <iostream>

using namespace std;

struct date
{
    int dia, mes, ano;
};

struct animal
{
    string nome;
    string especie;
    string localResgate;
    date dataResgate;
};

class benfeitor
{
    friend class ONG; //Para tornar os atributos e métodos privados acessiveis pela classe ONG

private:
    string mNome;
    string mTipoSocial;
    float *mValorDoacao; //Vetor para registrar doações
    int mQtdDoacao;
    float mTotalDoacao;

public:
    benfeitor();
    ~benfeitor();
    void cadastrarDoacoes();
    void somarDoacoes();
    void listarDoacoes();
};

benfeitor::benfeitor()
{
    mNome.clear();
    mTipoSocial.clear();
    mQtdDoacao = 0;
    mValorDoacao = new float[mQtdDoacao];
    mTotalDoacao = 0;
}

benfeitor::~benfeitor()
{
    delete[] mValorDoacao;
}

void benfeitor::cadastrarDoacoes()
{
    for (int i = 0; i < mQtdDoacao; i++)
    {
        cout << "Doacao " << i + 1 << ":" << endl;
        cin >> mValorDoacao[i];
    }
}

void benfeitor::somarDoacoes()
{
    mTotalDoacao = 0;
    for (int i = 0; i < mQtdDoacao; i++)
    {
        mTotalDoacao += mValorDoacao[i];
    }
}

void benfeitor::listarDoacoes()
{
    cout << "Doacoes de " << mNome << ":" << endl;
    for (int i = 0; i < mQtdDoacao; i++)
    {
        cout << "Doacao " << i + 1 << ": ";
        cout << mValorDoacao[i] << endl;
    }
    cout << "Total: "<< mTotalDoacao << endl;
}

class ONG
{
private:
    animal *mAnimal;
    int mQtdAnimais = 0;
    benfeitor *mBenfeitor;
    int mQtdBenfeitor = 0;
    benfeitor mMaiorBenfeitor; //Usada para armazenar o benfeitor que mais doou

public:
    ONG(int qtdAnimais, int qtdBenfeitor);
    ~ONG();
    void mostrarMaiorDoador();
    void cadastrarAnimais();
    void cadastrarBenfeitores();
    void cadastrarNovasDoacoes(string nomeDoador);
    void listarDoacoesPorNome(string nomeDoador);
};

ONG::ONG(int qtdAnimais, int qtdBenfeitor)
{
    mQtdAnimais = qtdAnimais;
    mQtdBenfeitor = qtdBenfeitor;
    mAnimal = new animal[mQtdAnimais];
    mBenfeitor = new benfeitor[mQtdBenfeitor];
}

ONG::~ONG()
{
    delete[] mAnimal;
    delete[] mBenfeitor;
}

void ONG::cadastrarAnimais()
{
    for (int i = 0; i < mQtdAnimais; i++)
    {
        cout << "Nome do animal " << i + 1 << ":" << endl;
        cin >> mAnimal[i].nome;
        cout << "Especie (cachorro ou gato):" << endl;
        cin >> mAnimal[i].especie;
        cout << "Local do resgate:" << endl;
        cin >> mAnimal[i].localResgate;
        cout << "Data do resgate (dia, mes, ano)" << endl;
        cin >> mAnimal[i].dataResgate.dia >> mAnimal[i].dataResgate.mes >> mAnimal[i].dataResgate.ano;
        cout << endl;
    }
}

void ONG::cadastrarBenfeitores()
{
    char op;
    for (int i = 0; i < mQtdBenfeitor; i++)
    {
        cout << "Nome do benfeitor " << i + 1 << ":" << endl;
        cin >> mBenfeitor[i].mNome;
        cout << "Tipo Social (Pessoa fisica ou juridica - escrever apenas 'fisica' ou 'juridica'):" << endl;
        cin >> mBenfeitor[i].mTipoSocial;
        cout << "Deseja registrar as doacoes? (s/n)" << endl;
        cin >> op;
        switch (op)
        {
        case 's':
            cout << "Quantas doacoes deseja registrar?" << endl;
            cin >> mBenfeitor[i].mQtdDoacao;
            mBenfeitor[i].mValorDoacao = new float[mBenfeitor[i].mQtdDoacao];
            mBenfeitor[i].cadastrarDoacoes();
            break;
        case 'S':
            cout << "Quantas doacoes deseja registrar?" << endl;
            cin >> mBenfeitor[i].mQtdDoacao;
            mBenfeitor[i].mValorDoacao = new float[mBenfeitor[i].mQtdDoacao];
            mBenfeitor[i].cadastrarDoacoes();
            break;
        default:
            break;
        }
        mBenfeitor[i].somarDoacoes(); //Sempre soma as doações após as inserções
        cout << endl;
    }
}

void ONG::mostrarMaiorDoador()
{
    //Pressupõe-se que nenhum doador terá o mesmo nome e caso hajam valores iguais será apresentado o primeiro
    mMaiorBenfeitor = mBenfeitor[0];
    for (int i = 0; i < mQtdBenfeitor; i++)
    {
        if (mMaiorBenfeitor.mTotalDoacao < mBenfeitor[i].mTotalDoacao)
            mMaiorBenfeitor = mBenfeitor[i];
    }
    cout << "A maior doacao, foi no valor de " << mMaiorBenfeitor.mTotalDoacao << " feita por " << mMaiorBenfeitor.mNome << endl;
}

void ONG::listarDoacoesPorNome(string nomeDoador)
{
    for (int i = 0; i < mQtdBenfeitor; i++)
    {
        if (nomeDoador == mBenfeitor[i].mNome)
            mBenfeitor[i].listarDoacoes();
    }
}

void ONG::cadastrarNovasDoacoes(string nomeDoador)
{
    for (int i = 0; i < mQtdBenfeitor; i++)
    {
        if (nomeDoador == mBenfeitor[i].mNome){
            mBenfeitor[i].mQtdDoacao++;
            mBenfeitor[i].mValorDoacao = (float *)realloc(mBenfeitor[i].mValorDoacao, mBenfeitor[i].mQtdDoacao * sizeof(float));
            int index = mBenfeitor[i].mQtdDoacao - 1;
            cout << "Digite o valor da doacao " << mBenfeitor[i].mQtdDoacao << " de " << mBenfeitor[i].mNome << ":" << endl;
            cin >> mBenfeitor[i].mValorDoacao[index];
            mBenfeitor[i].somarDoacoes(); 
        }
    }
}

int main()
{
    int qtdAnimais = 0;
    int qtdBenfeitores = 0;
    int op = 0;
    int novaOp = 0;

    string nomeDoador;
    cout << "Quantos animais deseja registrar?" << endl;
    cin >> qtdAnimais;
    cout << "Quantos benfeitores deseja registrar?" << endl;
    cin >> qtdBenfeitores;
    ONG *ong = new ONG(qtdAnimais, qtdBenfeitores);
    do
    {
        cout << endl;
        cout << "Escolha uma opcao:" << endl;
        cout << "1-Cadastrar animais" << endl;
        cout << "2-Cadastrar benfeitores" << endl;
        cout << "3-Cadastrar novas doacoes" << endl;
        cout << "4-Listar doacoes por nome" << endl;
        cout << "5-Mostrar maior doador" << endl;
        cout << "6-Sair" << endl;
        cin >> op;
        cout << endl;
        if (op == 1)
            ong->cadastrarAnimais();
        else if (op == 2)
            ong->cadastrarBenfeitores();
        else if (op == 3)
        {
            cout << "Digite o nome do doador:" << endl;
            cin >> nomeDoador;
            ong->cadastrarNovasDoacoes(nomeDoador);
        }
        else if (op == 4)
        {
            cout << "Digite o nome do doador que deseja listar:" << endl;
            cin >> nomeDoador;
            ong->listarDoacoesPorNome(nomeDoador);
        }
        else if (op == 5)
            ong->mostrarMaiorDoador();
    } while (op > 0 and op < 6);
    return 0;
}