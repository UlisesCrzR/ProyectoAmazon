#ifndef METODOPAGO_H
#define METODOPAGO_H

#include <iostream>
#include <string>
using namespace std;

class MetodoPago {
private:
    int idMetodoPago;
    string numero;
    string vencimiento;

    static int contadorID;

public:
    MetodoPago();
    MetodoPago(string _numero, string _vencimiento);

    int getIdMetodoPago();
    string getNumero();
    string getVencimiento();

    void setNombre(string _numero);
    void setVencimiento(string _vencimiento);
};

#endif // METODOPAGO_H
