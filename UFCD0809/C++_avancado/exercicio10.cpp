#include <iostream>

using namespace std;

int fatorial(unsigned int num){
    if(num == 1 || num == 0)
        return 1;
    else
        return fatorial(num - 1) * num;
}

int main(){
    unsigned int num;

    cout << "Insira um número: ";
    cin >> num;

    if(num >= 0)
        cout << num << "! = " << fatorial(num);
    else
        cout << "Número inválido";
}