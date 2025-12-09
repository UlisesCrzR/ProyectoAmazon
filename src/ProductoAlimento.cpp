#include "ProductoAlimento.h"
#include <ctime>

ProductoAlimento::ProductoAlimento() : Producto() {
    esPerecedero = false;
    fechaCaducidad = {};
}

ProductoAlimento::ProductoAlimento(string _nombre, string _descripcion, double _precio,
                                   int _stock, Categoria _categoria, double _peso, string _estatus,
                                   double _valoracionPromedio, tm _fechaCaducidad, bool _esPerecedero)
    : Producto(_nombre, _descripcion, _precio, _stock, _categoria.GetIdCategoria(),
               _peso, _estatus, _valoracionPromedio)
{
    fechaCaducidad = _fechaCaducidad;
    esPerecedero = _esPerecedero;
}

int ProductoAlimento::diasParaCaducar() const {
    time_t ahora = time(nullptr);
    tm hoy = *localtime(&ahora);

    time_t tCaducidad = mktime(const_cast<tm*>(&fechaCaducidad));
    time_t tHoy = mktime(&hoy);

    double segundos = difftime(tCaducidad, tHoy);

    return static_cast<int>(segundos / (60 * 60 * 24));
}

bool ProductoAlimento::requiereRefrigeracion() const {
    return esPerecedero;
}

// Getters
tm ProductoAlimento::getFechaCaducidad() const { return fechaCaducidad; }
bool ProductoAlimento::getEsPerecedero() const { return esPerecedero; }

// Setters
void ProductoAlimento::setFechaCaducidad(const tm& _fechaCaducidad) {
    fechaCaducidad = _fechaCaducidad;
}

void ProductoAlimento::setEsPerecedero(bool _esPerecedero) {
    esPerecedero = _esPerecedero;
}