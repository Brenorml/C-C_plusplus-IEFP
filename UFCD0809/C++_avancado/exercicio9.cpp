#include <iostream>

using namespace std;

int main(){
    int num, count, aux;

    cout << "Insira um número: ";
    cin >> num;

    if(num > 1){
        for (int i = num; i > 1; i--){
            if(num % i == 0){
                aux = i;
                count++;
            }
        }
        if(count > 1)
            cout << num << " é multiplo de " << aux << " e não é primo.";
        else
            cout << num << " é primo!";
    }
    else if(num == 1)
        cout << "1 não é primo";
    else
        cout << "0 não é primo";

    return 0;
}