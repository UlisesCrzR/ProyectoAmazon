#include <iostream>
#include <string>
#include "Direccion.h"
using namespace std;

Direccion::Direccion()
{
    calle = "";
    colonia = "";
    numero = 0;
    ciudad = "";
    estado = "";
    codigoPostal = 0;
    pais = "";
    referencias = "";
}

Direccion::Direccion(string _calle, string _colonia, int _numero, string _ciudad, string _estado, 
            int _codigoPostal, string _pais, string _referencias)
{
    calle = _calle;
    colonia = _colonia;
    numero = _numero;
    ciudad = _ciudad;
    estado = _estado;
    codigoPostal = _codigoPostal;
    pais = _pais;
    referencias = _referencias;
}

string Direccion::formatoCompleto()
{
    string formato = "Calle: " + calle + 
                    "\nColonia: " + colonia +
                    "\nNumero: " + to_string(numero) + 
                    "\nCiudad: " + ciudad + 
                    "\nEstado: " + estado + 
                    "\nCP: " + to_string(codigoPostal) +
                    "\nPais: " + pais + 
                    "\nReferencias: " + referencias; 
    return formato;
}
