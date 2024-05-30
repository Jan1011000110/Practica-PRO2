/** @file Cjt_productos.cc 
 *  @brief Código de la clase Cjt_productos.
 */

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

Producto Cjt_productos::leer_producto()
{
    Producto p;
    p.leer_producto();
    return p;
}

void Cjt_productos::leer_productos(int n)
{
    for (int i = 0; i < n; ++i) {
        productos.push_back(leer_producto());
        numero_de_productos += 1;
    }
}
