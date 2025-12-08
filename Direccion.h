#ifndef __DIRECCION_H__
#define __DIRECCION_H__

#include <iostream>
#include <string>
using namespace std;

class Direccion {
    private:
        string calle;
        string colonia;
        int numero;
        string ciudad;
        string estado;
        int codigoPostal;
        string pais;
        string referencias;

    public:
        Direccion();

        Direccion(string _calle, string _colonia, int _numero, string _ciudad, string _estado, 
            int _codigoPostal, string _pais, string _referencias);

        string formatoCompleto();

        // Getters
        string Direccion::getCalle() const { return calle; }
        int Direccion::getNumero() const { return numero; }
        string Direccion::getColonia() const { return colonia; }
        string Direccion::getCiudad() const { return ciudad; }
        string Direccion::getEstado() const { return estado; }
        int Direccion::getCodigoPostal() const { return codigoPostal; }
        string Direccion::getPais() const { return pais; }
        string Direccion::getReferencias() const { return referencias; }

        // Setters
        void Direccion::setCalle(const string& _calle) { calle = _calle; }
        void Direccion::setNumero(int _numero) { numero = _numero; }
        void Direccion::setColonia(const string& _colonia) { colonia = _colonia; }
        void Direccion::setCiudad(const string& _ciudad) { ciudad = _ciudad; }
        void Direccion::setEstado(const string& _estado) { estado = _estado; }
        void Direccion::setCodigoPostal(const int& _codigoPostal) { codigoPostal = _codigoPostal; }
        void Direccion::setPais(const string& _pais) { pais = _pais; }
        void Direccion::setReferencias(const string& _referencias) { referencias = _referencias; }
};
#endif // __DIRECCION_H__