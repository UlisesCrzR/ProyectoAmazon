#ifndef PRODUCTOALIMENTO_H
#define PRODUCTOALIMENTO_H

#include <ctime>
#include "producto.h"
#include "categoria.h"
using namespace std;

class ProductoAlimento : public Producto {
private:
    tm fechaCaducidad;
    bool esPerecedero;

public:
    ProductoAlimento();
    ProductoAlimento(string _nombre, string _descripcion, double _precio,
                     int _stock, Categoria _categoria, double _peso, string _estatus,
                     double _valoracionPromedio, tm _fechaCaducidad, bool _esPerecedero);

    // Métodos propios
    int diasParaCaducar() const;
    bool requiereRefrigeracion() const;

    // Getters y setters
    tm getFechaCaducidad() const;
    bool getEsPerecedero() const;

    void setFechaCaducidad(const tm& _fechaCaducidad);
    void setEsPerecedero(bool _esPerecedero);
};

#endif
