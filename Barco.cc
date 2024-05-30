/** @file Barco.cc 
 *  @brief Código de la clase Barco.
 */

#include "Barco.hh"

Barco::Barco() {}

void Barco::modificar_barco(int id_compra, int num_compra, int id_venta, int num_venta)
{
    this->id_compra = id_compra;
    this->num_compra = num_compra;
    this->id_venta = id_venta;
    this->num_venta = num_venta;
}

void Barco::agregar_viaje(const string &ciudad_id) 
{
    viajes.push_back(ciudad_id);
}

void Barco::borrar_viajes()
{
    viajes.clear();
}

void Barco::consultar_barco(int &id_compra, int &num_compra, int &id_venta, int &num_venta) const
{
    id_compra = this->id_compra;
    num_compra = this->num_compra;
    id_venta = this->id_venta;
    num_venta = this->num_venta;
}

int Barco::restante() const
{
    return num_compra + num_venta;
}

void Barco::escribir_barco() const
{
    cout << id_compra << " " << num_compra << " " << id_venta << " " << num_venta << endl;
    for (string ciudad : viajes)
    {
        cout << ciudad << endl;
    }
}