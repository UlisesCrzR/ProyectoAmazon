#ifndef PEDIDOITEM_H
#define PEDIDOITEM_H

#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class PedidoItem {
private:
    Producto producto;
    int cantidad;
    double precioUnitario;
    double subtotal;

public:
    PedidoItem();
    PedidoItem(Producto producto, int cantidad, double precioUnitario);

    // Getters
    Producto getProducto();
    int getCantidad();
    double getPrecioUnitario();
    double getSubtotal();
    double obtenerSubtotal();

    // Setters
    void setCantidad(int cantidad);
    void setProducto(Producto producto);
    void setPrecioUnitario(double precio);
};

#endif
