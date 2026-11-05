#include <iostream>
using namespace std;

//Ejercicio 1
// crear funcion de parametro que reciba 1 numero y devuelva verdadero o falso si es par o impar//

int main() {
    while (true) {
        int numero;
        cout << "Ingrese un numero (o 0 para salir): ";
        cin >> numero;

        if (numero == 0) {
            break; // Salir del bucle si el usuario ingresa 0
        }

        if (numero % 2 == 0) {
            cout << "El numero es par." << endl;
        } else {
            cout << "El numero es impar." << endl;
        }
    }

     
}

