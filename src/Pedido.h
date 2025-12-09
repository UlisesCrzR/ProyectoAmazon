#ifndef __PEDIDO_H__
#define __PEDIDO_H__

#include <iostream>
#include <string>
#include <vector>
#include "Direccion.h"
#include "MetodoPago.h"
#include "PedidoItem.h"
#include "Carrito.h"

using namespace std;

class Pedido {
private:
    int idPedido;
    string fechaPedido;
    string estado;
    vector<PedidoItem> items;
    Direccion direccionEnvio;
    MetodoPago metodoPago;
    float total;

    static int contadorID;

public:
    Pedido();
    Pedido(string _fechaPedido, Direccion _direccionEnvio, MetodoPago _metodoPago);

    double calcularTotal();
    void setContenido(const Carrito& carrito);
    void agregarItem(PedidoItem item);
    void actualizarEstado(string nuevoEstado);
    string obtenerDetalle() const;
    void procesarPago();

    // Getters
    int getIdPedido() const;
    string getFechaPedido() const;
    string getEstado() const;
    Direccion getDireccionEnvio() const;
    MetodoPago getMetodoPago() const;
    float getTotal() const;

    // Setters
    void setIdPedido(int _idPedido);
    void setFechaPedido(const string& _fechaPedido);
    void setEstado(const string& _estado);
    void setDireccionEnvio(const Direccion& d);
    void setMetodoPago(const MetodoPago& m);
    void setTotal(const float& t);
};

#endif
