//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)
//Lenguaje: C++11

#include <iostream>
#include <stack>

using namespace std;

int main(){
    int hola = 0;
    while(true)
    {
        hola++;
        stack<int> stk[27];
        int stacks = 0;
        string caso;
        cin >> caso;
        if(caso == "end") break;
        for (int i = 0; i < caso.size(); i++)
        {
            int letra = caso[i] - 65;
            int aux = 0;
            // "esta el stack vacio?"
            while(!stk[aux].empty())
            {// "NO! Peor, es la carga que voy a poner 'mayor' a la que esta mas arriba del stack"
                if(letra > stk[aux].top())
                {//"si... Por lo tanto, hagamos el mismo proceso pero con el siguiente stack"
                    aux++;
                    continue;
                }
            // "NO! Entonces terminemos de revisar cada stack y coloquemos la carga en este stack"
                break;
            }
            // "SI! Enotces coloquemos la carga en este stack"
            stk[aux].push(letra);
        }
        // "Cuantos stacks estamos usando?"
        for (int i = 0; !stk[i].empty(); i++)
        {
            stacks++;
        }
        cout << "Case " << hola << ": " << stacks << endl;
    }
}


/**
 * Our pure Code has ascended.
 * Beyond lies only the refuse and regret of its creation.
 * We shall enter that place no longer.
 */

// int main()
// {
//     int hola;
//     while (true)
//     {
//         hola++;
//         int stacks = 0;
//         algo stk[26];
//         string caso;
//         cin >> caso;
//         if(caso == "end") break;
//
//         //inicialicacion de los arreglos "cantidad" de cada algo
//         for (int i = 0; i < 26; i++) 
//             for (int j = 0; j < 26; j++)
//             {
//                 stk[i].cantidad[j] = 0;
//             }
//
//     
//         for (int i = 0; i < caso.size(); i++)
//         {
//             int letra = caso[i] - 65;
//             stk[0].stack.push(caso[i] - 65);
//             stk[0].cantidad[letra]++;
//         }
//         stk[0].flagUso = 1;
//
//         // esta "for" es para las letras
//         for (int i = 0; i < 26; i++)
//         {// este "for" es para moverme a lo largo de los 26 stacks
//             for (int j = 0; j < 26; j++)
//             {// "Mientras que en el stack j aun haya letras i:"
//                 while(stk[j].cantidad[i])
//                 {// "si el top del stack va en el barco i, entonces:"
//                     if(stk[j].stack.top() == i)
//                     {
//                         stk[j].stack.pop();
//                         stk[j].cantidad[i]--;
//                         continue;
//                     }
//                 // "si no, entonces pon el 1er elemento en el siguiente stack."
//                 // "PERO SOLO si el que estoy por colocar en el stack tiene un i mas pequenio que el que ya esta en el stack"
//                 // "si no anterior no se da, entonces revisar desde el 1er stack hasta que se de la condicion"
//                     int aux = 0;
//
//                     while(!stk[aux].stack.empty())
//                     {
//                         if(aux != j && stk[aux].stack.top() >= stk[j].stack.top()){
//                             break;
//                         }
//                         aux++;
//                     }
//
//                     if (!stk[aux].flagUso)
//                         stk[aux].flagUso = true;
//
//                     stk[aux].stack.push(stk[j].stack.top());
//                     stk[aux].cantidad[stk[j].stack.top()]++;
//                     stk[j].cantidad[stk[j].stack.top()]--;
//                     stk[j].stack.pop();
//                 }
//             }
//         }
//
//         for (int i = 0; i < 26; i++)
//         {
//             if (stk[i].flagUso)
//             {
//                 stacks++;
//             }
//         }
//         cout << "Case " << hola << ": " << stacks << endl;
//     }
// }