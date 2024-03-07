#include <iostream>
#include <list>
#include <string>
#include <cstring>

#define prateleiras 5
#define livros 30

using namespace std;

typedef struct
{
    string titulo = "";
    string autor = "";
    int ano = 0;
} Livro;

void MostrarLista(Livro listaLivros[prateleiras][livros]){
    fflush(stdin);
    int conta = 0;
    //Corre o vetor de vetores para verificar se existem elementos inseridos
    for (int i = 0; i < prateleiras; i++){
        for (int j = 0; j < livros; j++){            
            if(listaLivros[i][j].titulo != "" || listaLivros[i][j].autor != "" || listaLivros[i][j].ano != 0)
                conta++;
        }        
    }
    if(conta == 0)
        cout << "Nao existem elementos na lista." << endl << endl;
    else{        
        for (int i = 0; i < prateleiras; i++){
            conta = 0;
            for (int j = 0; j < livros; j++){
                if(listaLivros[i][j].titulo != "" || listaLivros[i][j].autor != "" || listaLivros[i][j].ano != 0) {
                    cout << "Localizacao: Prateleira " << i + 1 << " Posicao " << j + 1 << endl;
                    cout << "Titulo: " << listaLivros[i][j].titulo << endl;
                    cout << "Autor: " << listaLivros[i][j].autor << endl;
                    cout << "Ano: " << listaLivros[i][j].ano << endl;
                    cout << endl;
                    conta++;
                }
            }
            if(conta)
                cout << "Fim da Prateleira " << i + 1 << "..." << endl;
            else
                cout << "Prateleira " << i + 1 << " esta vazia..." << endl;
            cout << endl;
        }
    }    
}

void InserirLivro(Livro listaLivros[prateleiras][livros]){
    fflush(stdin);
    char continuar = 's';
    int posPrateleira = 0, posLivro = 0; 
    //Isnserção de livros até o utulizador conforme decisão do utilizador   
    while(continuar == 's')
    {
        cout << "Escolha uma prateleira de 1 a 5:  ";
        while(!(cin >> posPrateleira)){
            cout << "Opcao invalida!!!Digite novamente a prateleira de 1 a 5...." << endl << endl;
            cin.clear();
            fflush(stdin);
        }
        posPrateleira--;
        fflush(stdin);
        cout << "Escolha uma posicao para o livro de 1 a 30: ";
        while(!(cin >> posLivro)){
            cout << "Opcao invalida!!!Digite novamente a posicao para o livro de 1 a 30...." << endl << endl;
            cin.clear();
            fflush(stdin);
        }   
        posLivro--;
        fflush(stdin);
        //cout << "prateleira: " << posPrateleira << " posicao: " << posLivro << endl; //impressão de verificação.
        //Verificação de posição existente no array
        if(posLivro < 0 || posLivro > 30 || posPrateleira < 0 || posPrateleira > 4){
            cout << endl << "Prateleira ou posicao do livro invalidos!!!" << endl << endl;
        }
        else{
            //Verificação se a posição está livre
            if(listaLivros[posPrateleira][posLivro].titulo == "" && listaLivros[posPrateleira][posLivro].autor == "" && listaLivros[posPrateleira][posLivro].ano == 0){
                cout << "Inserir o titulo do livro: " ;
                getline(cin, listaLivros[posPrateleira][posLivro].titulo);
                cout << "Inserir o nome do autor: " ;
                getline(cin, listaLivros[posPrateleira][posLivro].autor);
                cout << "Inserir o ano da obra: " ;
                cin >> listaLivros[posPrateleira][posLivro].ano;  //CRIAR SOLUÇÃO PARA O CASO DE INSERIR CARACTER  
                fflush(stdin);  
                cout << endl << "Livro inserido com sucesso!!!" << endl << endl;        
            }
            else{  
                cout << endl << "Posicao ja ocupada por um livro." << endl << endl;
            }
        }
        //verificação de escolha do utilizador para continuar ou não
        cout << "Deseja inserir um novo livro? (s/n) ";
        cin >> continuar;
        tolower(continuar);          
        while(continuar != 's' && continuar != 'n'){
            fflush(stdin);
            cout << "Entrada invalida escolha 's' para sim ou 'n' para nao...(s/n) ";
            cin >> continuar;  
        }
    }    
}

