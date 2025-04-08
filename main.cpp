#include <iostream>
#include "json.hpp"
#include "Banco.h"
#include "Cliente.h"
#include <vector>
using namespace std;

int main() {
    Banco banco("Banco Javeriano");
    vector<Cliente> clientes;
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
                        banco.agregarCuentaAhorros(idCliente, tasaInteres, saldo);
                    } else if (tipoCuenta == "CORRIENTE") {
                        double limsobregiro = 5000;
                        cout << "El limite de sobregiro del BANCO JAVERIANO ES 5000" << endl;
                        cout << "Ingrese el dinero (saldo): ";
                        cin >> saldo;
                        banco.agregarCuentaCorriente(idCliente, limsobregiro, saldo);
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
                break;
            }
            case 4: {
                cout << "========OPERACIONES FINANCIERAS========" << endl;
                cout << "1. ALICAR TASA DE INTERES A CUENTAS DE AHORRO";
                cout << "2. TRANSFERIR";
                cout << "3. CONSIGNAR";
                cout << "4. RETIRAR";
                cout << "5. CONSULTAR SALDO" << endl;
                cin >> opcionesFinancieras;
                if (opcionesFinancieras == 1) {
                    banco.aplicarInteres();
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