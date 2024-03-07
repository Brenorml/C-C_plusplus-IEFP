#include <iostream>
#include <list>
#include <ctype.h>


using namespace std;

int main(){
    list<int> lista = {0, 1, 2, 3, 4, 5, 6};
    int option, count = 0;

    do{
        cout << "Escolha uma opção: " << endl;
        cout << "1 - Inserir elemento" << endl;
        cout << "2 - Listar lista de números" << endl;
        cout << "3 - Remover elemento" << endl;
        cout << "4 - Ordenar elemento" << endl;
        cout << "5 - Número de elementos da lista" << endl;
        cout << "6 - Limpar elementos da lista" << endl;
        cout << "0 - Sair" << endl;

        cin >> option;
        cout << endl;

        switch(option){
            case 1:
                cout << "Digite 'F' para inserir no incio da lista ou 'B' para inserir no final e prima enter..." << endl;
                cout << "(F/B)? ";
                char tipoInsercao;
                cin >> tipoInsercao;
                tipoInsercao = toupper(tipoInsercao);                
                if(tipoInsercao == 'F' || tipoInsercao == 'B'){
                    cout << "Digite o inteiro para inserção: ";
                    int valor;
                    cin >> valor;
                    if(tipoInsercao == 'F'){
                        lista.push_front(valor);
                        cout << endl;
                    }                        
                    else{
                        lista.push_back(valor);
                        cout << endl;
                    }
                    cout << "Valor inserido com sucesso!!!";
                }                    
                else{
                    cout << "Entrada inválida!" << endl;                    
                }
                cout << endl << endl;
                break;
            case 2:
                if(lista.empty()){
                    cout << "Não existem elementos na lista.";
                }
                else{
                    for(const int n : lista){
                    cout << n << " ";
                    }
                }                
                cout << endl << endl;
                break;
            case 3:
                cout << "Digite o valor que deseja remover: ";
                int valor;
                count = 0;
                cin >> valor;                
                for(int n : lista){
                    if(n == valor){
                        lista.remove(valor);
                        cout << "Elemento removido com sucesso!!!" << endl << endl;
                        count = 1;
                        break;
                    }                               
                }
                if(count == 0){
                    cout << "Elemento não encontrado!!!" ;
                    cout << endl << endl;                     
                }                
                break;
            case 4:
                lista.sort();                
                cout << "Lista ordenada com sucesso!!!" ;
                cout << endl << endl; 
                break;
            case 5:
                cout << "A lista contem " << size(lista) << " elementos.";
                cout << endl << endl; 
                break;
            case 6:
                lista.clear();
                cout << "Todos os elementos foram removidos com sucesso!!!" << endl << endl; 
                break;
            default:
                if(option > 6){
                    cout << "Opção inválida!!!" << endl;
                    cout << endl << endl; 
                } 
                else{
                    cout << "Aplicação encerrada...Adeus!!!" << endl;
                    cout << endl << endl; 
                }                  
        }            
    } while (option != 0);

    return 0;
}