#include "Cjt_ciudades.hh"

Cjt_ciudades::Cjt_ciudades() {}

void Cjt_ciudades::modifica_cantidad_disponible(string &ciudad_id, int prod_id, int cantidad_disponible, Producto &prod) 
{
    ciudades[ciudad_id].modifica_cantidad_disponible(prod_id, cantidad_disponible, prod);
}

void Cjt_ciudades::modifica_cantidad_requerida(string &ciudad_id, int prod_id, int cantidad_requerida, Producto &prod) 
{
    ciudades[ciudad_id].modifica_cantidad_requerida(prod_id, cantidad_requerida, prod);
}

void Cjt_ciudades::quitar_producto(string &ciudad_id, int prod_id, Producto &prod) 
{
    ciudades[ciudad_id].quitar_producto(prod_id, prod);
}

Inventario Cjt_ciudades::consulta_inventario(string &ciudad_id)
{
    return ciudades[ciudad_id].consulta_inventario();
}

bool Cjt_ciudades::contiene_producto(string &ciudad_id, int prod_id)
{
    return ciudades[ciudad_id].contiene_producto(prod_id);
}

int Cjt_ciudades::consulta_cantidad_disponible(string &ciudad_id, int prod_id)
{
    return ciudades[ciudad_id].consulta_cantidad_disponible(prod_id);
}

int Cjt_ciudades::consulta_cantidad_requerida(string &ciudad_id, int prod_id)
{   
    return ciudades[ciudad_id].consulta_cantidad_requerida(prod_id);
}

void Cjt_ciudades::consultar_producto(string &ciudad_id, int prod_id)
{
    ciudades[ciudad_id].consultar_producto(prod_id);
}

void Cjt_ciudades::escribir_atributos_totales(string &ciudad_id)
{
    ciudades[ciudad_id].escribir_atributos_totales();
}