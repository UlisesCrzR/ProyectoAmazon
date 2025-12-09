#include "Carrito.h"

Carrito::Carrito()
{
    idCarrito = "";
    subtotal = 0.0;
    contenido = {};
}

Carrito::Carrito(string _idcarrito, float _subtotal, vector<CarritoItem> _contenido,)
{
    idCarrito = _idcarrito;
    subtotal = _subtotal;
    contenido = _contenido;
}

void Carrito::agregarItem(vector<CarritoItem> contenido)
{
    // Agregar cada item del vector al contenido del carrito
    for(int i = 0; i < contenido.size(); i++) {
        this->contenido.push_back(contenido[i]);
    }
}

void Carrito::agregarItem(CarritoItem item)
{
    // Agregar un solo producto al carrito
    this->contenido.push_back(item);
}

void Carrito::eliminarItem(vector<CarritoItem> contenido)
{
    // Eliminar múltiples items del carrito
    for(int i = 0; i < contenido.size(); i++) {
        for(int j = 0; j < this->contenido.size(); j++) {
            if(this->contenido[j] == contenido[i]) {
                this->contenido.erase(this->contenido.begin() + j);
                break;
            }
        }
    }
}

void Carrito::eliminarItem(int indice)
{
    // Eliminar un solo producto del carrito por índice
    if(indice >= 0 && indice < this->contenido.size()) {
        this->contenido.erase(this->contenido.begin() + indice);
    }
}

void Carrito::vaciarCarrito(vector<CarritoItem> contenido)
{
    // Vaciar el carrito por completo
    this->contenido.clear();
    this->subtotal = 0.0;
}

// Getters
string Carrito::getIdCarrito()
{
    return this->idCarrito;
}

vector<CarritoItem> Carrito::getContenido()
{
    return this->contenido;
}

float Carrito::getSubtotal()
{
    return this->subtotal;
}

// Setters
void Carrito::setIdCarrito(string idCarrito)
{
    this->idCarrito = idCarrito;
}

void Carrito::setContenido(vector<CarritoItem> contenido)
{
    this->contenido = contenido;
}

void Carrito::setSubtotal(float subtotal)
{
    this->subtotal = subtotal;
}

void Carrito::pagarCarrito(float subtotal)
{
    this->contenido.clear();
    this->subtotal = 0.0;
}






