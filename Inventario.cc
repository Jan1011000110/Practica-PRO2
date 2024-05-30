/** @file Inventario.cc 
 *  @brief Código de la clase Inventario.
 */

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
    map<int, Cantidad>::iterator it1 = inv.begin();
    map<int, Cantidad>::iterator it2 = inv2.inv.begin();

    // Iteramos hasta que llegamos al final de un inventario
    while (it1 != inv.end() and it2 != inv2.inv.end()) {
        int id1 = it1->first;
        Cantidad cantidad1 = it1->second;
        int id2 = it2->first;
        Cantidad cantidad2 = it2->second;

        if (id1 == id2) // Si los dos inventarios contienen el producto con identificador id1=id2
        {
            // Cojo el minimo entre lo que le falta a inv y lo que le sobra a inv2
            int cantidad_comerciar = calculo_comercio(
                cantidad1.poseido, cantidad1.requerido, 
                cantidad2.poseido, cantidad2.requerido
            );
            // Comercio entre los dos inventarios la cantidad indicada
            modificar_cantidad_poseida(id1, cantidad_comerciar, productos.consultar_producto(id1));
            inv2.modificar_cantidad_poseida(id2, -cantidad_comerciar, productos.consultar_producto(id2));
            
            // Repito el proceso pero al reves
            cantidad_comerciar = calculo_comercio(
                cantidad2.poseido, cantidad2.requerido,
                cantidad1.poseido, cantidad1.requerido
            );
            modificar_cantidad_poseida(id1, -cantidad_comerciar, productos.consultar_producto(id1));
            inv2.modificar_cantidad_poseida(id2, cantidad_comerciar, productos.consultar_producto(id2));

            // Avanzamos los dos iteradores
            it1++;
            it2++;
        }
        else if (id1 < id2) // Avanzamos el primer iterador ya que el producto con id1 no esta en inv2
        {
            it1++;
        }
        else // Avanzamos el segundo iterador ya que el producto con id2 no esta en inv
        {
            it2++;  
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

int Inventario::calculo_comercio(int x, int y, int p, int q) 
{
    int comercio = 0;
    if (x < y and p > q)
    {
        comercio = min(y - x, p - q);
    }
    return comercio;
}