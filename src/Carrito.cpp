#include "Carrito.h"

Carrito::Carrito() {
    idCarrito = 0;
    idCliente = 0;
    subtotal = 0.0;
    contenido = {};
}

void Carrito::agregarItem(CarritoItem item) {
    contenido.push_back(item);
    recalcularSubtotal();
}

void Carrito::eliminarItem(int indice) {
    if (indice >= 0 && indice < contenido.size()) {
        contenido.erase(contenido.begin() + indice);
        recalcularSubtotal();
    }
}

void Carrito::vaciarCarrito() {
    contenido.clear();
    subtotal = 0.0;
}

void Carrito::recalcularSubtotal() {
    subtotal = 0.0;

    for(int i = 0; i < contenido.size(); i++) {
        subtotal += contenido[i].getSubtotal();
    }
}

int Carrito::getIdCarrito() const {
    return idCarrito;
}

int Carrito::getIdCliente() const {
    return idCliente;
}

vector<CarritoItem> Carrito::getContenido() const {
    return contenido;
}

float Carrito::getSubtotal() const {
    return subtotal;
}

void Carrito::setIdCarrito(int idCarrito) {
    this->idCarrito = idCarrito;
}

void Carrito::setIdCliente(int idCliente) {
    this->idCliente = idCliente;
}
