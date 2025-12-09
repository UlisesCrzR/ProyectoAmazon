#include "Envio.h"

Envio::Envio()
{
    idEnvio = "";
    direccion = "";
    estado = "";
    fechaEntrega = "";
    costoEnvio = 0.0;
}

Envio::Envio(string _idEnvio, string _direccion, string _estado, string _fechaEntrega, float _costoEnvio)
{
    idEnvio = _idEnvio;
    direccion = _direccion;
    estado = _estado;
    fechaEntrega = _fechaEntrega;
    costoEnvio = _costoEnvio;
}

// Getters
string Envio::getIdEnvio()
{
    return idEnvio;
}
string Envio::getDireccion()
{
    return direccion;
}
string Envio::getEstado()
{
    return estado;
}   
string Envio::getFechaEntrega()
{
    return fechaEntrega;
}

float Envio::getCostoEnvio()
{
    return costoEnvio;
}

// Setters
void Envio::setIdEnvio(string idEnvio)
{
    this->idEnvio = idEnvio;
}

void Envio::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void Envio::setEstado(string estado)
{
    this->estado = estado;
}

void Envio::setFechaEntrega(string fechaEntrega)
{
    this->fechaEntrega = fechaEntrega;
}

void Envio::setCostoEnvio(float costoEnvio)
{
    this->costoEnvio = costoEnvio;
}

//Metodos

void Envio::actualizarEstado(string nuevoEstado)
{
    this->estado = nuevoEstado;
}

void Envio::revisarEstado(string estado)
{
    cout << "El estado actual del envio es: " << this->estado << endl;
}

void Envio::revisarEntrega(string fechaEntrega)
{
    cout << "La fecha de entrega estimada es: " << this->fechaEntrega << endl;
}

void Envio::cancelarEnvio()
{
    this->estado = "Cancelado";
}

