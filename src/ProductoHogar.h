#ifndef PRODUCTOHOGAR_H
#define PRODUCTOHOGAR_H

#include "Producto.h"
#include "categoria.h"
#include <string>

using namespace std;

class ProductoHogar : public Producto {
private:
    string material;
    bool esArmable;

public:
    ProductoHogar();
    ProductoHogar(string _nombre, string _descripcion, double _precio,
                  int _stock, Categoria _categoria, double _peso, string _estatus, double _valoracionPromedio,
                  string _material, bool _esArmable);

    double calcularCostoArmado() const;
    string descripcionHogar() const;

    // Getters
    string getMaterial() const;
    bool getEsArmable() const;

    // Setters
    void setMaterial(const string& _material);
    void setEsArmable(bool _esArmable);
};

#endif
