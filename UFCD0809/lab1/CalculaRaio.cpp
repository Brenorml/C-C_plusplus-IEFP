#include <iostream>
#include <cmath>

using namespace std;

int main(){

    cout.precision(2);
    cout.setf(ios_base::fixed);

    const double pi = 3.14159265359;
    double raio, area, perimetro;
    
    cout << "Insira o valor do raio: ";
    cin >> raio;
    perimetro = 2 * pi * raio;
    area = pi * (pow(raio, 2));
 
    cout << "Perimetro: " << perimetro << endl;        
    cout << "Area: " << area << endl;   

    return 0;
}