#include "CarritoItem.h"

CarritoItem::CarritoItem(Producto producto, int cantidad){
    producto = producto;
    cantidad = cantidad;
    precioUnitario = producto.getPrecio();
    subtotal = calcularSubtotal();
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
        
    subtotal = calcularSubtotal();
}

double CarritoItem::calcularSubtotal(){
    subtotal = cantidad * precioUnitario;
    return subtotal;
}

Producto CarritoItem::getProducto(){
    return producto;
}

int CarritoItem::getCantidad(){
    return cantidad;
}

double CarritoItem::getPrecioUnitario(){
    return precioUnitario;
}

double CarritoItem::getSubtotal(){
    return subtotal;
}