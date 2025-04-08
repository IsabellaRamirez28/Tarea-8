//
// Created by isara on 28/03/2025.
//

#ifndef AHORRO_H
#define AHORRO_H
#include "Cuenta.h"


class Ahorro  : public Cuenta{
public:
    Ahorro(int num_cuenta, double saldo, int id_cliente, double tasa_interes)
        : Cuenta(num_cuenta, saldo, id_cliente),
          tasaInteres(tasa_interes) {}

    double getTsasInteres() const {return tasaInteres;}

    void mostrarCuentas() const override {
        cout << "Numero: " << numCuenta;
        cout << ", Saldo: " << saldo;
        cout << ", ID Clinte: " << idCliente;
        cout << ", Tasa Interes: " << tasaInteres;
        cout << ", Tipo: Ahorros" << endl;
    }

    string getTipo() const override {
        return "Ahorros";
    }

    json toJson() const override {
        return json{{"num_cuenta", numCuenta},
        {"saldo", saldo},
        {"idCliente", idCliente},
        {"Tipo", "Ahorros"},
        {"tasaInteres", tasaInteres}};
    }

    void aplicarInteres() override {
        saldo = saldo + (saldo * tasaInteres);
    }

    void retirar(int cant_retirar) override {
        if (cant_retirar < saldo) {
            saldo -= cant_retirar;
            cout << "SALDO NUEVO: " << saldo << endl;
        } else {
            cout << "SALDO INSUFICIENTE" << endl;
        }
    }
    void decrementar(int cantidad_transferir) override {
        if (cantidad_transferir < saldo) {
            saldo -= cantidad_transferir;
            cout << "SALDO NUEVO: " << saldo << endl;
            cout << "TRANSFERENCIA EXITOSA" << endl;
        } else {
            cout << "SALDO INSUFICIENTE" << endl;
        }
    }

private:
    double tasaInteres;

};



#endif //AHORRO_H
