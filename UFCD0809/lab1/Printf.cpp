#include <string>
#include <cstdio>

using namespace std;

int main() {
    // PRINTF através de exemplos:
    //
    // printf(STRING_de_FORMATAÇÃO, EXPR1, EXPR2, ...)
    //
    // STRING_de_FORMATAÇÃO: Texto com marcadores/directivas que serão
    // substituídos pelos resultados de EXPR1, EXPR2, ...
    // Deve existir um marcador por expressão (e vice-versa).

    // 1.
    printf("Alberto");
    printf("Armando\n");

    // 2.
    printf("Alberto\n");
    printf("Armando\n");

    // 3.
    // Valor1 -> 17 * 35 Valor2 -> 15 * 15
    printf("Valor1: %d Valor2: %d\n", 17 * 35, 15 * 15);
    printf("Valor1: %i Valor2: %i\n", 17 * 35, 15 * 15); 

    int x = 17 * 35, y = 15 * 15;
    printf("Valor1: %05d Valor2: %14d\n", x, y);
    printf("Valor1: %-5d Valor2: |%-14d|\n", x, y);
    printf("Valor1: %02d Valor2: %1d\n", x, y);

    // // 4.
    string txt = "ABCDEF";
    printf("Texto => |%10s|\n", txt.c_str());

    // // 5.
    double a = 7.23, b = 89.449;
    printf("Valor1: %f Valor2: %f\n", a, b);
    printf("Valor1: %.3f Valor2: %.3f\n", a, b);
    printf("Valor1: %.2f Valor2: %.2f\n", a, b);
    printf("Valor1: %.0f Valor2: %.0f\n", a, b);
    printf("Valor1: %7.2f Valor2: %7.2f\n", a, b);
    printf("Valor1: %07.2f Valor2: %07.2f\n", a, b);
    printf("Valor1: |%7.2f| Valor2: |%-7.2f|\n", a, b);
}

// PRINTF vs COUT
// int x = 17 * 35, y = 15 * 15;
// printf("Valor1: %d Valor2: %d\n", x, y);
// cout << "Valor1: " << x << " Valor2: " << y << endl;
// NOTA: o output das duas últimas instruções é igual
//
// double a = 7.23, b = 89.449;
// printf("Valor1: %f Valor2: %f\n", a, b);
// cout << "Valor1: " << a << " Valor2: " << b << endl;
// NOTA: o output das duas últimas instruções é diferente
