#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // Declaración de variables
    string nombreEmpleado;
    int edadEmpleado;
    char sexoEmpleado;
    double sueldoMensual;
    int tipoEmpleado;

  
    cout << "========== PILLOFON ===========" << endl;
    
    // 1. Nombre del empleado (con espacios)//
    cout << "Ingrese el nombre del empleado: ";
    getline(cin >> ws, nombreEmpleado);

    // 2. Edad del empleado (con validación de rango 18 a 65)//
    cout << "Ingrese la edad del empleado (18-65): ";
    cin >> edadEmpleado;  
    while (edadEmpleado < 18 || edadEmpleado > 65) {
        cout << "Edad fuera de rango / Edad incorrecta" << endl;
        cout << "Ingrese la edad del empleado: ";
        cin >> edadEmpleado;
    }

    // 3. Sexo del empleado (M/F)//
    cout << "Ingrese el sexo del empleado (M/F): ";
    cin >> sexoEmpleado;
    while (sexoEmpleado != 'M' && sexoEmpleado != 'm' && sexoEmpleado != 'F' && sexoEmpleado != 'f') {
        cout << "Sexo incorrecto. Ingrese M o F: ";
        cin >> sexoEmpleado;
    }

    // 4. Sueldo mensual //
    cout << "Ingrese el sueldo mensual del empleado (Min. 16000): ";
    cin >> sueldoMensual;
    while (sueldoMensual < 16000.0) {
        cout << "Sueldo incorrecto (Debe ser mayor o igual a 16,000)" << endl;
        cout << "Ingrese el sueldo mensual del empleado: ";
        cin >> sueldoMensual;
    }

    // 5. Tipo de empleado
    cout << "Ingrese el tipo de empleado:" << endl;
    cout << "1. Empleado de Planta" << endl;
    cout << "2. Empleado de Medio Tiempo" << endl;
    cout << "3. Empleado por Contrato" << endl;
    cout << "Opcion: ";
    cin >> tipoEmpleado;

    // Variables auxiliares para cálculos según el tipo
    double sueldoHora = 0, sueldoMinuto = 0, sueldoSegundo = 0;
    double sueldoQuincenal = sueldoMensual / 2;
    double totalHorasMes = 0;

    // muestra de resultados
    cout << "\n=======================================" << endl;
    cout << "      REPORTE DEL EMPLEADO PILLOFON    " << endl;
    cout << "=======================================" << endl;
    cout << "Nombre del empleado: " << nombreEmpleado << endl;
    cout << "Edad del empleado: " << edadEmpleado << endl;
    cout << "Sexo del empleado: " << sexoEmpleado << endl;
    cout << "Sueldo mensual: L. " << sueldoMensual << endl;

    // Uso de funcion switch
    switch (tipoEmpleado) {
        case 1: { // Empleado de Planta
            double horasPlantaMes = 214; // (9.5h*5*4) + (6h*4)
            sueldoHora = sueldoMensual / horasPlantaMes;
            sueldoMinuto = sueldoHora / 60;
            sueldoSegundo = sueldoHora / 3600;
            double sueldoDiarioLV = sueldoHora * 9.5;
            double sueldoSabado = sueldoHora * 6;
            double sueldoSemanalLV = sueldoDiarioLV * 5;
            double sueldoSemanalLVSab = sueldoSemanalLV + sueldoSabado;

            cout << "Tipo de empleado: Empleado de Planta" << endl;
            cout << "Sueldo diario (Lunes a Viernes): L. " << sueldoDiarioLV << endl;
            cout << "Sueldo del sabado: L. " << sueldoSabado << endl;
            cout << "Sueldo por hora: L. " << sueldoHora << endl;
            cout << "Sueldo por minuto: L. " << sueldoMinuto << endl;
            cout << "Sueldo por segundo: L. " << sueldoSegundo << endl;
            cout << "Sueldo semanal (lunes a viernes): L. " << sueldoSemanalLV << endl;
            cout << "Sueldo semanal (lunes a sabado): L. " << sueldoSemanalLVSab << endl;
            cout << "Sueldo quincenal: L. " << sueldoQuincenal << endl;
            cout << "Total de horas trabajadas al mes: " << horasPlantaMes << endl;
            break;
        }
        case 2: { // Empleado de medio tiempo
            double horasMedioTiempoMes = 132; // (5.5h * 6 * 4)
            sueldoHora = sueldoMensual / horasMedioTiempoMes;
            sueldoMinuto = sueldoHora / 60;
            sueldoSegundo = sueldoHora / 3600;
            double sueldoDiarioMT = sueldoHora * 5.5;
            double sueldoSemanalMT = sueldoDiarioMT * 6;

            cout << "Tipo de empleado: Empleado de medio tiempo" << endl;
            cout << "Sueldo diario: L. " << sueldoDiarioMT << endl;
            cout << "Sueldo por hora: L. " << sueldoHora << endl;
            cout << "Sueldo por minuto: L. " << sueldoMinuto << endl;
            cout << "Sueldo por segundo: L. " << sueldoSegundo << endl;
            cout << "Sueldo semanal: L. " << sueldoSemanalMT << endl;
            cout << "Sueldo quincenal: L. " << sueldoQuincenal << endl;
            cout << "Total de horas trabajadas al mes: " << horasMedioTiempoMes << endl;
            break;
        }
        case 3: { // Empleado por Contrato
            double horasContratoSemanal;
            cout << "Ingrese las horas semanales del empleado (entre 30 y 40): ";
            cin >> horasContratoSemanal;
            while (horasContratoSemanal < 30 || horasContratoSemanal > 40) {
                cout << "ERROR: Horas fuera de rango permitido (30-40)." << endl;
                cout << "Ingrese nuevamente las horas semanales: ";
                cin >> horasContratoSemanal;
            }

            double horasContratoMes = horasContratoSemanal * 4;
            sueldoHora = sueldoMensual / horasContratoMes;
            sueldoMinuto = sueldoHora / 60;
            sueldoSegundo = sueldoHora / 3600;
            double sueldoDiarioContrato = (horasContratoSemanal / 5.0) * sueldoHora;
            double sueldoSemanalContrato = sueldoDiarioContrato * 5;

            cout << "Tipo de empleado: Empleado por contrato" << endl;
            cout << "Sueldo estimado por dia: L. " << sueldoDiarioContrato << endl;
            cout << "Sueldo por hora: L. " << sueldoHora << endl;
            cout << "Sueldo por minuto: L. " << sueldoMinuto << endl;
            cout << "Sueldo por segundo: L. " << sueldoSegundo << endl;
            cout << "Sueldo estimado semanal: L. " << sueldoSemanalContrato << endl;
            cout << "Sueldo quincenal: L. " << sueldoQuincenal << endl;
            cout << "Total de horas trabajadas al mes: " << horasContratoMes << endl;
            break;
        }
        default:
            cout << "Tipo de empleado incorrecto." << endl;
            break;
    }


    return 0;
}