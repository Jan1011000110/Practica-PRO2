/** @file Cuenca.cc 
 *  @brief Código de la clase Cuenca.
 */

#include "Cuenca.hh"

Cuenca::Cuenca() {}

void Cuenca::calcular_viaje(const BinTree<string> &raiz, Barco &barco, vector<string> &ruta) const
{
    if (raiz.empty()) return;

    // Ciudad actual
    string ciudad_id = raiz.value();
    
    // Cojo los datos del barco
    int id_compra, num_compra, id_venta, num_venta;
    barco.consultar_barco(id_compra, num_compra, id_venta, num_venta);

    bool agregar = false;
    // Intento comprar y vender productos en la ciudad actual
    if (ciudades.contiene_producto(ciudad_id, id_compra))
    {
        // Calculo la cantidad maxima que puedo comprar
        int cantidad_comprar = 
            max(0, 
                min(
                    num_compra,
                    ciudades.consultar_cantidad_poseida(ciudad_id, id_compra) - 
                    ciudades.consultar_cantidad_requerida(ciudad_id, id_compra)
                )
            );
        // Actualizo el numero de productos que me quedan por comprar
        num_compra -= cantidad_comprar;
        // Miro si he comerciado en esta ciudad
        if (cantidad_comprar > 0)
            agregar = true;
    }
    if (ciudades.contiene_producto(ciudad_id, id_venta))
    {
        // Calculo la cantidad maxima que puedo vender
        int cantidad_vender = 
            max(0, 
                min(
                    num_venta,
                    ciudades.consultar_cantidad_requerida(ciudad_id, id_venta) - 
                    ciudades.consultar_cantidad_poseida(ciudad_id, id_venta)
                )
            );
        // Actualizo el numero de productos que me quedan por vender
        num_venta -= cantidad_vender;
        // Miro si he comerciado en esta ciudad
        if (cantidad_vender > 0)
            agregar = true;
    }
    
    // Modifico el barco con los nuevos valores una vez he comerciado
    barco.modificar_barco(id_compra, num_compra, id_venta, num_venta);

    Barco left_barco  = barco;
    vector<string> left_ruta;
    Barco right_barco = barco;
    vector<string> right_ruta;
    
    // Recursivamente calculo el viaje de la izquierda y de la derecha
    calcular_viaje(raiz.left(), left_barco, left_ruta);
    calcular_viaje(raiz.right(), right_barco, right_ruta);

    // Miro que ruta es mejor
    if (left_barco.restante() < right_barco.restante() or (left_barco.restante() == right_barco.restante() 
    and left_ruta.size() <= right_ruta.size()))
    {
        barco = left_barco;
        ruta.swap(left_ruta);
    }
    else 
    {
        barco = right_barco;
        ruta.swap(right_ruta);
    }

    // Si he comerciado en esta ciudad o no es la ultima en la que he comerciado entonces la agrego a la ruta
    if (not ruta.empty() or agregar) 
    {
        ruta.push_back(ciudad_id);
    }
}

