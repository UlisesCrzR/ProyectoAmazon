#include <iostream>
#include <string>
#include "Categoria.h"
using namespace std;

Categoria::Categoria() {
    idCategoria = 0;
    nombre = "";
    descripcion = "";
}

Categoria::Categoria(int _idCategoria, string _nombre, string _descripcion) {
    idCategoria = _idCategoria;
    nombre = _nombre;
    descripcion = _descripcion;
}

int Categoria::GetIdCategoria() {
    return idCategoria;
}

string Categoria::GetNombre() {
    return nombre;
}

string Categoria::GetDescripcion() {
    return descripcion;
}

void Categoria::SetNombre(string _nombre) {
    nombre = _nombre;
}

void Categoria::SetDescripcion(string _descripcion) {
    descripcion = _descripcion;
}
