#ifndef __PRODUCTOALIMENTO_H__
#define __PRODUCTOALIMENTO_H__

#include <iostream>
#include <string>
#include <ctime>
#include "Producto.h"
using namespace std;


class ProductoAlimento{
    private:
        tm fechaCaducidad;
        bool esPerecedero;
    public:
        ProductoAlimento();

        ProductoAlimento(int _idProducto, string _nombre, string _descripcion, double _precio, 
            int _stock, Categoria _categoria, double _peso, string _estatus, double _valoracionPromedio,
            tm _fechaCaducidad, bool _esPerecedero);
        
        int diasParaCaducar() const;

        bool requiereRefrigeracion() const;
        
        // Getters
        tm getFechaCaducidad() const ;
        bool getEsPerecedero() const ;
        
        // Setters
        void setFechaCaducidad(const tm& _fechaCaducidad) ;
        void setEsPerecedero(bool _esPerecedero) ;
}
#endif // __PRODUCTOALIMENTO_H__