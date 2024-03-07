#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

#define DIM 5

using namespace std;

int main()
{
//    string texto[DIM];
    char text[DIM];

    cout << "Digite um palavra: ";
    cin >> text;
//    for(int i = 0; i < DIM; i++)
//        getline(cin, texto[i]);



    ofstream ficheiro("exemplo1.txt");
    if(ficheiro.is_open()){
        ficheiro << text;
        ficheiro.close();
    }
    else{
        cout << "Não foi possível abrir o ficheiro para esxcrita\n";
    }

    char option = 'n';
    cout << "Deseja abrir o ficheiro? (s/n)";
    cin >> option;

    while(tolower(option) != 's' && tolower(option) != 'n'){
        cout << "Opcao invalida! Escolha 's' para sim ou 'n' para sair...";
        cin >> option;
    }
    if(option == 's'){
        fstream ficheiro("exemplo1.txt", ios::in);

        if(ficheiro.is_open()){
            string linha;
            while(getline(ficheiro, linha)){
                cout << linha << endl;
            }
            ficheiro.close();
        }
        else{
            cout << "Não foi possível abrir o ficheiro para leitura.\n";
        }
    }
    else{
        cout << "Aplicacao sera encerrada.\nAdeus...";
    }

    return 0;
}
