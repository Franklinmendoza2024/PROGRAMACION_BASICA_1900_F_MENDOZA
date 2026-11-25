#include <iostream>
using namespace std;

int main() {

    // Declaramos un arreglo con 5 números enteros.
    int numeros[] = {33, 11, 55, 22, 44};

    // Declaramos las variables que utilizaremos.
    int i, j, aux;

    // MÉTODO DE ORDENAMIENTO BURBUJA.

    // Este ciclo controla las pasadas que realizará el algoritmo.
    // Como tenemos 5 elementos, realizaremos 5 pasadas.
    for(i = 0; i < 5; i++) {

        // Este ciclo recorre el arreglo y compara los números vecinos.
        // j < 4 evita acceder a una posición fuera del arreglo.
        for(j = 0; j < 4; j++) {

            // Comparamos el elemento actual con el siguiente.
            // Si el actual es mayor, debemos intercambiarlos.
            if(numeros[j] > numeros[j + 1]) {

                // Guardamos temporalmente el número actual.
                aux = numeros[j];

                // Colocamos el número siguiente en la posición actual.
                numeros[j] = numeros[j + 1];

                // Colocamos el número guardado en la posición siguiente.
                // Así completamos el intercambio.
                numeros[j + 1] = aux;
            }
        }
    }

    // MOSTRAR LOS NÚMEROS EN ORDEN ASCENDENTE.

    cout << "Orden ascendente: ";

    // Recorremos el arreglo desde la posición 0 hasta la 4.
    for(i = 0; i < 5; i++) {

        // Mostramos cada elemento del arreglo.
        cout << numeros[i] << " ";
    }

    // MOSTRAR LOS NÚMEROS EN ORDEN DESCENDENTE.

    cout << "\nOrden descendente: ";

    // Recorremos el arreglo desde la última posición hasta la primera.
    for(i = 4; i >= 0; i--) {

        // Mostramos los elementos en orden inverso.
        cout << numeros[i] << " ";
    }

    return 0;
}