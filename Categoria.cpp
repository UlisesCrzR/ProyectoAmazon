//Descomentar cuando el Producto.h este listo
/* 
#include <iostream>
#include <string>
#include <vector>
#include "Categoria.h"
#include "Producto.h"
using namespace std;

Categoria::Categoria() 
{
    idCategoria = 0;
    nombre = "";
    descripcion = "";
}

Categoria::Categoria(int _idCategoria, string _nombre, string _descripcion) 
{
    idCategoria = _idCategoria;
    nombre = _nombre;
    descripcion = _descripcion;
}

int Categoria::GetIdCategoria() 
{
    return idCategoria;
}

string Categoria::GetNombre() 
{
    return nombre;
}

string Categoria::GetDescripcion() 
{
    return descripcion;
}

void Categoria::SetNombre(string _nombre) 
{
    nombre = _nombre;
}

void Categoria::SetDescripcion(string _descripcion) 
{
    descripcion = _descripcion;
}

void Categoria::agregarProducto(Producto p) 
{
    productos.push_back(p);
}

void Categoria::eliminarProducto(int idProducto) 
{
    vector<Producto> nuevoVector;
    for (int i = 0; i < productos.size(); i++) 
    {
        if (productos[i].GetIdProducto() != idProducto)
        {
            nuevoVector.push_back(productos[i]);
        }
    }
    productos = nuevoVector;
}

vector<Producto> Categoria::obtenerProductos() 
{
    return productos;
}
*/