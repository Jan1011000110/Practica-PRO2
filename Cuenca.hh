/** @file Cuenca.hh  
 *      @brief Especificación de la clase Cuenca.
*/

#ifndef CUENCA_HH
#define CUENCA_HH

#include "Cjt_productos.hh"
#include "Cjt_ciudades.hh"
#include "Barco.hh"
#include "BinTree.hh"

/** @class Cuenca
 *      @brief Representa la cuenca fluvial.
*/


class Cuenca
{
private:
    Cjt_productos productos;
    Cjt_ciudades ciudades;
    Barco barco;
    BinTree<string> estructura;
public:
    // Constructoras

    /** @brief Creadora por defecto.
     *      Se ejecuta automaticamente al declarar una cuenca.
     *      \pre <em>Cierto.</em>
     *      \post El resultado es una cuenca la cual todos sus atributos estan sin inicializar.
     */     

    Cuenca();

    // Modificadoras

    void hacer_viaje();

    void redistribuir();

    void redistribuir(const BinTree<string> &raiz);

    void comerciar(const string &ciudad_id1, const string &ciudad_id2);

    void modificar_barco();

    void poner_producto(const string &ciudad_id, int prod_id, int cantidad_disponible, int cantidad_requerida);

    void modificar_producto(const string &ciudad_id, int prod_id, int cantidad_disponible, int cantidad_requerida);

    void quitar_producto(const string &ciudad_id, int prod_id);

    // Consultoras

    void numero_productos() const;

    // Lectura

    void leer_productos(int n);

    void leer_inventario(const string &ciudad_id);

    void leer_inventarios();

    void leer_rio();

    BinTree<string> construir_estructura();

    // Escritura

    void escribir_barco() const;

    void escribir_producto(int prod_id) const;

    void escribir_ciudad(const string &ciudad_id);

    void consultar_producto_ciudad(const string &ciudad_id, int prod_id);
};

#endif