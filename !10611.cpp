//Juez: Online Judge
//Compilador C++11
//Online Judge ID: 1134306 (User: Chulz)

#include <bits/stdc++.h>

using namespace std;

// var globales
int n;
int q;

/**
 * Binary_search_Shorter_Taller:
 * se le entrega el array en donde buscar y un entero.
 * devuelve un "pair"
 *  pair.first: El entero mas grande que, a su ves, es mas chico que r
 * pair.second: El entero mas chico que, a su ves, es mas grande que r
*/
pair<int, int> binSearchST(int *arr, int r)
{
    int left = 0;
    int right = n;
    int mid;
    int baja = arr[0];
    int alta = arr[n-1];

    // busqueda del mas grande que, a su ves, es mas chico que r
    while(right - left > 1)
    {
        mid = floor((right + left) / 2);
        if(arr[mid] < r)
        {
            if(baja < arr[mid])
                baja = arr[mid];
            left = mid;
        }
        else
        {
            if(alta >= arr[mid])
                alta = arr[mid];
            right = mid;
        }
    }

    /**
     * Si llega a ocurrir que la busqueda anterior encontro que el mas grande era
     * del mismo tamanio que r entonces aun existe la posibilidad de que haya uno
     * mas chico que, a su ves, es mas grande que r.
     * el while loop de abajo es casi igual que el de arriba pero con unas pocas
     * diferencias
    */
    if(alta == r)
    {
        right = n;
        alta = arr[n-1];
        while(right - left > 1)
        {
            mid = floor((right + left) / 2);
            if(arr[mid] <= r) // la diferencia es que ahora este "if" es <= en ves de solo <
            {
                // y como el menor ya fue encontrado con el while de arriba
                // entonces no se debe sobre escribir el entero "baja"
                left = mid;
            }
            else
            {
                if(alta > arr[mid])
                    alta = arr[mid];
                right = mid;
            }
        }
    }

    // genero el pair de ints para devolverlos
    pair<int, int> aux;
    aux.first = baja;
    aux.second = alta;
    return aux;
}

int main()
{
    // acepto inputs de los tamanos de las chimps
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    // acepto inputs de los tamanos del playboy
    cin >> q;
    int que[q];
    for (int i = 0; i < q; i++)
    {
        cin >> que[i];
    }
    
    pair<int, int> par;

    // for loop que continuara hasta que los q pares sean encontrados e impresos
    for (int i = 0; i < q; i++)
    {
        par = binSearchST(h, que[i]);

        if(par.first != que[i]) cout << par.first;
        else cout << "X";
        cout << " ";

        if(par.second != que[i]) cout << par.second;
        else cout << "X";
        cout << endl;
    }
}