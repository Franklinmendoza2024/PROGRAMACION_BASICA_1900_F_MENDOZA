#include <iostream>
#include <string>
#include <iomanip> //Permite mostrar los promedios con dos decimales mediante setprecision(2).//
#include <limits> //Permite limpiar los caracteres pendientes de la entrada//
#include <cctype> //Proporciona la función isalpha(), que ayuda a verificar si un carácter es una letra.//

using namespace std;

// Funcion para validar el nombre
bool nombreValido(string nombre) {
    bool tieneLetra = false;

    for (char caracter : nombre) {
        if (isalpha(static_cast<unsigned char>(caracter))) {
            tieneLetra = true;
        } else if (caracter != ' ') {
            return false;
        }
    }

    return tieneLetra;
}

int main() {
    string nombreEstudiante[5];
    double parcial1[5], parcial2[5], parcial3[5];
    double promedioFinal[5];
    string calificacion[5];

    // Registro de los cinco estudiantes
    for (int i = 0; i < 5; i++) {
        cout << "\nIngrese el nombre del estudiante "
             << i + 1 << ": ";

        getline(cin, nombreEstudiante[i]);

        // Validar que el nombre contenga solo letras y espacios
        while (!nombreValido(nombreEstudiante[i])) {
            cout << "Error: ingrese un nombre valido "
                 << "(solo letras y espacios).\n";
            cout << "Ingrese nuevamente el nombre: ";
            getline(cin, nombreEstudiante[i]);
        }

        cout << "Ingrese la nota del primer parcial: ";
        cin >> parcial1[i];

        cout << "Ingrese la nota del segundo parcial: ";
        cin >> parcial2[i];

        cout << "Ingrese la nota del tercer parcial: ";
        cin >> parcial3[i];

        // Calculo del promedio final
        promedioFinal[i] =
            (parcial1[i] * 0.25) +
            (parcial2[i] * 0.35) +
            (parcial3[i] * 0.40);

        // Asignar calificacion
        if (promedioFinal[i] >= 90) {
            calificacion[i] = "Sobresaliente";
        } else if (promedioFinal[i] >= 80) {
            calificacion[i] = "Notable";
        } else if (promedioFinal[i] >= 70) {
            calificacion[i] = "Aprobado";
        } else if (promedioFinal[i] >= 60) {
            calificacion[i] = "Regular";
        } else {
            calificacion[i] = "Reprobado";
        }

        // Limpiar la entrada antes del siguiente nombre
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Mostrar los resultados del periodo
    cout << "\n============================================\n";
    cout << "           RESULTADOS DEL PERIODO\n";
    cout << "============================================\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < 5; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Nombre: " << nombreEstudiante[i] << endl;
        cout << "Nota del primer parcial: "
             << parcial1[i] << endl;
        cout << "Nota del segundo parcial: "
             << parcial2[i] << endl;
        cout << "Nota del tercer parcial: "
             << parcial3[i] << endl;
        cout << "Nota promedio: "
             << promedioFinal[i] << endl;
        cout << "Calificacion: "
             << calificacion[i] << endl;
        cout << "--------------------------------------------\n";
    }

    return 0;
}
