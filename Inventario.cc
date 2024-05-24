#include "Inventario.hh"

Inventario::Inventario() 
{
    peso_total = 0;
    volumen_total = 0;
}

void Inventario::borrar_inventario() 
{
    inv.clear();
    peso_total = 0;
    volumen_total = 0;
}

void Inventario::comerciar(Inventario &inv2, const Cjt_productos &productos) 
{
    for (map<int, Cantidad>::iterator it = inv.begin(); it != inv.end(); ++it)
    {
        int id = it->first;
        Cantidad cantidad = it->second;
        if (inv2.contiene_producto(id))
        {
            if (cantidad.poseido < cantidad.requerido and 
            inv2.consultar_cantidad_poseida(id) > inv2.consultar_cantidad_requerida(id))
            {
                int cantidad_comerciar = min(
                    cantidad.requerido - cantidad.poseido, 
                    inv2.consultar_cantidad_poseida(id) - inv2.consultar_cantidad_requerida(id)
                );
                modificar_cantidad_poseida(id, cantidad_comerciar, productos.consultar_producto(id));
                inv2.modificar_cantidad_poseida(id, -cantidad_comerciar, productos.consultar_producto(id));
            }
            else if (cantidad.poseido > cantidad.requerido and 
            inv2.consultar_cantidad_poseida(id) < inv2.consultar_cantidad_requerida(id))
            {
                int cantidad_comerciar = min(
                    cantidad.poseido - cantidad.requerido, 
                    inv2.consultar_cantidad_requerida(id) - inv2.consultar_cantidad_poseida(id)
                );
                modificar_cantidad_poseida(id, -cantidad_comerciar, productos.consultar_producto(id));
                inv2.modificar_cantidad_poseida(id, cantidad_comerciar, productos.consultar_producto(id));
            }
        }
    }
}

void Inventario::modificar_cantidad_poseida(int id, int cantidad_poseida, const Producto &prod)
{
    peso_total += cantidad_poseida * prod.consultar_peso();
    volumen_total += cantidad_poseida * prod.consultar_volumen();
    inv.at(id).poseido += cantidad_poseida;
}

void Inventario::modificar_cantidad_requerida(int id, int cantidad_requerida) 
{
    inv.at(id).requerido += cantidad_requerida;
}

void Inventario::poner_producto(int id, int cantidad_poseida, int cantidad_requerida, const Producto &prod) 
{
    inv[id].poseido = 0;
    inv[id].requerido = 0;
    modificar_cantidad_poseida(id, cantidad_poseida, prod);
    modificar_cantidad_requerida(id, cantidad_requerida);
}

void Inventario::quitar_producto(int id, const Producto &prod) 
{
    modificar_cantidad_poseida(id, -inv[id].poseido, prod);
    inv.erase(id);
}

bool Inventario::contiene_producto(int id) const
{
    return inv.count(id);
}

int Inventario::consultar_cantidad_poseida(int id) const
{
    return inv.at(id).poseido;
}

int Inventario::consultar_cantidad_requerida(int id) const
{   
    return inv.at(id).requerido;
}

void Inventario::leer_inventario(const Cjt_productos &productos)
{
    borrar_inventario();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        int id;
        int cantidad_poseida;
        int cantidad_requerida;
        cin >> id;
        cin >> cantidad_poseida;
        cin >> cantidad_requerida;
        poner_producto(id, cantidad_poseida, cantidad_requerida, productos.consultar_producto(id));
    }

}

void Inventario::consultar_producto(int id) const
{
    cout << consultar_cantidad_poseida(id) << endl;
    cout << consultar_cantidad_requerida(id) << endl;
}

void Inventario::escribir_atributos_totales() const
{
    cout << peso_total << " " << volumen_total << endl;
}

void Inventario::escribir_inventario() const
{
    for (map<int, Cantidad>::const_iterator it = inv.begin(); it != inv.end(); ++it)
    {
        cout << it->first << " ";
        cout << it->second.poseido << " ";
        cout << it->second.requerido << endl;
    }
}