#include "Ciudad.hh"

Ciudad::Ciudad() 
{
    peso_total = 0;
    volumen_total = 0;
}

void Ciudad::modifica_cantidad_disponible(int id, int cantidad_disponible, Producto &prod) 
{
    inventario.modifica_cantidad_disponible(id, cantidad_disponible, prod);
}

void Ciudad::modifica_cantidad_requerida(int id, int cantidad_requerida, Producto &prod) 
{
    inventario.modifica_cantidad_requerida(id, cantidad_requerida, prod);
}

void Ciudad::quitar_producto(int id, Producto &prod) 
{
    inventario.quitar_producto(id, prod);
}

Inventario Ciudad::consulta_inventario() const
{
    return inventario;
}

bool Ciudad::contiene_producto(int id) const
{
    return inventario.contiene_producto(id);
}

int Ciudad::consulta_cantidad_disponible(int id)
{
    return inventario.consulta_cantidad_disponible(id);
}

int Ciudad::consulta_cantidad_requerida(int id)
{   
    return inventario.consulta_cantidad_requerida(id);
}

void Ciudad::consultar_producto(int id)
{
    inventario.consultar_producto(id);
}

void Ciudad::escribir_atributos_totales() const
{
    inventario.escribir_atributos_totales();
}