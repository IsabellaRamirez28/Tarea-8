

// === Comienzo de Ahorro.cpp ===

//
// Created by isara on 28/03/2025.
//

#include "Ahorro.h"

// === Fin de Ahorro.cpp ===


// === Comienzo de Banco.cpp ===

//
// Created by isara on 28/03/2025.
//

#include "Banco.h"

// === Fin de Banco.cpp ===


// === Comienzo de Cliente.cpp ===

//
// Created by isara on 28/03/2025.
//

#include "Cliente.h"

// === Fin de Cliente.cpp ===


// === Comienzo de Corriente.cpp ===

//
// Created by isara on 28/03/2025.
//

#include "Corriente.h"

// === Fin de Corriente.cpp ===


// === Comienzo de Cuenta.cpp ===

//
// Created by isara on 28/03/2025.
//

#include "Cuenta.h"

// === Fin de Cuenta.cpp ===


// === Comienzo de main.cpp ===

#include <iostream>
#include "json.hpp"

int main() {

    return 0;
}
// === Fin de main.cpp ===


// === Comienzo de todo_en_uno.cpp ===


// === Fin de todo_en_uno.cpp ===


// === Comienzo de Ahorro.h ===

//
// Created by isara on 28/03/2025.
//

#ifndef AHORRO_H
#define AHORRO_H



class Ahorro {
private:
    int tasaInteres;

};



#endif //AHORRO_H

// === Fin de Ahorro.h ===


// === Comienzo de Banco.h ===

//
// Created by isara on 28/03/2025.
//

#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include <vector>
#include "Cliente.h"
#include "Cuenta.h"
#include "json.hpp"

using namespace std;

class Banco {
public:
    Banco(const string &nombre)
        : nombre(nombre) {
    }
    void agregarCliente(string num_Cliente, int id, string direc) {
        clientes.emplace_back(num_Cliente, id, direc);
    }
    void agregarCuenta(string num_cuenta, double saldo, id_cliente) {
        clientes.emplace_back(num_cuenta, saldo, int id_cliente);
    }
    void mostrar

private:
    string nombre;
    vector<Cliente> clientes;
    vector<Cuenta> cuentas;
};



#endif //BANCO_H

// === Fin de Banco.h ===


// === Comienzo de Cliente.h ===

//
// Created by isara on 28/03/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
using namespace std;


class Cliente {
public:
    Cliente(const string &nombre, int id, const string &direccion)
        : nombre(nombre),
          id(id),
          direccion(direccion) {
    }
    void mostrarClientes() const {
        cout << nombre << " " << id << " " << direccion << endl;
    }

private:
    string nombre;
    int id;
    string direccion;

};



#endif //CLIENTE_H

// === Fin de Cliente.h ===


// === Comienzo de Corriente.h ===

//
// Created by isara on 28/03/2025.
//

#ifndef CORRIENTE_H
#define CORRIENTE_H



class Corriente {
private:
    int limSobrecargo;

};



#endif //CORRIENTE_H

// === Fin de Corriente.h ===


// === Comienzo de Cuenta.h ===

//
// Created by isara on 28/03/2025.
//

#ifndef CUENTA_H
#define CUENTA_H
#include <vector>
#include "Cliente.h"

using namespace std;


class Cuenta {
public:
    Cuenta(int num_cuenta, double saldo, Cliente *cliente_asociado)
        : numCuenta(num_cuenta),
          saldo(saldo),
          clienteAsociado(cliente_asociado) {
    }
    void mostrarCuentas() {}

protected:
    int numCuenta;
    double saldo;
    Cliente* clienteAsociado;
};



#endif //CUENTA_H

// === Fin de Cuenta.h ===

