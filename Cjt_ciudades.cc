#include "Cjt_ciudades.hh"

Cjt_ciudades::Cjt_ciudades() {}

void Cjt_ciudades::modificar_cantidad_disponible(string &ciudad_id, int prod_id, int cantidad_disponible, Producto &prod) 
{
    ciudades[ciudad_id].modificar_cantidad_disponible(prod_id, cantidad_disponible, prod);
}

void Cjt_ciudades::modificar_cantidad_requerida(string &ciudad_id, int prod_id, int cantidad_requerida) 
{
    ciudades[ciudad_id].modificar_cantidad_requerida(prod_id, cantidad_requerida);
}

void Cjt_ciudades::quitar_producto(string &ciudad_id, int prod_id, Producto &prod) 
{
    ciudades[ciudad_id].quitar_producto(prod_id, prod);
}

bool Cjt_ciudades::existe_ciudad(string &ciudad_id) const
{
    return ciudades.count(ciudad_id);
}

Inventario Cjt_ciudades::consultar_inventario(string &ciudad_id)
{
    return ciudades[ciudad_id].consultar_inventario();
}

bool Cjt_ciudades::contiene_producto(string &ciudad_id, int prod_id)
{
    return ciudades[ciudad_id].contiene_producto(prod_id);
}

int Cjt_ciudades::consultar_cantidad_disponible(string &ciudad_id, int prod_id)
{
    return ciudades[ciudad_id].consultar_cantidad_disponible(prod_id);
}

int Cjt_ciudades::consultar_cantidad_requerida(string &ciudad_id, int prod_id)
{   
    return ciudades[ciudad_id].consultar_cantidad_requerida(prod_id);
}

void Cjt_ciudades::leer_inventario(string &ciudad_id, Cjt_productos &productos)
{
    ciudades[ciudad_id].leer_inventario(productos);
}

void Cjt_ciudades::consultar_producto(string &ciudad_id, int prod_id)
{
    ciudades[ciudad_id].consultar_producto(prod_id);
}

void Cjt_ciudades::escribir_atributos_totales(string &ciudad_id)
{
    ciudades[ciudad_id].escribir_atributos_totales();
}