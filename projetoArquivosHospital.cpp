
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include<conio.h>
#include <string>

using namespace std;

struct cidades {
    int codigo;
    string nome;
    string UF;
    qntd_Cidades;

};

struct especialidade {
    int codigo;
    string descricao;

};

struct medicos {
    int codigo;
    string nome;
    int cod_esp;
    string endereco;
    string telefone;
    int cod_cidade;
};

struct pacientes {
    string cpf;
    string nome;
    string endereco;
   int cod_cidade;
};

struct CID {
    int codigo;
    string descricao;

};

struct medicamentos {
    int codigo;
    string descricao;
    int qntd_estoque;
    int qntd_estoqueMin;
    int qntd_estoqueMax;
    float qntd_precoUni;
         
};
struct consultas {
    string cpf;
    int cod_medico;
    int data;
    int horario;
    int cod_CID;
    int cod_medicamento;
    int qntd_medicamento;

};

void lerCidades(cidades cida[], int qntdcidade) {
    for (int x = 0; x < qntdcidade; x++) {
        cin.ignore();
        cout << "\nDigite o nome da cidade " << x + 1 << ": ";
        getline(cin, cida[x].nome);
        

        cin.ignore();
        cout << "Digite o estado (UF) da cidade " << x + 1 << ": ";
        getline(cin, cida[x].UF);
    }
};



void lerEspecialidades(especialidade  esp[], int qntdEspecialidade) {
    for (int x = 0; x < qntdEspecialidade; x++) {
        cout << "Código da Especialidade: " << x + 1 << ":";
        cin >> esp[x].codigo;
        cout << "\nDigite a especialidade do medico" << x + 1 << ":";
        cin >> esp[x].descricao;
        
    
    
    }
        
}

void lerCID(CID CID[], int qntdCID) {
    for (int x = 0; x < qntdCID; x++) {
        cout << "Código do CID: ";
        cin >> CID[x].codigo;
        cout << "\nDigite o CID" << x + 1 << ":";
        cin >> CID[x].descricao;

    }
}

