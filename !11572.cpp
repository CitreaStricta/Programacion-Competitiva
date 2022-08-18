// Juez: Online Judge
// Compilador C++11
// Online Judge ID: 1134306 (User: Chulz)



#include <bits/stdc++.h>

using namespace std;

/**
 * 1ero probe solucionar el problema guardando los tamanios de los copos de nieve en un vector.
 * Pero mostro demorarse mucho [O(n^2) si mal no recuerdo].
 * El problema estaba en la busqueda en el mismo arreglo que demoraba O(n).
 * Cambie la estructura a un map, siendo el tamanio de los copos de nieve la "key"
 * y el "value" su indice (pensando en el map como si fuera un vector).
 * map::find() toma O(logn) time.
 * Por lo que el algoritmo para 'n' elementos tomaria O(n*logn).
*/

int main()
{
    int f;
    cin >> f;
    map<int, int> v;
    map<int, int>::iterator itm;
    int minIndiceAct;
    int resp;
    int key;
    int n;
    int i;
    
    while(f--)
    {
        v.clear();
        minIndiceAct = 0;
        resp = 0;
        cin >> n;
    
        for (i = 0; i < n; i++) // O(n)
        {
            cin >> key;
            itm = v.find(key); // O(n*logn) aqui se encontraba el mayor problema de este ejercicio
            // esta la "key" ya agregada al map?
            if(itm == v.end())
            {   // si NO lo encuentra
                // metelo al map
                v.insert(make_pair(key, i));
            }
            else
            {   // si SI lo encuentra
                // revisa si el elemento encontrado esta por delante, por detras o si esta en
                // el mismo lugar del elemento que se sabe no tiene elementos repetidos delante de el
                // (Si el "value" del iterador "itm" es mayor al minimo indice actual sin "key"s repetidas delanta de el)
                if((*itm).second >= minIndiceAct)
                {   // calculo la deferencia de distancia entre el ultimo elemento
                    // y el elemento con "key" repetida encontrada
                    // (el indice del ultimo elemento [INGRESADO AL MAP] es igual a (i-1))
                    if(resp < i - minIndiceAct)
                    {
                        resp = i - minIndiceAct;
                    }
                    // actualizo el minimo indice actual sin "key"s repetidas delanta de el
                    minIndiceAct = (*itm).second + 1;
                }
                // actualizo el "value" de la "key"
                (*itm).second = i;
            }
        }
        // esto es para el caso de que la cadena mas grande de elementos no repetidos
        // haya sido la que se creaba al final de todo el proceso de insercion en el map
        if(resp < (i - minIndiceAct))
            resp = (i - minIndiceAct);
        cout << resp << endl;
    }

    return 0;
}