#include "Cjt_productos.hh"

Cjt_productos::Cjt_productos() 
{
    numero_de_productos = 0;
    productos = {Producto()}; // fill with empty producto to get 1-indexing
}

int Cjt_productos::numero_productos() const
{
    return numero_de_productos;
}

bool Cjt_productos::existe_producto(int id) const
{
    return 1 <= id and id <= numero_productos(); 
}

Producto Cjt_productos::consultar_producto(int id) const
{
    return productos[id];
}

void Cjt_productos::escribir_producto(int id) const 
{
    productos[id].escribir();
}

void Cjt_productos::leer_productos()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Producto p;
        p.leer();
        productos.push_back(p);
        numero_de_productos += 1;
    }
}
