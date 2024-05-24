/** @file Inventario.hh  
 *      @brief Especificación de la clase Inventario.
*/

#ifndef INVENTARIO_HH
#define INVENTARIO_HH

#include "Cjt_productos.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @struct Cantidad.
 *      @brief Struct que almacena la cantidad poseida y requerida de los productos que posee.
*/

struct Cantidad
{
    int poseido;
    int requerido;
};


/** @class Inventario.
 *      @brief Facilita la gestion de inventario.
*/

class Inventario 
{
private:
    /** @brief Map que almacena la cantidad poseida y requerida de cada producto que posee.*/
    map<int, Cantidad> inv;
    /** @brief Peso total de todos los productoss del inventario.*/
    int peso_total;
    /** @brief Volumen total de todos los productos del inventario.*/
    int volumen_total;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automáticamente al declarar un inventario.
     *      \pre Cierto.
     *      \post El resultado es un inventario con el peso y volumen total inicializados a zero.
    */

    Inventario();

    // Modificadoras

    /** @brief Borra todos los productos del inventario.
     *      \pre Cierto.
     *      \post El inventario queda vacio.
    */
    void borrar_inventario();

    /** @brief Intercambia productos entre dos inventarios que le sobren a uno y le falten al otro.
     *      \pre Cierto.
     *      \post Se han intercambiado productos entre los dos inventarios que le sobraban a uno y le faltaban a otro.
    */
    void comerciar(Inventario &inventario2, const Cjt_productos &productos);


    /** @brief Modifica la cantidad poseida del producto con identificador <em>id</em>.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Se ha modificado la cantidad poseida del producto con identificador <em>id</em> del inventario 
     *      sumandole la cantidad indicada y se ha modificado el peso y el volumen total del inventario proporcionalmente.
    */
    void modificar_cantidad_poseida(int id, int cantidad_poseida, const Producto &prod);

    /** @brief Modifica la cantidad requerida del producto con identificador <em>id</em>.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Se ha modificado la cantidad requerida del producto con identificador <em>id</em> del inventario 
     *      sumandole la cantidad indicada.
    */
    void modificar_cantidad_requerida(int id, int cantidad_requerida);

    /** @brief Añade el producto prod con identificador <em>id</em> al inventario.
     *      \pre <em>El inventario no contiene el producto con identificador <em>id</em>.</em>
     *      \post Se ha añadido el producto con identificador <em>id</em> al inventario con la cantidad poseida y requerida indicada.
    */
    void poner_producto(int id, int cantidad_poseida, int cantidad_requerida, const Producto &prod);

    /** @brief Quita el producto con identificador <em>id</em> del inventario.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Se ha eliminado el producto con identificador <em>id</em> del inventario.
    */
    void quitar_producto(int id, const Producto &prod);


    // Consultoras

    /** @brief Comprueba si el inventario contiene un producto con identificador <em>id</em>.
     *      \pre Cierto.
     *      \post Devuelve cierto si el inventario contiene un producto con identificador <em>id</em>, falso en caso contrario.
    */
    bool contiene_producto(int id) const;

    /** @brief Devuelve la cantidad poseida del producto con identificador <em>id</em>.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Devuelve la cantidad poseida del producto con identificador <em>id</em>.
    */
    int consultar_cantidad_poseida(int id) const;

    /** @brief Devuelve la cantidad requerida del producto con identificador <em>id</em>.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Devuelve la cantidad requerida del producto con identificador <em>id</em>.
    */
    int consultar_cantidad_requerida(int id) const;

    // Lectura

    /** @brief Lee el inventario.
     *      \pre Se encuentra en el canal estandard de entrada un natural <em>n</em> y a continuacion
     *      <em>n</em> lineas con el identificador del producto y la cantidad poseida y requerida.
     *      \post Se ha leido el inventario del parametro implicito.
    */
    void leer_inventario(const Cjt_productos &productos);

    // Escritura

    /** @brief Imprime la cantidad poseida y requerida del producto con identificador <em>id</em>.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Se ha escrito la cantidad poseida y requerida del producto con identificador <em>id</em>
     *      del inventario en el canal standard de salida.
    */
    void consultar_producto(int id) const;

    /** @brief Imprime el peso y volumen total del parametro implicito.
     *      \pre Cierto.
     *      \post Se ha escrito el peso y volumen total del parametro implicito en el canal standard de salida.
    */
    void escribir_atributos_totales() const;

    /** @brief Imprime el inventario.
     *      \pre <em>Cierto.</em>
     *      \post Se ha escrito por cada producto del inventario: su identificador y la cantidad poseida y requerida.
    */
    void escribir_inventario() const;
};

#endif