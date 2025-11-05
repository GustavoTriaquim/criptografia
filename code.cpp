#include <iostream>
#include <string>
using namespace std;
string criptografar(string texto) {
    char letras[] =  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
    char simbolos[] = {'!',';','"','#','|','$','%','^','>','*','(',')','?',',','[',']','+','=','@','/','<',':','.','}','_','-',' '};
    string resultado = "";
    for (int i = 0; i < texto.length(); i++) {
        char c = tolower(texto[i]);
        bool encontrado = false;
        for (int j = 0; j < 27; j++) {
            if (c == letras[j]) {
                resultado += simbolos[j];
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            resultado += c;
        }
    }
    return resultado;
}

bool criptografado(string texto) {
    int letrasCount = 0;
    int simbolosCount = 0;
    for (int i = 0; i < texto.length(); i++) {
        char c = tolower(texto[i]);
        if (c >= 'a' && c <= 'z') letrasCount++;
        else if (c != ' ') simbolosCount++;
    }
    return simbolosCount > letrasCount;
}
string descriptografar(string texto) {
    char letras[] =  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
    char simbolos[] = {'!',';','"','#','|','$','%','^','>','*','(',')','?',',','[',']','+','=','@','/','<',':','.','}','_','-',' '};
    string resultado = "";

    for (int i = 0; i < texto.length(); i++) {
        char c = texto[i];
        bool encontrado = false;
        for (int j = 0; j < 27; j++) {
            if (c == simbolos[j]) {
                resultado += letras[j];
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            resultado += c;
        }
    }
    return resultado;
}
int main() {
    cout << "=== CRIPTOGRAFIA SIMÉTRICA SIMPLES ===" << endl;
    cout << "Método: Substituição letra-por-símbolo (usando vetores)" << endl << endl;
    string texto;
    cout << "Digite o texto: ";
    getline(cin, texto);
    if (criptografado(texto)) {
        cout << "\nTexto CRIPTOGRAFADO." << endl;
        cout << "Texto descriptografado: " << descriptografar(texto) << endl;
    } else {
        cout << "\nTexto DESCRIPTOGRAFADO." << endl;
        cout << "Criptografando " << texto << ": " << criptografar(texto) << endl;
    }
    return 0;
}
