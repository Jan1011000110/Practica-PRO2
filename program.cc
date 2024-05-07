/** @mainpage Comercio fluvial.
 * 
*/

/** @file program.cc
 		@brief Programa principal para la práctica de PRO2.
		
		Como bien da a entender el enunciado, se supone que los datos leídos siempre son correctos, de modo que no se incluyen comprobaciones al respecto.
*/

#include "Cuenca.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @brief Programa principal para la práctica de PRO2: <em>Comercio fluvial</em>.*/

int main() 
{
    Cuenca c;
    c.leer_productos();
    c.leer_rio();
    c.modificar_barco();

    string cm;
    cin >> cm;
    while (cm != "fin")
    {
        cout << "NAHSE = " << cm << endl;
        if (cm == "leer_rio" or cm == "lr") {
            c.leer_rio();
        }
        else if (cm == "leer_inventario" or cm == "li") {
            string ciudad_id;
            cin >> ciudad_id;
            c.leer_inventario(ciudad_id);
        }
        else if (cm == "leer_inventarios" or cm == "ls") {
            c.leer_inventarios();
        }
        else if (cm == "modificar_barco" or cm == "mb") {
            c.modificar_barco();
        }
        else if (cm == "escribir_barco" or cm == "eb") {
            c.escribir_barco();
        }
        else if (cm == "consultar_num" or cm == "cn") {
            c.numero_productos();
        }
        else if (cm == "agregar_productos" or cm == "ap") {
            c.leer_productos();
        }
        else if (cm == "escribir_producto" or cm == "ep") {
            int prod_id;
            cin >> prod_id;
            c.escribir_producto(prod_id);
        }
        else if (cm == "escribir_ciudad" or cm == "ec") {
            string ciudad_id;
            cin >> ciudad_id;
            c.escribir_ciudad(ciudad_id);
        }
        else if (cm == "poner_prod" or cm == "pp") {
            string ciudad_id;
            int prod_id, disponible, requerido;
            cin >> ciudad_id >> prod_id >> disponible >> requerido;
            c.poner_producto(ciudad_id, prod_id, disponible, requerido);
        }
    
        cin >> cm;
    }

}

