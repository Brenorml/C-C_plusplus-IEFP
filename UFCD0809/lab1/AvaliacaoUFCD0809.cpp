#include <iostream>
// #include <string.h>
// #include <cmath>
// #include <cctype>
// #include <vector>

using namespace std;

int main()
{
    // string letras = {'a', 'b', 'c', 'd'};
    // for (int i = letras.length() - 1; i > -1; i -= 1) {
    //     cout << letras[i] << '.';
    // }

    // auto r = 3.0 * 3;
    // cout << r;

    // auto p = 5 != 40;
    // cout << p;

    // auto ch = "ZYXWVUTSRQPONMLKJIHGFEDCBA"[26 - 9];
    // cout << ch;
    // cout << "\n";
    // auto y = 12 / 3 + 18 / 3.0 + 17 % 3 + 3 * 2;
    // cout << y;

    // double x = 1.28, z = 4;

    // std::printf("%-6.1f+%7.1f", z + 1, 2 * x);

    // string linhaTexto, linhaTexto2;
    // int contaMaior, contaDigito;
    // cout << "Escreva uma linha de texto: ";
    // //cin >> linhaTexto;
    // getline(cin, linhaTexto);

    // for (int i = 0; i < linhaTexto.length(); i++){
    //     if(linhaTexto[i] == toupper(linhaTexto[i])){
    //         contaMaior++;
    //     }
    //     else if(linhaTexto[i] != ' '){
    //         contaMaior++;
    //     }
    // }
    // //cout << contaMaior << " vogais maiusculas e " << linhaTexto.length() << " foram contabilizados.";
    // cout << contaMaior << " vogais maiusculas e " << contaMaior << " foram contabilizados.";

    // string letras = "Breno";

    // for (int i = 0; i < letras.length(); i += 1)
    // {
    //     cout << letras[i];
    //     if (i != letras.length() - 1)
    //     {
    //         cout << '.';
    //     }
    //     cout << '\n';
    // }

    // PROVA FINAL

    // auto g = "m"s + 'e';
    // cout << g << endl;
    // auto r = pow(2.0, 3);
    // cout << r << endl;
    // auto p = 5 < 40;
    // cout << p << endl;
    // auto d = 7.5 - (2 < 5 - 4);
    // cout << d << endl;
    // auto ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[26 - 18];
    // cout << ch << endl;
    // auto y = 5 / 2 + 5 / 2.0 + 5 % 2 + 5 * 2 - 1;
    // cout << y << endl;
    // auto b = vector<int>({-1, 23}).size() == 2;
    // cout << b << endl;
    // auto v = (37 % 13);
    // cout << v << endl;
    // auto m = 'C' - 'A';
    // cout << m << endl;
    // double x = 2.37, z = 4.396;
    // printf("%f-1", x);
    // cout << "\n";
    // printf("<V:%-6.3f|V:%.2f>\n", x, z);
    // for (int i = 0; i < 100; i += 1)
    // {
    //     printf("%d", i + 1);
    // }
    // int i = 33;
    // while (i < 150)
    // {
    //     cout << "Numero " << i << endl;
    //     i += 2;
    // }
    // for (int i = 33; i < 150; i += 2)
    // {
    //     cout << "Numero " << i << endl;
    // }
    // string caracteres = "ABCDEF";
    // for (char valor : caracteres)
    // {
    //     cout << valor << endl;
    // }

    // string linha = "";
    // int contaDigitos = 0;
    // int contaEspacos = 0;
    // while (getline(cin, linha))
    // {
    //     for (int i = 0; i < linha.length(); i++)
    //     {
    //         if (linha[i] >= 'a' && linha[i] <= 'z')
    //         {
    //             linha[i] -= ('a' - 'A');
    //         }
    //         else if (linha[i] >= 'A' && linha[i] <= 'Z')
    //         {
    //             linha[i] += ('a' - 'A');
    //         }
    //         else if (linha[i] >= '0' && linha[i] <= '9')
    //         {
    //             contaDigitos += 1;
    //         }
    //         else if (linha[i] == ' ')
    //         {
    //             contaEspacos += 1;
    //         }
    //     }
    //     cout << linha << endl;
    // }
    // cout << "Foram encontrados " << contaDigitos << " digitos.\n";
    // cout << "Foram encontrados " << contaEspacos << " espacos .\n";

    string linha;
    int contaEspacos;
    cout << "Escreva algo: ";
    getline(cin, linha);
    for (int i = 0; i < linha.length(); i++)
    {
        if(linha[i] == ' '){
            contaEspacos++;            
        }
        else{
            cout << linha[i];
            cout << '\n';
        }            
    }
    cout << "Foram encontrados " << contaEspacos << " espacos.\n";
    return 0;
}
