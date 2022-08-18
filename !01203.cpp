//Juez: Online Judge
//Compilador C++11
//Online Judge ID: 1134306 (User: Chulz)

#include <bits/stdc++.h>

using namespace std;

// Comparador custom. Si el tiempo del 1er elemento es igual
// al del 2do, ordena segun su ID. Si no, ordena segun su tiempo
struct compare
{
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
    {
        if(a.first.first == b.first.first)
            return a.second > b.second;
        return a.first.first > b.first.first;
    }
};

int main()
{
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> qrs;

    // input
    string null;
    int Q_num;
    int peri;
    while(true)
    {
        cin >> null;
        if(null == "#") break;
        cin >> Q_num >> peri;
        auto auxP = make_pair(peri, peri);
        qrs.push(make_pair(auxP, Q_num));
    }
    int k;
    cin >> k;

    // output
    int time = 0;

    /**
     * Los datos en la queue tienen un pair compuesto por un pair de ints y un int:
     *   pair.first.first: Cuando "time" sea igual a este numero, el ID de este elemento se escribira.
     *  pair.first.second: El tiempo de ejecucion segun programa. Cuando el elemento se escriba, "pair.first.first"
     *                     aumentara en "pair.first.second".
     *        pair.second: ID del elemento.
    */
    while(true)
    {
        time = qrs.top().first.first;
        if(time == qrs.top().first.first)
        {
            auto aux = qrs.top();
            qrs.pop();
            cout << aux.second << endl;
            aux.first.first += aux.first.second;
            qrs.push(aux);
            k--;
        }
        if(!k) break;
    }

    return 0;
}