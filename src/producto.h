#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <vector>
#include "categoria.h"

using namespace std;

class Producto {
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
    vector<Categoria> categorias;

     static int contadorID;

public:
    Producto();
    Producto(string _nombre, string _descripcion, double _precio,
             int _stock, int _idCategoria, float _peso, string _estatus,
             float _calificacionPromedio);

    static vector<Producto> cargarCatalogo();

    // Setters
    void setIdProducto(int _id);
    void setStock(int _cantidad);
    void setEstatus(string _estatus);
    void setNombre(string _nombre);
    void setDescripcion(string _descripcion);
    void setPrecio(double _precio);
    void setCategoria(int _idCategoria);
    void setPeso(float _peso);
    void setCalificacionPromedio(float _calificacion);

    // Getters
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

#endif