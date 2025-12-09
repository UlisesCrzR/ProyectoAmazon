#include<iostream>
#include <fstream> // File stream
#include <sstream> // string stream
#include <cstdlib> // convertidores
#include "producto.h"

vector<Producto> Producto::cargarCatalogo() {
    vector<Producto> productos;
    ifstream file("./catalogos/productos.txt");
    if (!file)
        throw runtime_error("Error en productos.txt");

    while (!file.eof()) {
        string nom, edad, area, sueldo;
        getline(file, nom, ',');
        getline(file, edad, ',');
        getline(file, area, ',');
        getline(file, sueldo);
    }

    file.close();
    return productos;
}