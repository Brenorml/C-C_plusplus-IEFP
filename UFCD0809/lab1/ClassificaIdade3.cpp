#include <iostream>

using namespace std;

int main(){
int age;

cout << "    Introduza a idade: ";
cin >> age;

if(age >= 65)
    cout << "    Senior" << endl;
else if(age >= 18)
    cout << "    Maior de idade" << endl;
else
    cout << "    Menor de idade" << endl;
}