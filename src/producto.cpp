#include <iostream>
#include <fstream>   // ifstream
#include <sstream>   // stringstream
#include <cstdlib>   // atoi, atof
#include <vector>
#include "producto.h"

using namespace std;

int Producto::contadorID = 10;

Producto::Producto()
{
    // Constructor vacío
    idProducto = 0;
    precio = 0.0;
    stock = 0;
    idCategoria = 0;
    peso = 0.0;
    calificacionPromedio = 0.0;
}

Producto::Producto(string _nombre, string _descripcion, double _precio,
             int _stock, int _idCategoria, float _peso, string _estatus,
             float _calificacionPromedio)
{
    idProducto = ++contadorID;
    nombre = _nombre;
    descripcion = _descripcion;
    precio = _precio;
    stock = _stock;
    idCategoria = _idCategoria;
    peso = _peso;
    estatus = _estatus;
    calificacionPromedio = _calificacionPromedio;
}

vector<Producto> Producto::cargarCatalogo() {
    vector<Producto> productos;
    ifstream file("./catalogos/productos.txt"); 

    if (!file) {
        cerr << "Error: No se pudo abrir ./catalogos/productos.txt" << endl;
        return productos;
    }

    while (file.good()) {
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

        // Limpieza básica por si el archivo tiene líneas vacías al final
        if (id.empty()) continue; 

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

// Implementación que faltaba y causaba el "undefined reference"
void Producto::setIdProducto(int _id)
{
    idProducto = _id;
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

string Producto::getCategoria() {
    // CORRECCIÓN: Usar size_t para evitar warning de comparación
    for(size_t i = 0; i < categorias.size(); i++) {
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