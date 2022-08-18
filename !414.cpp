//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)
//Lenguaje: C++11

#include <iostream>

using namespace std;

int main()
{
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) break;
        int x[n]; // cantidad de 'X' en cada linea

        for (int i = 0; i < n; i++)
        {// inicializacion de cada valor del arreglo x
            x[i] = 0;
        }

        string linea[n];
        cin.ignore(); // para evitar el 1er '\n' al aceptar el numero 'n'

        for (int i = 0; i < n; i++)
        { // aceptacion de cada linea de caracteres
            getline(cin, linea[i], '\n');
        }

        /**
         * Que hace el resto del codigo:
         * Cuenta cuantas 'X' hay en cada linea y guarda el numero en el arreglo x.
         * Luego, busco el arreglo con la mayor cantidad de 'X' en el.
        */

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < 25; i++)
            {
                if(linea[j].at(i) == 'X') x[j]++;
            }
        }

        int mayor = x[0];
        for (int i = 1; i < n; i++)
        {
            if(mayor < x[i]) mayor = x[i];
        }
        
        /**
         * ahora, como la linea con la mayor cantidad de 'X' definira la cantidad de espacios
         * restantes en cada otra linea entonces calculo la cantidad de espacios restantes
         * en cada linea como "la diferencia entre la linea con mas 'X' y todas las lineas"
        */
        int suma = 0;
        for (int i = 0; i < n; i++)
        {
            suma = suma + (mayor - x[i]);
        }
        cout << suma << endl;
    }
}