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
        cout << "#" << cm;
        if (cm == "leer_rio" or cm == "lr") {
            cout << endl;
            c.leer_rio();
        }
        else if (cm == "leer_inventario" or cm == "li") {
            string ciudad_id;
            cin >> ciudad_id;
            cout << ' ' << ciudad_id << endl;
            c.leer_inventario(ciudad_id);
        }
        else if (cm == "leer_inventarios" or cm == "ls") {
            cout << endl;
            c.leer_inventarios();
        }
        else if (cm == "modificar_barco" or cm == "mb") {
            cout << endl;
            c.modificar_barco();
        }
        else if (cm == "escribir_barco" or cm == "eb") {
            cout << endl;
            c.escribir_barco();
        }
        else if (cm == "consultar_num" or cm == "cn") {
            cout << endl;
            c.numero_productos();
        }
        else if (cm == "agregar_productos" or cm == "ap") {
            cout << endl;
            c.leer_productos();
        }
        else if (cm == "escribir_producto" or cm == "ep") {
            int prod_id;
            cin >> prod_id;
            cout << ' ' << prod_id << endl;
            c.escribir_producto(prod_id);
        }
        else if (cm == "escribir_ciudad" or cm == "ec") {
            string ciudad_id;
            cin >> ciudad_id;
            cout << ' ' << ciudad_id << endl;
            c.escribir_ciudad(ciudad_id);
        }
        else if (cm == "poner_prod" or cm == "pp") {
            string ciudad_id;
            int prod_id, cantidad_disponible, cantidad_requerida;
            cin >> ciudad_id >> prod_id >> cantidad_disponible >> cantidad_requerida;
            cout << ' ' << ciudad_id << ' ' << prod_id << ' '  << cantidad_disponible << ' ' << cantidad_requerida << endl;
            c.poner_producto(ciudad_id, prod_id, cantidad_disponible, cantidad_requerida);
        }
        else if (cm == "modificar_prod" or cm == "mp") {
            string ciudad_id;
            int prod_id, cantidad_disponible, cantidad_requerida;
            cin >> ciudad_id >> prod_id >> cantidad_disponible >> cantidad_requerida;
            cout << ' ' << ciudad_id << ' ' << prod_id << ' ' << cantidad_disponible << ' ' << cantidad_requerida << endl;
            c.modificar_producto(ciudad_id, prod_id, cantidad_disponible, cantidad_requerida);
        }
        else if (cm == "quitar_prod" or cm == "qp") {
            string ciudad_id;
            int prod_id;
            cin >> ciudad_id >> prod_id;
            cout << ' ' << ciudad_id << ' ' << prod_id << endl;
            c.quitar_producto(ciudad_id, prod_id);
        }
        else if (cm == "consultar_prod" or cm == "cp") {
            string ciudad_id;
            int prod_id;
            cin >> ciudad_id >> prod_id;
            cout << ' ' << ciudad_id << ' ' << prod_id << endl;
            c.consultar_producto_ciudad(ciudad_id, prod_id);
        }
        else if (cm == "comerciar" or cm == "co") {
            cout << endl;
        }
        else if (cm == "redistribuir" or cm == "re") {
            cout << endl;
            c.redistribuir();
        }
        else if (cm == "haver_viaje" or cm == "hv") {
            cout << endl;
        }
    
        cin >> cm;
    }

}

