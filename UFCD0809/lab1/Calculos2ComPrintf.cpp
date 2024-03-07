#include <iostream>
#include <cmath>

using namespace std;

int main(){
double num1, num2;

cout.precision(3);
cout.setf(ios_base::fixed);

cout << "    Introduza o valor 1: ";
cin >> num1;
cout << "    Introduza o valor 2: ";
cin >> num2;
// cout << "    Dobro da soma                            : " << (num1 + num2) * 2 << endl;
// cout << "    Triplo da soma do quadrado:              : " << ((pow(num1, 2)) + (pow(num2, 2))) * 3 << endl;
// cout << "    Soma dos cubos com multiplicacao por 2.5 : " << ((pow((2.5 * num1), 3)) + (pow((2.5 * num2), 3))) << endl;

printf("    Dobro da soma                            : %0.3lf\n", (num1 + num2) * 2);
printf("    Triplo da soma do quadrado:              : %0.3lf\n", ((pow(num1, 2)) + (pow(num2, 2))) * 3);
printf("    Soma dos cubos com multiplicacao por 2.5 : %0.3lf\n", ((pow((2.5 * num1), 3)) + (pow((2.5 * num2), 3))));
}