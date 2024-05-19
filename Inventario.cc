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

void Inventario::comerciar(Inventario &inv, const Cjt_productos &productos) 
{
    for (map<int, Cantidad>::iterator it = cantidad_productos.begin(); it != cantidad_productos.end(); ++it)
    {
        int id = it->first;
        Cantidad cantidad = it->second;
        if (inv.contiene_producto(id))
        {
            if (cantidad.poseido < cantidad.requerido and 
            inv.consultar_cantidad_poseido(id) > inv.consultar_cantidad_requerida(id))
            {
                int cantidad_comerciar = min(
                    cantidad.requerido - cantidad.poseido, 
                    inv.consultar_cantidad_poseido(id) - inv.consultar_cantidad_requerida(id)
                );
                modificar_cantidad_poseido(id, cantidad_comerciar, productos.consultar_producto(id));
                inv.modificar_cantidad_poseido(id, -cantidad_comerciar, productos.consultar_producto(id));
            }
            else if (cantidad.poseido > cantidad.requerido and 
            inv.consultar_cantidad_poseido(id) < inv.consultar_cantidad_requerida(id))
            {
                int cantidad_comerciar = min(
                    cantidad.poseido - cantidad.requerido, 
                    inv.consultar_cantidad_requerida(id) - inv.consultar_cantidad_poseido(id)
                );
                modificar_cantidad_poseido(id, -cantidad_comerciar, productos.consultar_producto(id));
                inv.modificar_cantidad_poseido(id, cantidad_comerciar, productos.consultar_producto(id));
            }
        }
    }
}

void Inventario::modificar_cantidad_poseido(int id, int cantidad_poseido, const Producto &prod) 
{
    peso_total += cantidad_poseido * prod.consultar_peso();
    volumen_total += cantidad_poseido * prod.consultar_volumen();
    cantidad_productos[id].poseido += cantidad_poseido;
}

void Inventario::modificar_cantidad_requerida(int id, int cantidad_requerida) 
{
    cantidad_productos.at(id).requerido += cantidad_requerida;
}

void Inventario::poner_producto(int id, int cantidad_poseido, int cantidad_requerida, const Producto &prod) 
{
    cantidad_productos[id].poseido = 0;
    cantidad_productos[id].requerido = 0;
    modificar_cantidad_poseido(id, cantidad_poseido, prod);
    modificar_cantidad_requerida(id, cantidad_requerida);
}

void Inventario::quitar_producto(int id, const Producto &prod) 
{
    modificar_cantidad_poseido(id, -cantidad_productos[id].poseido, prod);
    cantidad_productos.erase(id);
}

bool Inventario::contiene_producto(int id) const
{
    return cantidad_productos.count(id);
}

int Inventario::consultar_cantidad_poseido(int id) const
{
    return cantidad_productos.at(id).poseido;
}

int Inventario::consultar_cantidad_requerida(int id) const
{   
    return cantidad_productos.at(id).requerido;
}

void Inventario::leer_inventario(const Cjt_productos &productos)
{
    cantidad_productos.clear();
    peso_total = 0;
    volumen_total = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        int id;
        int cantidad_poseido;
        int cantidad_requerida;
        cin >> id;
        cin >> cantidad_poseido;
        cin >> cantidad_requerida;
        poner_producto(id, cantidad_poseido, cantidad_requerida, productos.consultar_producto(id));
    }

}

void Inventario::consultar_producto(int id) const
{
    cout << consultar_cantidad_poseido(id) << endl;
    cout << consultar_cantidad_requerida(id) << endl;
}

void Inventario::escribir_atributos_totales() const
{
    cout << peso_total << " " << volumen_total << endl;
}

void Inventario::escribir_inventario() const
{
    for (map<int, Cantidad>::const_iterator it = cantidad_productos.begin(); it != cantidad_productos.end(); ++it)
    {
        cout << it->first << " ";
        cout << it->second.poseido << " ";
        cout << it->second.requerido << endl;
    }
}