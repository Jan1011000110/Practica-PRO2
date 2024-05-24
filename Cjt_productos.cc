#include "Cjt_productos.hh"

Cjt_productos::Cjt_productos() 
{
    numero_de_productos = 0;
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
    return productos.at(id - 1);
}

void Cjt_productos::escribir_producto(int id) const 
{
    cout << id << ' ';
    productos.at(id - 1).escribir_producto();
}

void Cjt_productos::leer_productos(int n)
{
    for (int i = 0; i < n; ++i) {
        Producto p;
        p.leer_producto();
        productos.push_back(p);
        numero_de_productos += 1;
    }
}
