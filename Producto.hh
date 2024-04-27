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
 *      
 *      Dispone de ciertos atributos que definen al producto.
*/


class Producto 
{
private:    
    int peso;
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

    // Escritura

    /** @brief Operacion de escritura.
     *      \pre <em>Cierto.</em>
     *      \post Se han escrito los atributos del parámetro implicito en el canal standard de salida.
    */
    void escribir() const;

};

#endif

