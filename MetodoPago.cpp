#include <iostream>
#include <string>
#include "MetodoPago.h"
using namespace std;

MetodoPago::MetodoPago() 
{
    idMetodoPago = 0;
    nombre = "";
    descripcion = "";
}

MetodoPago::MetodoPago(int _idMetodoPago, string _nombre, string _descripcion) 
{
    idMetodoPago = _idMetodoPago;
    nombre = _nombre;
    descripcion = _descripcion;
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
