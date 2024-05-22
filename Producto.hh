/** @file Producto.hh  
 *      @brief Especificación de la clase Producto.
*/

#ifndef PRODUCTO_HH
#define PRODUCTO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @class
 *      @brief Representa un producto.
*/


class Producto 
{
private:    
    /** @brief Peso del producto.*/
    int peso;
    /** @brief Volumen del producto.*/
    int volumen;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automáticamente al declarar un producto.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es un producto el cual todos sus atributos no estan inicializados.
    */

    Producto();

    /** @brief Creadora con valores concretos.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es un producto con peso = peso y volumen = volumen.
    */

    Producto(int peso, int volumen);

    // Consultoras

    /** @brief Devuelve el peso del parametro implicito.
     *      \pre <em>Cierto.</em>
     *      \post Devuelve el peso del parametro implicito.
    */

    int consultar_peso() const;

    /** @brief Devuelve el volumen del parametro implicito.
     *      \pre <em>Cierto.</em>
     *      \post Devuelve el volumen del parametro implicito.
    */

    int consultar_volumen() const;

    // Escritura

    /** @brief Operación de escritura.
     *      \pre <em>Cierto.</em>
     *      \post Se han escrito los atributos del parámetro implicito en el canal standard de salida.
    */
    void escribir_producto() const;

    // Lectura

    /** @brief Operación de lectura del producto.
     *      \pre <em>Està disponible en el canal estandard de entrada dos naturales, los atributos del parametro implicito.</em>
     *      \post El paramentro implicito ahora tiene los atributos con los valores leidos.
    */      

    void leer_producto();

};

#endif

