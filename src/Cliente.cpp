#include <iostream>
#include <algorithm>
#include "Cliente.h"

int Cliente::contadorID = 0;

Cliente::Cliente()
{
    nombre = "";
    apellido = "";
    idCliente = contadorID++;
    idUsuario = 0;
    metodosPago = {};
    direcciones = {};
}

Cliente::Cliente(string _nombre, string _apellido)
{
    nombre = _nombre;
    apellido = _apellido;
    idCliente = ++contadorID;
}

int Cliente::getIdCliente()
{
    return idCliente;
}

string Cliente::getNombre()
{
    return nombre;
}

string Cliente::getApellido()
{
    return apellido;
}

Carrito Cliente::getCarrito() 
{ 
    return carrito; 
}

int Cliente::getIdUsuario()
{
    return idUsuario;
}

void Cliente::setIdUsuario(int _idUsuario)
{
    idUsuario = _idUsuario;
}

vector<Direccion> Cliente::getDirecciones()
{
    return direcciones;
}

vector<MetodoPago> Cliente::getMetodosPago()
{
    return metodosPago;
}

void Cliente::mostrarMetodosPago()
{
    for(size_t i = 0; i<  metodosPago.size(); i++){
        cout<<"--- ID Método de Pago: ---"<<metodosPago[i].getIdMetodoPago()<<endl;
        cout<<"Número: "<<metodosPago[i].getNumero()<<endl;
        cout<<"Vencimiento: "<<metodosPago[i].getIdMetodoPago()<<endl;
    }
}

void Cliente::mostrarDirecciones()
{
    for(size_t i = 0; i< direcciones.size(); i++){
        cout<<"--- ID Dirección: ---"<<direcciones[i].getIdDireccion()<<endl;
        cout<<"Calle: "<<direcciones[i].getCalle()<<endl;
        cout<<"Colonia: "<<direcciones[i].getColonia()<<endl;
        cout<<"Número: "<<direcciones[i].getNumero()<<endl;
        cout<<"Ciudad: "<<direcciones[i].getCiudad()<<endl;
        cout<<"Estado: "<<direcciones[i].getEstado()<<endl;
        cout<<"Código Postal: "<<direcciones[i].getCodigoPostal()<<endl;
        cout<<"País: "<<direcciones[i].getPais()<<endl;
        cout<<"Referencias: "<<direcciones[i].getReferencias()<<endl;
    }
}

void Cliente::setIdCliente(int _idCliente)
{
    idCliente = _idCliente;
}

void Cliente::setNombre(string _nombre)
{
    nombre = _nombre;
}

void Cliente::setApellido(string _apellido)
{
    apellido = _apellido;
}

void Cliente::agregarDireccion(string _calle, string _colonia, int _numero, string _ciudad, string _estado, int _codigoPostal, string _pais, string _referencias)
{
    Direccion d(_calle, _colonia, _numero, _ciudad, _estado, _codigoPostal, _pais, _referencias);
    direcciones.push_back(d);
}

void Cliente::eliminarDireccion(int _idDireccion)
{
    direcciones.erase(
        remove_if(direcciones.begin(), direcciones.end(),
                   [_idDireccion](Direccion &d) { return d.getIdDireccion() == _idDireccion; }),
        direcciones.end());
}

void Cliente::agregarMetodoPago(string _numero, string _vencimiento)
{
    MetodoPago mp(_numero, _vencimiento);
    metodosPago.push_back(mp);
}

void Cliente::eliminarMetodoPago(int _idMetodoPago)
{
    metodosPago.erase(remove_if(metodosPago.begin(), metodosPago.end(), [_idMetodoPago](MetodoPago &m) {
        return m.getIdMetodoPago() == _idMetodoPago;
    }), metodosPago.end());
}

void Cliente::addCarritoItem(Producto p, int cantidad)
{
    carrito.agregarItem( CarritoItem(p, cantidad) );
}

void Cliente::realizarPedido(string _fecha, Direccion _direccionEnvio, MetodoPago _metodoPago)
{
    Pedido nuevoPedido(_fecha, _direccionEnvio, _metodoPago);

    vector<CarritoItem> items = carrito.getContenido();

    for (size_t i = 0; i < items.size(); i++) {
        PedidoItem item;
        item.setProducto(items[i].getProducto());
        item.setCantidad(items[i].getCantidad());
        nuevoPedido.agregarItem(item);
    }

    pedidos.push_back(nuevoPedido);

    carrito.vaciarCarrito();
}

vector<Pedido> Cliente::getPedidos()
{
    return pedidos;
}

