#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <string>
using namespace std;

class Categoria {
private:
    int idCategoria;
    string nombre;
    string descripcion;

public:
    Categoria();
    Categoria(int _idCategoria, string _nombre, string _descripcion);

    int GetIdCategoria();
    string GetNombre();
    string GetDescripcion();

    void SetNombre(string _nombre);
    void SetDescripcion(string _descripcion);
};

#endif // CATEGORIA_H
