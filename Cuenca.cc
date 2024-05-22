#include "Cuenca.hh"

Cuenca::Cuenca() {}

void Cuenca::calcular_viaje(const BinTree<string> &raiz, Barco &barco, vector<string> &ruta)
{
    if (raiz.empty()) return;

    string ciudad_id = raiz.value();
    bool agregar = false;
    if (ciudades.contiene_producto(ciudad_id, barco.id_compra))
    {
        int cantidad_comprar = 
            max(0, 
                min(
                    barco.num_compra, 
                    ciudades.consultar_cantidad_poseido(ciudad_id, barco.id_compra) - 
                    ciudades.consultar_cantidad_requerida(ciudad_id, barco.id_compra)
                )
            );
        barco.num_compra -= cantidad_comprar;
        if (cantidad_comprar > 0)
            agregar = true;
    }
    if (ciudades.contiene_producto(ciudad_id, barco.id_venta))
    {
        int cantidad_vender = 
            max(0, 
                min(
                    barco.num_venta, 
                    ciudades.consultar_cantidad_requerida(ciudad_id, barco.id_venta) - 
                    ciudades.consultar_cantidad_poseido(ciudad_id, barco.id_venta)
                )
            );
        barco.num_venta -= cantidad_vender;
        if (cantidad_vender > 0)
            agregar = true;
    }

    Barco left_barco = barco;
    vector<string> left_ruta;
    Barco right_barco = barco;
    vector<string> right_ruta;
    
    calcular_viaje(raiz.left(), left_barco, left_ruta);
    calcular_viaje(raiz.right(), right_barco, right_ruta);

    if (left_barco.restante() < right_barco.restante() or (left_barco.restante() == right_barco.restante() and left_ruta.size() <= right_ruta.size()))
    {
        barco = left_barco;
        ruta = left_ruta;
    }
    else 
    {
        barco = right_barco;
        ruta = right_ruta;
    }

    if (not ruta.empty() or agregar) 
    {
        ruta.push_back(ciudad_id);
    }
}

void Cuenca::hacer_viaje(Barco &barco) 
{
    Barco copia = barco;
    vector<string> ruta;
    calcular_viaje(estructura, copia, ruta);

    if (barco.restante() != copia.restante()) 
    {
        copia = barco;
        for (int i = ruta.size() - 1; i >= 0; --i) 
        {
            string ciudad_id = ruta[i];
            if (ciudades.contiene_producto(ciudad_id, copia.id_compra))
            {
                int cantidad_comprar = 
                    max(0, 
                        min(
                            copia.num_compra, 
                            ciudades.consultar_cantidad_poseido(ciudad_id, copia.id_compra) - 
                            ciudades.consultar_cantidad_requerida(ciudad_id, copia.id_compra)
                        )
                    );
                copia.num_compra -= cantidad_comprar;
                ciudades.modificar_cantidad_poseido(ciudad_id, copia.id_compra, -cantidad_comprar, productos.consultar_producto(copia.id_compra));
            }
            if (ciudades.contiene_producto(ciudad_id, copia.id_venta))
            {
                int cantidad_vender = 
                    max(0, 
                        min(
                            copia.num_venta, 
                            ciudades.consultar_cantidad_requerida(ciudad_id, copia.id_venta) - 
                            ciudades.consultar_cantidad_poseido(ciudad_id, copia.id_venta)
                        )
                    );
                copia.num_venta -= cantidad_vender;
                ciudades.modificar_cantidad_poseido(ciudad_id, copia.id_venta, cantidad_vender, productos.consultar_producto(copia.id_venta));
            }

        }
        barco.agregar_viaje(ruta[0]);
    }
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

void Cuenca::modificar_barco(Barco &barco)
{
    int id_compra, num_compra, id_venta, num_venta;
    cin >> id_compra >> num_compra >> id_venta >> num_venta;

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
        ciudades.modificar_cantidad_poseido(
            ciudad_id, 
            prod_id, 
            cantidad_disponible - ciudades.consultar_cantidad_poseido(ciudad_id, prod_id), 
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

void Cuenca::escribir_ciudad(const string &ciudad_id)
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

void Cuenca::consultar_producto_ciudad(const string &ciudad_id, int prod_id)
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
        cout << ciudades.consultar_cantidad_poseido(ciudad_id, prod_id) << " " << 
                ciudades.consultar_cantidad_requerida(ciudad_id, prod_id) << endl;
    }
}