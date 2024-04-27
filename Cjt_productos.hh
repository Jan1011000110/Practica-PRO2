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
    int numero_productos;
public:
    
};

#endif