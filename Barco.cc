#include "Barco.hh"

Barco::Barco() {}

void Barco::calcular_viaje(const BinTree<string> &raiz, const Cjt_ciudades &ciudades, map<string, vector<int>> &dp) const
{
    int compra_izquierda = 0, venta_izquierda = 0, comercio_izquierda = 0, longitud_izquierda = 0;
    if (not raiz.left().empty())
    {
        calcular_viaje(raiz.left(), ciudades, dp);
        compra_izquierda = dp[raiz.left().value()][0];
        venta_izquierda = dp[raiz.left().value()][1];
        longitud_izquierda = dp[raiz.left().value()][2];
        comercio_izquierda = compra_izquierda + venta_izquierda;
        if (comercio_izquierda == 0) 
        {
            longitud_izquierda = 0;
        }
    }
    int compra_derecha = 0, venta_derecha = 0, comercio_derecha = 0, longitud_derecha = 0;
    if (not raiz.right().empty())
    {
        calcular_viaje(raiz.right(), ciudades, dp);
        compra_derecha = dp[raiz.right().value()][0];
        venta_derecha = dp[raiz.right().value()][1];
        longitud_derecha = dp[raiz.right().value()][2];
        comercio_derecha = compra_derecha + venta_derecha;
        if (comercio_derecha == 0) 
        {
            longitud_derecha = 0;
        }
    }
    
    if (comercio_derecha > comercio_izquierda or (comercio_derecha == comercio_izquierda and longitud_derecha <= longitud_izquierda))
    {
        int cantidad_a_comprar = unidades_comprar - compra_derecha;
        if (ciudades.contiene_producto(raiz.value(), prod_id_comprar))
        {
            //cout << ciudades.consultar_cantidad_disponible(raiz.value(), prod_id_comprar) - ciudades.consultar_cantidad_requerida(raiz.value(), prod_id_comprar) << endl;
            cantidad_a_comprar = min(
                cantidad_a_comprar, 
                ciudades.consultar_cantidad_disponible(raiz.value(), prod_id_comprar) - ciudades.consultar_cantidad_requerida(raiz.value(), prod_id_comprar)
            );
        }
        else 
        {
            cantidad_a_comprar = 0;
        }
        if (cantidad_a_comprar < 0) cantidad_a_comprar = 0;

        int cantidad_a_vender = unidades_vender - venta_derecha;
        if (ciudades.contiene_producto(raiz.value(), prod_id_vender))
        {
            //cout << ciudades.consultar_cantidad_requerida(raiz.value(), prod_id_vender) - ciudades.consultar_cantidad_disponible(raiz.value(), prod_id_vender) << endl;
            cantidad_a_vender = min(
                cantidad_a_vender, 
                ciudades.consultar_cantidad_requerida(raiz.value(), prod_id_vender) - ciudades.consultar_cantidad_disponible(raiz.value(), prod_id_vender)
            );
        }
        else 
        {
            cantidad_a_vender = 0;
        }
        if (cantidad_a_vender < 0) cantidad_a_vender = 0;

        dp[raiz.value()] = {compra_derecha + cantidad_a_comprar, venta_derecha + cantidad_a_vender, longitud_derecha + 1, 0, cantidad_a_comprar, cantidad_a_vender};
    }
    else
    {
        int cantidad_a_comprar = unidades_comprar - compra_izquierda;
        if (ciudades.contiene_producto(raiz.value(), prod_id_comprar))
        {
            //cout << ciudades.consultar_cantidad_disponible(raiz.value(), prod_id_comprar) - ciudades.consultar_cantidad_requerida(raiz.value(), prod_id_comprar) << endl;
            cantidad_a_comprar = min(
                cantidad_a_comprar, 
                ciudades.consultar_cantidad_disponible(raiz.value(), prod_id_comprar) - ciudades.consultar_cantidad_requerida(raiz.value(), prod_id_comprar)
            );
        }
        else 
        {
            cantidad_a_comprar = 0;
        }
        if (cantidad_a_comprar < 0) cantidad_a_comprar = 0;

        int cantidad_a_vender = unidades_vender - venta_izquierda;
        if (ciudades.contiene_producto(raiz.value(), prod_id_vender))
        {
            //cout << ciudades.consultar_cantidad_requerida(raiz.value(), prod_id_vender) - ciudades.consultar_cantidad_disponible(raiz.value(), prod_id_vender) << endl;
            cantidad_a_vender = min(
                cantidad_a_vender, 
                ciudades.consultar_cantidad_requerida(raiz.value(), prod_id_vender) - ciudades.consultar_cantidad_disponible(raiz.value(), prod_id_vender)
            );
        }
        else 
        {
            cantidad_a_vender = 0;
        }
        if (cantidad_a_vender < 0) cantidad_a_vender = 0;

        dp[raiz.value()] = {compra_izquierda + cantidad_a_comprar, venta_izquierda + cantidad_a_vender, longitud_izquierda + 1, 1, cantidad_a_comprar, cantidad_a_vender};
    }

    //cout << "raiz = " << raiz.value() << " "<<  dp[raiz.value()][0] << " " << dp[raiz.value()][1] << endl;
}

