#include <iostream>

using namespace std;

int main(){
int num, max = 0;

for (int i = 0; i < 3; i++){
    cout << "    Introduza o " << (i + 1) << " numero: ";
    cin >> num;
    if(num > max)
        max = num;
}

cout << "    Maior numero: " << (max) << endl;
}