#include "Cjt_ciudades.hh"

Cjt_ciudades::Cjt_ciudades() {}

void Cjt_ciudades::comerciar(const string &ciudad_id1, const string &ciudad_id2, const Cjt_productos &productos)
{
    ciudades.at(ciudad_id1).comerciar(ciudades[ciudad_id2], productos);
}

void Cjt_ciudades::poner_ciudad(const string &ciudad_id) 
{
    ciudades[ciudad_id] = Ciudad();
}

void Cjt_ciudades::poner_producto(const string &ciudad_id, int prod_id, int cantidad_disponible, int cantidad_requerida, const Producto &prod)
{
    ciudades.at(ciudad_id).poner_producto(prod_id, cantidad_disponible, cantidad_requerida, prod);
}

void Cjt_ciudades::modificar_cantidad_disponible(const string &ciudad_id, int prod_id, int cantidad_disponible, const Producto &prod) 
{
    ciudades.at(ciudad_id).modificar_cantidad_disponible(prod_id, cantidad_disponible, prod);
}

void Cjt_ciudades::modificar_cantidad_requerida(const string &ciudad_id, int prod_id, int cantidad_requerida) 
{
    ciudades.at(ciudad_id).modificar_cantidad_requerida(prod_id, cantidad_requerida);
}

void Cjt_ciudades::quitar_producto(const string &ciudad_id, int prod_id, const Producto &prod)
{
    ciudades.at(ciudad_id).quitar_producto(prod_id, prod);
}

bool Cjt_ciudades::existe_ciudad(const string &ciudad_id) const
{
    return ciudades.count(ciudad_id);
}

Inventario Cjt_ciudades::consultar_inventario(const string &ciudad_id) const
{
    return ciudades.at(ciudad_id).consultar_inventario();
}

bool Cjt_ciudades::contiene_producto(const string &ciudad_id, int prod_id) const
{
    return ciudades.at(ciudad_id).contiene_producto(prod_id);
}

int Cjt_ciudades::consultar_cantidad_disponible(const string &ciudad_id, int prod_id) const
{
    return ciudades.at(ciudad_id).consultar_cantidad_disponible(prod_id);
}

int Cjt_ciudades::consultar_cantidad_requerida(const string &ciudad_id, int prod_id) const
{   
    return ciudades.at(ciudad_id).consultar_cantidad_requerida(prod_id);
}

void Cjt_ciudades::leer_inventario(const string &ciudad_id, const Cjt_productos &productos)
{
    ciudades.at(ciudad_id).leer_inventario(productos);
}

void Cjt_ciudades::consultar_producto(const string &ciudad_id, int prod_id) const
{
    ciudades.at(ciudad_id).consultar_producto(prod_id);
}

void Cjt_ciudades::escribir_atributos_totales(const string &ciudad_id) const
{
    ciudades.at(ciudad_id).escribir_atributos_totales();
}

void Cjt_ciudades::escribir_inventario(const string &ciudad_id) const
{
    ciudades.at(ciudad_id).escribir_inventario();
}