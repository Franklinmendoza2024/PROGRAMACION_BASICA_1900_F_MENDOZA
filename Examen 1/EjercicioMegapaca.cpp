#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variables de control principal
    string nombreCliente;
    char sexoCliente;
    int edadCliente, tipoCliente, metodoPago;
    char continuarCliente = 'S';

    int clientesAtendidos = 0;
    double ventasTotalesLps = 0;
    double totalDescuentosDia = 0;
    double totalIsvDia = 0;

    int contEfectivo = 0;
    int contTransferencia = 0;

    // Inventarios iniciales
    double stock1 = 40, stock2 = 30, stock3 = 20;   // Casual
    double stock4 = 18, stock5 = 15, stock6 = 10;   // Oficina
    double stock7 = 16, stock8 = 12, stock9 = 25;   // Calzado
    double stock10 = 35, stock11 = 30, stock12 = 14; // Accesorios

    // Acumuladores de unidades vendidas por producto 
    double v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, v6 = 0;
    double v7 = 0, v8 = 0, v9 = 0, v10 = 0, v11 = 0, v12 = 0;

    // Acumuladores de ganancias por categoria
    double gananciaCasual = 0, gananciaOficina = 0, gananciaCalzado = 0, gananciaAccesorios = 0;

    // Ciclo principal para atender multiples clientes
    while (continuarCliente == 'S' || continuarCliente == 's') {

        cout << "\n==================================================\n";
        cout << "      TIENDA DE ROPA PUMA MEGAPACA                \n";
        cout << "==================================================\n";
        cout << "Nombre del cliente: ";
        cin >> nombreCliente;

        do {
            cout << "Sexo (M - Masculino / F - Femenino): ";
            cin >> sexoCliente;
            if (sexoCliente != 'M' && sexoCliente != 'm' && sexoCliente != 'F' && sexoCliente != 'f') {
                cout << "Opcion incorrecta. Ingrese M o F.\n";
            }
        } while (sexoCliente != 'M' && sexoCliente != 'm' && sexoCliente != 'F' && sexoCliente != 'f');

        // Restriccion de edad: 16 a 90 años
        do {
            cout << "Edad (16 a 90 a" << (char)164 << "os): "; // esta parte me dio guerra, hasta que encontre como hacer que se vea la ñ
            cin >> edadCliente;
            if (edadCliente < 16 || edadCliente > 90) {
                cout << "Error: edad fuera de rango.\n";
            }
        } while (edadCliente < 16 || edadCliente > 90);

        do {
            cout << "\nTipo de cliente:\n";
            cout << "1. Regular (5% descuento en Ropa Casual)\n";
            cout << "2. Premium (10% descuento en Calzado y Accesorios)\n";
            cout << "3. Mayorista (12% descuento en Ropa de Oficina)\n";
            cout << "Seleccione (1-3): ";
            cin >> tipoCliente;
            if (tipoCliente < 1 || tipoCliente > 3) {
                cout << "Opcion invalida.\n";
            }
        } while (tipoCliente < 1 || tipoCliente > 3);

        // Variables de la compra del cliente actual
        double subtotalCasual = 0, subtotalOficina = 0, subtotalCalzado = 0, subtotalAccesorios = 0;
        double subtotalCliente = 0;
        int puntosCliente = 0;

        // Cantidades compradas por producto en esta factura
        double c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
        double c7 = 0, c8 = 0, c9 = 0, c10 = 0, c11 = 0, c12 = 0;

        bool realizandoCompra = true;

        // Ciclo principal de categorias
        while (realizandoCompra) {
            int opcionMenuCategoria = 0;
            
            cout << "\n--- MENU DE CATEGORIAS ---\n";
            cout << "1. Ropa Casual (Productos 1 al 3)\n";
            cout << "2. Ropa de Oficina (Productos 4 al 6)\n";
            cout << "3. Calzado (Productos 7 al 9)\n";
            cout << "4. Accesorios (Productos 10 al 12)\n";
            cout << "5. Finalizar seleccion y proceder al pago\n";
            cout << "Seleccione una opcion (1-5): ";
            cin >> opcionMenuCategoria;

            if (opcionMenuCategoria == 5) {
                realizandoCompra = false; 
                break;
            }

            if (opcionMenuCategoria < 1 || opcionMenuCategoria > 4) {
                cout << "Opcion invalida. Intente de nuevo.\n";
                continue;
            }

            // ciclo para mantenerse en la tabla de la categoria elegida
            bool enCategoria = true;
            while (enCategoria) {
                cout << "\n-----------------------------------------------------------------\n";
                cout << " COD | PRODUCTO               | PRECIO   | STOCK | PUNTOS\n";
                cout << "-----------------------------------------------------------------\n";
                
                if (opcionMenuCategoria == 1) {
                    cout << "  1  | Camiseta basica        | L 180.00 | " << stock1 << "   |  10\n";
                    cout << "  2  | Jeans clasico          | L 450.00 | " << stock2 << "   |  25\n";
                    cout << "  3  | Sudadera               | L 520.00 | " << stock3 << "   |  30\n";
                } else if (opcionMenuCategoria == 2) {
                    cout << "  4  | Camisa formal          | L 650.00 | " << stock4 << "   |  40\n";
                    cout << "  5  | Pantalon de vestir     | L 750.00 | " << stock5 << "   |  45\n";
                    cout << "  6  | Blazer                 | L 1200.0 | " << stock6 << "   |  70\n";
                } else if (opcionMenuCategoria == 3) {
                    cout << "  7  | Tenis deportivos       | L 980.00 | " << stock7 << "   |  60\n";
                    cout << "  8  | Zapatos formales       | L 1100.0 | " << stock8 << "   |  65\n";
                    cout << "  9  | Sandalias              | L 420.00 | " << stock9 << "   |  20\n";
                } else if (opcionMenuCategoria == 4) {
                    cout << " 10  | Cinturon               | L 220.00 | " << stock10 << "   |  12\n";
                    cout << " 11  | Gorra                  | L 160.00 | " << stock11 << "   |  8\n";
                    cout << " 12  | Bolso                  | L 850.00 | " << stock12 << "   |  50\n";
                }
                cout << "-----------------------------------------------------------------\n";
                cout << " (Ingrese 0 para regresar al menu principal de categorias)\n";

                int codigo = 0;
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;

                if (codigo == 0) {
                    enCategoria = false; // Sale de la categoria y regresa al menu general
                    continue;
                }

                // Validacion estricta para que el codigo pertenezca unicamente a la seccion actual
                bool codigoValidoParaSeccion = false;
                if (opcionMenuCategoria == 1 && (codigo >= 1 && codigo <= 3)) codigoValidoParaSeccion = true;
                else if (opcionMenuCategoria == 2 && (codigo >= 4 && codigo <= 6)) codigoValidoParaSeccion = true;
                else if (opcionMenuCategoria == 3 && (codigo >= 7 && codigo <= 9)) codigoValidoParaSeccion = true;
                else if (opcionMenuCategoria == 4 && (codigo >= 10 && codigo <= 12)) codigoValidoParaSeccion = true;

                if (!codigoValidoParaSeccion) {
                    cout << "\n[ERROR]: Codigo incorrecto o no pertenece a esta seccion. Intente de nuevo.\n";
                    continue; 
                }

                double cantidad = 0;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;

                if (cantidad <= 0) {
                    cout << "La cantidad debe ser mayor a cero.\n";
                } else {
                    bool stockOk = false;
                    double precioUnitario = 0;

                    if (codigo == 1) {
                        if (cantidad <= stock1) { stock1 -= cantidad; stockOk = true; precioUnitario = 180.00; c1 += cantidad; v1 += cantidad; subtotalCasual += precioUnitario * cantidad; puntosCliente += 10 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock1 << "\n";
                    } else if (codigo == 2) {
                        if (cantidad <= stock2) { stock2 -= cantidad; stockOk = true; precioUnitario = 450.00; c2 += cantidad; v2 += cantidad; subtotalCasual += precioUnitario * cantidad; puntosCliente += 25 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock2 << "\n";
                    } else if (codigo == 3) {
                        if (cantidad <= stock3) { stock3 -= cantidad; stockOk = true; precioUnitario = 520.00; c3 += cantidad; v3 += cantidad; subtotalCasual += precioUnitario * cantidad; puntosCliente += 30 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock3 << "\n";
                    } else if (codigo == 4) {
                        if (cantidad <= stock4) { stock4 -= cantidad; stockOk = true; precioUnitario = 650.00; c4 += cantidad; v4 += cantidad; subtotalOficina += precioUnitario * cantidad; puntosCliente += 40 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock4 << "\n";
                    } else if (codigo == 5) {
                        if (cantidad <= stock5) { stock5 -= cantidad; stockOk = true; precioUnitario = 750.00; c5 += cantidad; v5 += cantidad; subtotalOficina += precioUnitario * cantidad; puntosCliente += 45 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock5 << "\n";
                    } else if (codigo == 6) {
                        if (cantidad <= stock6) { stock6 -= cantidad; stockOk = true; precioUnitario = 1200.00; c6 += cantidad; v6 += cantidad; subtotalOficina += precioUnitario * cantidad; puntosCliente += 70 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock6 << "\n";
                    } else if (codigo == 7) {
                        if (cantidad <= stock7) { stock7 -= cantidad; stockOk = true; precioUnitario = 980.00; c7 += cantidad; v7 += cantidad; subtotalCalzado += precioUnitario * cantidad; puntosCliente += 60 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock7 << "\n";
                    } else if (codigo == 8) {
                        if (cantidad <= stock8) { stock8 -= cantidad; stockOk = true; precioUnitario = 1100.00; c8 += cantidad; v8 += cantidad; subtotalCalzado += precioUnitario * cantidad; puntosCliente += 65 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock8 << "\n";
                    } else if (codigo == 9) {
                        if (cantidad <= stock9) { stock9 -= cantidad; stockOk = true; precioUnitario = 420.00; c9 += cantidad; v9 += cantidad; subtotalCalzado += precioUnitario * cantidad; puntosCliente += 20 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock9 << "\n";
                    } else if (codigo == 10) {
                        if (cantidad <= stock10) { stock10 -= cantidad; stockOk = true; precioUnitario = 220.00; c10 += cantidad; v10 += cantidad; subtotalAccesorios += precioUnitario * cantidad; puntosCliente += 12 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock10 << "\n";
                    } else if (codigo == 11) {
                        if (cantidad <= stock11) { stock11 -= cantidad; stockOk = true; precioUnitario = 160.00; c11 += cantidad; v11 += cantidad; subtotalAccesorios += precioUnitario * cantidad; puntosCliente += 8 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock11 << "\n";
                    } else if (codigo == 12) {
                        if (cantidad <= stock12) { stock12 -= cantidad; stockOk = true; precioUnitario = 850.00; c12 += cantidad; v12 += cantidad; subtotalAccesorios += precioUnitario * cantidad; puntosCliente += 50 * (int)cantidad; }
                        else cout << "Stock insuficiente. Disponible: " << stock12 << "\n";
                    }

                    if (stockOk) {
                        cout << "Producto agregado exitosamente!\n";
                        
                        // Preguntar si desea seguir agregando mas productos en esta misma seccion
                        char seguirComprando;
                        cout << "Desea agregar otro producto en esta seccion? (S/N): ";
                        cin >> seguirComprando;
                        if (seguirComprando != 'S' && seguirComprando != 's') {
                            enCategoria = false; //  regreso al menu general
                        }
                    }
                }
            }
        }

        subtotalCliente = subtotalCasual + subtotalOficina + subtotalCalzado + subtotalAccesorios;

        if (subtotalCliente == 0) {
            cout << "\nNo se selecciono ningun producto para este cliente.\n";
            cout << "Desea ingresar otro cliente? (S/N): ";
            cin >> continuarCliente;
            continue;
        }

        // --- CALCULO DE DESCUENTOS ---
        double descTipoCliente = 0;
        if (tipoCliente == 1) {
            descTipoCliente = subtotalCasual * 0.05;
        } else if (tipoCliente == 2) {
            descTipoCliente = (subtotalCalzado + subtotalAccesorios) * 0.10;
        } else if (tipoCliente == 3) {
            descTipoCliente = subtotalOficina * 0.12;
        }

        double descGenero = 0;
        if (sexoCliente == 'F' || sexoCliente == 'f') {
            descGenero = subtotalAccesorios * 0.08;
        } else if (sexoCliente == 'M' || sexoCliente == 'm') {
            descGenero = subtotalCalzado * 0.05;
        }

        double descTerceraEdad = 0;
        if (edadCliente >= 60) {
            descTerceraEdad = subtotalCliente * 0.10;
        }

        double descOutfit = 0;
        if (c1 > 0 && c2 > 0) {
            descOutfit = ((c1 * 180.00) + (c2 * 450.00)) * 0.06;
        }

        double descOficinaPro = 0;
        if (c4 > 0 && c5 > 0) {
            descOficinaPro = ((c4 * 650.00) + (c5 * 750.00)) * 0.07;
        }

        double descVolumen = 0;
        if (c1 > 3) descVolumen += (c1 * 180.00) * 0.04;
        if (c2 > 3) descVolumen += (c2 * 450.00) * 0.04;
        if (c3 > 3) descVolumen += (c3 * 520.00) * 0.04;
        if (c4 > 3) descVolumen += (c4 * 650.00) * 0.04;
        if (c5 > 3) descVolumen += (c5 * 750.00) * 0.04;
        if (c6 > 3) descVolumen += (c6 * 1200.00) * 0.04;
        if (c7 > 3) descVolumen += (c7 * 980.00) * 0.04;
        if (c8 > 3) descVolumen += (c8 * 1100.00) * 0.04;
        if (c9 > 3) descVolumen += (c9 * 420.00) * 0.04;
        if (c10 > 3) descVolumen += (c10 * 220.00) * 0.04;
        if (c11 > 3) descVolumen += (c11 * 160.00) * 0.04;
        if (c12 > 3) descVolumen += (c12 * 850.00) * 0.04;

        double descuentoTotalCliente = descTipoCliente + descGenero + descTerceraEdad + descOutfit + descOficinaPro + descVolumen;
        if (descuentoTotalCliente > subtotalCliente) {
            descuentoTotalCliente = subtotalCliente;
        }
        totalDescuentosDia += descuentoTotalCliente;

        double subtotalConDescuento = subtotalCliente - descuentoTotalCliente;
        double isvGeneral = subtotalConDescuento * 0.15;
        totalIsvDia += isvGeneral;

        double totalPagarLps = subtotalConDescuento + isvGeneral;

        double descCasualCat = (tipoCliente == 1 ? subtotalCasual * 0.05 : 0);
        double descOficinaCat = (tipoCliente == 3 ? subtotalOficina * 0.12 : 0);
        double descCalzadoCat = (tipoCliente == 2 ? subtotalCalzado * 0.10 : 0) + ((sexoCliente == 'M' || sexoCliente == 'm') ? subtotalCalzado * 0.05 : 0);
        double descAccesoriosCat = (tipoCliente == 2 ? subtotalAccesorios * 0.10 : 0) + ((sexoCliente == 'F' || sexoCliente == 'f') ? subtotalAccesorios * 0.08 : 0);

        gananciaCasual += (subtotalCasual - descCasualCat);
        gananciaOficina += (subtotalOficina - descOficinaCat);
        gananciaCalzado += (subtotalCalzado - descCalzadoCat);
        gananciaAccesorios += (subtotalAccesorios - descAccesoriosCat);

        // --- METODOS DE PAGO ---
        do {
            cout << "\n==================================================\n";
            cout << "     MONTO TOTAL A CANCELAR: L " << totalPagarLps << "\n";
            cout << "==================================================\n";
            cout << "--- SELECCIONE METODO DE PAGO ---\n";
            cout << "1. Efectivo\n";
            cout << "2. Transferencia Bancaria\n";
            cout << "Seleccione opcion (1-2): ";
            cin >> metodoPago;
            if (metodoPago != 1 && metodoPago != 2) {
                cout << "Opcion invalida. Intente de nuevo.\n";
            }
        } while (metodoPago != 1 && metodoPago != 2);

        if (metodoPago == 1) {
            contEfectivo++;
            double montoRecibido = 0;
            do {
                cout << "Ingrese monto recibido en Lps.: ";
                cin >> montoRecibido;
                if (montoRecibido < totalPagarLps) {
                    cout << "Monto insuficiente. El total a pagar es L " << totalPagarLps << "\n";
                }
            } while (montoRecibido < totalPagarLps);
            cout << "Cambio a entregar: L " << (montoRecibido - totalPagarLps) << "\n";
            
            ventasTotalesLps += totalPagarLps;
        } else {
            contTransferencia++;
            string comprobante = "";
            string bancoEmisor = "";
            double comisionACH = 0;

            cout << "\n--- DATOS DE TRANSFERENCIA BANCARIA ---\n";
            cout << "Cuenta de destino fija (BAC Credomatic): 7908409200\n";
            cout << "Ingrese el nombre de su banco emisor: ";
            cin >> bancoEmisor;

            cout << "Numero de comprobante/referencia: ";
            cin >> comprobante;

            if (bancoEmisor == "BAC" || bancoEmisor == "bac" || bancoEmisor == "BAC Credomatic" || bancoEmisor == "bac credomatic") {
                cout << "Transferencia exitosa!.\n";
            } else {
                comisionACH = 40.00;
                totalPagarLps += comisionACH;
                cout << "Aviso: Banco diferente a BAC. Se ha cobrado una comision ACH de L 40.00.\n";
                cout << "Nuevo total ajustado con comision: L " << totalPagarLps << "\n";
            }

            ventasTotalesLps += totalPagarLps;
        }

        // --- FACTURA FINAL ---
        cout << "\n==================================================\n";
        cout << "                  FACTURA FINAL                   \n";
        cout << "==================================================\n";
        cout << "Cliente: " << nombreCliente << " | Edad: " << edadCliente << " | Sexo: " << sexoCliente << "\n";
        cout << "Tipo de cliente: " << tipoCliente << "\n";
        cout << "--------------------------------------------------\n";
        if (c1 > 0) cout << "- Camiseta basica: " << c1 << " un. x L 180.00 = L " << c1 * 180.00 << "\n";
        if (c2 > 0) cout << "- Jeans clasico: " << c2 << " un. x L 450.00 = L " << c2 * 450.00 << "\n";
        if (c3 > 0) cout << "- Sudadera: " << c3 << " un. x L 520.00 = L " << c3 * 520.00 << "\n";
        if (c4 > 0) cout << "- Camisa formal: " << c4 << " un. x L 650.00 = L " << c4 * 650.00 << "\n";
        if (c5 > 0) cout << "- Pantalon de vestir: " << c5 << " un. x L 750.00 = L " << c5 * 750.00 << "\n";
        if (c6 > 0) cout << "- Blazer: " << c6 << " un. x L 1200.00 = L " << c6 * 1200.00 << "\n";
        if (c7 > 0) cout << "- Tenis deportivos: " << c7 << " un. x L 980.00 = L " << c7 * 980.00 << "\n";
        if (c8 > 0) cout << "- Zapatos formales: " << c8 << " un. x L 1100.00 = L " << c8 * 1100.00 << "\n";
        if (c9 > 0) cout << "- Sandalias: " << c9 << " un. x L 420.00 = L " << c9 * 420.00 << "\n";
        if (c10 > 0) cout << "- Cinturon: " << c10 << " un. x L 220.00 = L " << c10 * 220.00 << "\n";
        if (c11 > 0) cout << "- Gorra: " << c11 << " un. x L 160.00 = L " << c11 * 160.00 << "\n";
        if (c12 > 0) cout << "- Bolso: " << c12 << " un. x L 850.00 = L " << c12 * 850.00 << "\n";
        cout << "--------------------------------------------------\n";
        cout << "Subtotal: L " << subtotalCliente << "\n";
        cout << "Descuentos totales aplicados: L " << descuentoTotalCliente << "\n";
        cout << "ISV (15%): L " << isvGeneral << "\n";
        cout << "TOTAL A PAGAR (Lps.): L " << totalPagarLps << "\n";
        cout << "TOTAL A PAGAR (USD $1 = 26.42 Lps.): $ " << (totalPagarLps / 26.42) << "\n";
        cout << "PUNTOS ACUMULADOS EN ESTA COMPRA: " << puntosCliente << " pts\n";
        cout << "==================================================\n";

        clientesAtendidos++;

        cout << "\nDesea ingresar otro cliente? (S/N): ";
        cin >> continuarCliente;
    }

    // --- MODULO DE ESTADISTICAS ---
    cout << "\n==================================================\n";
    cout << "           ESTADISTICAS FINALES DEL DIA           \n";
    cout << "==================================================\n";
    cout << "1. Total general vendido en Lps.: L " << ventasTotalesLps << "\n";
    cout << "2. Total general vendido en USD: $ " << (ventasTotalesLps / 26.42) << "\n";
    cout << "3. Total ISV recaudado: L " << totalIsvDia << "\n";
    cout << "4. Total descuentos aplicados del dia: L " << totalDescuentosDia << "\n";

    cout << "\nGANANCIAS POR CATEGORIA (Sin ISV):\n";
    cout << "- Ropa Casual: L " << gananciaCasual << "\n";
    cout << "- Ropa de Oficina: L " << gananciaOficina << "\n";
    cout << "- Calzado: L " << gananciaCalzado << "\n";
    cout << "- Accesorios: L " << gananciaAccesorios << "\n";

    double ventasArr[12] = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12};
    string nombresArr[12] = {
        "Camiseta basica", "Jeans clasico", "Sudadera",
        "Camisa formal", "Pantalon de vestir", "Blazer",
        "Tenis deportivos", "Zapatos formales", "Sandalias",
        "Cinturon", "Gorra", "Bolso"
    };

    double mayorV = v1, menorV = v1;
    string prodMas = nombresArr[0], prodMenos = nombresArr[0];
    bool primerNoCeroEncontrado = false;

    for (int i = 0; i < 12; i++) {
        if (ventasArr[i] > mayorV) {
            mayorV = ventasArr[i];
            prodMas = nombresArr[i];
        }
        if (ventasArr[i] > 0) {
            if (!primerNoCeroEncontrado || ventasArr[i] < menorV) {
                menorV = ventasArr[i];
                prodMenos = nombresArr[i];
                primerNoCeroEncontrado = true;
            }
        }
    }

    cout << "\nREPORTE DE PRODUCTOS:\n";
    if (mayorV > 0) {
        cout << "- Producto mas vendido: " << prodMas << " (" << mayorV << " unidades)\n";
        cout << "- Producto menos vendido: " << prodMenos << " (" << menorV << " unidades)\n";
    } else {
        cout << "- No se registraron ventas de productos.\n";
    }

    cout << "\nMETODO DE PAGO MAS UTILIZADO:\n";
    cout << "- Efectivo: " << contEfectivo << " veces\n";
    cout << "- Transferencia: " << contTransferencia << " veces\n";
    if (contEfectivo > contTransferencia) {
        cout << "Metodo mas popular: Efectivo\n";
    } else if (contTransferencia > contEfectivo) {
        cout << "Metodo mas popular: Transferencia\n";
    } else {
        cout << "Empate entre ambos metodos.\n";
    }
    cout << "==================================================\n";

    return 0;
}

// Franklin Omar Mendoza Sanchez
// 20241002543
