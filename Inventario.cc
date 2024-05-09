#include "Inventario.hh"

Inventario::Inventario() 
{
    peso_total = 0;
    volumen_total = 0;
}

void Inventario::borrar_inventario() 
{
    cantidad_productos.clear();
    peso_total = 0;
    volumen_total = 0;
}

void Inventario::comerciar(Inventario &inventario2, const Cjt_productos &productos) 
{
    for (auto key : cantidad_productos)
    {
        int id = key.first;
        Cantidad cantidad = key.second;
        if (inventario2.contiene_producto(id))
        {
            if (cantidad.disponible < cantidad.requerido and 
            inventario2.consultar_cantidad_disponible(id) > inventario2.consultar_cantidad_requerida(id))
            {
                int cantidad_a_comerciar = min(
                    cantidad.requerido - cantidad.disponible, 
                    inventario2.consultar_cantidad_disponible(id) - inventario2.consultar_cantidad_requerida(id)
                );
                modificar_cantidad_disponible(id, cantidad_a_comerciar, productos.consultar_producto(id));
                inventario2.modificar_cantidad_disponible(id, -cantidad_a_comerciar, productos.consultar_producto(id));
            }
            else if (cantidad.disponible > cantidad.requerido and 
            inventario2.consultar_cantidad_disponible(id) < inventario2.consultar_cantidad_requerida(id))
            {
                int cantidad_a_comerciar = min(
                    cantidad.disponible - cantidad.requerido, 
                    inventario2.consultar_cantidad_requerida(id) - inventario2.consultar_cantidad_disponible(id)
                );
                modificar_cantidad_disponible(id, -cantidad_a_comerciar, productos.consultar_producto(id));
                inventario2.modificar_cantidad_disponible(id, cantidad_a_comerciar, productos.consultar_producto(id));
            
            }
        }
    }
}

void Inventario::modificar_cantidad_disponible(int id, int cantidad_disponible, const Producto &prod) 
{
    peso_total += cantidad_disponible * prod.consultar_peso();
    volumen_total += cantidad_disponible * prod.consultar_volumen();
    cantidad_productos[id].disponible += cantidad_disponible;
}

void Inventario::modificar_cantidad_requerida(int id, int cantidad_requerida) 
{
    cantidad_productos[id].requerido += cantidad_requerida;
}

void Inventario::poner_producto(int id, int cantidad_disponible, int cantidad_requerida, const Producto &prod) 
{
    cantidad_productos[id].disponible = 0;
    cantidad_productos[id].requerido = 0;
    modificar_cantidad_disponible(id, cantidad_disponible, prod);
    modificar_cantidad_requerida(id, cantidad_requerida);
}

void Inventario::quitar_producto(int id, const Producto &prod) 
{
    modificar_cantidad_disponible(id, -cantidad_productos[id].disponible, prod);
    cantidad_productos.erase(id);
}

bool Inventario::contiene_producto(int id) const
{
    return cantidad_productos.count(id);
}

int Inventario::consultar_cantidad_disponible(int id) const
{
    return cantidad_productos.at(id).disponible;
}

int Inventario::consultar_cantidad_requerida(int id) const
{   
    return cantidad_productos.at(id).requerido;
}

void Inventario::consultar_producto(int id) const
{
    cout << consultar_cantidad_disponible(id) << endl;
    cout << consultar_cantidad_requerida(id) << endl;
}

void Inventario::escribir_atributos_totales() const
{
    cout << peso_total << " " << volumen_total << endl;
}

void Inventario::escribir_inventario() const
{
    for (auto it = cantidad_productos.begin(); it != cantidad_productos.end(); ++it)
    {
        cout << it->first << " ";
        cout << it->second.disponible << " ";
        cout << it->second.requerido << endl;
    }
}