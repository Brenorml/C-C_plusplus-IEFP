#include <iostream>
#include <string>

using namespace std;

//escreva um a função que receba por parametro 3 numeros e retorne a média dos numeros~

//float media(float n1, float n2,  float n3)
//{
//    float res;
//    res =(n1+n2+n3)/3;
//    return res;
//}
//
//int main()
//{
//float num1=10;
//float num2=11;
//float num3=10;
//    cout << "A media de  "<< num1 << " ," << num2<< " , "<< num3 <<" : " <<media(num1 , num2,num3 ) <<endl;
//return 0;
//}

//float somaarray(float listan[], int  tam)
//{
//    float soma;
//    soma=0;
//    for (int i = 0; i <= tam-1 ; i++)
//    {
//        soma += listan[i];
//    }
//
//    return soma;
//}
//
//int main()
//{
//    int tamanho=5;
//    float lista_numeros[tamanho]={17.2,15,20,17.8,7.5};
//    cout << "Soma :"<< somaarray(lista_numeros,tamanho) <<endl;
//
//
//return 0;
//}

int ParImpar(int num){
    if(num % 2 == 0)
        return 0;
    return 1;
}

int main(){
    int num;
    cout << "Digite um valor: ";
    cin >> num;

    if(!(ParImpar(num)))
        cout << num << " e par" << endl;
    else
        cout << num << " e impar" << endl;

    return 0;
}