void Cuenca::hacer_viaje(Barco &barco)
{
    // Copio los valores de barco a una copia
    Barco copia;
    int id_compra, num_compra, id_venta, num_venta;
    barco.consultar_barco(id_compra, num_compra, id_venta, num_venta);
    copia.modificar_barco(id_compra, num_compra, id_venta, num_venta);

    // Cojo la ruta optima de comercio en el viaje
    vector<string> ruta;
    calcular_viaje(estructura, copia, ruta);

    // Si he comerciado en almenos alguna ciudad
    if (barco.restante() != copia.restante()) 
    {   
        // De nuevo copio los valores de barco
        int id_compra, num_compra, id_venta, num_venta;
        barco.consultar_barco(id_compra, num_compra, id_venta, num_venta);
        copia.modificar_barco(id_compra, num_compra, id_venta, num_venta);

        // Itero por todas las ciudades de la ruta
        for (int i = ruta.size() - 1; i >= 0; --i) 
        {
            string ciudad_id = ruta[i];
            // Comercio en la ciudad
            if (ciudades.contiene_producto(ciudad_id, id_compra))
            {
                // Calculo la cantidad maxima que puedo comprar
                int cantidad_comprar = 
                    max(0, 
                        min(
                            num_compra, 
                            ciudades.consultar_cantidad_poseida(ciudad_id, id_compra) - 
                            ciudades.consultar_cantidad_requerida(ciudad_id, id_compra)
                        )
                    );
                // Actualizo el numero de productos que me quedan por comprar
                num_compra -= cantidad_comprar;
                // Comercio de verdad con la ciudad
                ciudades.modificar_cantidad_poseida(ciudad_id, id_compra, -cantidad_comprar, productos.consultar_producto(id_compra));
            }
            if (ciudades.contiene_producto(ciudad_id, id_venta))
            {
                // Calculo la cantidad maxima que puedo vender
                int cantidad_vender = 
                    max(0, 
                        min(
                            num_venta,
                            ciudades.consultar_cantidad_requerida(ciudad_id, id_venta) - 
                            ciudades.consultar_cantidad_poseida(ciudad_id, id_venta)
                        )
                    );
                // Actualizo el numero de productos que me quedan por vender
                num_venta -= cantidad_vender;
                // Comercio de verdad con la ciudad
                ciudades.modificar_cantidad_poseida(ciudad_id, id_venta, cantidad_vender, productos.consultar_producto(id_venta));
            }
            copia.modificar_barco(id_compra, num_compra, id_venta, num_venta);
        }
        // Agrego la ultima ciudad en la que he comerciado al vector de viajes
        barco.agregar_viaje(ruta[0]);
    }
    // Escribo el numero de productos que he comprado y vendido en todo el viaje
    cout << barco.restante() - copia.restante() << endl;
}

void Cuenca::redistribuir()
{
    redistribuir(estructura);
}

void Cuenca::redistribuir(const BinTree<string> &raiz)
{
    if (raiz.empty()) return;
    if (not raiz.left().empty()) 
    {
        comerciar(raiz.value(), raiz.left().value());
        redistribuir(raiz.left());
    }
    if (not raiz.right().empty()) 
    {
        comerciar(raiz.value(), raiz.right().value());
        redistribuir(raiz.right());
    }
}

void Cuenca::comerciar(const string &ciudad_id1, const string &ciudad_id2)
{
    if (not ciudades.existe_ciudad(ciudad_id1) or not ciudades.existe_ciudad(ciudad_id2))
    {
        cout << "error: no existe la ciudad" << endl;
    }
    else if (ciudad_id1 == ciudad_id2)
    {
        cout << "error: ciudad repetida" << endl;
    }
    else 
    {
        ciudades.comerciar(ciudad_id1, ciudad_id2, productos);
    }
}

void Cuenca::modificar_barco(int id_compra, int num_compra, int id_venta, int num_venta, Barco &barco)
{
    if (not productos.existe_producto(id_compra) or not productos.existe_producto(id_venta))
    {
        cout << "error: no existe el producto" << endl;
    }
    else if (id_compra == id_venta) 
    {
        cout << "error: no se puede comprar y vender el mismo producto" << endl;
    }
    else 
    {
        barco.modificar_barco(id_compra, num_compra, id_venta, num_venta);
    }
}

void Cuenca::poner_producto(const string &ciudad_id, int prod_id, int cantidad_disponible, int cantidad_requerida)
{
    if (not productos.existe_producto(prod_id))
    {
        cout << "error: no existe el producto" << endl;
    }
    else if (not ciudades.existe_ciudad(ciudad_id))
    {
        cout << "error: no existe la ciudad" << endl;
    }
    else if (ciudades.contiene_producto(ciudad_id, prod_id))
    {
        cout << "error: la ciudad ya tiene el producto" << endl;
    }
    else {
        ciudades.poner_producto(ciudad_id, prod_id, cantidad_disponible, cantidad_requerida, productos.consultar_producto(prod_id));
        ciudades.escribir_atributos_totales(ciudad_id);
    }
}

