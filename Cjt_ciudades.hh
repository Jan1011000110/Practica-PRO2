/** @file Cjt_ciudades.hh
 *      @brief Especificacion de la clase Cjt_ciudades.
 *    
 */

#ifndef CJT_CIUDADES_HH
#define CJT_CIUDADES_HH

#include "Ciudad.hh"

#ifndef NO_DIAGRAM
#include <string>
#endif

/** @class Cjt_ciudades
 *      @brief Representa el conjunto de ciudades de la cuenca fluvial, con un identificador unico para cada una.
*/

class Cjt_ciudades
{
private:
    /** @brief Map que almacena todas las ciudades.*/
    map<string, Ciudad> ciudades;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automáticamente al declarar un conjunto de ciudades.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es un conjunto de ciudades el cual todos sus atributos no estan inicializados.
    */

    Cjt_ciudades();

    // Modificadoras

    /** @brief Modifica la cantidad disponible del producto tipo prod_id de la ciudad con identificador ciudad_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe y contiene el producto con tipo prod_id.</em>
     *      \post Se ha modificado las cantidad disponible del producto tipo prod_id de la ciudad con identificador ciudad_id 
     *      con la cantidad indicada y se ha modificado el peso y el volumen total del inventario.
    */

    void modificar_cantidad_disponible(string &ciudad_id, int prod_id, int cantidad_disponible, Producto &prod);

    /** @brief Modifica la cantidad requerida del producto tipo prod_id de la ciudad con identificador ciudad_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe y contiene el producto tipo prod_id.</em>
     *      \post Se ha modificado las cantidad requerida del producto tipo prod_id de la ciudad con identificador ciudad_id
     *      con la cantidad indicada.
    */

    void modificar_cantidad_requerida(string &ciudad_id, int prod_id, int cantidad_requerida);


    /** @brief Quita el producto tipo prod_id de la ciudad con identificador ciudad_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe y contiene el producto tipo prod_id.</em>
     *      \post Se ha eliminado el producto tipo prod_id de la ciuad con identificador ciudad_id.
    */

    void quitar_producto(string &ciudad_id, int id, Producto &prod);


    // Consultoras

    /** @brief Devuelve si la ciudad con identificador ciudad_id existe.
     *      \pre <em>Cierto.</em>
     *      \post Devuelve cierto si la ciudad con identificador ciudad_id existe, falso en caso contrario.
     */

    bool existe_ciudad(string &ciudad_id) const;

    /** @brief Devuelve el inventario de la ciudad con identificador ciudad_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe</em>
     *      \post Devuelve el inventario de la ciudad con identificador ciudad_id.
     */

    Inventario consultar_inventario(string &ciudad_id);

    /** @brief Comprueba si la ciudad con identificador ciudad_id contiene un producto tipo prod_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe.</em>
     *      \post Devuelve cierto si la ciudad con identificador ciudad_id contiene un producto tipo prod_id, falso en caso contrario.
    */

    bool contiene_producto(string &ciudad_id, int prod_id);

    /** @brief Devuelve la cantidad disponible del producto tipo prod_id de la ciudad con identificador ciudad_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe y contiene el producto tipo prod_id.</em>
     *      \post Devuelve la cantidad disponible del producto tipo prod_id de la ciuadd con identificador ciudad_id.
    */

    int consultar_cantidad_disponible(string &ciudad_id, int prod_id);

    /** @brief Devuelve la cantidad requerida del producto tipo prod_id de la ciudad con identificador ciudad_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe y contiene el producto tipo prod_id.</em>
     *      \post Devuelve la cantidad requerida del producto tipo prod_id de la ciuadd con identificador ciudad_id.
    */

    int consultar_cantidad_requerida(string &ciudad_id, int prod_id);

    // Lectura

    /** @brief Lee el inventario de la ciudad con identificador ciudad_id.
     *      \pre <em>Está disponible en el canal de entrada un entero n positivo 
     *      y a continuación n lineas, cada una de ellas con el identificador del producto, 
     *      cuantas unidades tiene la ciudad y cuantas necesita de ese producto.</em>
     *      \post Se han agregado n productos al inventario de la ciudad con identificador ciudad_id.
     */

    void leer_inventario(string &ciudad_id, Cjt_productos &productos);

    // Escritura

    /** @brief Imprime la cantidad disponible y requerida de la ciudad con identificador ciudad_id del producto tipo prod_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe y contiene el producto tipo prod_id.</em>
     *      \post Se ha escrito la cantidad disponible y requerida del producto tipo prod_id
     *      de la ciudad con identificador ciudad_id en el canal standard de salida.
    */

    void consultar_producto(string &ciudad_id, int prod_id);

    /** @brief Imprime el peso y volumen total del producto tipo prod_id de la ciudad con identificador ciudad_id.
     *      \pre <em>La ciudad con identificador ciudad_id existe.</em>
     *      \post Se ha escrito el peso y volumen total del producto tipo prod_id de la ciudad con identificador ciudad_id 
     *      en el canal standard de salida.
    */

    void escribir_atributos_totales(string &ciudad_id);
};


#endif