#include "PedidoItem.h"

// Constructor vacío
PedidoItem::PedidoItem() {
    cantidad = 0;
    precioUnitario = 0.0;
    subtotal = 0.0;
    producto = Producto();
}

// Constructor completo
PedidoItem::PedidoItem(Producto p, int cant, double precio) {
    producto = p;
    cantidad = cant;
    precioUnitario = precio;
    subtotal = cantidad * precioUnitario;
}

// Getters
Producto PedidoItem::getProducto() {
    return producto;
}

int PedidoItem::getCantidad() {
    return cantidad;
}

double PedidoItem::getPrecioUnitario() {
    return precioUnitario;
}

double PedidoItem::getSubtotal() {
    return subtotal;
}

double PedidoItem::obtenerSubtotal() {
    return subtotal;
}

// Setters
void PedidoItem::setCantidad(int cant) {
    cantidad = cant;
    subtotal = cantidad * precioUnitario;
}

void PedidoItem::setProducto(Producto p) {
    producto = p;
}

void PedidoItem::setPrecioUnitario(double precio) {
    precioUnitario = precio;
    subtotal = cantidad * precioUnitario;
}
