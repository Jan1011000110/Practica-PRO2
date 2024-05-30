/** @file Cuenca.hh  
 *  @brief Especificación de la clase Cuenca.
*/

#ifndef CUENCA_HH
#define CUENCA_HH

#include "Cjt_ciudades.hh"
#include "Barco.hh"

/*
 * Clase Cuenca
 */

/** @class Cuenca
 *  @brief Representa la información y las operaciones de la cuenca fluvial.
*/

class Cuenca
{
private:
    /** @brief Conjunto de productos de la cuenca. */
    Cjt_productos productos;
    /** @brief Conjunto de ciudades de la cuenca. */
    Cjt_ciudades ciudades;
    /** @brief Arbol binario con la estructura de la cuenca. */
    BinTree<string> estructura;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automaticamente al declarar una cuenca.
     *      \pre Cierto.
     *      \post El resultado es una cuenca la cual todos sus atributos estan sin inicializar.
     */     
    Cuenca();

    // Modificadoras

    /** @brief Operación que guarda en un vector la mejor ruta de un viaje.
     *    \pre Cierto.
     *    \post El resultado es un vector que almacena los nombres de las ciudades por las que pasa el barco en un viaje,
     *    la ruta se escoje primero en función de la cantidad de productos que se pueden comerciar y en caso de empate
     *    se escoje la ruta que pase por menos ciudades y en caso de empate la ruta que viene río arriba a mano derecha.
     */
    void calcular_viaje(const BinTree<string> &raiz, Barco &barco, vector<string> &ruta) const;

    /** @brief Operación que realiza un viaje de comercio con el barco.
     *    \pre Cierto.
     *    \post El barco ha comerciado con las ciudades que pasan por la ruta optima del viaje, se ha agregado
     *    al vector de viajes de barco el identificador de la última ciudad en la que se ha comerciado y se ha escrito
     *    por el canal estándard de salida el numero de productos que ha comprado y vendido el barco en la ruta optima.
     */
    void hacer_viaje(Barco &barco);

    /** @brief Operación de redistribución de productos entre ciudades.
     *      \pre Cierto.
     *      \post Se han redistribuido los productos entre las ciudades de la cuenca. La ciudad de la desembocadura comercia con su
     *      ciudad río arriba a mano derecha y luego con la ciudad río arriba a mano izquierda, y así sucesivamente.
     */
    void redistribuir();

    /** @brief Operación de redistribución de productos entre ciudades.
     *      \pre Cierto.
     *      \post Se han redistribuido los productos entre las ciudades de la cuenca. La ciudad de la desembocadura comercia con su
     *      ciudad río arriba a mano derecha y luego con la ciudad río arriba a mano izquierda, y así sucesivamente.
     */
    void redistribuir(const BinTree<string> &raiz);

    /** @brief Operación de comercio entre dos ciudades.
     *      \pre Cierto.
     *      \post Si algun identificador <em>ciudad_id1</em> o <em>ciudad_id2</em> no es valido o son el mismo se ha escrito un mensaje de 
     *      error por el canal estándard de salida, en caso contrario una ciudad le ha dado a la otra todos los productos que le sobren hasta 
     *      alcanzar si es posible los que la otra necesite, y viceversa.
     */
    void comerciar(const string &ciudad_id1, const string &ciudad_id2);

    /** @brief Modificadora de los atributos del barco.
     *      \pre Cierto.
     *      \post Si algun identificador <em>id_compra</em> o <em>id_venta</em> no es valido o son el mismo se ha escrito un mensaje de error
     *      por el canal estándard de salida, en caso contrario se ha modificado los atributos del barco con el valor de los parametros.
     */ 
    void modificar_barco(int id_compra, int num_compra, int id_venta, int num_venta, Barco &barco);

    /** @brief Añade un producto a una ciudad.
     *      \pre Cierto.
     *      \post Si algun identificador <em>ciudad_id</em> o <em>prod_id</em> no es valido o la ciudad <em>ciudad_id</em> no contiene el producto
     *      <em>prod_id</em> se ha escrito un mensaje de error por el canal estándard de salida, en caso contrario se ha añadido el producto con 
     *      identificador <em>prod_id</em> a la ciudad con identificador <em>ciudad_id</em>.
    */
    void poner_producto(const string &ciudad_id, int prod_id, int cantidad_disponible, int cantidad_requerida);