void Cuenca::modificar_producto(const string &ciudad_id, int prod_id, int cantidad_disponible, int cantidad_requerida)
{
    if (not productos.existe_producto(prod_id))
    {
        cout << "error: no existe el producto" << endl;
    }
    else if (not ciudades.existe_ciudad(ciudad_id))
    {
        cout << "error: no existe la ciudad" << endl;
    }
    else if (not ciudades.contiene_producto(ciudad_id, prod_id))
    {
        cout << "error: la ciudad no tiene el producto" << endl;
    }
    else { 
        ciudades.modificar_cantidad_poseida(
            ciudad_id, 
            prod_id, 
            cantidad_disponible - ciudades.consultar_cantidad_poseida(ciudad_id, prod_id), 
            productos.consultar_producto(prod_id)
        );
        ciudades.modificar_cantidad_requerida(
            ciudad_id, 
            prod_id, 
            cantidad_requerida - ciudades.consultar_cantidad_requerida(ciudad_id, prod_id)
        );
        ciudades.escribir_atributos_totales(ciudad_id);
    }
}

void Cuenca::quitar_producto(const string &ciudad_id, int prod_id) 
{
    if (not productos.existe_producto(prod_id))
    {
        cout << "error: no existe el producto" << endl;
    }
    else if (not ciudades.existe_ciudad(ciudad_id))
    {
        cout << "error: no existe la ciudad" << endl;
    }
    else if (not ciudades.contiene_producto(ciudad_id, prod_id))
    {
        cout << "error: la ciudad no tiene el producto" << endl;
    }
    else 
    {
        ciudades.quitar_producto(ciudad_id, prod_id, productos.consultar_producto(prod_id));
        ciudades.escribir_atributos_totales(ciudad_id);
    }
}

void Cuenca::numero_productos() const
{
    cout << productos.numero_productos() << endl;
}

void Cuenca::leer_productos(int n)
{
    productos.leer_productos(n);
}


void Cuenca::leer_inventario(const string &ciudad_id)
{
    if (not ciudades.existe_ciudad(ciudad_id)) 
    {
        cout << "error: no existe la ciudad" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) 
        {
            int foo1, foo2, foo3;
            cin >> foo1 >> foo2 >> foo3;
        }
    }
    else 
    {
        ciudades.leer_inventario(ciudad_id, productos);
    }
}

void Cuenca::leer_inventarios()
{
    string ciudad_id;
    cin >> ciudad_id;
    while (ciudad_id != "#")
    {
        leer_inventario(ciudad_id);
        cin >> ciudad_id;
    }
}

void Cuenca::leer_rio() 
{
    ciudades = Cjt_ciudades(); 
    estructura = construir_estructura(); 
}

BinTree<string> Cuenca::construir_estructura() 
{
    string ciudad_id;
    cin >> ciudad_id;
    if (ciudad_id == "#") 
    {
        return BinTree<string>();
    }
    ciudades.poner_ciudad(ciudad_id);
    BinTree<string> left = construir_estructura();
    BinTree<string> right = construir_estructura();
    return BinTree<string>(ciudad_id, left, right);
}

void Cuenca::escribir_producto(int prod_id) const
{
    if (not productos.existe_producto(prod_id)) 
    {
        cout << "error: no existe el producto" << endl;
    }
    else 
    {
        productos.escribir_producto(prod_id);
    }
}

void Cuenca::escribir_ciudad(const string &ciudad_id) const
{
    if (not ciudades.existe_ciudad(ciudad_id))
    {
        cout << "error: no existe la ciudad" << endl;
    }
    else 
    {
        ciudades.escribir_inventario(ciudad_id);
        ciudades.escribir_atributos_totales(ciudad_id);
    }
}

void Cuenca::consultar_producto_ciudad(const string &ciudad_id, int prod_id) const
{
    if (not productos.existe_producto(prod_id))
    {
        cout << "error: no existe el producto" << endl;
    }
    else if (not ciudades.existe_ciudad(ciudad_id))
    {
        cout << "error: no existe la ciudad" << endl;
    }
    else if (not ciudades.contiene_producto(ciudad_id, prod_id))
    {
        cout << "error: la ciudad no tiene el producto" << endl;
    }
    else {
        cout << ciudades.consultar_cantidad_poseida(ciudad_id, prod_id) << " " << 
                ciudades.consultar_cantidad_requerida(ciudad_id, prod_id) << endl;
    }
}