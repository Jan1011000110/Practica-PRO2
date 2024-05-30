/** @file Barco.hh  
 *  @brief Especificación de la clase Ciudad.
*/

#ifndef BARCO_HH
#define BARCO_HH

#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
#endif

using namespace std;

/*
 * Clase Barco
 */

/** @class Barco
 *  @brief Representa el barco de comercio de la cuenca fluvial.
*/

class Barco 
{
private:
    /** @brief Identificador del producto que quiere comprar el parametro implicito. */
    int id_compra;
    /** @brief Cantidad de productos que quiere comprar el parametro implicito. */
    int num_compra;
    /** @brief Identificador del producto que quiere vender el parametro implicito. */
    int id_venta;
    /** @brief Cantidad de productos que quiere vender el parametro implicito. */
    int num_venta;
    /** @brief Vector en el que se guardan las ultimas ciudades en las que se ha comerciado en cada viaje. */
    vector<string> viajes;
public:

    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automaticamente al declarar un barco.
     *      \pre Cierto.
     *      \post El resultado es un barco el cual todos sus atributos estan sin inicializar.
    */     
    Barco();

    // Modificadoras

    /** @brief Modificadora de los atributos del barco.
     *     \pre Los identificadores de producto <em>id_compra</em>, <em>id_venta</em> son validos y diferentes.
     *     \post Los atributos del barco quedan modificados con los valores de los parametros.
     */
    void modificar_barco(int id_compra, int num_compra, int id_venta, int num_venta);

    /** @brief Agrega un identificador de una ciudad al vector del parametro implicito.
     *      \pre Cierto.
     *      \post Se ha añadido el identificador de la ciudad al vector del parametro implicito.
     */
    void agregar_viaje(const string &ciudad_id);

    /** @brief Vacia el vector del parametro implicito.
     *      \pre Cierto.
     *      \post El vector del parametro implicito queda vacio.
     */
    void borrar_viajes();

    // Consultoras

    /** @brief Consulta los atributos del barco.
     *      \pre El barco esta inicializado.
     *      \post Los parametros pasados por referencia tienen los valores de los atributos del barco.
     */
    void consultar_barco(int &id_compra, int &num_compra, int &id_venta, int &num_venta) const;

    /** @brief Consulta la suma del numero de productos que quiere comprar y vender el parametro implicito.
     *      \pre El barco esta inicializado.
     *      \post Devuelve la suma del numero de productos que quiere comprar y vender el parametro implicito.
     */
    int restante() const;

    // Escritura

    /** @brief Escribe los atributos del barco y el vector de viajes.
     *      \pre El barco esta inicializado.
     *      \post Se han escrito los atributos del barco y el vector de viajes en el canal standard de salida.
    */
    void escribir_barco() const;
};

#endif