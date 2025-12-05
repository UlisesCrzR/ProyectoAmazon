#ifndef __CARRITO_H__
#define __CARRITO_H__

#include <vector>
#include "Cliente.h"
#include "CarritoItem.h"
#include <string>

using namespace std;

class Carrito: public CarritoItem, public Cliente {
private:
    string idCarrito;
    vector<CarritoItem> contenido;
    float subtotal;
public:
    Carrito();
    Carrito(string _idcarrito, float _subtotal, vector<CarritoItem> _contenido,);
    void agregarItem(vector<CarritoItem> contenido);
    void agregarItem(CarritoItem item);
    void eliminarItem(vector<CarritoItem> contenido);
    void eliminarItem(int indice);
    void vaciarCarrito(vector<CarritoItem> contenido);
    void pagarCarrito(float subtotal);
    
    // Getters
    string getIdCarrito();
    vector<CarritoItem> getContenido();
    float getSubtotal();
    
    // Setters
    void setIdCarrito(string idCarrito);
    void setContenido(vector<CarritoItem> contenido);
    void setSubtotal(float subtotal);


};
#endif // __CARRITO_H__