#include <iostream>
#include <string>
#include <vector>
#include "Categoria.h"
#include "Producto.h"
#include <fstream>   // ifstream
#include <sstream>   // stringstream
#include <cstdlib>   // conversión
using namespace std;

Categoria::Categoria() 
{
    idCategoria = 0;
    nombre = "";
    descripcion = "";
}

Categoria::Categoria(string _nombre, string _descripcion) 
{
    idCategoria = ++contadorID;
    nombre = _nombre;
    descripcion = _descripcion;
}

vector<Categoria> Categoria::cargarCatalogo() {
    vector<Categoria> categorias;
    ifstream file("./catalogos/categorias.txt");

    if (!file)
        throw runtime_error("Error: No se pudo abrir categorias.txt");

    while (!file.eof()) {
        string idCat, nombre, descripcion;

        getline(file, idCat, ',');
        getline(file, nombre, ',');
        getline(file, descripcion);

        if (idCat =="")
            break;

        Categoria c;
        c.SetIdCategoria( atoi(idCat.c_str()) );
        c.SetNombre(nombre);
        c.SetDescripcion(descripcion);

        categorias.push_back(c);
    }


    file.close();
    return categorias;
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

void Categoria::SetIdCategoria(int _idCategoria)
{
    idCategoria = _idCategoria;
}

void Categoria::SetNombre(string _nombre) 
{
    nombre = _nombre;
}

void Categoria::SetDescripcion(string _descripcion) 
{
    descripcion = _descripcion;
}