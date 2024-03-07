#include <iostream>
#include <string>

using namespace std;

int main() {
    // auto primNome = "Alberto"s;
    // auto apelido = "Alves"s;
    // cout << primNome << " " << apelido << endl;
    // cout << (primNome + " " + apelido) << endl;
    // auto nomeCompleto = apelido + ',' + primNome;
    // cout << nomeCompleto << endl;

    // string str1 = "ABC", str2 = "XYZ";
    // cout << (str1 + ',' + str2) << endl;
    // string str = str1;
    // str1 = str2;
    // str2 = str;
    // cout << (str1 + ',' + str2) << endl;

    // int b = 20; auto c = 10;
    // cout << b/c << ',' << ",";
    // b = b + 1; c = c - 3;
    // cout << b/c << "\nFim!\n";

    double x = 2.37;
    int y = 70;
    printf("%f", x);
    printf("%9d", y);
    printf("%.1f + %d = %.3f", x, y, x + y);
    printf("X:%5.2f\nY:%5d\n", x, y);
    return 0;
}