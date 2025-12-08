#include <iostream>
#include <string>
#include "MetodoPago.h"
using namespace std;

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

int MetodoPago::GetIdMetodoPago() 
{
    return idMetodoPago;
}

string MetodoPago::GetNombre() 
{
    return nombre;
}

string MetodoPago::GetDescripcion() 
{
    return descripcion;
}

void MetodoPago::SetNombre(string _nombre) 
{
    nombre = _nombre;
}

void MetodoPago::SetDescripcion(string _descripcion) 
{
    descripcion = _descripcion;
}
