#ifndef TIENDA_H
#define TIENDA_H
#include <iostream>
#include <string>
#include <vector>
#include "producto.h"
#include "usuario.h"
#include "Cliente.h"
#include "categoria.h"

using namespace std;

class Tienda{
    private:
        string nombre;
        vector<Producto> productos;
        vector<Usuario> usuarios; // Lista de usuarios del sistema
        vector<Cliente> clientes; // Lista de clientes registrados
        vector<Categoria> categorias; // Lista de categorías de productos

    public:
        Tienda();
        Tienda(string _nombre);

        void cargarCatalogos();

        int iniciarSesion(string _email, string _contrasena);
        bool registrarse(string _email, string _contrasena, string _telefono);
        
        void eliminarUsuario(int _idUsuario);

        void agregarProducto(
            string _nombre,
            string _descripcion,
            double _precio,
            int _stock,
            int _idCategoria,
            float _peso,
            string _estatus,
            float _calificacionPromedio
        );

        void eliminarProducto(int _idProducto);

        void nuevaCategoria(string _nombre, string _descripcion);
        
        void registrarCliente(string _nombre, string _apellido, string _direccion, string _metodoPago);
        void eliminarCliente(int _idCliente);

        void mostrarProductos();

        string getNombre();

        vector<Cliente> getClientes();
        vector<Categoria> getCategorias();
        vector<Producto> getProductos();

        Producto getProductoById(int _idProducto);
};

#endif // TIENDA_H