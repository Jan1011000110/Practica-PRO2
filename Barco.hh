/** @file Barco.hh  
 *      @brief Especificación de la clase Ciudad.
*/

#ifndef BARCO_HH
#define BARCO_HH

#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
#include <map>
#endif

using namespace std;


/** @class Barco
 *      @brief Representa el barco de comercio de la cuenca fluvial.
*/

class Barco 
{
private:
    static vector<string> viajes;
public:
    int id_compra;
    int num_compra;
    int id_venta;
    int num_venta;

    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automaticamente al declarar un barco.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es un barco el cual todos sus atributos estan sin inicializar.
     */     

    Barco();

    // Modificadoras

    void modificar_barco(int id_compra, int num_compra, int id_venta, int num_venta);

    void agregar_viaje(const string &ciudad_id);

    void borrar_viajes();

    // Consultoras

    int restante() const;

    // Escritura

    void escribir_barco() const;
};

#endif