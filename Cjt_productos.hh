/** @file Cjt_productos.hh
 *  @brief Especificación de la clase Cjt_productos.
*/

#ifndef CJT_PRODUCTOS_HH
#define CJT_PRODUCTOS_HH

#ifndef NO_DIAGRAM
#include <vector>
#endif

#include "Producto.hh"

/*
 * Clase Cjt_productos
 */

/** @class Cjt_productos
 *      @brief Representa un conjunto de productos de la cuenca fluvial.
*/

class Cjt_productos 
{
private:
    /** @brief Vector que almacena los productos. */
    vector<Producto> productos;   
    /** @brief Numero de productos totales. */
    int numero_de_productos;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automáticamente al declarar un conjunto de productos.
     *      \pre Cierto.
     *      \post El resultado es un conjunto de productos vacio.
    */
    Cjt_productos();

    // Consultoras

    /** @brief Consultora del numero total de productos.
     *      \pre Cierto.
     *      \post Devuelve el numero total de productos.
    */
    int numero_productos() const;

    /** @brief Consultora de la existencia de un producto.
     *      \pre Cierto.
     *      \post Devuelve cierto si existe un producto con identificador <em>id</em>, falso en caso contrario.
    */
    bool existe_producto(int id) const;

    /** @brief Consultora de un producto.
     *      \pre Existe un productao con identificador <em>id</em>.
     *      \post Devuelve el producto con identificador <em>id</em>.
    */
    Producto consultar_producto(int id) const;

    // Lectura

private:
    /** @brief Operacion de lectura de un producto.
     *      \pre Está disponible en el canal de entrada los atributos de un producto.
     *      \post Se ha leido y devuelto un producto nuevo.
     */
    static Producto leer_producto();


public:
    /** @brief Operacion de lectura de conjuto de productos.
     *      \pre Está disponible en el canal de entrada un entero <em>N</em> positivo 
     *      y a continuación <em>N</em> lineas con los atributos de cada producto.
     *      \post Se han agregado <em>N</em> productos nuevos al vector productos y se ha actualizado el numero de productos totales.
    */
    void leer_productos(int n);

    // Escritura
    
    /** @brief Operacion de escritura de un producto.
     *      \pre Existe un producto con identificador <em>id</em>.
     *      \post Se han escrito los atributos del producto con identificador <em>id</em> en el canal standard de salida.
    */      
    void escribir_producto(int id) const;
};

#endif