void lerMedicamentos(medicamentos med[], int qntdMedicamentos){
    for (int x = 0; x < qntdMedicamentos; x++) {
        cout << "\nDigite os dados do medicamento " << x + 1 << ":\n";
        cout << "Código: ";
        cin >> med[x].codigo;
        cin.ignore(); 
        cout << "Descrição: ";
        getline(cin, med[x].descricao, 25);
        cout << "Quantidade em estoque: ";
        cin >> med[x].qntd_estoque;
        cout << "Quantidade mínima em estoque: ";
        cin >> med[x].qntd_estoqueMin;
        cout << "Quantidade máxima em estoque: ";
        cin >> med[x].qntd_estoqueMax;
        cout << "Preço unitário: ";
        cin >> med[x].qntd_precoUni;
    }
}
void lerMedicos(medicos med[], int qntdMedicos) {
    for (int x = 0; x < qntdMedicos; x++) {
        do {
            cout << "\nDigite o código do médico " << x + 1 << ": ";
            cin >> med[x].codigo;
            if (codigoExiste(med, x, med[x].codigo)) {
                cout << "Código já existe. Por favor, insira um código único.\n";
            }
        } while (codigoExiste(med, x, med[x].codigo)); 

        cout << "Digite o nome do médico " << x + 1 << ": ";
        cin.ignore(); 
        getline(cin, med[x].nome);
    }
void incluirMedico(medicos med[], int& qntdMedicos) {
    cout << "\nIncluir Novo Médico\n";
    if (qntdMedicos >= MAX_MEDICOS) {
        cout << "Não é possível adicionar mais médicos. Limite máximo atingido.\n";
        return;
    }
    cout << "Digite o código do médico: ";
    cin >> med[qntdMedicos].codigo;
    cout << "Digite o nome do médico: ";
    cin.ignore(); 
    getline(cin, med[qntdMedicos].nome);
    cout << "Digite o código da especialidade do médico: ";
    cin >> med[qntdMedicos].cod_esp;
    cout << "Digite o endereço do médico: ";
    cin.ignore(); 
    getline(cin, med[qntdMedicos].endereco);
    cout << "Digite o telefone do médico: ";
    getline(cin, med[qntdMedicos].telefone);
    cout << "Digite o código da cidade do médico: ";
    cin >> med[qntdMedicos].cod_cidade;
    qntdMedicos++;
    cout << "Novo médico incluído com sucesso!\n";
}
bool codigoExiste(const medicos med[], int qntdMedicos, int codigo) {
    for (int x = 0; x < qntdMedicos; x++) {
        if (med[x].codigo == codigo) {
            return true; 
        }
    }
    return false; 
}

void buscarEspecialidade(const especialidade espec[], int qntdEspecialidades, int codigo) {
    bool encontrou = false;
    for (int x = 0; x < qntdEspecialidades; x++) {
        if (espec[x].codigo == codigo) {
            cout << "Descrição da especialidade com código " << codigo << ": " << espec[x].descricao << endl;
            encontrou = true;
            break;
        }
    }
    if (!encontrou) {
        cout << "Especialidade com código " << codigo << " não encontrada." << endl;
    }
}
// Função para buscar uma cidade pelo código e exibir o nome e UF
void buscarCidade(const cidades cid[], int qntdCidades, int codigo) {
    bool encontrou = false;
    for (int i = 0; i < qntdCidades; i++) {
        if (cida[x].codigo == codigo) {
            cout << "Nome da cidade com código " << codigo << ": " << cida[x].nome << endl;
            cout << "UF da cidade com código " << codigo << ": " << cida[x].UF << endl;
            encontrou = true;
            break;
        }
    }
    if (!encontrou) {
        cout << "Cidade com código " << codigo << " não encontrada." << endl;
    }
}

void incluirPacientes(const )
int main() {                                      //----------------------------------------------------------------------------------------------------------------
    const int qntdCidades = 3; 
    cidades cid[qntdCidades] = {
        {1, "São Paulo", "SP"},
        {2, "Rio de Janeiro", "RJ"},
        {3, "Belo Horizonte", "MG"}
    };

    int codigoBusca;
    cout << "Digite o código da cidade: ";
    cin >> codigoBusca;

    buscarCidade(cid, qntdCidades, codigoBusca);

    return 0;
}
const int MAX_MEDICOS = 100;
    medicos med[MAX_MEDICOS];
    int qntdMedicos = 0; 
    incluirMedico(med, qntdMedicos);
    cout << "\nDados dos médicos após a inclusão:\n";
    for (int x = 0; x < qntdMedicos; x++) {
        cout << "\nMédico " << x + 1 << ":\n";
        cout << "Código: " << med[x].codigo << "\n";
        cout << "Nome: " << med[x].nome << "\n";
        cout << "Código da Especialidade: " << med[x].cod_esp << "\n";
        cout << "Endereço: " << med[x].endereco << "\n";
        cout << "Telefone: " << med[x].telefone << "\n";
        cout << "Código da Cidade: " << med[x].cod_cidade << "\n";
    }
   int qntdMedicos;

    cout << "Quantos médicos você deseja registrar? ";
    cin >> qntdMedicos;
    medicos med[qntdMedicos];
    lerMedicos(med, qntdMedicos);
    // Opcional: Exibe os dados lidos para confirmar a leitura
    cout << "\nDados dos médicos registrados:\n";
    for (int x = 0; x < qntdMedicos; x++) {
        cout << "\nMédico " << x + 1 << ":\n";
        cout << "Código: " << med[x].codigo << "\n";
        cout << "Nome: " << med[x].nome << "\n";
        const int qntdEspecialidades = 3; 
    especialidade espec[qntdEspecialidades] = {
        {1, "Cardiologia"},
        {2, "Dermatologia"},
        {3, "Pediatria"}
    };

    int codigoBusca;
    cout << "Digite o código da especialidade: ";
    cin >> codigoBusca;

    buscarEspecialidade(espec, qntdEspecialidades, codigoBusca);

     const int qntdCidades = 3; 
    cidades cid[qntdCidades] = {
        {1, "São Paulo", "SP"},
        {2, "Rio de Janeiro", "RJ"},
        {3, "Belo Horizonte", "MG"}
    };

    int codigoBusca;
    cout << "Digite o código da cidade: ";
    cin >> codigoBusca;

   void buscarCidade(cid, qntdCidades, codigoBusca);


    }
}
return 0;

































