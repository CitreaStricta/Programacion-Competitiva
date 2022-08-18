//Juez: Online Judge
//Compilador C++11
//Online Judge ID: 1134306 (User: Chulz)

#include <bits/stdc++.h>

using namespace std;

int votersVoting[110][110];
int votersPref[110];
int n, m , c;

void DFS(vector<vector<int>> &g, vector<bool> &nods, int v)
{
    nods[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int visitando = g[v].at(i);
        if(!nods[visitando]) DFS(g, nods, visitando);
    }
}


bool DFS(vector<vector<int>> &g, int N)
{
    vector<bool> nods;
    nods.assign(N, false);
    DFS(g, nods, c-1);
    bool win = true;
    for (int i = 0; i < N; i++)
    {
        if(!nods[i])
        { 
            win = false;
            break;
        }
    }

    return win;
}


int main()
{
    vector<vector<int>> g;
    int count = 1;
    int votersVoting[110][110];
    int votersPref[110];
    int A, B;
    while(true)
    {
        // n indica cant. cantidatos
        // m indica cant. votantes
        // c el candidato que quiero que gane
        cin >> n >> m >> c;
        if(n == 0 && m == 0 && c == 0) break;

        // setteo cada rango a 0
        memset(votersVoting, 0, sizeof(votersVoting));

        for (int i = 0; i < m; i++)
        {
            // guardo las preferencias de cada votante
            for (int j = 0; j < n; j++)
            {
                cin >> votersPref[j];
            }
            // Ordeno los votos que cada candidato tiene en contra del otro
            // al momento de la disputa entre los dos
            for (int k = 0; k < n; k++)
            {
                for (int l = k+1; l < n; l++)
                {
                    votersVoting[votersPref[k] - 1]
                                [votersPref[l] - 1]++;
                }
            }
        }

        // limpio el grafo que se uso para la ejecucion anterior
        g.resize(n);
        for (int i = 0; i < n; i++)
        {
            g[i].clear();
        }

        // preparo la nueva ejecucion 
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                // si el cantidato "i" tiene mas de la mitad de los votos posibles
                // entonces gana contra "j". Si no, lo contrario
                int aux = votersVoting[i][j];
                if(aux > m/2) g[i].push_back(j);
                else g[j].push_back(i);
            }
        }

        // ejecuto un algoritmo DFS que me dice si mi grafo dirigido puede llegar a todos los nodos
        // del grafo si el DFS es ejecutado desde el nodo c-1, es decir, el nodo de mi candidato
        if(DFS(g, n)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
    
}

/*     0  1  2  3  4  5  6    7    8  9 10 11 12 13 14

0      0 12 13 12 11  9 11   11   15 10  9 14 11 12 15 
1     11  0 12 12  9  8 11   10   12  9  7 12  8 14 14 
2     10 11  0 12  9 12 11   12   12 10 10 12  6  9 11 
3     11 11 11  0  9 11 13   12   13  9  7 11 12 10 16 
4     12 14 14 14  0 13 12   12   15 14 16 15 10 12 15 
5     14 15 11 12 10  0 14   10   13 12 10 11 10 13 12 
6     12 12 12 10 11  9  0   11   14 10  9 14  7  9 13 
7     12 13 11 11 11 13 12    0   16 11  9 13 12 10 15 
8      8 11 11 10  8 10  9    7    0 11 10  7  7  8 14 
9     13 14 13 14  9 11 13   12   12  0 10 13  9 11 15 
10    14 16 13 16  7 13 14   14   13 13  0 18 11 12 16 
11     9 11 11 12  8 12  9   10   16 10  5  0  9 10 15 
12    12 15 17 11 13 13 16   11   16 14 12 14  0 13 17 
13    11  9 14 13 11 10 14   13   15 12 11 13 10  0 15 
14     8  9 12  7  8 11 10    8    9  8  7  8  6  8  0
*/