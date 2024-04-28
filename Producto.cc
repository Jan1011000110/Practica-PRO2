#include "Producto.hh"

Producto::Producto() {};

Producto::Producto(int peso, int volumen) 
{
    this->peso = peso;
    this->volumen = volumen;
}

void Producto::escribir() const 
{
    cout << "Peso: " << peso << endl;
    cout << "Volumen: " << volumen << endl;
}

void Producto::leer()
{
    cin >> peso;
    cin >> volumen;
}