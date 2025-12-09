#ifndef __ENVIO_H__
#define __ENVIO_H__

#include <string>
#include <iostream>
#include <vector>
#include "Pedido.h"

using namespace std;
class Envio {
    protected:
        string idEnvio;
        string direccion;
        string estado;
        string fechaEntrega;
        float costoEnvio;
    public:
        Envio();
        Envio(string _idEnvio, string _direccion, string _estado, string _fechaEntrega, float _costoEnvio);

        // Getters
        string getIdEnvio();
        string getDireccion();
        string getEstado();
        string getFechaEntrega();
        float getCostoEnvio();

        // Setters
        void setIdEnvio(string idEnvio);
        void setDireccion(string direccion);
        void setEstado(string estado);
        void setFechaEntrega(string fechaEntrega);
        void setCostoEnvio(float costoEnvio);

        void actualizarEstado(string nuevoEstado);
        void revisarEstado(string estado);
        void revisarEntrega(string fechaEntrega);
        void cancelarEnvio();

};

#endif // __ENVIO_H__