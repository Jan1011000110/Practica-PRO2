/** @file Inventario.hh  
 *  @brief Especificación de la clase Inventario.
*/

#ifndef INVENTARIO_HH
#define INVENTARIO_HH

#include "Cjt_productos.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @struct Cantidad
 *  @brief Struct que almacena la cantidad poseida y requerida de los productos que posee.
*/

struct Cantidad
{
    /** @brief Cantidad de un producto que posee el inventario de una ciudad. */
    int poseido;
    /** @brief Cantidad de un producto que requere el inventario de una ciudad. */
    int requerido;
};

/*
 * Clase Inventario
 */

/** @class Inventario
 *  @brief Representa el inventario de una ciudad.
*/

class Inventario 
{
private:
    /** @brief Map que almacena la cantidad poseida y requerida de cada producto que posee. */
    map<int, Cantidad> inv;
    /** @brief Peso total de todos los productoss del inventario. */
    int peso_total;
    /** @brief Volumen total de todos los productos del inventario. */
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


    /** @brief Modificadora de la cantidad poseida de un producto.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Se ha modificado la cantidad poseida del producto con identificador <em>id</em> del inventario 
     *      sumandole la cantidad indicada y se ha modificado el peso y el volumen total del inventario proporcionalmente.
    */
    void modificar_cantidad_poseida(int id, int cantidad_poseida, const Producto &prod);

    /** @brief Modificadora de la cantidad requerida de un producto.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Se ha modificado la cantidad requerida del producto con identificador <em>id</em> del inventario 
     *      sumandole la cantidad indicada.
    */
    void modificar_cantidad_requerida(int id, int cantidad_requerida);

    /** @brief Añade un producto al inventario.
     *      \pre <em>El inventario no contiene el producto con identificador <em>id</em>.
     *      \post Se ha añadido el producto con identificador <em>id</em> al inventario con la cantidad poseida y requerida indicada.
    */
    void poner_producto(int id, int cantidad_poseida, int cantidad_requerida, const Producto &prod);

    /** @brief Quita un producto del inventario.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Se ha eliminado el producto con identificador <em>id</em> del inventario.
    */
    void quitar_producto(int id, const Producto &prod);


    // Consultoras

    /** @brief Consulta si el inventario contiene un producto.
     *      \pre Cierto.
     *      \post Devuelve cierto si el inventario contiene un producto con identificador <em>id</em>, falso en caso contrario.
    */
    bool contiene_producto(int id) const;

    /** @brief Consultora de la cantidad poseida de un producto.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Devuelve la cantidad poseida del producto con identificador <em>id</em>.
    */
    int consultar_cantidad_poseida(int id) const;

    /** @brief Consultora de la cantidad requerida de un producto.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Devuelve la cantidad requerida del producto con identificador <em>id</em>.
    */
    int consultar_cantidad_requerida(int id) const;

    // Lectura

    /** @brief Operación de lectura del inventario.
     *      \pre Se encuentra en el canal estandard de entrada un natural <em>N</em> y a continuacion
     *      <em>N/em> lineas con el identificador valido de un producto, un entero no negativo con la cantidad poseida y 
     *      un entero positivo con la cantidad requerida.
     *      \post Se ha leido el inventario del parametro implicito.
    */
    void leer_inventario(const Cjt_productos &productos);

    // Escritura

    /** @brief Operación de escritura de la cantidad de un prodcucto.
     *      \pre El inventario contiene el producto con identificador <em>id</em>.
     *      \post Se ha escrito la cantidad poseida y requerida del producto con identificador <em>id</em>
     *      del inventario en el canal standard de salida.
    */
    void consultar_producto(int id) const;

    /** @brief Operación de escritura del peso y volumen total.
     *      \pre Cierto.
     *      \post Se ha escrito el peso y volumen total del parametro implicito en el canal standard de salida.
    */
    void escribir_atributos_totales() const;

    /** @brief Operación de escritura del inventario.
     *      \pre Cierto.
     *      \post Se ha escrito por cada producto del inventario: su identificador y la cantidad poseida y requerida.
    */
    void escribir_inventario() const;

private:
    /** @brief Calculo de la cantidad de productos que se pueden comerciar.
     *     \pre Cierto.
     *     \post Devuelve la cantidad de productos que se pueden comerciar, si x<y (al primer inventario le faltan unidades) y 
     *     p>q (al segundo inventario le sobran unidades) entonces se comercia el maximo unidades que se pueda (min(y-x, p-q)).
     */
    static int calculo_comercio(int x, int y, int p, int q);
};

#endif