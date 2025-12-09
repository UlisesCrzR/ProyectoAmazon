#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

ProductoHogar::ProductoHogar():Producto()
{
    
}

ProductoHogar::ProductoHogar(int _idProducto, string _nombre, string _descripcion, double _precio, 
            int _stock, Categoria _categoria, double _peso, string _estatus, double _valoracionPromedio, 
            string _material, bool _esArmable):Producto(_idProducto, _nombre, _descripcion, _precio, _stock, _categoria, _peso, _estatus, _valoracionPromedio)
{
    
}

double ProductoHogar::calcularCostoArmado() const
{
    return esArmable ? 150.0 : 0.0;
}

string ProductoHogar::descripcionHogar() const
{
    return "Material: " + material + ", Armable: " + (esArmable ? "Sí" : "No");
}