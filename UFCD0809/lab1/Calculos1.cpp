#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double num;

    cout.precision(3); //quantos algarismos
    cout.setf(ios_base::fixed); //à direita do '.' - casas decimais.

    cout << "Introduza o valor: ";
    cin >> num;
    cout << "Dobro: " << num * 2 << endl;
    cout << "Triplo: " << num * 3 << endl;
    cout << "Quadrado: " << pow(num, 2) << endl;
    cout << "Cubo: " << pow(num, 3) << endl;
    num = 2.5 * num + 10;
    cout << "2.5 x X + 10 = " << num;
}