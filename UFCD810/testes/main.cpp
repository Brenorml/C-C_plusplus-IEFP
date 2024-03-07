#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define MAX 20

using namespace std;

//Estrutura para representação do item
typedef struct {
    int id = 0;
    string description = "";
    int quant = 0;
    float price = 0.00;
    float total = 0.00;
} Itens;

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
void ExtractAndAddToArray(const string& line, Itens* newItem) {
    istringstream iss(line); //Utilizada a classe isstringstream para tratar os dados da string line como fluxo de entrada sendo iss o objeto da classe que lerá os dados em line
    string token;
    int index = 0;
    while (getline(iss, token, '|')) { //Tokenização para fazer o split das linhas
        size_t start = token.find_first_not_of(" \t\r\n"); //Processamento dos tokens para remoção de espaços em branco no início
        size_t end = token.find_last_not_of(" \t\r\n"); //Processamento dos tokens para remoção de espaços em branco no final
        if (start != string::npos && end != string::npos) { //Verifica se o token apresenta algum caractere na string
            switch (index) {
                case 0:
                    newItem->id = stoi(token);
                    break;
                case 1:
                    newItem->description = token;
                    break;
                case 2:
                    newItem->quant = stoi(token);
                    break;
                case 3:
                    newItem->price = stof(token);
                    break;
            }
            ++index;
        }
    }
    newItem->total = newItem->price * newItem->quant; //Como se trata de um procedimento para tratar os dados foi trabalhado o ponteiro para a variavel newItem do tipo Item
}

