#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define MAX 20

using namespace std;

//Estrutura para representação do contacto
typedef struct {
    int id = 0;
    string nome = "";
    string apelido = "";
    int fone = 0;
    string email = "";

} Contactos;

// Verificar se um ficheiro existe
bool VerifyFile(const string strName) {
    ifstream content(strName);
    if (content.is_open()) {
        content.seekg(0, ios::end); //Verificação de conteúdo movendo ponteiro de leitura para o final do ficheiro
        streampos dim = content.tellg(); //Retornar ponteiro de leitura para posição atual indicando o tamanho do ficheiro em bytes
        content.close();
        return dim > 0; //Ficheiro não está vazio
    }
    return false;
}

// Extrair os dados de uma linha e adicioná-los a uma estrutura de item
void ExtractAndAddToArray(const string& line, Contactos* newItem) {
    istringstream iss(line); //Utilizada a classe isstringstream para tratar os dados da string line como fluxo de entrada sendo iss o objeto da classe que lerá os dados em line
    string token;
    int index = 0;
    while (getline(iss, token, '|')) { //Tokenização para fazer o split das linhas
        size_t start = token.find_first_not_of(" \t\r\n"); //Processamento dos tokens para remoção de espaços em branco no início
        size_t end = token.find_last_not_of(" \t\r\n"); //Processamento dos tokens para remoção de espaços em branco no final
        if (start != string::npos && end != string::npos) { //Verifica se o token apresenta algum caractere na string
            switch (index) {
                case 0:
                    newItem->id = stoi(token); //coversão do token de string para int
                    break;
                case 1:
                    newItem->nome = token;
                    break;
                case 2:
                    newItem->apelido = token;
                    break;
                case 3:
                    newItem->fone = stoi(token); //coversão do token de string para int
                    break;
                case 4:
                    newItem->email = token;
            }
            ++index;
        }
    }
}

// Criar uma lista de Contactos a partir de um arquivo
int CreateList(Contactos* ContactosArray, const string strName) {
    ifstream content(strName);
    int lineCount = 0;
    string line;

    if (content.is_open()) {
        getline(content, line);  // Ignora a primeira linha (cabeçalho)
        while (getline(content, line)) {
            if (!line.empty() && line.find_first_not_of(" \t\v\r\n") != string::npos) {
                ExtractAndAddToArray(line, &ContactosArray[lineCount]);
                ++lineCount;
            }
        }
        content.close();
    } else {
        cerr << "Erro ao abrir o arquivo." << endl;
    }

    return lineCount;
}

// Menu para abrir um arquivo
int MenuFile(Contactos* ContactosArray, string& strName, int& countLine) {

    //Gerar ficheiro de nome de entrada
    cout << "Digite o nome do ficheiro: ";
    getline(cin, strName);
    strName += ".txt"; //Adicionar extensão de ficheiro

    if (VerifyFile(strName)) {
        cout << "Ficheiro ja existente..." << endl;
        countLine = CreateList(ContactosArray, strName);
    } else {
        cout << "Novo ficheiro criado com sucesso!" << endl;
    }
    return 1;
}

// Inserir um novo item na lista
int InsertItem(const string strName, int id, Contactos* ContactosArray) {
    Contactos newItem;

    cout << "Digite o nome: ";
    getline(cin, newItem.nome);

    cout << "Digite o apelido: ";
    getline(cin, newItem.apelido);

    cout << "Digite o telefone: ";
    cin >> newItem.fone;
    cin.ignore();

    cout << "Digite o email: ";
    getline(cin, newItem.email);

    newItem.id = id + 1; // Definir o ID do novo item

    ContactosArray[id] = newItem; // adicionar novo item ao array

    if(ContactosArray[id].id != 0){
        cout << "Item inserido com sucesso!" << endl;
        return 1;
    }
    else{
        cout << "Falha ao inserir o item!" << endl;
        return 0;
    }

}

// Imprimir a lista de Contactos
void PrintList(Contactos* ContactosArray, int countLine){
    //Imprimir cabeçalho
    cout << setw(5) << left << "ID"
         << '|' << setw(10) << left << "Nome"
         << '|' << setw(15) << left << "Apelido"
         << '|' << setw(15) << left << "Telefone"
         << '|' << setw(30) << left << "Email"
         << '|' << endl << "--------------------------------------------------------------------------------" << endl;
    // Imprimir cada item
    for (int i = 0; i < countLine; ++i) {
        cout << setw(5) << left << ContactosArray[i].id
             << '|' << setw(10) << left << ContactosArray[i].nome
             << '|' << setw(15) << left << ContactosArray[i].apelido
             << '|' << setw(15) << left << ContactosArray[i].fone
             << '|' << setw(30) << left << ContactosArray[i].email
             << '|' << endl << "--------------------------------------------------------------------------------" << endl;
    }
}

// Apagar um item da lista
bool DeleteItem(Contactos* ContactosArray, int& countLine, int idToDelete) {
    // Verificar se o ID a ser excluído é válido
    if (idToDelete <= 0 || idToDelete > countLine) {
        cout << "ID invalido!" << endl;
        return false;
    }

    // Deslocar os Contactos no array para preencher a lacuna deixada pelo item excluído
    for (int i = idToDelete - 1; i < countLine - 1; ++i) {
        ContactosArray[i] = ContactosArray[i + 1];
        // Atualizar o ID do item após a exclusão
        ContactosArray[i].id = i + 1;
    }

    // Zerar o último item no array
    ContactosArray[countLine - 1].id = 0;

    // Decrementar o número total de Contactos
    --countLine;

    return true;
}

