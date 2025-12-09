#ifndef __PRODUCTOELECTRONICO_H__
#define __PRODUCTOELECTRONICO_H__

#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class ProductoElectronico{
    private:
        int garantiaMeses;
        double consumoEnergia;
    public:
        ProductoElectronico();

        ProductoElectronico(int _idProducto, string _nombre, string _descripcion, double _precio, 
            int _stock, Categoria _categoria, double _peso, string _estatus, double _valoracionPromedio, 
            int _garantiaMeses, double _consumoEnergia);
        
        double calcularConsumoAnual() const;
        
        void extenderGarantia(int meses);

        int getGarantiaMeses() const ;
        double getConsumoEnergia() const ;

        void setGarantiaMeses(int _garantiaMeses) ;
        void setConsumoEnergia(double _consumoEnergia) ;
}
#endif // __PRODUCTOELECTRONICO_H__



