//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)
//Lenguaje: C++11

#include <iostream>
#include <queue>

using namespace std;

struct ferry
{
    bool lado = true; // true = izquierda, false = derecha
    int capacidad;
    int carga = 0;
    int viajes = 0;
};

/**
 * La funcion "procedimiento" resive una direccion de memoria "ferry" y una direccion de memoria de una de las dos queue llamada "lado".
 * La funcion "llena" el ferry con los elementos de "lado" y se asegura de que este (el ferry) no sobrepase su carga maxima.
 * Si el ferry fuera a sobrepasar su carga maxima, no lo hace.
 * Cuando el "ferry" esta lleno la funcion "envia" al ferry al otro lado del rio, aumenta la variable "viajes" de "ferry" en 1 y vacia su carga.
 * Si la queue "lado" fuera a estar vacia, entonces manda al "ferry" devuelta y aumenta la variable "viajes" de "ferry" en 1.
*/
void procedimiento(ferry &ferry, queue<int> &lado)
{
    if(!lado.empty())
    {
        while(true)
        {
            if(!lado.empty())
            {
                int suma;
                suma = ferry.carga + lado.front();
                if(suma <= ferry.capacidad)
                {
                    ferry.carga = suma;
                    lado.pop();
                    continue;
                }
            }
            ferry.lado = !ferry.lado;
            ferry.viajes++;
            ferry.carga = 0;
            break;
        }
    }
    else
    {
        ferry.lado = !ferry.lado;
        ferry.viajes++;
    }
}

int main()
{
    int c;
    cin >> c;
    while(c--)
    {
        queue<int> left;
        queue<int> right;
        int l, m;
        cin >> l >> m;
        ferry ferry; // una estructura llamada "ferry" que "lleva la cuenta" de lo que esta pasando con la
        //cantidad de viajes totales y se encarga de saber en que lado el ferry se encuentra
        ferry.capacidad = l*100;

        for (int i = 0; i < m; i++)
        { // lectura de inputs. Tambien se encarga de llenar las colas de autos en cada lado del rio (llenar las queue)
            string lado;
            int largoA;
            cin >> largoA >> lado;
            if(lado == "left") left.push(largoA);
            else right.push(largoA);
        }
        
        // hasta que ambos lados no esten vacios el ferry se sigue moviendo
        while (!left.empty() || !right.empty())
        {
            if(ferry.lado) // "si esta a la izquierda"
            {
               procedimiento(ferry, left);
            }
            else // "si esta a la derecha"
            {
                procedimiento(ferry, right);
            }
        }
        cout << ferry.viajes << endl;
    }
}