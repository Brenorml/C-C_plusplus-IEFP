#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

int main(){
    cout << "inicio" << endl;
    sleep_for(milliseconds(500));
    system("cls");
    cout << "Meio segundo depois" << endl;
}