void Barco::hacer_viaje(const BinTree<string> &raiz, Cjt_ciudades &ciudades, const Cjt_productos &productos)
{
    map<string, vector<int>> dp;
    calcular_viaje(raiz, ciudades, dp);

    BinTree<string> aux = raiz;
    while (not aux.empty()) 
    {
        if (dp[aux.value()][3] == 0)
        {
            int cantidad_a_comprar = dp[aux.value()][4];
            int cantidad_a_vender = dp[aux.value()][5];

            if ((cantidad_a_comprar + cantidad_a_vender > 0) and (aux.right().empty() or (dp[aux.right().value()][0] == 0 and dp[aux.right().value()][1] == 0)))
            {
                viajes.push_back(aux.value());
            }

            if (cantidad_a_comprar > 0) 
            {
                ciudades.modificar_cantidad_disponible(aux.value(), prod_id_comprar, -cantidad_a_comprar, productos.consultar_producto(prod_id_comprar));
            }
            if (cantidad_a_vender > 0) 
            {
                ciudades.modificar_cantidad_disponible(aux.value(), prod_id_vender, cantidad_a_vender, productos.consultar_producto(prod_id_vender));
            }

            aux = aux.right();
        }
        else
        {
            int cantidad_a_comprar = dp[aux.value()][4];
            int cantidad_a_vender = dp[aux.value()][5];

            if ((cantidad_a_comprar + cantidad_a_vender > 0) and (aux.left().empty() or (dp[aux.left().value()][0] == 0 and dp[aux.left().value()][1] == 0)))
            {
                viajes.push_back(aux.value());
            }

            if (cantidad_a_comprar > 0) 
            {
                ciudades.modificar_cantidad_disponible(aux.value(), prod_id_comprar, -cantidad_a_comprar, productos.consultar_producto(prod_id_comprar));
            }
            if (cantidad_a_vender > 0) 
            {
                ciudades.modificar_cantidad_disponible(aux.value(), prod_id_vender, cantidad_a_vender, productos.consultar_producto(prod_id_vender));
            }

            aux = aux.left();
        }
    }
    cout << dp[raiz.value()][0] + dp[raiz.value()][1] << endl;
}

void Barco::modificar_barco(int prod_id_comprar, int unidades_comprar, int prod_id_vender, int unidades_vender)
{
    this->prod_id_comprar = prod_id_comprar;
    this->unidades_comprar = unidades_comprar;
    this->prod_id_vender = prod_id_vender;
    this->unidades_vender = unidades_vender;
}

void Barco::borrar_viajes()
{
    viajes.clear();
}

void Barco::escribir_barco() const
{
    cout << prod_id_comprar << " " << unidades_comprar << " " << prod_id_vender << " " << unidades_vender << endl;
    for (string ciudad : viajes)
    {
        cout << ciudad << endl;
    }
}