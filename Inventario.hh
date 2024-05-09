/** @file Inventario.hh  
 *      @brief Especificación de la clase Inventario.
*/

#ifndef INVENTARIO_HH
#define INVENTARIO_HH

#include "Cjt_productos.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @struct Cantidad
 *      @brief Struct que almacena la cantidad disponible y requerida de un producto   
*/

struct Cantidad
{
    int disponible;
    int requerido;
};


/** @class Inventario
 *      @brief Facilita la gestion de inventario.
*/

class Inventario 
{
private:
    /** @brief Map que almacena la cantidad disponible y requerido de cada producto que posee*/
    map<int, Cantidad> cantidad_productos;
    /** @brief Peso total de todos los productoss del inventario*/
    int peso_total;
    /** @brief Volumen total de todos los productos del inventario*/
    int volumen_total;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automáticamente al declarar un inventario.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es un inventario con el peso y volumen total inicializados a zero.
    */

    Inventario();

    // Modificadoras

    void borrar_inventario();

    void comerciar(Inventario &inventario2, const Cjt_productos &productos);

    /** @brief Modifica la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha modificado las cantidad disponible del producto con identificador id del inventario
     *      con la cantidad indicada y se ha modificado el peso y el volumen total del inventario.
    */

    void modificar_cantidad_disponible(int id, int cantidad_disponible, const Producto &prod);

    /** @brief Modifica la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha modificado las cantidad requerida del producto con identificador id del inventario 
     *      con la cantidad indicada.
    */

    void modificar_cantidad_requerida(int id, int cantidad_requerida);

    /** @brief Modifica la cantidad disponible y requerida del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha modificado las cantidad requerida y disponible del producto con identificador id del inventario 
     *      con la cantidad indicada y se ha modificado el peso y el volumen total del inventario.
    */

    void poner_producto(int id, int cantidad_disponible, int cantidad_requerida, const Producto &prod);

    /** @brief Quita el producto prod con identificador id del inventario.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha eliminado el producto con identificador id del inventario.
    */

    void quitar_producto(int id, const Producto &prod);


    // Consultoras

    /** @brief Comprueba si el inventario contiene un producto con identificador id.
     *      \pre <em>Cierto.</em>
     *      \post Devuelve cierto si el inventario contiene un producto con identificador id, falso en caso contrario.
    */

    bool contiene_producto(int id) const;

    /** @brief Devuelve la cantidad disponible del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Devuelve la cantidad disponible del producto con identificador id.
    */

    int consultar_cantidad_disponible(int id) const;

    /** @brief Devuelve la cantidad requerida del producto con identificador id.
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Devuelve la cantidad requerida del producto con identificador id.
    */

    int consultar_cantidad_requerida(int id) const;

    // Escritura

    /** @brief Imprime la cantidad disponible y requerida del producto con identificador id
     *      \pre <em>El inventario contiene el producto con identificador id.</em>
     *      \post Se ha escrito la cantidad disponible y requerida del producto con identificador id
     *      del inventario en el canal standard de salida.
    */

    void consultar_producto(int id) const;

    /** @brief Imprime el peso y volumen total del parametro implicito.
     *      \pre <em>Cierto.</em>
     *      \post Se ha escrito el peso y volumen total del parametro implicito en el canal standard de salida.
    */

    void escribir_atributos_totales() const;

    void escribir_inventario() const;
};

#endif