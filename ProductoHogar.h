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
        string getMaterial() const ;
        bool getEsArmable() const ;

        // Getters
        void setMaterial(const string& _material) ;
        void setEsArmable(bool _esArmable) ;
}
#endif // __PRODUCTOHOGAR_H__