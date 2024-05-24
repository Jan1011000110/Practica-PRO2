/** @file Producto.hh  
 *      @brief Especificación de la clase Producto.
*/

#ifndef PRODUCTO_HH
#define PRODUCTO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @class Producto.
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
     *      \pre Cierto.
     *      \post El resultado es un producto el cual todos sus atributos no estan inicializados.
    */
    Producto();

    /** @brief Creadora con valores concretos.
     *      \pre Cierto.
     *      \post El resultado es un producto con peso = peso y volumen = volumen.
    */  
    Producto(int peso, int volumen);

    // Consultoras

    /** @brief Devuelve el peso del parametro implicito.
     *      \pre Cierto.
     *      \post Devuelve el peso del parametro implicito.
    */
    int consultar_peso() const;

    /** @brief Devuelve el volumen del parametro implicito.
     *      \pre Cierto.
     *      \post Devuelve el volumen del parametro implicito.
    */
    int consultar_volumen() const;

    // Escritura

    /** @brief Operación de escritura.
     *      \pre Cierto.
     *      \post Se han escrito los atributos del parámetro implicito en el canal standard de salida.
    */
    void escribir_producto() const;

    // Lectura

    /** @brief Operación de lectura del producto.
     *      \pre Està disponible en el canal estandard de entrada dos naturales, los atributos del parametro implicito.
     *      \post El paramentro implicito ahora tiene los atributos con los valores leidos.
    */      
    void leer_producto();

};

#endif

