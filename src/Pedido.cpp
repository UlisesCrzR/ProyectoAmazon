#include "Pedido.h"
#include <iostream>
#include <iomanip>

int Pedido::contadorID = 0;

Pedido::Pedido() {
    idPedido = ++contadorID;
    fechaPedido = "";
    estado = "Pendiente";
    total = 0.0;
}

Pedido::Pedido(string _fechaPedido, Direccion _direccionEnvio, MetodoPago _metodoPago) {
    idPedido = ++contadorID;
    fechaPedido = _fechaPedido;
    direccionEnvio = _direccionEnvio;
    metodoPago = _metodoPago;
    estado = "Pendiente";
    total = 0.0;
}

double Pedido::calcularTotal() {
    total = 0.0;
    for (int i = 0; i < items.size(); i++) {
        total += items[i].obtenerSubtotal();
    }
    return total;
}

void Pedido::setContenido(const Carrito& carrito) {
    items.clear();
    vector<CarritoItem> carro = carrito.getContenido();

    for (auto& c : carro) {
        PedidoItem item;
        item.setProducto(c.getProducto());
        item.setCantidad(c.getCantidad());
        items.push_back(item);
    }

    calcularTotal();
}

void Pedido::agregarItem(PedidoItem item) {
    items.push_back(item);
    calcularTotal();
}

void Pedido::actualizarEstado(string nuevoEstado) {
    estado = nuevoEstado;
}

string Pedido::obtenerDetalle() const {
    string s = "Pedido #" + to_string(idPedido) +
        "\nFecha: " + fechaPedido +
        "\nEstado: " + estado +
        "\nTotal: $" + to_string(total);
    return s;
}

void Pedido::procesarPago() {
    cout << "\n--- Procesando pago ---\n";
    cout << "Pedido: " << idPedido << endl;
    cout << "Total: $" << total << endl;

    if (total > 0) {
        cout << "Pago realizado correctamente.\n";
        actualizarEstado("Pagado");
    } else {
        cout << "Error: Total = 0.\n";
        actualizarEstado("Error en Pago");
    }
}

// GETTERS
int Pedido::getIdPedido() const { return idPedido; }
string Pedido::getFechaPedido() const { return fechaPedido; }
string Pedido::getEstado() const { return estado; }
Direccion Pedido::getDireccionEnvio() const { return direccionEnvio; }
MetodoPago Pedido::getMetodoPago() const { return metodoPago; }
float Pedido::getTotal() const { return total; }

// SETTERS
void Pedido::setIdPedido(int _idPedido) { idPedido = _idPedido; }
void Pedido::setFechaPedido(const string& _fechaPedido) { fechaPedido = _fechaPedido; }
void Pedido::setEstado(const string& _estado) { estado = _estado; }
void Pedido::setDireccionEnvio(const Direccion& d) { direccionEnvio = d; }
void Pedido::setMetodoPago(const MetodoPago& m) { metodoPago = m; }
void Pedido::setTotal(const float& t) { total = t; }
