#include <iostream>
#include <string>

using namespace std;

int main() {
    int idade;
    string nome, apelido;

    cout << "Qual o seu primeiro nome? ";
    cin >> nome;
    cout << "Qual o seu apelido? ";
    cin >> apelido;
    cout << "Qual a sua idade? ";
    cin >> idade;
    cout << "Bom dia, Sr(a). " << apelido << ", " << nome << "." << endl;
    cout << "Sua idade é " << idade << " anos.\n";
}