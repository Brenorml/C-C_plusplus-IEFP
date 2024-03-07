#include <iostream>
#include <string>

using namespace std;

int main (){
    int array[4];

    for (int i = 0; i < sizeof(array)/sizeof(int); i++){
        cout << "Insira o valor para o indice " << (i + 1) << ": ";
        cin >> array[i];
    }
    cout << "{ ";
    for (int i = 0; i < sizeof(array)/sizeof(int); i++){
        cout << array[i] << " ";
    }
    cout << "}";
}