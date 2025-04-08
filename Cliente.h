//
// Created by isara on 28/03/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

#include "json.hpp"
using namespace std;
using json = nlohmann::json;


class Cliente {
public:
    Cliente(const string &nombre, const int id, const string &direccion)
        : nombre(nombre),
          id(id),
          direccion(direccion) {
        cout << nombre << " este es tu id: " << id << endl;
    }

    string getNombre() const { return nombre;}

    int getId() const { return id; }

    string getDireccion() const { return direccion; }

    void mostrarClientes() const {
        cout << "Nombre: " << nombre << " " << "Numero ID: " << id << " " << "Direccion: " << direccion << endl;
    }
    json toJson() const {
        return json{
        {"id", id},
        {"nombre", nombre},
        {"direccion", direccion, }};
    }

private:
    string nombre;
    int id;
    string direccion;

};



#endif //CLIENTE_H
