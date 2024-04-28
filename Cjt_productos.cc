#include "Cjt_productos.hh"

Cjt_productos::Cjt_productos() {}

int Cjt_productos::numero_productos() const
{
    return numero_de_productos;
}

bool Cjt_productos::existe_producto(int id) const
{
    return id <= numero_de_productos; 
}

void Cjt_productos::escribir_producto(int id) const 
{
    productos[id - 1].escribir();
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
