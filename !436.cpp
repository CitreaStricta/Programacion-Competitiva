//Juez: Online Judge
//Compilador C++11
//Online Judge ID: 1134306 (User: Chulz)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string pais1, pais2;
    unordered_map<string, int> paises;
    double c, cambio[30][30];
    int n, m, caso = 1;

    while (true)
    {
        cin >> n;
        if(!n) break;

        memset(cambio, 0, sizeof(cambio));
        
        // tomo los paises como clave y les entrego un valor para su valor que ira de [0, n-1]
        // (esto guardandolo todo en un map no ordenado)
        for (int i = 0; i < n; i++)
        {
            cin >> pais1;
            paises.insert(make_pair(pais1, i));
        }

        cin >> m;

        // tomo el pais1, el cambio de moneda al pais2 y el pais2
        // y creo un grafo implementando una matriz de adyacencia
        for (int i = 0; i < m; i++)
        {
            cin >> pais1 >> c >> pais2;
            cambio[paises.at(pais1)][paises.at(pais2)] = c;
        }

        // ejecuto Floyd-Warshall
        // PERO ME QUEDO CON EL ELEMENTO MAS GRANDE AL HACER LA COMPARACION
        // y, en vez de sumar los "caminos", multiplico los caminos entre si
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    // multiplicacion de los caminos
                    double aux = cambio[i][k] * cambio[k][j];
                    if(cambio[i][j] < aux)
                    {
                        cambio[i][j] = aux;
                    }
                }
            }
        }

        bool money = false;
        for (int i = 0; i < n; i++)
        {
            // (toda la matriz inicio con ceros)
            // En la diagonal principal, los numeros mayores a cero indican que
            // existe un camino que puede salir de un nodo/vertice y llegar al mismo.
            // Si alguno de esos numeros es mayor a 1 entonces el arbitrage es posible.
            if(cambio[i][i] > 1)
            {
                money = true;
                break;
            }
        }

        if(money) cout << "Case " << caso << ": " << "Yes" << endl;
        else cout << "Case " << caso << ": " << "No" << endl;
        caso++;
    }
}

/**
11
A
B
C
D
E
F
G
H
I
J
K
15
A 7.9 F
C 1.1 F
C 5.0 I
C 5.7 K
D 1.8 A
E 0.7 B
E 9.7 C
G 4.2 B
G 0.6 E
H 7.1 A
H 8.5 G
I 1.4 J
J 9.9 I
J 6.9 K
K 8.3 A
*/

/*
         x
         0    1   2   3   4    5   6   7   8   9   10

x 0      x    0   0 1.8   0    0   0 7.1   0   0  8.3
  1      0    x   0   0 0.7    0 4.2   0   0   0    0
  2      0    0   x   0 9.7    0   0   0   0   0    0
  3      0    0   0   x   0    0   0   0   0   0    0
  4      0    0   0   0   x    0 0.6   0   0   0    0
  5    7.9    0 1.1   0   0    x   0   0   0   0    0
  6      0    0   0   0   0    0   x 8.5   0   0    0
  7      0    0   0   0   0    0   0   x   0   0    0
  8      0    0 5.0   0   0    0   0   0   x 9.9    0
  9      0    0   0   0   0    0   0   0 1.4   x    0
 10      0    0 5.7   0   0    0   0   0   0 6.9    x

*/

/*

  0   0 0 0 0 7.9 0 0 0 0 0 
  0   0 0 0 0 0 0 0 0 0 0 
  0   0 0 0 0 1.1 0 0 5 0 5.7 
1.8   0 0 0 0 0 0 0 0 0 0 
  0 0.7 9.7 0 0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 0 0 0 0 
  0 4.2 0 0 0.6 0 0 0 0 0 0 
7.1 0 0 0 0 0 8.5 0 0 0 0 
  0 0 0 0 0 0 0 0 0 1.4 0 
  0 0 0 0 0 0 0 0 9.9 0 6.9 
8.3 0 0 0 0 0 0 0 0 0 0 

a                x    0     0 0   0         7.9   0 0        0         0           0 
b                0    x     0 0   0           0   0 0        0         0           0 
c        5556.3354    0     x 0   0 43895.04966   0 0     69.3     97.02     669.438 
d              1.8    0     0 x   0       14.22   0 0        0         0           0 
e      53896.45338  0.7   9.7 0   x 425781.9817   0 0   672.21   941.094   6493.5486 
f                0    0     0 0   0           x   0 0        0         0           0 
g      32337.87203  4.2  5.82 0 0.6  255469.189   x 0  403.326  564.6564  3896.12916 
h      274871.9122 35.7 49.47 0 5.1 2171488.107 8.5 x 3428.271 4799.5794 33117.09786 
i       1111.26708    0     0 0   0 8779.009932   0 0   13.86x    19.404    133.8876 
j      11001.54409    0     0 0   0 86912.19833   0 0  137.214 192.0996x  1325.48724 
k              8.3    0     0 0   0       65.57   0 0        0         0           x


   0 0.5  0 
   0   0 10 
0.21   0  0 

  1.05   0.525   5.25 
   2.1    1.05   10.5 
0.2205 0.11025 1.1025

   0  0.5 4.9 
1.99    0  10 
0.19 0.09   0 

0.995   0.5    5 
 1.99 0.995   10 
 0.19 0.095 0.95 


*/




/*
los indices de la matriz de abajo son los vertices que estan conectados con el peso entre ellos
(el vertice 1 esta conectado al 2 con un peso de 3. El vertice 1 no esta conectado con el 5 
por lo que su distancia es "infinita" [00])

     0   3  5  1 00 00
     3   0 00 00  9 00
     5  00  0  7  7  1
     1  00  7  0 00  4
    00   9  7 00  0 00
    00  00  1  4 00  0
 
*/