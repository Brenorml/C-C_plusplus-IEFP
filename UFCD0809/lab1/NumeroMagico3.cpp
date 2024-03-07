#include <iostream>

using namespace std;

int main(){

    int num;
    cout << "Advinhe o número mágico: ";
    cin >> num;

    while(num != 19){
        cout << "O número " << num << " não é o número mágico" << endl;
        if(num - 3 == 19 || num + 3 == 19)
            cout << "Está próximo..." << endl;
        if(num - 1 == 19 || num + 1 == 19) 
            cout << "Está muito próximo..." << endl;
        cout << "Tente novamente e advinhe o número mágico: ";
        cin >> num;
    }
    
    cout << "Parabéns, advinhou!" << endl;

    return 0;
}