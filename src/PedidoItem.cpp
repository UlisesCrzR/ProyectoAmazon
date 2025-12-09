#include "PedidoItem.h"

PedidoItem::PedidoItem(Producto producto, int cantidad, double precioUnitario){
    producto = producto;
    cantidad = cantidad;
    precioUnitario = precioUnitario;
    subtotal = cantidad * precioUnitario;
}

Producto PedidoItem::getProducto(){
    return producto;
}

int PedidoItem::getCantidad(){
    return cantidad;
}

double PedidoItem::getPrecioUnitario(){
    return precioUnitario;
}

double PedidoItem::getSubtotal(){
    return subtotal;
}


double PedidoItem::obtenerSubtotal(){
    return subtotal;
}
