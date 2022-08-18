// Juez: Online Judge
// Compilador C++11
// Online Judge ID: 1134306 (User: Chulz)

#include <bits/stdc++.h>

using namespace std;

/**
 * sin utilizar una cola de prioridad, probablemente el tiempo
 * maximo de ejecucion se hubiera sobrepasado
*/

int main()
{
    priority_queue<int> gArmy;
    priority_queue<int> bArmy;
    stack<int> gwr;
    stack<int> bwr;
    int bf, ng, nb;
    int gSoldier;
    int bSoldier;
    int f;
    cin >> f;

    while(f--)
    {
        cin >> bf >> ng >> nb;

        // preparo el ejercito verde
        for (int i = 0; i < ng; i++)
        {
            cin >> gSoldier;
            gArmy.push(gSoldier);
        }

        // preparo el ejercito azul
        for (int i = 0; i < nb; i++)
        {
            cin >> bSoldier;
            bArmy.push(bSoldier);
        }
        // mientras que ninguno de los 2 ejercitos sea igual a 0
        // las battallas continuaran
        while(!gArmy.empty() && !bArmy.empty())
        {   // inicio las batallas
            for(int i = 0; i < bf && i < ng && i < nb; i++)
            {   // preparo a los soldados de cada ejercito
                gSoldier = gArmy.top();
                gArmy.pop();
                bSoldier = bArmy.top();
                bArmy.pop();

                //si ambos tienen la misma fuerza
                if(gSoldier == bSoldier) continue;

                // si el soldado verde es mas fuerte que el azul
                if(gSoldier > bSoldier)
                {   // el soldado verde va a su sala de espera respectiva
                    // y el soldado azul desaparece
                    gSoldier -= bSoldier;
                    gwr.push(gSoldier);
                }
                // si el soldado azul es mas fuerte que el verde
                else
                {   // lo mismo que si el "if" ocurriera pero a favor del azul
                    bSoldier -= gSoldier;
                    bwr.push(bSoldier);
                }
            }
            // devuelvo a los soldados que estan en sus salas de espera respectuvas
            // a sus ejercitos respectivos
            while (!gwr.empty())
            {
                gArmy.push(gwr.top());
                gwr.pop();
            }

            while (!bwr.empty())
            {
                bArmy.push(bwr.top());
                bwr.pop();
            }

            // al finalizar cada tanda de batallas
            // actualizo la cantidad de soldados que cada ejercito tiene
            ng = gArmy.size();
            nb = bArmy.size();
        }
        
        // printea los resultados
        if(gArmy.empty() && bArmy.empty())
        {
            cout << "green and blue died" << endl;
            if(f) cout << endl;
            continue;
        }

        if(gArmy.empty())
        {
            cout << "blue wins" << endl;
            while(!bArmy.empty())
            {
                cout << bArmy.top() << endl;
                bArmy.pop();
            }
        }
        else
        {
            cout << "green wins" << endl;
            while(!gArmy.empty())
            {
                cout << gArmy.top() << endl;
                gArmy.pop();
            }
        }

        if(f) cout << endl;
    }

    return 0;
}