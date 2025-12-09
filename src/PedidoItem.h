#ifndef PEDIDOITEM_H
#define PEDIDOITEM_H
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;


class PedidoItem{
   private:
    Producto producto;
    int cantidad;
    double precioUnitario;
    double subtotal;
public:
    PedidoItem(Producto producto, int cantidad, double precioUnitario);

    Producto getProducto();
    int getCantidad();
    double getPrecioUnitario();
    double getSubtotal() const;
    
    double obtenerSubtotal();
};

#endif 