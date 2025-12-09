#ifndef CARRITOITEM_H
#define CARRITOITEM_H
#include <iostream>
#include <string>
#include "producto.h"
using namespace std;

class CarritoItem{
private:
    Producto producto;
    int cantidad;
    double subtotal;
public:
    CarritoItem(Producto producto, int _cantidad);

    void setCantidad(int cantidad);
    void aumentarCantidad(int n);
    void disminuirCantidad(int n);
    double calcularSubtotal();

    Producto getProducto();
    int getCantidad();
    double getSubtotal();
};

#endif 