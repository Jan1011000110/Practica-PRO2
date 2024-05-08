/** @file Ciudad.hh  
 *      @brief Especificación de la clase Ciudad.
*/

#ifndef CIUDAD_HH
#define CIUDAD_HH

#include "Inventario.hh"
#include "Cjt_productos.hh"

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

    void poner_producto(int prod_id, int cantidad_disponible, int cantidad_requerida, const Producto &prod);

    /** @brief Modifica la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha modificado las cantidad disponible del producto con identificador id del inventario
     *      con la cantidad indicada y se ha modificado el peso y el volumen total del inventario.
    */

    void modificar_cantidad_disponible(int id, int cantidad_disponible, const Producto &prod);

    /** @brief Modifica la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha modificado la cantidad requerida del producto con identificador id del inventario 
     *      con la cantidad indicada.
    */

    void modificar_cantidad_requerida(int id, int cantidad_requerida);


    /** @brief Quita el producto prod con identificador id del inventario.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha eliminado el producto con identificador id del inventario.
    */

    void quitar_producto(int id, const Producto &prod);


    // Consultoras

    /** @brief Devuelve el inventario del parametro implicito.
     *      \pre <em>Cierto.</em>
     *      \post Devuelve el inventario del parametro implicito.
     */

    Inventario consultar_inventario() const;

    /** @brief Comprueba si el inventario contiene un producto con identificador id.
     *      \pre <em>Cierto.</em>
     *      \post Devuelve cierto si el inventario contiene un producto con identificador id, falso en caso contrario.
    */

    bool contiene_producto(int id) const;

    /** @brief Devuelve la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Devuelve la cantidad disponible del producto con identificador id.
    */

    int consultar_cantidad_disponible(int id);

    /** @brief Devuelve la cantidad requerida del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Devuelve la cantidad requerida del producto con identificador id.
    */

    int consultar_cantidad_requerida(int id);

    // Lectura

    /** @brief Lee el inventario de la ciudad.
     *      \pre <em>Está disponible en el canal de entrada un entero n positivo 
     *      y a continuación n lineas, cada una de ellas con el identificador del producto, 
     *      cuantas unidades tiene la ciudad y cuantas necesita de ese producto.</em>
     *      \post Se han agregado n productos al inventario de la ciudad.
     */

    void leer_inventario(const Cjt_productos &productos);

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

    void escribir_inventario() const;
};

#endif