#include "Producto.hh"

Producto::Producto() {};

Producto::Producto(int peso, int volumen) 
{
    this->peso = peso;
    this->volumen = volumen;
}

int Producto::consultar_peso() const
{
    return peso;
}

int Producto::consultar_volumen() const
{
    return volumen;
}

void Producto::escribir() const 
{
    cout << peso << " " << volumen << endl;
}

void Producto::leer()
{
    cin >> peso;
    cin >> volumen;
}