int PesquisarLivro(int opcao, int posicao[], Livro listaLivros[prateleiras][livros])
{
    fflush(stdin);
    string nome;
    //Estrutura generica de auxilio para as opções apagar/editar onde encontra o livro conforme o critério escolhido (coordenadas atribuidas ao vector posicao) e devolve a validação
    switch(opcao){
        case 1:
            cout << "Digite um nome: ";
            getline(cin, nome);         
            for (int i = 0; i < prateleiras; i++){
                for (int j = 0; j < livros; j++){
                    int comparaTitulo = strcmp(nome.c_str(), listaLivros[i][j].titulo.c_str());
                    int comparaAutor = strcmp(nome.c_str(), listaLivros[i][j].autor.c_str());
                    if(comparaTitulo == 0 || comparaAutor == 0){
                        posicao[0] = i;
                        posicao[1] = j;                        
                        return 1;
                    }
                }
            }
            break;
        case 2:
            cout << "Escolha uma prateleira de 1 a 5: ";
            while(!(cin >> posicao[0])){
                cout << "Opcao invalida!!!Digite novamente uma prateleira de 1 a 5...." << endl;
                cin.clear();
                fflush(stdin);
            }
            posicao[0] = posicao[0] - 1;
            fflush(stdin);
            cout << "Escolha a posicao do livro de 1 a 30: ";
            while(!(cin >> posicao[1])){
                cout << "Opcao invalida!!!Digite novamente a posicao do livro de 1 a 30...." << endl << endl;
                cin.clear();
                fflush(stdin);
            }
            posicao[1] = posicao[1] - 1;
            fflush(stdin);
            if(posicao[1] < 0 || posicao[1] > 30 || posicao[0] < 0 || posicao[0] > 4){
                cout << endl << "Prateleira ou posicao do livro invalidos!!!" << endl << endl;
            }
            else{
            //Verificação se a posição está ocupada
                if(listaLivros[posicao[0]][posicao[1]].titulo != "" || listaLivros[posicao[0]][posicao[1]].autor != "" || listaLivros[posicao[0]][posicao[1]].ano != 0){                    
                    return 1;
                }
            }
            break;
        default:
            cout << "Entrada invalida" << endl << endl;
    }
    return 0;
}

void RemoverLivro(Livro listaLivros[prateleiras][livros]){
    fflush(stdin);
    int opcao = 0, posicao[2];
    cout << "1 - Apagar por nome" << endl;
    cout << "2 - Apagar por posicao" << endl;
    while(!(cin >> opcao)){
        cout << "Opcao invalida!!!Digite novamente...." << endl << endl;
        cin.clear();
        fflush(stdin);
    }
    fflush(stdin);
    MostrarLista(listaLivros);    
    if(opcao = PesquisarLivro(opcao, posicao, listaLivros) == 1){
        listaLivros[posicao[0]][posicao[1]].titulo = "";
        listaLivros[posicao[0]][posicao[1]].autor = "";
        listaLivros[posicao[0]][posicao[1]].ano = 0;
        cout << endl << "Livro removido com sucesso!!!" << endl << endl;
    }
    else
        cout << endl << "Livro nao encontrado." << endl << endl;
}

void EditarLivro(Livro listaLivros[prateleiras][livros]){
    fflush(stdin);
    int opcao = 0, posicao[2];;
    cout << "1 - Editar por nome" << endl;
    cout << "2 - Editar por posicao" << endl;
    while(!(cin >> opcao)){
        cout << "Opcao invalida!!!Digite novamente...." << endl << endl;
        cin.clear();
        fflush(stdin);
    }
    fflush(stdin);
    MostrarLista(listaLivros);
    if(opcao = PesquisarLivro(opcao, posicao, listaLivros) == 1){
        cout << "Digite o novo Titulo: ";
        getline(cin, listaLivros[posicao[0]][posicao[1]].titulo);
        cout << "Digite o novo nome do Autor: ";
        getline(cin, listaLivros[posicao[0]][posicao[1]].autor);
        cout << "Digite o novo Ano da obra: ";
        cin >> listaLivros[posicao[0]][posicao[1]].ano;
        cout << endl << "Livro editado com sucesso!!!" << endl << endl;
    }
    else
        cout << endl << "Livro nao encontrado." << endl << endl;
}



int menu(int opcao, Livro listaLivros[prateleiras][livros]){
    if(opcao){
        switch(opcao){
        case 1:
            MostrarLista(listaLivros);
            break;
        case 2:
            InserirLivro(listaLivros);
            break;
        case 3:
            RemoverLivro(listaLivros);
            break;
        case 4:
            EditarLivro(listaLivros);
            break;
        default:
            if(opcao > 4){
                cout << "Opcao invalida!!!" << endl;
                cout << endl << endl;                
            } 
        }
        return 1;
    }
    else{
        cout << "Aplicacao encerrada...Adeus!!!" << endl;
        cout << endl << endl; 
        return 0;
    }    
}

int main(){    
    int opcao;    
    Livro listaLivros[prateleiras][livros];    
    cout << endl;
    do{
        cout << "Escolha uma opcao: " << endl;
        cout << "1 - Listar livros" << endl;
        cout << "2 - Inserir livro" << endl;
        cout << "3 - Remover livro" << endl;
        cout << "4 - Editar livro" << endl;        
        cout << "0 - Sair" << endl;

        while(!(cin >> opcao)){
            cout << "Opcao invalida!!!Digite novamente...." << endl;
            cin.clear();
            fflush(stdin);
        }        
        cout << endl;

    } while (menu(opcao, listaLivros));
    return 0;
}