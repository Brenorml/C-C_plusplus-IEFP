#include <iostream>
#include <string>

using namespace std;

int main() {
    // string palavra;
    
    // cout << "Introduza texto:" << endl;    
    // cin >> palavra;
    // cout << "Palavra introduzida: " << palavra << endl;
    // cout << "Primeira letra da palavra: " << palavra[0] << endl;

    auto contaPalavras = 0; // semelhante a int contaPalavras = 0
    auto contaInicVogal = 0;
    cout << "Introduza texto:" << endl;
    string palavra;
    while (cin >> palavra) {
        contaPalavras += 1;
        char ch = palavra[0];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            contaInicVogal += 1;
        }
    }
    cout << "Número de palavras: " << contaPalavras << endl;
    cout << "Número de palavras começadas por vogal: " << contaInicVogal << endl;

return 0;
}