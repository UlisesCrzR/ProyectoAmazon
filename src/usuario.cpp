#include<iostream>
#include <fstream> // File stream
#include <sstream> // string stream
#include <cstdlib> // convertidores
#include "usuario.h"

Usuario::Usuario()
{
    email = "";
    contrasena = "";
    telefono = "";
    idUsuario = contadorID++;
}

Usuario::Usuario(string _email, string _contrasena, string _telefono)
{
    email = _email;
    contrasena = _contrasena;
    telefono = _telefono;
    idUsuario = contadorID++;
}

vector<Usuario> Usuario::cargarCatalogo() {
    vector<Usuario> usuarios;
    ifstream file("./catalogos/usuarios.txt");
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
    return usuarios;
}

int Usuario::getIdUsuario()
{
    return idUsuario;
}

string Usuario::getEmail()
{
    return email;
}

string Usuario::getContrasena()
{
    return contrasena;
}

string Usuario::getTelefono()
{
    return telefono;
}

void Usuario::setIdUsuario(int _idUsuario)
{
    idUsuario = _idUsuario;
}

void Usuario::setEmail(string _email)
{
    email = _email;
}

void Usuario::setContrasena(string _contrasena)
{
    contrasena = _contrasena;
}

void Usuario::setTelefono(string _telefono)
{
    telefono = _telefono;
}