//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)
//Lenguaje: C++11

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) return 0;
        // se inicia el while de cada "bloque"
        while(true)
        {
            stack<int> estacion;
            int orden[n];
        // "revisando" es una variable auxiliar para ver el incide "revisando" del arreglo "orden"
            int revisando = 0;
            for (int i = 0; i < n; i++)
            {// acepto los inputs del "orden de salida a B" hasta tener los n inputs o hasta que el 1ero sea un 0
                cin>>orden[i];
                if(orden[i]==0) break;
            }
            if(orden[0] == 0) // en el caso de que sea 0, se preguntara denuevo por el "largo" (n) del tren
            {
                cout << endl; // para separar los bloques de datos con un espacio
                break;
            }
            /**
             * Resive el tren en su orden de llegada (1, 2, ..., n) desde la linea A y guarda el vagon entrante en la "estacion".
             * Si el vagon que esta en el top() de la "estacion" es por el que se pregunta en "orden[revisando]"
             * entonces mueve el vagon en top() a la linea B. Eso se hace hasta que sea falso o hasta que la "estacion" se vacie
             */ 
            for (int i = 0; i < n; i++)
            {
                estacion.push(i+1);
                while(!estacion.empty())
                {
                    if(estacion.top() == orden[revisando]){
                        estacion.pop();
                        revisando++;
                        continue;
                    }
                    break;
                }
            }
            // si la "estacion" esta vacia, significa que no hubo problema con el reordenamiento de los vagones y se devuelve "Yes"
            if(estacion.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}