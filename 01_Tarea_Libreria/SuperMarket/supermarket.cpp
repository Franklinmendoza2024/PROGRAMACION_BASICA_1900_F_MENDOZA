#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    string nombreCliente, sexoCliente;
    int edadCliente, tipoCliente, opcionDia;
    int opcionMenu, opcionProducto;
    int cantidadClientesAtendidos = 0;
    int cantidadTiposCarne;
    char continuarCliente = 'S', continuarCompra = 'S';

    // Nombres de productos
    string tomates = "Tomates";
    string repollo = "Repollo";
    string papas = "Papas";
    string carneMolida = "Carne molida";
    string carneCerdo = "Carne de cerdo";
    string carneAsar = "Carne para asar";
    string cervezaNacional = "Cerveza nacional";
    string cervezaExtranjera = "Cerveza extranjera";
    string vino = "Vino";
    string vodka = "Vodka";

    // Inventario
    double stockTomates = 100, stockRepollo = 100, stockPapas = 100;
    double stockCarneMolida = 80, stockCarneCerdo = 80;
    double stockCarneAsar = 80, stockCervezaNacional = 120;
    double stockCervezaExtranjera = 120, stockVino = 60;
    double stockVodka = 60;

    // Precios
    double precioTomates = 10, precioRepollo = 15, precioPapas = 17;
    double precioCarneMolida = 50, precioCarneCerdo = 70;
    double precioCarneAsar = 75, precioCervezaNacional = 50;
    double precioCervezaExtranjera = 80, precioVino = 200;
    double precioVodka = 100;

    // Acumuladores de ventas de todos los clientes
    double vendidoTomates = 0, vendidoRepollo = 0, vendidoPapas = 0;
    double vendidoCarneMolida = 0, vendidoCarneCerdo = 0;
    double vendidoCarneAsar = 0, vendidoCervezaNacional = 0;
    double vendidoCervezaExtranjera = 0, vendidoVino = 0;
    double vendidoVodka = 0;

    double ventasTotales = 0;

    while (continuarCliente == 'S' || continuarCliente == 's') {

        cout << "\n========== PUMA SUPER-MARKET ==========\n";
        cout << "Nombre del cliente: ";
        cin >> nombreCliente;

        do {
            cout << "Sexo (M/F): ";
            cin >> sexoCliente;

            if (sexoCliente != "M" && sexoCliente != "m" &&
                sexoCliente != "F" && sexoCliente != "f") {
                cout << "Sexo incorrecto.\n";
            }

        } while (sexoCliente != "M" && sexoCliente != "m" &&
                 sexoCliente != "F" && sexoCliente != "f");

        do {
            cout << "Edad (15 a 100): ";
            cin >> edadCliente;

            if (edadCliente < 15 || edadCliente > 100) {
                cout << "Edad fuera de rango.\n";
            }

        } while (edadCliente < 15 || edadCliente > 100);

        do {
            cout << "\nTipo de cliente:\n";
            cout << "1. Cliente estrella\n";
            cout << "2. Cliente regular\n";
            cout << "3. Cliente nuevo\n";
            cout << "Seleccione: ";
            cin >> tipoCliente;

            if (tipoCliente < 1 || tipoCliente > 3) {
                cout << "Opcion incorrecta.\n";
            }

        } while (tipoCliente < 1 || tipoCliente > 3);

        do {
            cout << "\nDia de compra:\n";
            cout << "1. Lunes\n";
            cout << "2. Martes\n";
            cout << "3. Miercoles\n";
            cout << "4. Jueves\n";
            cout << "5. Viernes\n";
            cout << "6. Sabado\n";
            cout << "7. Domingo\n";
            cout << "Seleccione: ";
            cin >> opcionDia;

            if (opcionDia != 1 && opcionDia != 2 && opcionDia != 3 &&
                opcionDia != 4 && opcionDia != 5 && opcionDia != 6 && opcionDia != 7) {
                cout << "Dia incorrecto.\n";
            }

        } while (opcionDia != 1 && opcionDia != 2 && opcionDia != 3 &&
                 opcionDia != 4 && opcionDia != 5 && opcionDia != 6 && opcionDia != 7);

        // Cantidades compradas por cliente 1
        double cantTomates = 0, cantRepollo = 0, cantPapas = 0;
        double cantCarneMolida = 0, cantCarneCerdo = 0;
        double cantCarneAsar = 0, cantCervezaNacional = 0;
        double cantCervezaExtranjera = 0, cantVino = 0;
        double cantVodka = 0;

        double subtotalVerduras = 0;
        double subtotalCarnes = 0;
        double subtotalLicores = 0;
        double subtotalCliente = 0;

        double descuentoClienteEstrella = 0;
        double descuentoClienteRegular = 0;
        double descuentoClienteNuevo = 0;
        double descuentoDia = 0;
        double descuentoTerceraEdad = 0;
        double descuentoSixPac = 0;
        double descuentoSegundaCarne = 0;
        double descuentoTotal = 0;

        double ISV = 0, isvAdicional = 0;
        double impuestoTotal = 0, totalPagar = 0;
        double cantidad, importe, precioActual, stockActual;

        string nombreActual, unidadActual;
        int carneSeleccionada = 0;
        bool descuentoCarneAplicado = false;

        continuarCompra = 'S';

        while (continuarCompra == 'S' || continuarCompra == 's') {

            do {
                cout << "\nAreas disponibles:\n";
                cout << "1. Verduras\n";
                cout << "2. Carnes\n";
                cout << "3. Licores\n";
                cout << "Seleccione el area: ";
                cin >> opcionMenu;

                if (opcionMenu < 1 || opcionMenu > 3) {
                    cout << "Solo puede ingresar 1, 2 o 3.\n";
                }
                else if (opcionMenu == 3 && edadCliente < 18) {
                    cout << "Acceso denegado. Debe tener 18 anos.\n";
                    opcionMenu = 0;
                }

            } while (opcionMenu < 1 || opcionMenu > 3);

            if (opcionMenu == 1) {
                cout << "\n1. Tomates - L 10 por libra\n";
                cout << "2. Repollo - L 15 por libra\n";
                cout << "3. Papas - L 17 por libra\n";
            }
            else if (opcionMenu == 2) {
                cout << "\n4. Carne molida - L 50 por libra\n";
                cout << "5. Carne de cerdo - L 70 por libra\n";
                cout << "6. Carne para asar - L 75 por libra\n";
            }
            else {
                cout << "\n7. Cerveza nacional - L 50 por botella\n";
                cout << "8. Cerveza extranjera - L 80 por botella\n";
                cout << "9. Vino - L 200 por botella\n";
                cout << "10. Vodka - L 100 por botella\n";
            }

            cout << "Codigo del producto: ";
            cin >> opcionProducto;

            if (opcionProducto < 1 || opcionProducto > 10 ||
                (opcionMenu == 1 && opcionProducto > 3) ||
                (opcionMenu == 2 &&
                 (opcionProducto < 4 || opcionProducto > 6)) ||
                (opcionMenu == 3 && opcionProducto < 7)) {

                cout << "Producto incorrecto para esta area.\n";

            }
            else {

                // Identificacion de productos
                switch (opcionProducto) {

                    case 1:
                        nombreActual = tomates;
                        unidadActual = "libras";
                        precioActual = precioTomates;
                        stockActual = stockTomates;
                        break;

                    case 2:
                        nombreActual = repollo;
                        unidadActual = "libras";
                        precioActual = precioRepollo;
                        stockActual = stockRepollo;
                        break;

                    case 3:
                        nombreActual = papas;
                        unidadActual = "libras";
                        precioActual = precioPapas;
                        stockActual = stockPapas;
                        break;

                    case 4:
                        nombreActual = carneMolida;
                        unidadActual = "libras";
                        precioActual = precioCarneMolida;
                        stockActual = stockCarneMolida;
                        break;

                    case 5:
                        nombreActual = carneCerdo;
                        unidadActual = "libras";
                        precioActual = precioCarneCerdo;
                        stockActual = stockCarneCerdo;
                        break;

                    case 6:
                        nombreActual = carneAsar;
                        unidadActual = "libras";
                        precioActual = precioCarneAsar;
                        stockActual = stockCarneAsar;
                        break;

                    case 7:
                        nombreActual = cervezaNacional;
                        unidadActual = "botellas";
                        precioActual = precioCervezaNacional;
                        stockActual = stockCervezaNacional;
                        break;

                    case 8:
                        nombreActual = cervezaExtranjera;
                        unidadActual = "botellas";
                        precioActual = precioCervezaExtranjera;
                        stockActual = stockCervezaExtranjera;
                        break;

                    case 9:
                        nombreActual = vino;
                        unidadActual = "botellas";
                        precioActual = precioVino;
                        stockActual = stockVino;
                        break;

                    case 10:
                        nombreActual = vodka;
                        unidadActual = "botellas";
                        precioActual = precioVodka;
                        stockActual = stockVodka;
                        break;
                }

                cout << "Producto: " << nombreActual << "\n";
                cout << "Precio por " <<
                    (opcionProducto <= 6 ? "libra" : "botella");
                cout << ": L " << precioActual << "\n";

                cout << "Cantidad en " << unidadActual << ": ";
                cin >> cantidad;

                if (cantidad <= 0) {
                    cout << "La cantidad debe ser mayor que cero.\n";
                }
                else if (cantidad > stockActual) {
                    cout << "Inventario insuficiente. Disponible: "
                         << stockActual << " " << unidadActual << "\n";
                }
                else if (opcionProducto >= 7 &&
                         cantidad != (int)cantidad) {
                    cout << "Las botellas deben ser cantidades enteras.\n";
                }
                else {

                    importe = precioActual * cantidad;

                    // Descuento del 50% en la segunda seleccion de carne
                    if (opcionProducto >= 4 && opcionProducto <= 6) {
                        carneSeleccionada++;

                        if (carneSeleccionada == 2 &&
                            !descuentoCarneAplicado) {

                            descuentoSegundaCarne = importe * 0.50;
                            descuentoCarneAplicado = true;

                            cout << "Descuento del 50% en la segunda carne: L "
                                 << descuentoSegundaCarne << "\n";
                        }
                    }

                    // Registrar cantidad, inventario y ventas
                    switch (opcionProducto) {

                        case 1:
                            cantTomates += cantidad;
                            stockTomates -= cantidad;
                            vendidoTomates += cantidad;
                            break;

                        case 2:
                            cantRepollo += cantidad;
                            stockRepollo -= cantidad;
                            vendidoRepollo += cantidad;
                            break;

                        case 3:
                            cantPapas += cantidad;
                            stockPapas -= cantidad;
                            vendidoPapas += cantidad;
                            break;

                        case 4:
                            cantCarneMolida += cantidad;
                            stockCarneMolida -= cantidad;
                            vendidoCarneMolida += cantidad;
                            break;

                        case 5:
                            cantCarneCerdo += cantidad;
                            stockCarneCerdo -= cantidad;
                            vendidoCarneCerdo += cantidad;
                            break;

                        case 6:
                            cantCarneAsar += cantidad;
                            stockCarneAsar -= cantidad;
                            vendidoCarneAsar += cantidad;
                            break;

                        case 7:
                            cantCervezaNacional += cantidad;
                            stockCervezaNacional -= cantidad;
                            vendidoCervezaNacional += cantidad;
                            break;

                        case 8:
                            cantCervezaExtranjera += cantidad;
                            stockCervezaExtranjera -= cantidad;
                            vendidoCervezaExtranjera += cantidad;
                            break;

                        case 9:
                            cantVino += cantidad;
                            stockVino -= cantidad;
                            vendidoVino += cantidad;
                            break;

                        case 10:
                            cantVodka += cantidad;
                            stockVodka -= cantidad;
                            vendidoVodka += cantidad;
                            break;
                    }

                    // Acumular subtotal por area
                    if (opcionProducto <= 3) {
                        subtotalVerduras += importe;
                    }
                    else if (opcionProducto <= 6) {
                        subtotalCarnes += importe;
                    }
                    else {
                        subtotalLicores += importe;
                    }

                    cout << "Producto agregado correctamente.\n";
                }
            }

            cout << "\nDesea agregar otro producto? (S/N): ";
            cin >> continuarCompra;
        }

        // Calcular descuento segun tipo de cliente
        if (tipoCliente == 1) {
            descuentoClienteEstrella =
                (subtotalVerduras + subtotalCarnes) * 0.04;
        }
        else if (tipoCliente == 2) {
            descuentoClienteRegular = subtotalCarnes * 0.03;
        }
        else if (tipoCliente == 3) {
            descuentoClienteNuevo = subtotalLicores * 0.02;
        }

        subtotalCliente =
            subtotalVerduras + subtotalCarnes + subtotalLicores;

        // Descuentos del dia (Lunes=1, Miercoles=3, Viernes=5)
        if (opcionDia == 1 || opcionDia == 3) {
            descuentoDia = subtotalCliente * 0.03; // 3% adicional Lunes o Miércoles
        }
        else if (opcionDia == 5 && edadCliente >= 65) {
            descuentoTerceraEdad = subtotalCliente * 0.10; // 10% adicional tercera edad Viernes
        }

        // Descuento por cada grupo completo de seis botellas
        descuentoSixPac =
            ((int)(cantCervezaNacional / 6) +
             (int)(cantCervezaExtranjera / 6)) * 10.00;

        descuentoTotal =
            descuentoClienteEstrella +
            descuentoClienteRegular +
            descuentoClienteNuevo +
            descuentoDia +
            descuentoTerceraEdad +
            descuentoSixPac +
            descuentoSegundaCarne;

        if (descuentoTotal > subtotalCliente) {
            descuentoTotal = subtotalCliente;
        }

        // Impuestos
        ISV = (subtotalVerduras + subtotalCarnes) * 0.15;
        isvAdicional = subtotalLicores * 0.18;
        impuestoTotal = ISV + isvAdicional;

        totalPagar = subtotalCliente - descuentoTotal + impuestoTotal;

        // FACTURA
        cout << "\n=============== FACTURA ===============\n";
        cout << "Cliente: " << nombreCliente << "\n";
        cout << "Sexo: " << sexoCliente << "\n";
        cout << "Edad: " << edadCliente << "\n";
        cout << "Tipo de cliente: " << tipoCliente << "\n";
        
        // Mostrar nombre del día correctamente en la factura
        cout << "Dia: ";
        if (opcionDia == 1) cout << "Lunes\n";
        else if (opcionDia == 2) cout << "Martes\n";
        else if (opcionDia == 3) cout << "Miercoles\n";
        else if (opcionDia == 4) cout << "Jueves\n";
        else if (opcionDia == 5) cout << "Viernes\n";
        else if (opcionDia == 6) cout << "Sabado\n";
        else if (opcionDia == 7) cout << "Domingo\n";

        cout << "\nPRODUCTOS COMPRADOS\n";

        if (cantTomates > 0)
            cout << tomates << ": " << cantTomates
                 << " libras x L " << precioTomates << " = L "
                 << cantTomates * precioTomates << "\n";

        if (cantRepollo > 0)
            cout << repollo << ": " << cantRepollo
                 << " libras x L " << precioRepollo << " = L "
                 << cantRepollo * precioRepollo << "\n";

        if (cantPapas > 0)
            cout << papas << ": " << cantPapas
                 << " libras x L " << precioPapas << " = L "
                 << cantPapas * precioPapas << "\n";

        if (cantCarneMolida > 0)
            cout << carneMolida << ": " << cantCarneMolida
                 << " libras x L " << precioCarneMolida << " = L "
                 << cantCarneMolida * precioCarneMolida << "\n";

        if (cantCarneCerdo > 0)
            cout << carneCerdo << ": " << cantCarneCerdo
                 << " libras x L " << precioCarneCerdo << " = L "
                 << cantCarneCerdo * precioCarneCerdo << "\n";

        if (cantCarneAsar > 0)
            cout << carneAsar << ": " << cantCarneAsar
                 << " libras x L " << precioCarneAsar << " = L "
                 << cantCarneAsar * precioCarneAsar << "\n";

        if (cantCervezaNacional > 0)
            cout << cervezaNacional << ": " << cantCervezaNacional
                 << " botellas x L " << precioCervezaNacional << " = L "
                 << cantCervezaNacional * precioCervezaNacional << "\n";

        if (cantCervezaExtranjera > 0)
            cout << cervezaExtranjera << ": " << cantCervezaExtranjera
                 << " botellas x L " << precioCervezaExtranjera << " = L "
                 << cantCervezaExtranjera * precioCervezaExtranjera << "\n";

        if (cantVino > 0)
            cout << vino << ": " << cantVino
                 << " botellas x L " << precioVino << " = L "
                 << cantVino * precioVino << "\n";

        if (cantVodka > 0)
            cout << vodka << ": " << cantVodka
                 << " botellas x L " << precioVodka << " = L "
                 << cantVodka * precioVodka << "\n";

        cout << "---------------------------------------\n";
        cout << "Subtotal: L " << subtotalCliente << "\n";
        cout << "Descuento cliente estrella: L "
             << descuentoClienteEstrella << "\n";
        cout << "Descuento cliente regular: L "
             << descuentoClienteRegular << "\n";
        cout << "Descuento cliente nuevo: L "
             << descuentoClienteNuevo << "\n";
        cout << "Descuento del dia (Lunes/Miercoles): L " << descuentoDia << "\n";
        cout << "Descuento tercera edad (Viernes): L " << descuentoTerceraEdad << "\n";
        cout << "Descuento six-pack: L " << descuentoSixPac << "\n";
        cout << "Descuento segunda carne: L "
             << descuentoSegundaCarne << "\n";
        cout << "Descuentos totales: L " << descuentoTotal << "\n";
        cout << "ISV general (15%): L " << ISV << "\n";
        cout << "ISV de licores (18%): L " << isvAdicional << "\n";
        cout << "TOTAL A PAGAR: L " << totalPagar << "\n";
        cout << "Total a pagar en Dolares ($1 USD = 24.5 L): $ " << (totalPagar / 24.5) << "\n";
        cout << "=======================================\n";

        ventasTotales += totalPagar;
        cantidadClientesAtendidos++;

        cout << "\nDesea atender a otro cliente? (S/N): ";
        cin >> continuarCliente;
    }

    // INFORME GENERAL DEL DIA
    cout << "\n========== INFORME GENERAL ==========\n";
    cout << "Clientes atendidos: " << cantidadClientesAtendidos << "\n";
    cout << "Ventas totales: L " << ventasTotales << "\n";

    cout << "\nPRODUCTOS VENDIDOS\n";
    cout << tomates << ": " << vendidoTomates << " libras\n";
    cout << repollo << ": " << vendidoRepollo << " libras\n";
    cout << papas << ": " << vendidoPapas << " libras\n";
    cout << carneMolida << ": " << vendidoCarneMolida << " libras\n";
    cout << carneCerdo << ": " << vendidoCarneCerdo << " libras\n";
    cout << carneAsar << ": " << vendidoCarneAsar << " libras\n";
    cout << cervezaNacional << ": " << vendidoCervezaNacional
         << " botellas\n";
    cout << cervezaExtranjera << ": " << vendidoCervezaExtranjera
         << " botellas\n";
    cout << vino << ": " << vendidoVino << " botellas\n";
    cout << vodka << ": " << vendidoVodka << " botellas\n";

    // Identificar el producto con mayor cantidad vendida
    double mayorVenta = vendidoTomates;
    string productoMasVendido = tomates;

    if (vendidoRepollo > mayorVenta) {
        mayorVenta = vendidoRepollo;
        productoMasVendido = repollo;
    }
    if (vendidoPapas > mayorVenta) {
        mayorVenta = vendidoPapas;
        productoMasVendido = papas;
    }
    if (vendidoCarneMolida > mayorVenta) {
        mayorVenta = vendidoCarneMolida;
        productoMasVendido = carneMolida;
    }
    if (vendidoCarneCerdo > mayorVenta) {
        mayorVenta = vendidoCarneCerdo;
        productoMasVendido = carneCerdo;
    }
    if (vendidoCarneAsar > mayorVenta) {
        mayorVenta = vendidoCarneAsar;
        productoMasVendido = carneAsar;
    }
    if (vendidoCervezaNacional > mayorVenta) {
        mayorVenta = vendidoCervezaNacional;
        productoMasVendido = cervezaNacional;
    }
    if (vendidoCervezaExtranjera > mayorVenta) {
        mayorVenta = vendidoCervezaExtranjera;
        productoMasVendido = cervezaExtranjera;
    }
    if (vendidoVino > mayorVenta) {
        mayorVenta = vendidoVino;
        productoMasVendido = vino;
    }
    if (vendidoVodka > mayorVenta) {
        mayorVenta = vendidoVodka;
        productoMasVendido = productoMasVendido; // Mantener nombre correcto
        mayorVenta = vendidoVodka;
        productoMasVendido = vodka;
    }

    if (mayorVenta > 0) {
        cout << "\nProducto con mayor cantidad vendida: "
             << productoMasVendido << "\n";
        cout << "Cantidad vendida: " << mayorVenta << "\n";
    }
    else {
        cout << "\nNo se vendieron productos.\n";
    }

    cout << "=====================================\n";

    return 0;
}

//Franklin Omar Mendoza Sanchez - 20241002543 