#include "CarritoItem.h"

CarritoItem::CarritoItem(Producto _producto, int _cantidad){
    producto = _producto;
    cantidad = _cantidad;
}

void CarritoItem::setCantidad(int cantidad){
    this->cantidad = cantidad;
    subtotal = calcularSubtotal();
}

void CarritoItem::aumentarCantidad(int n){
    cantidad += n;
    subtotal = calcularSubtotal();
}

void CarritoItem::disminuirCantidad(int n){
    if (cantidad - n >= 0)
        cantidad -= n;
    else
        cantidad = 0;
        
    subtotal=calcularSubtotal();
}

double CarritoItem::calcularSubtotal(){
    subtotal = cantidad * producto.getPrecio();
    return subtotal;
}

Producto CarritoItem::getProducto(){
    return producto;
}

int CarritoItem::getCantidad(){
    return cantidad;
}

double CarritoItem::getSubtotal(){
    return subtotal;
}
