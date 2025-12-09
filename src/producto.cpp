#include <iostream>
#include <fstream>   // ifstream
#include <sstream>   // stringstream
#include <cstdlib>   // conversión
#include "producto.h"
using namespace std;

vector<Producto> Producto::cargarCatalogo() {
    vector<Producto> productos;
    ifstream file("./catalogos/productos.txt");

    if (!file)
        throw runtime_error("Error: No se pudo abrir productos.txt");

    while (!file.eof()) {
        string id, nom, desc, precio, stock, idCat, peso, estatus, calif;

        getline(file, id, ',');
        getline(file, nom, ',');
        getline(file, desc, ',');
        getline(file, precio, ',');
        getline(file, stock, ',');
        getline(file, idCat, ',');
        getline(file, peso, ',');
        getline(file, estatus, ',');
        getline(file, calif);

        if (id == "")
            break;

        Producto p;

        p.setIdProducto( atoi(id.c_str()) );
        p.setNombre(nom);
        p.setDescripcion(desc);
        p.setPrecio( atof(precio.c_str()) );
        p.setStock( atoi(stock.c_str()) );
        p.setCategoria( atoi(idCat.c_str()) );
        p.setPeso( atof(peso.c_str()) );
        p.setEstatus(estatus);
        p.setCalificacionPromedio( atof(calif.c_str()) );

        productos.push_back(p);
    }

    file.close();
    return productos;
}


void Producto::setStock(int _cantidad) {
    stock = _cantidad;
}

void Producto::setEstatus(string _estatus) {
    estatus = _estatus;
}

void Producto::setNombre(string _nombre) {
    nombre = _nombre;
}

void Producto::setDescripcion(string _descripcion) {
    descripcion = _descripcion;
}

void Producto::setPrecio(double _precio) {
    precio = _precio;
}

void Producto::setCategoria(int _idCategoria) {
    idCategoria = _idCategoria;
}

void Producto::setPeso(float _peso) {
    peso = _peso;
}

void Producto::setCalificacionPromedio(float _calificacion) {
    calificacionPromedio = _calificacion;
}


int Producto::getIdProducto() {
    return idProducto;
}

string Producto::getNombre() {
    return nombre;
}

string Producto::getDescripcion() {
    return descripcion;
}

double Producto::getPrecio() {
    return precio;
}

int Producto::getStock() {
    return stock;
}

string Producto::getCategoria(vector<Categoria> categorias) {
    for(int i = 0; i < categorias.size(); i++) {
        if (categorias[i].GetIdCategoria() == idCategoria) {
            return categorias[i].GetNombre();
        }
    }
    return "Categoria desconocida";
}

float Producto::getPeso() {
    return peso;
}

string Producto::getEstatus() {
    return estatus;
}

float Producto::getCalificacionPromedio() {
    return calificacionPromedio;
}
