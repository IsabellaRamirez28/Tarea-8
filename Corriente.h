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
        cout << ", Saldo: " << saldo;
        cout << ", ID Clinte: " << idCliente;
        cout << ", Limite de sobregiro: " << limSobregiro;
        cout << ", Tipo: Corriente" << endl;
    }

    string getTipo() const override {
        return "Corriente";
    }

    json toJson() const override {
        return json{{"num_cuenta", numCuenta},
        {"saldo", saldo},
        {"idCliente", idCliente},
        {"Limite de Sobregiro", limSobregiro},
        {"Tipo", "Corriente"}};
    }

    void retirar(int cant_retirar) override {
        if (cant_retirar < saldo + limSobregiro) {
            saldo -= cant_retirar;
            cout << "SALDO NUEVO: " << saldo << endl;
        } else {
            cout << "SALDO INSUFICIENTE" << endl;
        }
    }

    void decrementar(int cantidad_transferir) override {
        if (cantidad_transferir < saldo + limSobregiro) {
            saldo -= cantidad_transferir;
            cout << "SALDO NUEVO: " << saldo << endl;
            cout << "TRANSFERENCIA EXITOSA" << endl;
        } else {
            cout << "SALDO INSUFICIENTE" << endl;
        }
    }

private:
    int limSobregiro;

};



#endif //CORRIENTE_H
