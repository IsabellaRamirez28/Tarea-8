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

    double getTsasInteres() {return tasaInteres;}

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

    void aplicarInteres() {
        saldo = saldo + (saldo * tasaInteres);
    }

private:
    double tasaInteres;

};



#endif //AHORRO_H
