#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <algorithm> // Para a função reverse

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

// Função para exibir os caracteres individualmente
void exibirCaracteres(const string& texto, bool diagonal = false) {
    if (diagonal) {
        int espacos = 0;
        for (size_t i = 0; i < texto.length(); i++) {
            cout << string(espacos, ' ') << texto[i] << endl;
            espacos += 2; // Ajusta o número de espaços conforme necessário
            sleep_for(milliseconds(100)); // Ajuste o tempo conforme necessário
        }
    } else {
        for (char c : texto) {
            cout << c << endl;
            sleep_for(milliseconds(100)); // Ajuste o tempo conforme necessário
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " palavra1 [palavra2] ... [palavraN]" << endl;
        return 1;
    }

    string texto;
    for (int i = 1; i < argc; i++) {
        texto += argv[i];
        if (i < argc - 1) {
            texto += " "; // Adiciona espaço entre as palavras, exceto para a última palavra
        }
    }

    // Aplicar efeitos
    cout << "Efeito 1 - Diagonal Esquerda..." << endl;
    exibirCaracteres(texto, true);

    cout << "Efeito 2 - Diagonal Esquerda, Palavras Invertidas..." << endl;
    reverse(texto.begin(), texto.end());
    exibirCaracteres(texto, true);

    cout << "Efeito 3 - Diagonais Cruzadas..." << endl;
    string diagonalCruzada = texto;
    reverse(diagonalCruzada.begin(), diagonalCruzada.end());
    exibirCaracteres(texto);
    exibirCaracteres(diagonalCruzada);

    cout << "Efeito 4 - Diagonal Direita, Palavras por Ordem Inversa..." << endl;
    reverse(texto.begin(), texto.end());
    exibirCaracteres(texto, true);

    return 0;
}
