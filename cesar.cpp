#include <iostream>
#include <string>
using namespace std;

string criptografar(string texto, int chave) {
    string resultado = "";
    
    for (int i = 0; i < texto.length(); i++) {
        char c = texto[i];
        
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + chave) % 26 + base;
        }
        
        resultado += c;
    }
    
    return resultado;
}

string descriptografar(string texto, int chave) {
    return criptografar(texto, 26 - (chave % 26));
}

int main() {
    cout << "=== CIFRA DE CÉSAR ===" << endl;
    cout << "Método: Substituição monoalfabética com deslocamento fixo" << endl << endl;
    
    string texto;
    int chave;
    int opcao;
    
    cout << "Digite o texto: ";
    cin >> texto;
    
    cout << "Digite a chave (ex: 3): ";
    cin >> chave;
    
    cout << "\nEscolha uma opção:" << endl;
    cout << "1 - Criptografar" << endl;
    cout << "2 - Descriptografar" << endl;
    cout << "Opção: ";
    cin >> opcao;
    
    cout << endl;
    
    if (opcao == 1) {
        cout << "Texto criptografado: " << criptografar(texto, chave) << endl;
    } else if (opcao == 2) {
        cout << "Texto descriptografado: " << descriptografar(texto, chave) << endl;
    } else {
        cout << "Opção inválida." << endl;
    }
    
    return 0;
}
