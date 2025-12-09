#include "ProductoHogar.h"

ProductoHogar::ProductoHogar() : Producto()
{
    material = "Desconocido";
    esArmable = false;
}

ProductoHogar::ProductoHogar(string _nombre, string _descripcion, double _precio,
                             int _stock, Categoria _categoria, double _peso, string _estatus, double _valoracionPromedio,
                             string _material, bool _esArmable)
    : Producto(_nombre, _descripcion, _precio, _stock, _categoria.GetIdCategoria(),
               _peso, _estatus, _valoracionPromedio)
{
    material = _material;
    esArmable = _esArmable;
}

double ProductoHogar::calcularCostoArmado() const
{
    if (esArmable)
    {
        return precio * 0.1; // ejemplo: 10% del precio como costo de armado
    }

    return 0;
}

string ProductoHogar::descripcionHogar() const
{
    string desc = "Material: " + material;
    if (esArmable)
    {
        desc += " (Armable)";
    }
    else
    {
        desc += " (No armable)";
    }

    return desc;
}

// Getters
string ProductoHogar::getMaterial() const
{
    return material;
}

bool ProductoHogar::getEsArmable() const
{
    return esArmable;
}

// Setters
void ProductoHogar::setMaterial(const string& _material)
{
    material = _material;
}

void ProductoHogar::setEsArmable(bool _esArmable)
{
    esArmable = _esArmable;
}
