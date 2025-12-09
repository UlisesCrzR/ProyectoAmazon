#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include <vector>
#include "metodopago.h"
#include "direccion.h"

using namespace std;

class Cliente{
    private:
        int idCliente;
        int idUsuario;
        string nombre;
        string apellido;
        vector<MetodoPago> metodosPago;
        vector<Direccion> direcciones;
        //vector<int> pedidos;
        static int contadorID;
    public:
        Cliente();
        Cliente(string nombre, string apellido);

        int getIdCliente();
        string getNombre();
        string getApellido();

        int getIdUsuario();
        void setIdUsuario(int _idUsuario);


        vector<Direccion> getDirecciones();
        vector<MetodoPago> getMetodosPago();

        void mostrarMetodosPago();
        void mostrarDirecciones();

        void setIdCliente(int idCliente);
        void setNombre(string nombre);
        void setApellido(string apellido);

        void agregarDireccion(string _calle, string _colonia, int _numero, string _ciudad, string _estado, int _codigoPostal, string _pais, string _referencias);
        void eliminarDireccion(int idDireccion);

        void agregarMetodoPago(string _numero, string _vencimiento);
        void eliminarMetodoPago(int idMetodoPago);
};

#endif // CLIENTE_H