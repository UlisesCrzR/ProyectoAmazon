#ifndef __PRODUCTOHOGAR_H__
#define __PRODUCTOHOGAR_H__

#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;


class ProductoHogar{
    private:
        string material;
        bool esArmable;
    public:
        ProductoHogar();

        ProductoHogar(int _idProducto, string _nombre, string _descripcion, double _precio, 
            int _stock, Categoria _categoria, double _peso, string _estatus, double _valoracionPromedio,
            string _material, bool _esArmable);
        
        double calcularCostoArmado() const;

        string descripcionHogar() const;

        // Setters
        string ProductoHogar::getMaterial() const { return material; }
        bool ProductoHogar::getEsArmable() const { return esArmable; }

        // Getters
        void ProductoHogar::setMaterial(const string& _material) { material = _material; }
        void ProductoHogar::setEsArmable(bool _esArmable) { esArmable = _esArmable; }
}
#endif // __PRODUCTOHOGAR_H__