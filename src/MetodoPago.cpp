#include <iostream>
#include <string>
#include "MetodoPago.h"
using namespace std;

int MetodoPago::contadorID = 1;

MetodoPago::MetodoPago() 
{
    idMetodoPago = ++contadorID;
    numero = "";
    vencimiento = "";
}

MetodoPago::MetodoPago(string _nombre, string _descripcion) 
{
    idMetodoPago = ++contadorID;
    numero = _nombre;
    vencimiento = _descripcion;
}

int MetodoPago::getIdMetodoPago()
{
    return idMetodoPago;
}

string MetodoPago::getNumero()
{
    return numero;
}

string MetodoPago::getVencimiento()
{
    return vencimiento;
}

void MetodoPago::setNombre(string _numero)
{
    numero = _numero; 
}

void MetodoPago::setVencimiento(string _vencimiento)
{
    vencimiento = _vencimiento;
}
