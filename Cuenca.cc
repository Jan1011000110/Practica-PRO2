#include "Cuenca.hh"

Cuenca::Cuenca() {}

void Cuenca::leer_productos() 
{
    productos.leer_productos();
}

void Cuenca::leer_inventario(string &ciudad_id)
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

void Cuenca::leer_rio() 
{
    estructura = construir_estructura();
    cout << estructura.value() << endl;
    // Resetejar inventaris ciutats
    // Resetejar historial viatges barco
}

BinTree<string> Cuenca::construir_estructura() 
{
    string s;
    cin >> s;
    if (s == "#") {
        return BinTree<string>();
    }
    BinTree<string> left = construir_estructura();
    BinTree<string> right = construir_estructura();
    return BinTree<string>(s, left, right);
}