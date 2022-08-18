//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)
//Lenguaje: C++11

/*
 * Termone buscando el ejercicio en internet.
 * Pero, en mi defensa, fue por una pura lesera.
 * No entendia como era que el programa tenia que finalizarse.
 * Resulto ser que no tenia que finalizarce y tenia que seguir preguntando
 * indefinidamente.
 * 
 * De cualquier forma, deje bien comentado el codigo.
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    // ascepto inputs de forma indefinida
    while(cin >> n) // me "trago" el 1er input "basura"
    {
        n--; // lo disminuyo en 1 para crear el arreglo de n-1 diferencias
        int arr[n];

        int resp = 1; // inicializo la flag que usare para definir si es "Jully" o no
        int aux, aux2;
        int naux = n;

        cin >> aux; // el 1er input a comparar lo guardo afuera del "while" para compararlo enseguida con el siguiente
        while(naux--)
        {
            cin >> aux2;
            arr[naux] = abs(aux-aux2); // guardo las diferencias en el arreglo
            aux = aux2; // y guardo aux2 en aux para calcular la diferencia con el siguiente input
        }

        // sorteo el arreglo para facilitar la comparacion y comprobacion de que los
        // numeros del 1 al n-1 estan precentes. Si no, "Not jully".
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if(arr[i] != i+1){
                cout << "Not jolly" << endl;
                resp = 0;
                break;
            }
        }
        if(resp)
            cout << "Jolly" << endl;
    }
}
