#ifndef CARRITOITEM_H
#define CARRITOITEM_H
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class CarritoItem{
private:
    Producto producto;
    int cantidad;
    double precioUnitario;
    double subtotal;
public:
    CarritoItem(Producto producto, int cantidad);

    void setCantidad(int cantidad);
    void aumentarCantidad(int n);
    void disminuirCantidad(int n);
    double calcularSubtotal();

    Producto getProducto();
    int getCantidad();
    double getPrecioUnitario();
    double getSubtotal();
}

#endif 