/** @file Barco.hh  
 *      @brief Especificación de la clase Ciudad.
*/

#ifndef BARCO_HH
#define BARCO_HH

#include "Cjt_productos.hh"
#include "Cjt_ciudades.hh"
#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
#include <map>
#endif

using namespace std;

// struct Nodo
// {
//     string ciudad_id;
//     int id;
//     int numero_hijos;
// };


/** @class Barco
 *      @brief Representa el barco de comercio de la cuenca fluvial.
*/

class Barco 
{
private:
    int prod_id_comprar;
    int unidades_comprar;
    int prod_id_vender;
    int unidades_vender;
    vector<string> viajes;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automaticamente al declarar un barco.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es un barco el cual todos sus atributos estan sin inicializar.
     */     

    Barco();

    // Modificadoras

    void calcular_viaje(const BinTree<string> &raiz, const Cjt_ciudades &ciudades, map<string, vector<int>> &dp) const;
    
    void hacer_viaje(const BinTree<string> &raiz, Cjt_ciudades &ciudades,  Cjt_productos &productos);

    void modificar_barco(int prod_id_comprar, int unidades_comprar, int prod_id_vender, int unidades_vender);

    void borrar_viajes();

    // Escritura

    void escribir_barco() const;
};

#endif