#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Funcion para validar que el nombre solo tenga letras y espacios sin <cctype>
bool nombreValido(string nombre) {
    bool tieneLetra = false;

    for (char caracter : nombre) {
        if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) {
            tieneLetra = true;
        } else if (caracter != ' ') {
            return false;
        }
    }

    return tieneLetra;
}

// Funcion para convertir minuscula a mayuscula sin <cctype>
char aMayuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Funcion para limpiar caracteres restantes en cin sin usar <limits>
void limpiarEntrada() {
    char c;
    while (cin.get(c) && c != '\n') {
        // Descarta caracteres hasta el salto de linea
    }
}

// Funcion para obtener la observacion segun el puntaje (base 100 o nota final)
string obtenerObservacion(double puntaje) {
    if (puntaje >= 65.0) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

int main() {
    int cantidad = 4; // Puedes cambiar este numero segun los estudiantes a registrar

    vector<string> nombreEstudiante(cantidad);
    vector<long long> numeroCuentaEstudiante(cantidad);
    vector<int> edadEstudiante(cantidad);
    vector<char> sexoEstudiante(cantidad);
    vector<string> carreraEstudiante(cantidad);

    vector<double> nota1(cantidad);
    vector<double> nota2(cantidad);
    vector<double> nota3(cantidad);

    vector<double> pond1(cantidad);
    vector<double> pond2(cantidad);
    vector<double> pond3(cantidad);

    vector<string> observacion1(cantidad);
    vector<string> observacion2(cantidad);
    vector<string> observacion3(cantidad);

    vector<double> notaFinal(cantidad);
    vector<string> ponderacionFinal(cantidad);

    for (int i = 0; i < cantidad; i++) {
        cout << "\n============================================\n";
        cout << "Registro del estudiante " << i + 1 << endl;
        cout << "============================================\n";

        cout << "Ingrese el nombre del estudiante: ";
        getline(cin, nombreEstudiante[i]);

        while (!nombreValido(nombreEstudiante[i])) {
            cout << "Error: ingrese un nombre valido (solo letras y espacios).\n";
            cout << "Ingrese nuevamente el nombre: ";
            getline(cin, nombreEstudiante[i]);
        }

        cout << "Ingrese el numero de cuenta: ";
        cin >> numeroCuentaEstudiante[i];

        cout << "Ingrese la edad: ";
        cin >> edadEstudiante[i];

        cout << "Ingrese el sexo (M/F): ";
        cin >> sexoEstudiante[i];
        sexoEstudiante[i] = aMayuscula(sexoEstudiante[i]);

        limpiarEntrada();
        cout << "Ingrese la carrera: ";
        getline(cin, carreraEstudiante[i]);

        cout << "Ingrese la nota 1 (base 100, vale 25%): ";
        cin >> nota1[i];

        cout << "Ingrese la nota 2 (base 100, vale 35%): ";
        cin >> nota2[i];

        cout << "Ingrese la nota 3 (base 100, vale 40%): ";
        cin >> nota3[i];

        limpiarEntrada();

        // Ponderacion de cada parcial
        pond1[i] = nota1[i] * 0.25;
        pond2[i] = nota2[i] * 0.35;
        pond3[i] = nota3[i] * 0.40;

        // Observacion por cada parcial (mayor o igual a 65 -> Aprobado, menor -> Reprobado)
        observacion1[i] = obtenerObservacion(nota1[i]);
        observacion2[i] = obtenerObservacion(nota2[i]);
        observacion3[i] = obtenerObservacion(nota3[i]);

        // Nota final y ponderacion general
        notaFinal[i] = pond1[i] + pond2[i] + pond3[i];
        ponderacionFinal[i] = obtenerObservacion(notaFinal[i]);
    }

    cout << "\n============================================\n";
    cout << "           RESULTADOS DEL PERIODO\n";
    cout << "============================================\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "Nombre: " << nombreEstudiante[i] << endl;
        cout << "Numero de cuenta: " << numeroCuentaEstudiante[i] << endl;
        cout << "Edad: " << edadEstudiante[i] << endl;
        cout << "Sexo: " << sexoEstudiante[i] << endl;
        cout << "Carrera: " << carreraEstudiante[i] << endl;

        cout << "Nota 1: " << nota1[i]
             << " | Ponderada (25%): " << pond1[i]
             << " | Observacion 1: " << observacion1[i] << endl;

        cout << "Nota 2: " << nota2[i]
             << " | Ponderada (35%): " << pond2[i]
             << " | Observacion 2: " << observacion2[i] << endl;

        cout << "Nota 3: " << nota3[i]
             << " | Ponderada (40%): " << pond3[i]
             << " | Observacion 3: " << observacion3[i] << endl;

        cout << "Nota final: " << notaFinal[i] << endl;
        cout << "Ponderacion: " << ponderacionFinal[i] << endl;
        cout << "--------------------------------------------\n";
    }

    return 0;
}