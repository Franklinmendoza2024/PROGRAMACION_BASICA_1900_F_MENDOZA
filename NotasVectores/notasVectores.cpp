#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Vectores para almacenar los datos de hasta 15 estudiantes
vector<string> nombresEstudiantes(15);
vector<string> numeroCuentaEstudiante(15);
vector<int> edadEstudiante(15);
vector<char> sexoEstudiante(15);
vector<string> carreraEstudiante(15);

vector<float> notas1(15);
vector<float> notas2(15);
vector<float> notas3(15);

vector<float> pond1(15);
vector<float> pond2(15);
vector<float> pond3(15);

vector<string> obsParcial1(15);
vector<string> obsParcial2(15);
vector<string> obsParcial3(15);

vector<float> notasFinales(15);
vector<string> observacionEstudiante(15);

int i = 0;

char aMayuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

string evaluarEstado(float nota) {
    if (nota >= 65) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

float pedirNota(string mensaje) {
    float nota;
    cout << mensaje;
    cin >> nota;
    while (nota < 0 || nota > 100) {
        cout << "Nota fuera de rango (0-100)." << endl;
        cout << mensaje;
        cin >> nota;
    }
    return nota;
}

string elegirCarrera() {
    int opcion;
    cout << "\n--- MENU DE CARRERAS ---" << endl;
    cout << "1. Informatica Administrativa" << endl;
    cout << "2. Medicina" << endl;
    cout << "3. Trabajo Social" << endl;
    cout << "4. Derecho" << endl;
    cout << "Seleccione una opcion (1-4): ";
    cin >> opcion;

    while (opcion < 1 || opcion > 4) {
        cout << "Opcion invalida. Seleccione 1, 2, 3 o 4: ";
        cin >> opcion;
    }

    if (opcion == 1) {
        return "Informatica Administrativa";
    } else if (opcion == 2) {
        return "Medicina";
    } else if (opcion == 3) {
        return "Trabajo Social";
    } else {
        return "Derecho";
    }
}

int main() {
    char respuesta;

    cout << "=== Programa de Gestion de Estudiantes ===" << endl;

    do {
        cout << "\nEstudiante " << i + 1 << endl;

        cout << "Ingrese el nombre del estudiante: ";
        cin >> nombresEstudiantes[i];

        cout << "Ingrese el numero de cuenta del estudiante: ";
        cin >> numeroCuentaEstudiante[i];

        cout << "Ingrese la edad del estudiante: ";
        cin >> edadEstudiante[i];
        while (edadEstudiante[i] < 0 || edadEstudiante[i] > 100) {
            cout << "Edad fuera de rango" << endl;
            cout << "Ingrese la edad del estudiante: ";
            cin >> edadEstudiante[i];
        }

        cout << "Ingrese el sexo del estudiante (M/F): ";
        cin >> sexoEstudiante[i];
        sexoEstudiante[i] = aMayuscula(sexoEstudiante[i]);
        while (sexoEstudiante[i] != 'M' && sexoEstudiante[i] != 'F') {
            cout << "Ingrese M o F: ";
            cin >> sexoEstudiante[i];
            sexoEstudiante[i] = aMayuscula(sexoEstudiante[i]);
        }

        carreraEstudiante[i] = elegirCarrera();

        notas1[i] = pedirNota("Ingrese la nota del I parcial (0-100): ");
        notas2[i] = pedirNota("Ingrese la nota del II parcial (0-100): ");
        notas3[i] = pedirNota("Ingrese la nota del III parcial (0-100): ");

        // Ponderaciones por parcial
        pond1[i] = notas1[i] * 0.25;
        pond2[i] = notas2[i] * 0.35;
        pond3[i] = notas3[i] * 0.40;

        // Observaciones por parcial
        obsParcial1[i] = evaluarEstado(notas1[i]);
        obsParcial2[i] = evaluarEstado(notas2[i]);
        obsParcial3[i] = evaluarEstado(notas3[i]);

        // Nota final y observacion general
        notasFinales[i] = pond1[i] + pond2[i] + pond3[i];
        observacionEstudiante[i] = evaluarEstado(notasFinales[i]);

        cout << "La nota final del estudiante " << nombresEstudiantes[i]
             << " es: " << notasFinales[i] << " (" << observacionEstudiante[i] << ")" << endl;

        i++;

        if (i < 15) {
            cout << "Desea ingresar otro estudiante? (s/n): ";
            cin >> respuesta;
            respuesta = aMayuscula(respuesta);
        } else {
            respuesta = 'N';
        }

    } while (respuesta == 'S');

    // Resumen de estudiantes ingresados
    cout << "\n=== Resumen de Estudiantes ===" << endl;
    for (int j = 0; j < i; j++) {
        cout << "\nEstudiante " << j + 1 << endl;
        cout << "Nombre: " << nombresEstudiantes[j] << endl;
        cout << "Cuenta: " << numeroCuentaEstudiante[j] << endl;
        cout << "Edad: " << edadEstudiante[j] << endl;
        cout << "Sexo: " << sexoEstudiante[j] << endl;
        cout << "Carrera: " << carreraEstudiante[j] << endl;
        cout << "I Parcial: " << notas1[j] << " | Pond: " << pond1[j] << " | " << obsParcial1[j] << endl;
        cout << "II Parcial: " << notas2[j] << " | Pond: " << pond2[j] << " | " << obsParcial2[j] << endl;
        cout << "III Parcial: " << notas3[j] << " | Pond: " << pond3[j] << " | " << obsParcial3[j] << endl;
        cout << "Nota final: " << notasFinales[j] << " | Observacion: " << observacionEstudiante[j] << endl;
    }

    return 0;
}