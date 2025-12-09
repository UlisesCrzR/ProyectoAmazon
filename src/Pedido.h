#ifndef __PEDIDO_H__
#define __PEDIDO_H__

#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include "PedidoItem.h"
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
    string getIdPedido() const ;
    Cliente getCliente() const ;
    string getFechaPedido() const ;
    string getEstado() const ;
    Direccion getDireccionEnvio() const ;
    MetodoPago getMetodoPago() const ;
    float getTotal() const ;

    // Setters
    void setIdPedido(const string& _idPedido) ;
    void setCliente(const Cliente& _cliente) ;
    void setFechaPedido(const string& _fechaPedido) ;
    void setEstado(const string& estado) ;
    void setDireccionEnvio(const Direccion& _direccion) ;
    void setMetodoPago(const MetodoPago& _metodoPago) ;
    void setTotal(const float& _nuevototal) ;
};

#endif // __PEDIDO_H__