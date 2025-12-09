#ifndef __CARRITO_H__
#define __CARRITO_H__

#include <vector>
#include <string>
#include "CarritoItem.h"

using namespace std;

class Carrito {
private:
    int idCarrito;
    int idCliente;
    vector<CarritoItem> contenido;
    float subtotal;

public:
    Carrito();

    // Métodos funcionales
    void agregarItem(CarritoItem item);
    void eliminarItem(int indice);
    void vaciarCarrito();
    void recalcularSubtotal();

    // Getters
    int getIdCarrito() const;
    int getIdCliente() const;
    vector<CarritoItem> getContenido() const;
    float getSubtotal() const;

    // Setters
    void setIdCarrito(int idCarrito);
    void setIdCliente(int idCliente);
};

#endif // __CARRITO_H__
