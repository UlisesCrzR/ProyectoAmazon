#ifndef METODOPAGO_H
#define METODOPAGO_H

#include <iostream>
#include <string>
using namespace std;

class MetodoPago {
private:
    int idMetodoPago;
    string nombre;
    string descripcion;

public:
    MetodoPago();
    MetodoPago(int _idMetodoPago, string _nombre, string _descripcion);

    int GetIdMetodoPago();
    string GetNombre();
    string GetDescripcion();

    void SetNombre(string _nombre);
    void SetDescripcion(string _descripcion);
};

#endif // METODOPAGO_H