// Criar uma lista de itens a partir de um arquivo
int CreateList(Itens* itensArray, const string strName) {
    ifstream content(strName);
    int lineCount = 0;
    string line;

    if (content.is_open()) {
        getline(content, line);  // Ignora a primeira linha (cabeçalho)
        while (getline(content, line)) {
            if (!line.empty() && line.find_first_not_of(" \t\v\r\n") != string::npos) {
                ExtractAndAddToArray(line, &itensArray[lineCount]);
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
int MenuFile(Itens* itensArray, string& strName, int& countLine) {

    //Gerar ficheiro de nome de entrada
    cout << "Digite o nome do ficheiro: ";
    getline(cin, strName);
    strName += ".txt"; //Adicionar extensão de ficheiro

    if (VerifyFile(strName)) {
        cout << "Ficheiro ja existente..." << endl;
        countLine = CreateList(itensArray, strName);
    } else {
        cout << "Novo ficheiro criado com sucesso!" << endl;
    }
    return 1;
}

// Inserir um novo item na lista
void InsertItem(const string strName, int id, Itens* itensArray) {
    Itens newItem;

    cout << "Digite o nome do item: ";
    getline(cin, newItem.description);

    cout << "Digite a quantidade: ";
    cin >> newItem.quant;

    cout << "Digite o preco: ";
    cin >> newItem.price;

    newItem.total = newItem.price * newItem.quant;

    newItem.id = id + 1; // Definir o ID do novo item

    itensArray[id] = newItem;

    if(itensArray[id].id != 0)
        cout << "Item inserido com sucesso!" << endl;
    else
        cout << "Falha ao inserir o item!" << endl;
}

// Imprimir a lista de itens
void PrintList(Itens* itensArray, int countLine){
    //Imprimir cabeçalho
    cout << setw(10) << left << "Item"
         << '|' << setw(25) << left << "Descricao"
         << '|' << setw(20) << left << "Quantidade"
         << '|' << setw(10) << left << "Preco"
         << '|' << setw(10) << left << "Total"
         << '|' << endl << "--------------------------------------------------------------------------------" << endl;
    // Imprimir cada item
    for (int i = 0; i < countLine; ++i) {
        cout << setw(10) << left << itensArray[i].id
             << '|' << setw(25) << left << itensArray[i].description
             << '|' << setw(20) << left << itensArray[i].quant
             << '|' << setw(10) << left << itensArray[i].price
             << '|' << setw(10) << left << itensArray[i].total
             << '|' << endl << "--------------------------------------------------------------------------------" << endl;
    }
}

// Apagar um item da lista
bool DeleteItem(Itens* itensArray, int& countLine, int idToDelete) {
    // Verificar se o ID a ser excluído é válido
    if (idToDelete <= 0 || idToDelete > countLine) {
        cout << "ID invalido!" << endl;
        return false;
    }

    // Deslocar os itens no array para preencher a lacuna deixada pelo item excluído
    for (int i = idToDelete - 1; i < countLine - 1; ++i) {
        itensArray[i] = itensArray[i + 1];
        // Atualizar o ID do item após a exclusão
        itensArray[i].id = i + 1;
    }

    // Zerar o último item no array
    itensArray[countLine - 1].id = 0;

    // Decrementar o número total de itens
    --countLine;

    return true;
}

// Editar um item da lista
bool EditItem(Itens* itensArray, int countLine, int idToEdit) {
    // Verificar se o ID a ser editado é válido
    if (idToEdit <= 0 || idToEdit > countLine) {
        cout << "ID invalido!" << endl;
        return false;
    }

    // Encontrar o índice do item no array
    for(int i = 0; i < countLine; i++){
        if(itensArray[i].id == idToEdit){
            cout << "Digite o novo nome do item: ";
            getline(cin, itensArray[i].description);

            cout << "Digite a nova quantidade: ";
            cin >> itensArray[i].quant;

            cout << "Digite o novo preco: ";
            cin >> itensArray[i].price;

            // Atualizar o total após a edição
            itensArray[i].total = itensArray[i].price * itensArray[i].quant;
        }
    }
    return true;
}

// Escrever a lista de itens em um arquivo
bool WriteFile(Itens* itensArray, int countLine, const string strName){
    ofstream content(strName, ios::trunc); // Abrir o arquivo para escrita (e truncá-lo para limpar seu conteúdo anterior)
    content << fixed << setprecision(2); // Definir a precisão dos números float

    if (content.is_open()) {
        // Escrever o cabeçalho
        content << setw(10) << left << "Item"
         << '|' << setw(25) << left << "Descricao"
         << '|' << setw(20) << left << "Quantidade"
         << '|' << setw(10) << left << "Preco"
         << '|' << setw(10) << left << "Total"
         << '|' << endl;
        // Escrever cada item no arquivo
        for(int i = 0; i < countLine; i++){
            content << setw(10) << left << itensArray[i].id
                << '|' << setw(25) << left << itensArray[i].description
                << '|' << setw(20) << left << itensArray[i].quant
                << '|' << setw(10) << left << itensArray[i].price
                << '|' << setw(10) << left << itensArray[i].total
                << '|' << endl;
        }
        content.close();
        return true;
    } else {
        cerr << "Erro ao abrir o arquivo." << endl;
        return false;
    }
}

// Escrever a lista de itens em um arquivo CSV
bool WriteCSV(Itens* itensArray, int countLine, const string strName) {
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
    csvFile << "Item,Descricao,Quantidade,Preco,Total" << endl;

    // Escrever cada item no formato CSV
    for (int i = 0; i < countLine; ++i) {
        csvFile << itensArray[i].id << ","
                << "\"" << itensArray[i].description << "\","
                << itensArray[i].quant << ","
                << fixed << setprecision(2) << itensArray[i].price << ","
                << fixed << setprecision(2) << itensArray[i].total << endl;
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
    Itens itensArray[MAX];
    int option, opening = 0;

    do {
        cout << "\n\n\t1 - Inserir\n\t2 - Listar\n\t3 - Apagar\n\t4 - Editar\n\t5 - Gravar\n\t6 - Ler\n\t7 - Tabela Excel\n\t0 - Sair\n\nEscolha uma opcao: ";
        cin >> option;
        cin.ignore();  // Limpar buffer

        switch (option) {
            case 0:
                break;
            case 1:
                if(opening){
                    if(countLine += InsertItem(strName, countLine, itensArray) == 1)
                }

                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 2:
                if(opening)
                    PrintList(itensArray, countLine);
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 3:
                if(opening){
                    int idToDelete;
                    cout << "Digite o ID do item a ser apagado: ";
                    cin >> idToDelete;
                    cin.ignore();
                    if (DeleteItem(itensArray, countLine, idToDelete)) {
                        cout << "Item apagado com sucesso!" << endl;
                    } else {
                        cout << "Falha ao apagar o item." << endl;
                    }
                }
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 4:
                if(opening){
                    int idToEdit;
                    cout << "Digite o ID do item a ser editado: ";
                    cin >> idToEdit;
                    cin.ignore();
                    if(EditItem(itensArray, countLine, idToEdit)){
                        cout << "Item editado com sucesso!" << endl;
                    }
                    else
                        cout << "Falha ao editar o item." << endl;
                }
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 5:
                if(opening){
                    if(WriteFile(itensArray, countLine, strName))
                        cout << "Ficheiro guardado com sucesso." << endl;
                }
                else
                    cout << "Nenhum ficheiro foi aberto." << endl;
                break;
            case 6:
                opening = MenuFile(itensArray, strName, countLine);
                break;
            case 7:
                if(opening)
                    if(WriteCSV(itensArray, countLine, strName))

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
