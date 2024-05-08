#include "Cuenca.hh"

Cuenca::Cuenca() {}

void Cuenca::redistribuir()
{

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
        ciudades.modificar_cantidad_disponible(ciudad_id, prod_id, cantidad_disponible, productos.consultar_producto(prod_id));
        ciudades.modificar_cantidad_requerida(ciudad_id, prod_id, cantidad_requerida);
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

void Cuenca::leer_productos()
{
    productos.leer_productos();
}


void Cuenca::leer_inventario(const string &ciudad_id)
{
    if (not ciudades.existe_ciudad(ciudad_id)) 
    {
        cout << "error: no existe la ciudad" << endl;
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

    // FALTA RESETEJAR VIATGES BARCO
}

BinTree<string> Cuenca::construir_estructura() 
{
    string s;
    cin >> s;
    if (s == "#") 
    {
        return BinTree<string>();
    }
    ciudades.poner_ciudad(s);
    BinTree<string> left = construir_estructura();
    BinTree<string> right = construir_estructura();
    return BinTree<string>(s, left, right);
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
    else {
        cout << ciudades.consultar_cantidad_disponible(ciudad_id, prod_id) << " " << 
                ciudades.consultar_cantidad_requerida(ciudad_id, prod_id) << endl;
    }
}