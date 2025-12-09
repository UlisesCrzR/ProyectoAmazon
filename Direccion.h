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
        string getCalle() const ;
        int getNumero() const ;
        string getColonia() const;
        string getCiudad() const ;
        string getEstado() const ;
        int getCodigoPostal() const ;
        string getPais() const ;
        string getReferencias() const ;

        // Setters
        void setCalle(const string& _calle) ;
        void setNumero(int _numero) ;
        void setColonia(const string& _colonia) ;
        void setCiudad(const string& _ciudad) ;
        void setEstado(const string& _estado);
        void setCodigoPostal(const int& _codigoPostal);
        void setPais(const string& _pais) ;
        void setReferencias(const string& _referencias) ;
};
#endif // __DIRECCION_H__