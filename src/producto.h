#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>
#include <vector>
#include "categoria.h"
using namespace std;

class Producto{
    protected:
        int idProducto;
        string nombre;
        string descripcion;
        double precio;
        int stock;
        int idCategoria;
        float peso;
        string estatus;
        float calificacionPromedio;
    public:
        static vector<Producto> Producto::cargarCatalogo();

        void setStock(int _cantidad);
        void setEstatus(string _estatus);
        void setNombre(string _nombre);
        void setDescripcion(string _descripcion);
        void setPrecio(double _precio);
        void setCategoria(int _idCategoria);
        void setPeso(float _peso);
        void setCalificacionPromedio(float _calificacion);

        int getIdProducto();
        string getNombre();
        string getDescripcion();
        double getPrecio();
        int getStock();
        string getCategoria();
        float getPeso();
        string getEstatus();
        float getCalificacionPromedio();
};

#endif // PRODUCTO_H