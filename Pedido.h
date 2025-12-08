#ifndef __PEDIDO_H__
#define __PEDIDO_H__

#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include "PedidoItem.h"
#include "Direccion.h"
#include "MetodoPago.h"
using namespace std;

class Pedido{
    private:
        string idPedido;
        Cliente cliente;
        string fechaPedido;
        string estado;
        vector<PedidoItem> items;
        Direccion direccionEnvio;
        MetodoPago metodoPago;
        float total;
    public:
        Pedido();

        Pedido(string _idPedido, Cliente _cliente, string _fechaPedido, Direccion _direccionEnvio, MetodoPago _metodoPago);

        double calcularTotal();

        void agregarItem(const PedidoItem& item);

        void actualizarEstado(const string& nuevoEstado);

        string obtenerDetalle() const;

        void procesarPago();

    // Getters
    string Pedido::getIdPedido() const { return idPedido; }
    Cliente Pedido::getCliente() const { return cliente; }
    string Pedido::getFechaPedido() const { return fechaPedido; }
    string Pedido::getEstado() const { return estado; }
    Direccion Pedido::getDireccionEnvio() const { return direccionEnvio; }
    MetodoPago Pedido::getMetodoPago() const { return metodoPago; }
    float Pedido::getTotal() const { return total; }

    // Setters
    void Pedido::setIdPedido(const string& _idPedido) { idPedido = _idPedido; }
    void Pedido::setCliente(const Cliente& _cliente) { cliente = _cliente; }
    void Pedido::setFechaPedido(const string& _fechaPedido) { fechaPedido = _fechaPedido; }
    void Pedido::setEstado(const string& estado) { estado = _estado; }
    void Pedido::setDireccionEnvio(const Direccion& _direccion) { direccionEnvio = _direccionEnvio; }
    void Pedido::setMetodoPago(const MetodoPago& _metodoPago) { metodoPago = _metodoPago; }
    void Pedido::setTotal(const float& _nuevototal) { total = _nuevoTotal; }
};

#endif // __PEDIDO_H__