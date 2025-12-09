#include "Direccion.h"
#include <string>

int Direccion::contadorID = 1;

Direccion::Direccion() {
    idDireccion = contadorID++;
    calle = "";
    colonia = "";
    numero = 0;
    ciudad = "";
    estado = "";
    codigoPostal = 0;
    pais = "";
    referencias = "";
}

Direccion::Direccion(string _calle, string _colonia, int _numero,
                     string _ciudad, string _estado,
                     int _codigoPostal, string _pais, string _referencias)
{
    idDireccion = contadorID++;
    calle = _calle;
    colonia = _colonia;
    numero = _numero;
    ciudad = _ciudad;
    estado = _estado;
    codigoPostal = _codigoPostal;
    pais = _pais;
    referencias = _referencias;
}

string Direccion::mostrarDireccion() {
    string formato = 
        "Calle: " + calle + 
        "\nColonia: " + colonia +
        "\nNumero: " + to_string(numero) +
        "\nCiudad: " + ciudad +
        "\nEstado: " + estado +
        "\nCP: " + to_string(codigoPostal) +
        "\nPais: " + pais +
        "\nReferencias: " + referencias;

    return formato;
}

//getters
int Direccion::getIdDireccion() const { 
    return idDireccion; 
}

string Direccion::getCalle() const { 
    return calle; 
}

string Direccion::getColonia() const { 
    return colonia; 
}

int Direccion::getNumero() const { 
    return numero; 
}

string Direccion::getCiudad() const { 
    return ciudad; 
}

string Direccion::getEstado() const { 
    return estado; 
}

int Direccion::getCodigoPostal() const { 
    return codigoPostal; 
}

string Direccion::getPais() const { 
    return pais; 
}

string Direccion::getReferencias() const { 
    return referencias; 
}

//setters

void Direccion::setCalle(const string& _calle) { 
    calle = _calle; 
}

void Direccion::setColonia(const string& _colonia) { 
    colonia = _colonia; 
}

void Direccion::setNumero(int _numero) { 
    numero = _numero; 
}

void Direccion::setCiudad(const string& _ciudad) { 
    ciudad = _ciudad; 
}

void Direccion::setEstado(const string& _estado) { 
    estado = _estado; 
}

void Direccion::setCodigoPostal(int _codigoPostal) { 
    codigoPostal = _codigoPostal; 
}

void Direccion::setPais(const string& _pais) { 
    pais = _pais; 
}

void Direccion::setReferencias(const string& _referencias) { 
    referencias = _referencias; 
}
