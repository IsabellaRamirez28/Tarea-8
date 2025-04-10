//
// Created by isara on 28/03/2025.
//

#ifndef BANCO_H
#define BANCO_H
#include <fstream>
#include <iostream>
#include <vector>

#include "Ahorro.h"
#include "Cliente.h"
#include "Corriente.h"
#include "Cuenta.h"
#include "json.hpp"

using namespace std;

class Banco {
public:
    Banco(const string &nombre)
        : nombre(nombre) {
    }
    string getNombre() {
        return nombre;
    }

    void agregarCliente(string nombre, string direc) {
        clientes.emplace_back(nombre, ++idCliente, direc);
    }
    void agregarCuentaAhorros(int idCliente, double saldo, int tasaInteres) {
        cuentas.push_back(new Ahorro(++num_cuenta, saldo, idCliente, tasaInteres));
    }
    void agregarCuentaCorriente(int idCliente, double saldo, int limsobregiro) {
            cuentas.push_back(new Corriente(++num_cuenta, saldo, idCliente, limsobregiro));
    }
    void mostrarCliente() {
        for (const auto &cliente : clientes) {
            cliente.mostrarClientes();
        }
    }
    void mostrarCuentas() const {
        for (const auto &cuenta : cuentas) {
            cuenta->mostrarCuentas();
        }
    }

    bool existeCliente(int id) const {
        for (const auto& c : clientes) {
            if (c.getId() == id) return true;
        }
        return false;
    }

    void aplicarInteres() {
        for (auto& cuenta : cuentas) {
            cuenta->aplicarInteres();
        }
    }

    void guardarDatos( const string& archivo ) {
        json j;
        j["NOMBRE"] = nombre;
        for (const auto &cliente : clientes) {
            j["CLIENTES"].push_back(cliente.toJson());
        }
        for (const auto &cuenta : cuentas) {
            j["CUENTAS"].push_back(cuenta->toJson());
        }
        ofstream file( archivo );
        if (!file) return;
        file << j.dump(4);
        file.close();
    }

    void numTotalClientes() {
        cout << "Numero de clientes: " << clientes.size() << endl;
    }

    void numTotalCuentas() {
        cout << "Numero de cuentas: " << cuentas.size() << endl;
    }

    void tranferirCuentas(int origen, int destino, int cantidad_transferir) {
        for (const auto &cuenta : cuentas) {
            if (cuenta->getNumCuenta() == origen) {
                cuenta->decrementar(cantidad_transferir);
            }
        }
        for (const auto &cuenta : cuentas) {
            if (cuenta->getNumCuenta() == destino) {
                cuenta->incrementar(cantidad_transferir);
            }
        }
    }

    void consignarEnCuenta(int num_cuenta, int cant_consignar) {
        for (const auto &cuenta : cuentas) {
            if (cuenta->getNumCuenta() == num_cuenta) {
                cuenta->consignar(cant_consignar);
            }
        }
    }

    void retirarDeCuenta(int num_cuenta, int cant_retirar) {
        for (const auto &cuenta : cuentas) {
            if (cuenta->getNumCuenta() == num_cuenta) {
                cuenta->retirar(cant_retirar);
            }
        }
    }

private:
    string nombre;
    vector<Cliente> clientes;
    vector<Cuenta*> cuentas;
    int idCliente = 0;
    int num_cuenta = 99;

};



#endif //BANCO_H
