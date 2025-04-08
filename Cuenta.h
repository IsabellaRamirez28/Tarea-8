//
// Created by isara on 28/03/2025.
//

#ifndef CUENTA_H
#define CUENTA_H
#include <vector>
#include "Cliente.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;


class Cuenta {
public:
    Cuenta(int num_cuenta, double saldo, int id_cliente)
        : numCuenta(num_cuenta),
          saldo(saldo),
          idCliente(id_cliente) {}

    int getNumCuenta() const {
        return numCuenta;
    }

    double getSaldo() const {
        return saldo;
    }

    int getidCliente() const {
        return idCliente;
    }

    virtual string getTipo() const = 0;

    virtual ~Cuenta() {}

    virtual void mostrarCuentas() const = 0;

    virtual void aplicarInteres() {}

    virtual json toJson() const {
        return json{{"num_cuenta", numCuenta},
        {"saldo", saldo},
        {"idCliente", idCliente}};
    }

    virtual void consignar(int cant_consignar) {
        saldo += cant_consignar;
        cout << "SALDO NUEVO: " << saldo << endl;
    }

    virtual void retirar(int cant_retirar) = 0;

    virtual void decrementar(int cantidad_transferir) = 0;

    void incrementar(int cantidad_transferir) {
        saldo += cantidad_transferir;
    }

protected:
    int numCuenta;
    double saldo;
    int idCliente;
};



#endif //CUENTA_H
