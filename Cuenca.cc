#include "Cuenca.hh"

Cuenca::Cuenca() {}

void Cuenca::hacer_viaje()
{
    barco.hacer_viaje(estructura, ciudades, productos);
}

void Cuenca::redistribuir()
{
    redistribuir(estructura);
}

void Cuenca::redistribuir(const BinTree<string> &raiz)
{
    if (raiz.empty()) return;
    if (not raiz.right().empty()) 
    {
        comerciar(raiz.value(), raiz.right().value());
    }
    if (not raiz.left().empty()) 
    {
        comerciar(raiz.value(), raiz.left().value());
    }
    redistribuir(raiz.right());
    redistribuir(raiz.left());
}

void Cuenca::comerciar(const string &ciudad_id1, const string &ciudad_id2)
{
    if (not ciudades.existe_ciudad(ciudad_id1) or not ciudades.existe_ciudad(ciudad_id2))
    {
        cout << "error: no existe la ciudad" << endl;
    }
    else 
    {
        ciudades.comerciar(ciudad_id1, ciudad_id2, productos);
    }
}

void Cuenca::modificar_barco()
{
    int prod_id_comprar, unidades_comprar, prod_id_vender, unidades_vender;
    cin >> prod_id_comprar >> unidades_comprar >> prod_id_vender >> unidades_vender;

    if (not productos.existe_producto(prod_id_comprar) or not productos.existe_producto(prod_id_vender))
    {
        cout << "error: no existe el producto" << endl;
    }
    else if (prod_id_comprar == prod_id_vender) 
    {
        cout << "error: no se puede comprar y vender el mismo producto" << endl;
    }
    else 
    {
        barco.modificar_barco(prod_id_comprar, unidades_comprar, prod_id_vender, unidades_vender);
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
        ciudades.modificar_cantidad_disponible(
            ciudad_id, 
            prod_id, 
            cantidad_disponible - ciudades.consultar_cantidad_disponible(ciudad_id, prod_id), 
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
    ciudades = Cjt_ciudades(); // is it slow?
    estructura = construir_estructura();
    barco.borrar_viajes();
    // FALTA RESETEJAR VIATGES BARCO
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

void Cuenca::escribir_barco() const
{
    barco.escribir_barco();
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
        // FALTA ESCIURE INVENTARI
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
        cout << ciudades.consultar_cantidad_disponible(ciudad_id, prod_id) << " " << 
                ciudades.consultar_cantidad_requerida(ciudad_id, prod_id) << endl;
    }
}