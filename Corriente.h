//
// Created by isara on 28/03/2025.
//

#ifndef CORRIENTE_H
#define CORRIENTE_H
#include "Cuenta.h"


class Corriente : public Cuenta{
public:
    Corriente(int num_cuenta, double saldo, int id_cliente, int lim_sobregiro)
        : Cuenta(num_cuenta, saldo, id_cliente),
          limSobregiro(lim_sobregiro) {
    }

    double getLimsobreGiro() const {return limSobregiro;}

    void mostrarCuentas() const override {
        cout << "Numero: " << numCuenta;
        cout << "Saldo: " << saldo;
        cout << "ID Clinte: " << idCliente;
        cout << "Limite de sobregiro: " << limSobregiro;
        cout << "Tipo: Corriente" << endl;
    }

    string getTipo() const override {
        return "Corriente";
    }

    json toJson() const override {
        return json{{"num_cuenta", numCuenta},
        {"saldo", saldo},
        {"idCliente", idCliente},
        {"Tipo", "Corriente"},
        {"Limite de Sobregiro", limSobregiro}};
    }

private:
    int limSobregiro;

};



#endif //CORRIENTE_H
