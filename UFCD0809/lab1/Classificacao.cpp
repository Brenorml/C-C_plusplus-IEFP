#include <iostream>

using namespace std;

int main()
{
    int nota;

    while ("")
    {
        cout << "Introduza a classificação: ";
        cin >> nota;       

        if (nota <= 0 || nota > 20)
        {
            cout << "    ERROR: Classificação inválida";
            break;
        }
        cout << "Classificação entre: " << endl;

        if (nota <= 4)
            cout << "    1 - 4: Fraco" << endl;
        else if (nota <= 9)
            cout << "    5 - 9: Insuficiente" << endl;
        else if (nota <= 14)
            cout << "    10 - 14: Suficiente" << endl;
        else
            cout << "    15 - 20: Bom" << endl;
    }
}