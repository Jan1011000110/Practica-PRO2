/** @file Cjt_ciudades.hh
 *      @brief Especificacion de la clase Cjt_ciudades.
 *    
 */

#ifndef CJT_CIUDADES_HH
#define CJT_CIUDADES_HH

#include "Inventario.hh"

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
    map<string, Inventario> ciudades;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automáticamente al declarar un conjunto de ciudades.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es un conjunto de ciudades el cual todos sus atributos no estan inicializados.
    */
    Cjt_ciudades();

    // Modificadoras

    /** @brief Realiza un comercio entre dos ciudades.
     *      \pre Cierto.
     *      \post La ciudad con identificador <em>ciudad_id1</em> comercia con la ciudad con identificador <em>ciudad_id2</em>.
    */
    void comerciar(const string &ciudad_id1, const string &ciudad_id2, const Cjt_productos &productos);

    /** @brief Añade una ciudad al conjunto de ciudades.
     *      \pre No existe una ciudad con identificador <em>ciudad_id</em>.
     *      \post Se ha añadido una ciudad con identificador <em>ciudad_id</em>.
    */
    void poner_ciudad(const string &ciudad_id);

    /** @brief Añade un producto a una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id</em> no contiene el producto con identificador <em>prod_id</em>.
     *      \post Se ha añadido el producto con identificador <em>prod_id</em> a la ciudad con identificador <em>ciudad_id</em>.
    */
    void poner_producto(const string &ciudad_id, int prod_id, int cantidad_disponible, int cantidad_requerida, const Producto &prod);

    /** @brief Modifica la cantidad poseida de un producto en una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id<em> existe y contiene el producto con identificador <em>prod_id</em>.
     *      \post Se ha modificado las cantidad poseida del producto con identificador <em>prod_id</em> de la ciudad con 
     *      identificador <em>ciudad_id</em> con la cantidad indicada.
    */
    void modificar_cantidad_poseida(const string &ciudad_id, int prod_id, int cantidad_disponible, const Producto &prod);

    /** @brief Modifica la cantidad requerida de un producto en una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id</em> existe y contiene el producto con identificador <em>prod_id</em>.
     *      \post Se ha modificado la cantidad requerida del producto con identificador <em>prod_id</em> de la ciudad con 
     *      identificador <em>ciudad_id</em> con la cantidad indicada.
    */
    void modificar_cantidad_requerida(const string &ciudad_id, int prod_id, int cantidad_requerida);


    /** @brief Quita un producto del inventario de una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id</em> existe y contiene el producto con identificador <em>prod_id</em>.
     *      \post Se ha eliminado el producto con identificador <em>prod_id</em> de la ciuad con identificador ciudad_id.
    */
    void quitar_producto(const string &ciudad_id, int prod_id, const Producto &prod);


    // Consultoras

    /** @brief Devuelve si una ciudad existe.
     *      \pre Cierto.
     *      \post Devuelve cierto si la ciudad con identificador <em>ciudad_id</em> existe, falso en caso contrario.
     */
    bool existe_ciudad(const string &ciudad_id) const;

    /** @brief Devuelve el inventario de una ciudad.
     *      \pre La ciudad con identificador ciudad_id existe.
     *      \post Devuelve el inventario de la ciudad con identificador <em>ciudad_id</em>.
     */
    Inventario consultar_inventario(const string &ciudad_id) const;

    /** @brief Comprueba si una ciudad tiene un producto.
     *      \pre La ciudad con identificador <em>ciudad_id</em> existe.
     *      \post Devuelve cierto si la ciudad con identificador <em>ciudad_id</em> contiene el producto con identificador <em>prod_id</em>, falso en caso contrario.
    */
    bool contiene_producto(const string &ciudad_id, int prod_id) const;

    /** @brief Devuelve la cantidad poseida de un producto en el inventario de una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id</em> existe y contiene el producto con identificador <em>prod_id</em>.
     *      \post Devuelve la cantidad poseida del producto con identificador <em>prod_id</em> de la ciuadd con identificador <em>ciudad_id</em>.
    */
    int consultar_cantidad_poseida(const string &ciudad_id, int prod_id) const;

    /** @brief Devuelve la cantidad requerida de un producto en el inventario de una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id</em> existe y contiene el producto con identificador <em>prod_id</em>.
     *      \post Devuelve la cantidad requerida del producto con identificador <em>prod_id</em> de la ciuad con identificador <em>ciudad_id</em>.
    */
    int consultar_cantidad_requerida(const string &ciudad_id, int prod_id) const;

    // Lectura

    /** @brief Lee el inventario de una ciudad.
     *      \pre Está disponible en el canal de entrada un entero N positivo 
     *      y a continuación N lineas, cada una de ellas con el identificador de un producto y
     *      cuantas unidades de ese producto posee y requiere la ciudad con identificador <em>ciudad_id</em>.
     *      \post Se ha leido el inventario de la ciudad con identificador <em>ciudad_id</em>.
     */
    void leer_inventario(const string &ciudad_id, const Cjt_productos &productos);

    // Escritura

    /** @brief Imprime la cantidad poseida y requerida de un producto en el inventario de una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id</em> existe y contiene el producto con identificador <em>prod_id</em>.
     *      \post Se ha escrito la cantidad poseida y requerida del producto con identificador <em>prod_id</em>
     *      de la ciudad con identificador <em>ciudad_id</em> en el canal standard de salida.
    */
    void consultar_producto(const string &ciudad_id, int prod_id) const;

    /** @brief Imprime el peso y volumen total de un producto del inventario de una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id</em> existe.
     *      \post Se ha escrito el peso y volumen total del producto con identificador <em>prod_id</em> de la ciudad con identificador 
     *      <em>ciudad_id</em> en el canal standard de salida.
    */
    void escribir_atributos_totales(const string &ciudad_id) const;

    /** @brief Imprime el inventario de una ciudad.
     *      \pre La ciudad con identificador <em>ciudad_id</em> existe.
     *      \post Se ha escrito el inventario de la ciudad con identificador <em>ciudad_id</em> en el canal standard de salida.
    */
    void escribir_inventario(const string &ciudad_id) const;
};


#endif