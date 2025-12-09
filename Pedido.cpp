#include <iostream>
#include <iomanip>
#include "Pedido.h"
using namespace std;


Pedido::Pedido()
{
    idPedido = "";
    fechaPedido = "";
    total = 0.0f;
    estado = "";
}

Pedido::Pedido(string _idPedido, Cliente _cliente, string _fechaPedido, Direccion _direccionEnvio, MetodoPago _metodoPago)
{
    idPedido = _idPedido;
    cliente = _cliente;
    fechaPedido = _fechaPedido;
    direccionEnvio = _direccionEnvio;
    metodoPago = _metodoPago;
    estado = "Pendiente";
}

double Pedido::calcularTotal()
{
    for (const auto& item : items){
        total += item.obtenerSubtotal();
    }

   return static_cast<double>(total);
}

void Pedido::agregarItem(PedidoItem item)
{
    items.push_back(item);
    calcularTotal();
}

void Pedido::actualizarEstado(string nuevoEstado)
{
    estado = nuevoEstado;
}

string Pedido::obtenerDetalle()
{
    string detalle = "ID: " + idPedido + 
                    "\nCliente: " + cliente.getNombre() +
                    "\nFecha: " + fechaPedido + 
                    "\nEstado: " + estado + 
                    "\nTotal: " + to_string(total);
    return detalle;
}

void Pedido::procesarPago()
{
    cout << "--- Iniciando Proceso de Pago ---" << endl;
    cout << "Pedido ID: " << idPedido << endl;
    cout << "Monto a cobrar: $" << total << endl;

    cout << "Validar metodo de pago: " << metodoPago.validar() << endl;

    if (total > 0 and ) {
        cout << "Validando fondos..." << endl;
        cout << "Transaccion aprobada." << endl;

        this->actualizarEstado("Pagado");
        
        cout << "Nuevo estado del pedido: " << this->estado << endl;
    } else {
        cout << "Error: El total del pedido es $0. No se puede procesar." << endl;
        this->actualizarEstado("Error en Pago");
    }
}

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