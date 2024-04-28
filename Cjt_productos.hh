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
    /** @brief Vector que almacena los productos*/
    vector<Producto> productos;   
    /** @brief Numero de productos totales*/
    int numero_de_productos;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automáticamente al declarar un conjunto de productos.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es un conjunto de productos el cual todos sus atributos no estan inicializados.
    */
    Cjt_productos();

    // Consultoras

    /** @brief Devuelve el numero total de productos
     *      \pre <em>Cierto.</em>
     *      \post Devuelve el numero total de productos
    */

    int numero_productos() const;

    /** @brief Comprueba si existe un producto con identificador id
     *      \pre <em>Cierto.</em>
     *      \post Devuelve cierto si existe un producto con identificador id, falso en caso contrario
    */

    bool existe_producto(int id) const;

    // Escritura
    
    /** @brief Escribe el producto con identificador id
     *      \pre <em>Existe un producto con identificador id.</em>
     *      \post Se ha escrito el producto con identificador id en el canal standard de salida.
    */      

    void escribir_producto(int id) const;

    // Lectura

    /** @brief Lee un conjunto de productos nuevos
     *      \pre <em>Está disponible en el canal de entrada un entero n positivo 
     *      y a continuación los parametros de n productos nuevos.</em>
     *      \post Se han agregado n productos nuevos al vector productos y se ha actualizado el numero de productos totales
    */

    void leer_productos();
};

#endif