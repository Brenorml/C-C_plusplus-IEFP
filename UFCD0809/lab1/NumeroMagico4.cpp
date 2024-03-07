#include <iostream>
#include <ctime>


using namespace std;

int main(){

    int num = 0;    
    srand(time(nullptr));
    const int numMagica = rand() % 20 + 1;
    const int numMagic = 20;
    
    while(num != numMagic){
        cout << "Advinhe o número mágico: ";
        cin >> num;        
        if(num == numMagic){
            cout << "Parabéns, advinhou!" << endl;
            break;
        }            
        else if(num - 3 == numMagic || num + 3 == numMagic || num - 2 == numMagic || num + 2 == numMagic)
            cout << "Está próximo..." << endl;
        else if(num - 1 == numMagic || num + 1 == numMagic) 
            cout << "Está muito próximo..." << endl;
        else
            cout << "O número " << num << " não é o número mágico" << endl;
        cout << "Tente novamente..." << endl;
    }
}