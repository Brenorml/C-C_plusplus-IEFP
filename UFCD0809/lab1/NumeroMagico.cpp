#include <iostream>

using namespace std;

int main(){

    int num;
    cout << "Advinhe o número mágico: ";
    cin >> num;

    if(num == 19) {
        cout << "Parabéns, advinhou!" << endl;        
    }
    else {
        cout << "O número " << num << " não é o número mágico" << endl;
    }

    return 0;
}