// Editar um item da lista
bool EditItem(Contactos* ContactosArray, int countLine, int idToEdit) {
    // Verificar se o ID a ser editado é válido
    if (idToEdit <= 0 || idToEdit > countLine) {
        cout << "ID invalido!" << endl;
        return false;
    }

    // Encontrar o índice do item no array
    for(int i = 0; i < countLine; i++){
        if(ContactosArray[i].id == idToEdit){
            cout << "Digite o novo nome: ";
            getline(cin, ContactosArray[i].nome);

            cout << "Digite o novo apelido: ";
            getline(cin, ContactosArray[i].apelido);

            cout << "Digite o novo telefone: ";
            cin >> ContactosArray[i].fone;
            cin.ignore();

            cout << "Digite o novo email: ";
            getline(cin, ContactosArray[i].email);
        }
    }
    return true;
}

// Escrever a lista de Contactos em um arquivo
bool WriteFile(Contactos* ContactosArray, int countLine, const string strName){
    ofstream content(strName, ios::trunc); // Abrir o arquivo para escrita (e truncá-lo para limpar seu conteúdo anterior)

    if (content.is_open()) {
        // Escrever o cabeçalho
        content << setw(5) << left << "ID"
         << '|' << setw(10) << left << "Nome"
         << '|' << setw(15) << left << "Apelido"
         << '|' << setw(15) << left << "Telefone"
         << '|' << setw(30) << left << "Email"
         << '|' << endl;
        // Escrever cada item no arquivo
        for(int i = 0; i < countLine; i++){
            content << setw(5) << left << ContactosArray[i].id
                << '|' << setw(10) << left << ContactosArray[i].nome
                << '|' << setw(15) << left << ContactosArray[i].apelido
                << '|' << setw(15) << left << ContactosArray[i].fone
                << '|' << setw(30) << left << ContactosArray[i].email
                << '|' << endl;
        }
        content.close();
        return true;
    } else {
        cerr << "Erro ao abrir o arquivo." << endl;
        return false;
    }
}

// Escrever a lista de Contactos em um arquivo CSV
bool WriteCSV(Contactos* ContactosArray, int countLine, const string strName) {
    string nomeBase;
    size_t pos = strName.find_last_of('.');
    if (pos != std::string::npos) {
        // Se a posição do ponto for encontrada, remove a extensão
        nomeBase = strName.substr(0, pos);
    } else {
        // Se não houver ponto na string, apenas imprime a string original
        cout << "Não foi encontrada nenhuma extensão na string." << endl;
    }
    ofstream csvFile(nomeBase + ".csv"); // Criar um arquivo CSV

    // Verificar se o arquivo foi aberto corretamente
    if (!csvFile.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
        return false;
    }

    // Escrever cabeçalho
    csvFile << "ID,Nome,Apelido,Telefone,Email" << endl;

    // Escrever cada item no formato CSV
    for (int i = 0; i < countLine; ++i) {
        csvFile << ContactosArray[i].id << ","
                << "\"" << ContactosArray[i].nome << "\","
                << ContactosArray[i].apelido << ","
                << ContactosArray[i].fone << ","
                << ContactosArray[i].email << endl;
    }

    // Fechar o arquivo
    csvFile.close();

    cout << "Arquivo CSV gerado com sucesso." << endl;
    return true;
}

// Menu principal
void MenuOptions() {
    int countLine = 0;
    string strName;
    Contactos ContactosArray[MAX];
    int option, opening = 0;

    do {
        cout << "\n\n\t1 - Criar Contato\n\t2 - Listar Contatos\n\t3 - Atualizar Contato\n\t4 - Apagar Contato\n\t5 - Gravar\n\t6 - Ler\n\t7 - Tabela Excel\n\t0 - Sair\n\nEscolha uma opcao: ";
        cin >> option;
        cin.ignore();  // Limpar buffer

        switch (option) {
            case 0:
                break;
            case 1:
                if(opening)
                    countLine += InsertItem(strName, countLine, ContactosArray);
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 2:
                if(opening)
                    PrintList(ContactosArray, countLine);
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 3:
                if(opening){
                    int idToEdit;
                    cout << "Digite o ID do item a ser editado: ";
                    cin >> idToEdit;
                    cin.ignore();
                    if(EditItem(ContactosArray, countLine, idToEdit)){
                        cout << "Item editado com sucesso!" << endl;
                    }
                    else
                        cout << "Falha ao editar o item." << endl;
                }
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 4:
                if(opening){
                    int idToDelete;
                    cout << "Digite o ID do item a ser apagado: ";
                    cin >> idToDelete;
                    cin.ignore();
                    if (DeleteItem(ContactosArray, countLine, idToDelete)) {
                        cout << "Item apagado com sucesso!" << endl;
                    } else {
                        cout << "Falha ao apagar o item." << endl;
                    }
                }
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 5:
                if(opening){
                    if(WriteFile(ContactosArray, countLine, strName))
                        cout << "Ficheiro guardado com sucesso." << endl;
                }
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 6:
                opening = MenuFile(ContactosArray, strName, countLine);
                break;
            case 7:
                if(opening){
                    if(WriteCSV(ContactosArray, countLine, strName))
                        cout << "Ficheiro impresso com sucesso." << endl;
                }
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            default:
                cout << "Opcao invalida!!!" << endl;
        }
    } while (option != 0);
}

int main() {
    MenuOptions();
    return 0;
}
