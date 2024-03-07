#include <iostream>

using namespace std;

int main(){

    int hora, min, seg;

    cout << "Introduza a hora minuto segundo: ";
    cin >> hora >> min >> seg;

    hora *= 3600;
    min *= 60;

    cout << "Tempo total: " << hora + min + seg << endl;

    return 0;
}