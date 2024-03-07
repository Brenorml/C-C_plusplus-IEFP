#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

int main(){
    list<int> lista = {1, 2, 3, 4, 5, 6};
    set<int> lista2;
    cout << lista.front() << endl;
    cout << lista.back() << endl;

    lista.push_front(100);
    lista.push_back(200);
    for(const int n : lista){
        cout << n << " ";
    }
    cout << endl;
    lista.pop_front();
    lista.pop_back();
    
    for(const int n : lista){
        cout << n << " ";
    }
    cout << endl;
    lista2.insert(100);
    lista2.insert(200);
    lista2.insert(300);

    for(const int n : lista2){
        cout << n << " ";
    }
    cout << endl;
    cout << lista.size() << endl;    
    return 0;
}