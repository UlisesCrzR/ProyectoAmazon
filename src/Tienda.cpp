#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm> 

using namespace std;
#include "tienda.h"
#include "usuario.h"

Tienda::Tienda()
{
    productos = {};
    clientes = {};
    nombre = "";
}

Tienda::Tienda(string _nombre)
{
    nombre = _nombre;
}

void Tienda::cargarCatalogos() {
    productos = Producto::cargarCatalogo();
    usuarios = Usuario::cargarCatalogo();
}

int Tienda::iniciarSesion(string _email, string _contrasena)
{
    for(size_t i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getEmail() == _email && usuarios[i].getContrasena() == _contrasena){
            cout << "Inicio de sesion exitoso. Bienvenido, " << _email << "." << endl;
            return usuarios[i].getIdUsuario();
        }
    }
    cout << "Usuario o contraseña incorrectos." << endl;
    return -1;
}

bool Tienda::registrarse(string _email, string _contrasena, string _telefono)
{
    std::regex email_regex(R"(^[A-Za-z0-9._%+\-]+@[A-Za-z0-9.\-]+\.[A-Za-z]{2,}$)");

    if (!std::regex_match(_email, email_regex)) {
        cout << "Email inválido: " << _email << endl;
        return false;
    }

    for (size_t i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].getEmail() == _email) {
            cout << "El email ya está registrado: " << _email << endl;
            return false;
        }
    }

    usuarios.emplace_back(_email, _contrasena, _telefono);
    cout << "Registro exitoso para: " << _email << endl;
    return true;
}

void Tienda::eliminarUsuario(int _idUsuario)
{
    usuarios.erase(
    remove_if(usuarios.begin(), usuarios.end(),
                [_idUsuario](Usuario &u) { return u.getIdUsuario() == _idUsuario; }),
    usuarios.end());
}

void Tienda::agregarProducto(
            string _nombre,
            string _descripcion,
            double _precio,
            int _stock,
            int _idCategoria,
            float _peso,
            string _estatus,
            float _calificacionPromedio)
{
    productos.emplace_back(_nombre, _descripcion, _precio, _stock, _idCategoria, _peso, _estatus, _calificacionPromedio);
}

void Tienda::eliminarProducto(int _idProducto)
{
    productos.erase(
    remove_if(productos.begin(), productos.end(),
                [_idProducto](Producto &d) { return d.getIdProducto() == _idProducto; }),
    productos.end());
}

void Tienda::nuevaCategoria(string _nombre, string _descripcion)
{
    Categoria categoria(_nombre, _descripcion);
    categorias.push_back(categoria);
}

void Tienda::registrarCliente(string _nombre, string _apellido, string _direccion, string _metodoPago)
{
    Cliente cliente(_nombre, _apellido);
    if(!usuarios.empty()) {
        cliente.setIdUsuario( usuarios.back().getIdUsuario() );  
    }
    clientes.push_back(cliente);
}

void Tienda::eliminarCliente(int _idCliente)
{
    clientes.erase(
    remove_if(clientes.begin(), clientes.end(),
                [_idCliente](Cliente &c) { return c.getIdCliente() == _idCliente; }),
    clientes.end());
}

void Tienda::mostrarProductos()
{
    for(size_t i = 0; i < productos.size(); i++){
        cout<<"ID Producto: "<<productos[i].getIdProducto()<<endl;
        cout<<"Nombre: "<<productos[i].getNombre()<<endl;
        cout<<"Descripción: "<<productos[i].getDescripcion()<<endl;
        cout<<"Precio: "<<productos[i].getPrecio()<<endl;
        cout<<"Stock: "<<productos[i].getStock()<<endl;
        cout<<"Categoría: "<<productos[i].getCategoria()<<endl;
        cout<<"Peso: "<<productos[i].getPeso()<<endl;
        cout<<"Estatus: "<<productos[i].getEstatus()<<endl;
        cout<<"Calificación Promedio: "<<productos[i].getCalificacionPromedio()<<endl;
        cout<<"-------------------------------"<<endl;
    }
}

string Tienda::getNombre()
{
    return nombre;
}

vector<Cliente> Tienda::getClientes()
{
    return clientes;
}

vector<Categoria> Tienda::getCategorias()
{
    return categorias;
}

vector<Producto> Tienda::getProductos()
{
    return productos;
}

Producto Tienda::getProductoById(int _idProducto)
{
    for(size_t i = 0; i < productos.size(); i++){
        if(productos[i].getIdProducto() == _idProducto){
            return productos[i];
        }
    }
    return Producto();
}