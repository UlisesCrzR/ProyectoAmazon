#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <string>
#include <vector>
#include "Producto.h"
using namespace std;

class Categoria {
private:
    int idCategoria;
    string nombre;
    string descripcion;
    vector<Producto> productos;

    static int contadorID;

public:
    Categoria();
    Categoria(string _nombre, string _descripcion);

    static vector<Categoria> cargarCatalogo();

    int GetIdCategoria();
    string GetNombre();
    string GetDescripcion();

    void SetIdCategoria(int _idCategoria);
    void SetNombre(string _nombre);
    void SetDescripcion(string _descripcion);

    vector<Categoria> getCategorias();
};

#endif // CATEGORIA_H