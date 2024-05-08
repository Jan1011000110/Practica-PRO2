#include "Ciudad.hh"

Ciudad::Ciudad() 
{
    peso_total = 0;
    volumen_total = 0;
}

void Ciudad::poner_producto(int prod_id, int cantidad_disponible, int cantidad_requerida, const Producto &prod)
{
    inventario.poner_producto(prod_id, cantidad_disponible, cantidad_requerida, prod);
}

void Ciudad::modificar_cantidad_disponible(int id, int cantidad_disponible, const Producto &prod) 
{
    inventario.modificar_cantidad_disponible(id, cantidad_disponible, prod);
}

void Ciudad::modificar_cantidad_requerida(int id, int cantidad_requerida) 
{
    inventario.modificar_cantidad_requerida(id, cantidad_requerida);
}

void Ciudad::quitar_producto(int id, const Producto &prod) 
{
    inventario.quitar_producto(id, prod);
}

Inventario Ciudad::consultar_inventario() const
{
    return inventario;
}

bool Ciudad::contiene_producto(int id) const
{
    return inventario.contiene_producto(id);
}

int Ciudad::consultar_cantidad_disponible(int id)
{
    return inventario.consultar_cantidad_disponible(id);
}

int Ciudad::consultar_cantidad_requerida(int id)
{   
    return inventario.consultar_cantidad_requerida(id);
}

void Ciudad::leer_inventario(const Cjt_productos &productos) 
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int prod_id;
        int cantidad_disponible;
        int cantidad_requerida;
        cin >> prod_id;
        cin >> cantidad_disponible;
        cin >> cantidad_requerida;
        Producto prod = productos.consultar_producto(prod_id);
        inventario.poner_producto(prod_id, cantidad_disponible, cantidad_requerida, prod);
    }
}

void Ciudad::consultar_producto(int id)
{
    inventario.consultar_producto(id);
}

void Ciudad::escribir_atributos_totales() const
{
    inventario.escribir_atributos_totales();
}

void Ciudad::escribir_inventario() const
{
    inventario.escribir_inventario();
}