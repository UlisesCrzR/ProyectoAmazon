#include "ProductoElectronico.h"
#include <string>

ProductoElectronico::ProductoElectronico() : Producto() {
    consumoEnergia = 0;
    garantiaMeses = 0;
}

ProductoElectronico::ProductoElectronico(string _nombre, string _descripcion, double _precio,
                                         int _stock, Categoria _categoria, double _peso, string _estatus,
                                         double _valoracionPromedio, int _garantiaMeses, double _consumoEnergia)
    : Producto(_nombre, _descripcion, _precio, _stock, _categoria.GetIdCategoria(),
               _peso, _estatus, _valoracionPromedio)
{
    consumoEnergia = _consumoEnergia;
    garantiaMeses = _garantiaMeses;
}

double ProductoElectronico::calcularConsumoAnual() const {
    return consumoEnergia*12;
}

void ProductoElectronico::extenderGarantia(int meses) {
    garantiaMeses += meses;
}

// Getters
int ProductoElectronico::getGarantiaMeses() const { return garantiaMeses; }
double ProductoElectronico::getConsumoEnergia() const { return consumoEnergia; }

// Setters
void ProductoElectronico::setGarantiaMeses(int _garantiaMeses) { 
    garantiaMeses = _garantiaMeses; 
}
void ProductoElectronico::setConsumoEnergia(double _consumoEnergia) { 
    consumoEnergia = _consumoEnergia; 
}
