#include "Barco.hh"

Barco::Barco() {}

void Barco::modificar_barco(int prod_id_comprar, int unidades_comprar, int prod_id_vender, int unidades_vender) 
{
    this->prod_id_comprar = prod_id_comprar;
    this->unidades_comprar = unidades_comprar;
    this->prod_id_vender = prod_id_vender;
    this->unidades_vender = unidades_vender;
}

void Barco::escribir_barco() const
{
    cout << prod_id_comprar << endl;
    cout << unidades_comprar << endl;
    cout << prod_id_vender << endl;
    cout << unidades_vender << endl;
    for (string ciudad : viajes) {
        cout << ciudad << endl;
    }
}