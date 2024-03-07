#include <iostream>
//#include <clocale>

using namespace std;

int soma(int a, int b){
    return a + b;
}

int main(){
    //setlocale(LC_ALL, "Portuguese");
    cout << "Olá, mundo! Adeus" << endl;
    cout << soma(2, 3) << endl;
    return 0;
}