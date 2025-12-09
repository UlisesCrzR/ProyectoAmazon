#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

ProductoAlimento::ProductoAlimento():Producto()
{
    
}

ProductoAlimento::ProductoAlimento(int _idProducto, string _nombre, string _descripcion, double _precio, 
            int _stock, Categoria _categoria, double _peso, string _estatus, double _valoracionPromedio, 
            string _fechaCaducidad, bool _esPerecedero):Producto(_idProducto, _nombre, _descripcion, _precio, _stock, _categoria, _peso, _estatus, _valoracionPromedio)
{
    
}

int ProductoAlimento::diasParaCaducar()
{
    time_t ahora = time(nullptr);
    tm hoy = *localtime(&ahora);
    double segundos = difftime(mktime(const_cast<tm*>(&fechaCaducidad)), mktime(&hoy));
    return static_cast<int>(segundos / (60 * 60 * 24));
}

bool ProductoAlimento::requiereRefrigeracion()
{
    if (esPerecedero) {
        cout << "Si necesita refrigeracion" << endl;
    } else {
        cout << "No necesita refrigeracion" << endl;
    }
}