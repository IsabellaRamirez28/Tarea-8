#include <iostream>
#include "json.hpp"
#include "Banco.h"
#include "Cliente.h"
#include <vector>
using namespace std;

int main() {
    Banco banco("Banco Javeriano");
    string nombreCliente, direccionCliente, tipoCuenta;
    int saldo = 0, numCuenta, idCliente, negativoCorriente, opcion, opcionClientes, opcionCuentas, opcionEstadisticas, opcionesFinancieras;

    do {
        cout << "===========MENU BANCO JAVERIANO==========" << endl;
        cout << "1. MANTENIMIENTO DE CLIENTES" << endl;
        cout << "2. MANTENIMIENTO DE CUENTAS" << endl;
        cout << "3. ESTADISTICAS" << endl;
        cout << "4. OPERACIONES FINANCIERAS" << endl;
        cout << "5. SALIR" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "========MANTENIMIENTO DE CLIENTES========" << endl;
                cout << "1. AGREGAR CLIENTE" << endl;
                cout << "2. LISTAR CLIENTES" << endl;
                cin >> opcionClientes;
                if (opcionClientes == 1) {
                    cout << "========AGREGAR CLIENTE========" << endl;
                    cout << "INGRESE SU NOMBRE: " << endl;
                    cin >> nombreCliente;
                    cout << "INGRESE SU DIRECCION: " << endl;
                    cin >> direccionCliente;
                    banco.agregarCliente(nombreCliente, direccionCliente);
                    break;
                } if (opcionClientes == 2) {
                    cout << "========LISTAR CLIENTES========" << endl;
                    banco.mostrarCliente();
                    break;
                }
            }
            case 2: {
                cout << "========MANTENIMIENTO DE CUENTAS========" << endl;
                cout << "1. AGREGAR CUENTA" << endl;
                cout << "2. LISTAR CUENTAS" << endl;
                cin >> opcionCuentas;
                if (opcionCuentas == 1) {
                    cout << "========AGREGAR CUENTA========" << endl;
                    cout << "Ingrese su numero ID: ";
                    cin >> idCliente;
                    if (!banco.existeCliente(idCliente)) {
                        cout << "ID no valido. El cliente no existe.\n";
                        break;
                    }
                    cout << "Ingrese tipo de Cuenta a crear (AHORROS/CORRIENTE): ";
                    cin >> tipoCuenta;
                    if (tipoCuenta == "AHORROS") {
                        double tasaInteres = 0.02;
                        cout << "La tasa de interes del BANCO JAVERIANO ES 2%" << endl;
                        cout << "Ingrese el dinero (saldo): " << endl;
                        cin >> saldo;
                        banco.agregarCuentaAhorros(idCliente, saldo, tasaInteres);
                    } else if (tipoCuenta == "CORRIENTE") {
                        double limsobregiro = 5000;
                        cout << "El limite de sobregiro del BANCO JAVERIANO ES 5000" << endl;
                        cout << "Ingrese el dinero (saldo): ";
                        cin >> saldo;
                        banco.agregarCuentaCorriente(idCliente, saldo, limsobregiro);
                    } else {
                        cout << "TIPO DE CUENTA INVALIDA " << endl;
                    }
                } else if (opcionCuentas == 2) {
                    cout << "========LISTAR CUENTAS========" << endl;
                    banco.mostrarCuentas();
                } else {
                    cout << "OPCION INVALIDA " << endl;
                }
                break;
            }
            case 3: {
                cout << "========ESTADISTICAS========" << endl;
                cout << "1. TOTAL CLIENTES" << endl;
                cout << "2. TOTAL DE CUENTAS" << endl;
                cout << "3. PROMEDIO DEL SALDO DE LAS CUENTAS" << endl;
                cout << "4. NUMERO DE CUENTAS DE AHORRO" << endl;
                cout << "5. NUMERO DE CUENTAS CORRIENTES" << endl;
                cin >> opcionEstadisticas;
                if (opcionEstadisticas == 1) {
                    cout << "========TOTAL CLIENTES========" << endl;
                    banco.numTotalClientes();
                } else if (opcionEstadisticas == 2) {
                    cout << "========TOTAL DE CUENTAS========" << endl;
                    banco.numTotalCuentas();
                }
                break;
            }
            case 4: {
                cout << "========OPERACIONES FINANCIERAS========" << endl;
                cout << "1. ALICAR TASA DE INTERES A CUENTAS DE AHORRO" << endl;
                cout << "2. TRANSFERIR" << endl;
                cout << "3. CONSIGNAR" <<endl;
                cout << "4. RETIRAR" << endl;
                cin >> opcionesFinancieras;
                if (opcionesFinancieras == 1) {
                    banco.aplicarInteres();
                } else if (opcionesFinancieras == 2) {
                    cout << "========TRANSFERIR========" << endl;
                    int cantidadTransferir, origen, destino;
                    cout << "Ingrese el numero de cuenta origen: ";
                    cin >> origen;
                    cout << "Ingrese el numero de cuenta destino: ";
                    cin >> destino;
                    cout << "Ingrese la cantidad a transferir: ";
                    cin >> cantidadTransferir;
                    // banco.tranferirCuentas(origen, destino, cantidadTransferir);
                } else if (opcionesFinancieras == 3) {
                    int cantConsignar;
                    cout << "========CONSIGNAR========" << endl;
                    cout << "Ingrese el numero de cuenta a consignar: ";
                    cin >> numCuenta;
                    cout << "Ingrese el dinero a consignar: ";
                    cin >> cantConsignar;
                    banco.consignarEnCuenta(numCuenta, cantConsignar);
                } else if (opcionesFinancieras == 4) {
                    int cantRetirar;
                    cout << "========RETIRAR========" << endl;
                    cout << "Ingrese el numero de cuenta del cual desea retirar: ";
                    cin >> numCuenta;
                    cout << "Ingrese el dinero a retirar: ";
                    cin >> cantRetirar;
                    banco.retirarDeCuenta(numCuenta, cantRetirar);
                } else {
                    cout << "OPCION INVALIDA " << endl;
                }
                break;
            }
            case 5:
                banco.guardarDatos("../bancojaveriano.json");
                cout << "DATOS GUARDADOS" << endl;
            default:
                cout << "OPCION INVALIDA.\n";
        }
    } while (opcion != 5);

    return 0;
}