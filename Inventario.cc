#include "Inventario.hh"

Inventario::Inventario() 
{
    peso_total = 0;
    volumen_total = 0;
}

void Inventario::modificar_cantidad_disponible(int id, int cantidad_disponible, Producto &prod) 
{
    peso_total += (cantidad_disponible - cantidad_productos[id].disponible)  * prod.consultar_peso();
    volumen_total += (cantidad_disponible - cantidad_productos[id].disponible) * prod.consultar_volumen();
    cantidad_productos[id].disponible = cantidad_disponible;
}

void Inventario::modificar_cantidad_requerida(int id, int cantidad_requerida) 
{
    cantidad_productos[id].requerido = cantidad_requerida;
}

void Inventario::poner_producto(int id, int cantidad_disponible, int cantidad_requerida, Producto &prod) 
{
    cantidad_productos[id].disponible = 0;
    cantidad_productos[id].requerido = 0;
    modificar_cantidad_disponible(id, cantidad_disponible, prod);
    modificar_cantidad_requerida(id, cantidad_requerida);
}

void Inventario::quitar_producto(int id, Producto &prod) 
{
    modificar_cantidad_disponible(id, 0, prod);
    cantidad_productos.erase(id);
}

bool Inventario::contiene_producto(int id) const
{
    return cantidad_productos.count(id);
}

int Inventario::consultar_cantidad_disponible(int id)
{
    return cantidad_productos[id].disponible;
}

int Inventario::consultar_cantidad_requerida(int id)
{   
    return cantidad_productos[id].requerido;
}

void Inventario::consultar_producto(int id)
{
    cout << consultar_cantidad_disponible(id) << endl;
    cout << consultar_cantidad_requerida(id) << endl;
}

void Inventario::escribir_atributos_totales() const
{
    cout << peso_total << endl;
    cout << volumen_total << endl;
}