/** @file Cuenca.hh  
 *      @brief Especificación de la clase Cuenca.
*/

#ifndef CUENCA_HH
#define CUENCA_HH

#include "Cjt_productos.hh"
#include "Cjt_ciudades.hh"
#include "Barco.hh"
#include "BinTree.hh"

/** @class Cuenca
 *      @brief Representa la cuenca fluvial.
*/

class Cuenca
{
private:
    Cjt_productos productos;
    Cjt_ciudades ciudades;
    Barco barco;
    BinTree<string> estructura;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automaticamente al declarar una cuenca.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es una cuenca la cual todos sus atributos estan sin inicializar.
     */     

    Cuenca();

    // Modificadoras

    void redistribuir();

    // Lectura

    void leer_productos();

    void leer_inventario(string &ciudad_id);

    void leer_rio();

    BinTree<string> construir_estructura();

};

#endif