/** @mainpage Comercio fluvial.
 * 
*/

/** @file program.cc
 		@brief Programa principal para la práctica de PRO2.
		
		Como bien da a entender el enunciado, se supone que los datos leídos siempre son correctos, de modo que no se incluyen comprobaciones al respecto.
*/

#include "Cuenca.hh"

/** @brief Programa principal para la práctica de PRO2: <em>Comercio fluvial</em>.*/

int main() 
{
    Cuenca c;
    c.leer_productos();
    c.leer_rio();
    
    string cm;
    cin >> cm;
    while (cm != "fin")
    {
        if (cm == "leer_rio" or cm == "lr") {
            c.leer_rio();
        }
        else if (cm == "leer_inventario" or cm == "li") {
            
        }
        else if (cm == "leer_inventarios" or cm == "ls") {

        }

        cin >> cm;
    }
}

