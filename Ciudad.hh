/** @file Ciudad.hh  
 *      @brief Especificación de la clase Ciudad.
*/

#ifndef CIUDAD_HH
#define CIUDAD_HH

#include "Inventario.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif


/** @class Ciudad
 *      @brief Representa una ciudad de la cuenca fluvial.
*/

class Ciudad 
{
private:
    /** @brief Map que almacena la cantidad disponible y requerido de cada producto que posee*/
    Inventario inventario;
    /** @brief Peso total de todos los productoss del inventario*/
    int peso_total;
    /** @brief Volumen total de todos los productos del inventario*/
    int volumen_total;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automáticamente al declarar un ciudad.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es una ciudad con el peso y volumen total inicializados a zero.
    */

    Ciudad();

    // Modificadoras

    /** @brief Modifica la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha modificado las cantidad disponible del producto con identificador id del inventario
     *      con la cantidad indicada y se ha modificado el peso y el volumen total del inventario.
    */

    void modifica_cantidad_disponible(int id, int cantidad_disponible, Producto &prod);

    /** @brief Modifica la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha modificado la cantidad requerida del producto con identificador id del inventario 
     *      con la cantidad indicada.
    */

    void modifica_cantidad_requerida(int id, int cantidad_requerida, Producto &prod);


    /** @brief Quita el producto prod con identificador id del inventario.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha eliminado el producto con identificador id del inventario.
    */

    void quitar_producto(int id, Producto &prod);


    // Consultoras

    /** @brief Devuelve el inventario del parametro implicito.
     *      \pre <em>Cierto.</em>
     *      \post Devuelve el inventario del parametro implicito.
     */

    Inventario consulta_inventario() const;

    /** @brief Comprueba si el inventario contiene un producto con identificador id.
     *      \pre <em>Cierto.</em>
     *      \post Devuelve cierto si el inventario contiene un producto con identificador id, falso en caso contrario.
    */

    bool contiene_producto(int id) const;

    /** @brief Devuelve la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Devuelve la cantidad disponible del producto con identificador id.
    */

    int consulta_cantidad_disponible(int id);

    /** @brief Devuelve la cantidad requerida del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Devuelve la cantidad requerida del producto con identificador id.
    */

    int consulta_cantidad_requerida(int id);

    // Lectura

    // Escritura

    /** @brief Imprime la cantidad disponible y requerida del producto con identificador id
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha escrito la cantidad disponible y requerida del producto con identificador id
     *      del inventario en el canal standard de salida.
    */

    void consultar_producto(int id);

    /** @brief Imprime el peso y volumen total del parametro implicito.
     *      \pre <em>Cierto.</em>
     *      \post Se ha escrito el peso y volumen total del producto con identificador id en el canal standard de salida.
    */

    void escribir_atributos_totales() const;
};

#endif