/** @file Cjt_productos.hh
 *      @brief Especificación de la clase Cjt_productos.
*/

#ifndef CJT_PRODUCTOS_HH
#define CJT_PRODUCTOS_HH

#ifndef NO_DIAGRAM
#include <vector>
#endif

#include "Producto.hh"

/** @class Cjt_productos
 *      @brief Facilita la gestion de operaciones de un conjunto de productos.
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

    /** @brief Devuelve el numero total de productos.
     *      \pre Cierto.
     *      \post Devuelve el numero total de productos.
    */
    int numero_productos() const;

    /** @brief Comprueba si existe un producto con identificador <em>id</em>.
     *      \pre Cierto.
     *      \post Devuelve cierto si existe un producto con identificador <em>id</em>, falso en caso contrario.
    */
    bool existe_producto(int id) const;

    /** @brief Devuelve el producto con identificador <em>id</em>.
     *      \pre Existe un producto con identificador <em>id</em>.
     *      \post Devuelve el producto con identificador <em>id</em>.
    */
    Producto consultar_producto(int id) const;

    // Lectura

    /** @brief Lee un conjunto de productos nuevos.
     *      \pre <em>Está disponible en el canal de entrada un entero <em>n</em> positivo 
     *      y a continuación <em>n</em> lineas con los atributos de cada producto.</em>
     *      \post Se han agregado <em>n</em> productos nuevos al vector productos y se ha actualizado el numero de productos totales.
    */
    void leer_productos(int n);

    // Escritura
    
    /** @brief Escribe el producto con identificador <em>id</em>.
     *      \pre Existe un producto con identificador <em>id</em>.
     *      \post Se han escrito los atributos del producto con identificador <em>id</em> en el canal standard de salida.
    */      
    void escribir_producto(int id) const;
};

#endif