    /** @brief Modificadora de la cantidad poseida de un producto en una ciudad..
     *      \pre Cierto.
     *      \post Si algun identificador <em>ciudad_id</em> o <em>prod_id</em> no es valido o la ciudad <em>ciudad_id</em> no contiene el producto
     *      <em>prod_id</em> se ha escrito un mensaje de error por el canal estándard de salida, en caso contrario se ha modificado las cantidad poseida 
     *      y requerida del producto con identificador <em>prod_id</em> de la ciudad con identificador <em>ciudad_id</em> con las cantidades indicadas.
    */
    void modificar_producto(const string &ciudad_id, int prod_id, int cantidad_disponible, int cantidad_requerida);

    /** @brief Quita un producto del inventario de una ciudad.
     *      \pre Cierto.
     *      \post Si algun identificador <em>ciudad_id</em> o <em>prod_id</em> no es valido o la ciudad <em>ciudad_id</em> no contiene el producto
     *      <em>prod_id</em> se ha escrito un mensaje de error por el canal estándard de salida, en caso contrario se ha eliminado el producto con 
     *      identificador <em>prod_id</em> de la ciudad con identificador <em>ciudad_id</em>.
    */
    void quitar_producto(const string &ciudad_id, int prod_id);

    // Consultoras

    /** @brief Consultora del numero total de productos.
     *      \pre Cierto.
     *      \post Devuelve el numero total de productos.
    */
    void numero_productos() const;

    // Lectura

    /** @brief Operacion de lectura de un conjuto de productos.
     *      \pre Está disponible en el canal de entrada un entero <em>N</em> positivo 
     *      y a continuación <em>N</em> lineas con los atributos de cada producto.
     *      \post Se han agregado <em>N</em> productos nuevos al conjunto de productos.
    */
    void leer_productos(int n);

    /** @brief Operación de lectura del inventario de una ciudad.
     *      \pre Se encuentra en el canal estandard de entrada un natural <em>N</em> y a continuacion
     *      <em>N/em> lineas con el identificador valido de un producto, un entero no negativo con la cantidad poseida y 
     *      un entero positivo con la cantidad requerida.
     *      \post Si el identificador <em>ciudad_id</em> no es valido se ha escrito un mensaje de error por el canal estándard de salida y se ha leido
     *      los datos de un inventario que no usamos, en caso contrario se ha leido el inventario de la ciudad con identificador <em>ciudad_id</em>.
    */
    void leer_inventario(const string &ciudad_id);

    /** @brief Operación de lectura de varios inventarios.
     *      \pre Se encuentra en el canal estandard de entrada un nombre positivo <em>N</em> y a continuacion los datos de <em>N</em> inventarios.
     *      \post Se han leido los datos de <em>N</em> inventarios.
     */
    void leer_inventarios();

    /** @brief Operación de lectura de la cuenca.
     *      \pre Se encuentra en el canal estándard de entrada la estructura de la cuenca.
     *      \post Se han vaciado los ciudades de la cuenca y se ha leido la estructura de la cuenca.
     */
    void leer_rio();

    /** @brief Operación de lectura de la estructura de la cuenca.
     *      \pre Se encuentra en el canal estándard de entrada la estructura de la cuenca.
     *      \post Se ha leido la estructura de la cuenca.
     */
    BinTree<string> construir_estructura();

    // Escritura

    /** @brief Operación de escritura de un producto.
     *      \pre Cierto.
     *      \post Si el identificador <em>prod_id</em> no es valido se ha escrito un mensaje de error por el canal estándard de salida, 
     *      en caso contrario se ha escrito los atributos del producto con identificador <em>prod_id</em> en el canal estándard de salida.
     */
    void escribir_producto(int prod_id) const;

    /** @brief Operación de escritura de una ciudad.
     *      \pre Cierto.
     *      \post Si el identificador <em>ciudad_id</em> no es valido se ha escrito un mensaje de error por el canal estándard de salida, 
     *      en caso contrario se ha escrito el inventario y el peso y volumen total de la ciudad con identificador <em>ciudad_id</em>.
     */
    void escribir_ciudad(const string &ciudad_id) const;

    /** @brief Operación de escritura de un producto en una ciudad.
     *      \pre Cierto.
     *      \post Si algun identificador <em>ciudad_id</em> o <em>prod_id</em> no es valido o la ciudad <em>ciudad_id</em> no contiene el producto
     *      <em>prod_id</em> se ha escrito un mensaje de error por el canal estándard de salida, en caso contrario se ha escrito la cantidad 
     *      disponible y requerida del producto <em>prod_id</em> en la ciudad <em>ciudad_id</em>.
     */
    void consultar_producto_ciudad(const string &ciudad_id, int prod_id) const;
};

#endif