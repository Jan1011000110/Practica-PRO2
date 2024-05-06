/** @file Barco.hh  
 *      @brief Especificación de la clase Ciudad.
*/

#ifndef BARCO_HH
#define BARCO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
#endif

using namespace std;

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

    void modificar_barco(int prod_id_comprar, int unidades_comprar, int prod_id_vender, int unidades_vender);

    // Escritura

    void escribir_barco() const;
};

#endif