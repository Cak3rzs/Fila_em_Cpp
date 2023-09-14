#include <iostream>
#include <string>
using namespace std;

#define MAX_FILA 5

struct DADOS_ALUNO {
    int codaluno;
    string nome;
    char turma;
    bool removido;
};

bool enfileirar(DADOS_ALUNO fila[], int codaluno, const string& nome, char turma, int& fimfila, int& totalfila);
bool exibir(DADOS_ALUNO fila[], int inifila, int fimfila, int totalfila);
bool desenfileirar(DADOS_ALUNO fila[], int& inifila, int& totalfila);

int main() {
    DADOS_ALUNO filaaluno[MAX_FILA];
    int inifila = 0;
    int totalfila = 0;
    int fimfila = 0;
    bool ret;
    int codaluno;
    int opcao;
    string nome;
    char turma;

    do {
        cout << "\n1 - enfileirar";
        cout << "\n2 - exibir";
        cout << "\n3 - desenfileirar";
        cout << "\n4 - sair";
        cout << "\nDigite a opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Insercao" << endl;
                cout << "Digite o codigo do aluno: ";
                cin >> codaluno;
                cout << "Digite o nome do aluno: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite a turma do aluno (A ou B): ";
                cin >> turma;
                ret = enfileirar(filaaluno, codaluno, nome, turma, fimfila, totalfila);
                if (ret == true) {
                    cout << "\nInsercao feita com sucesso!" << endl;
                }
                system("cls");
                break;

            case 2:
                ret = exibir(filaaluno, inifila, fimfila, totalfila);
                if (ret == false) {
                    cout << "\nNao foi possivel exibir a fila" << endl;
                }
                break;

            case 3:
                ret = desenfileirar(filaaluno, inifila, totalfila);
                if (ret == false) {
                    cout << "\nNao foi possivel desenfileirar a fila" << endl;
                }
                break;

            case 4:
                cout << "Saindo do programa!";
                break;

            default:
                cout << "\nERRO: A opção digitada não é válida. Tente novamente..." << endl;
        }
    } while (opcao != 4);

    return 0;
}

bool enfileirar(DADOS_ALUNO fila[], int codaluno, const string& nome, char turma, int& fimfila, int& totalfila) {
    if (totalfila == MAX_FILA) {
        cout << "\nA fila esta cheia." << endl;
        return false;
    }

    fila[fimfila].codaluno = codaluno;
    fila[fimfila].nome = nome;
    fila[fimfila].turma = turma;
    fila[fimfila].removido = false;

    fimfila = (fimfila + 1) % MAX_FILA; // Circular
    totalfila++;

    return true;
}

bool exibir(DADOS_ALUNO fila[], int inifila, int fimfila, int totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila esta vazia." << endl;
        return false;
    }

    int index = inifila;
    for (int i = 0; i < totalfila; i++) {
        if (!fila[index].removido) {
            cout << "Codigo: " << fila[index].codaluno << ", Nome: " << fila[index].nome << ", Turma: " << fila[index].turma << endl;
        }
        index = (index + 1) % MAX_FILA;
    }

    return true;
}

bool desenfileirar(DADOS_ALUNO fila[], int& inifila, int& totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila esta vazia." << endl;
        return false;
    }

    fila[inifila].removido = true;
    inifila = (inifila + 1) % MAX_FILA; // Circular
    totalfila--;

    return true;
}
