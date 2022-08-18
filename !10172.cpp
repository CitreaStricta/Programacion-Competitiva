//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)
//Lenguaje: C++11

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct estacion
{
    int maxq;
    queue<int> bplat;
};

struct carrier
{
    int estacionAct = 1;
    int maxq;
    stack<int> bplat;
};

int main()
{
    int set, n, s, q;
    cin >> set;
    int tiempo[set];

    for (int j = 0; j < set; j++)
    {
        tiempo[j] = 0;
        cin >> n >> s >> q;
        carrier car;
        car.maxq = s;
        int cargo = 0;
        estacion anillo[n];
        for (int i = 0; i < n; i++){
            anillo[i].maxq = q;
            int aux, auxp;
            cin >> aux;

            while(aux--){
                cin >> auxp;
                anillo[i].bplat.push(auxp);
                cargo++;
            }
        }

        while(cargo)
        {
            if(car.estacionAct > n) car.estacionAct = 1;
        
            while(!car.bplat.empty())
            {// "mientras que tenga cargos en el stack, las saco y las coloco..."
                if(car.bplat.top() == car.estacionAct) // "en A si el cargo es del pais de la estacion actual"
                {
                    car.bplat.pop();
                    tiempo[j]++;
                    cargo--;
                    continue;
                }

                if (anillo[car.estacionAct - 1].maxq != anillo[car.estacionAct - 1].bplat.size()) // "en B si B no esta lleno y el cargo no es de esta estacion"
                {
                    anillo[car.estacionAct - 1].bplat.push(car.bplat.top());
                    car.bplat.pop();
                    tiempo[j]++;
                    continue;
                }
                break;
            }

            while(!anillo[car.estacionAct - 1].bplat.empty())
            { // "vuelvo a cargar el stack con lo que esta en B de la estacion si el stack no esta lleno"
                if(car.bplat.size() != car.maxq){
                    car.bplat.push(anillo[car.estacionAct - 1].bplat.front());
                    anillo[car.estacionAct - 1].bplat.pop();
                    tiempo[j]++;
                    continue;
                }
                break;
            }
            if(cargo){
                car.estacionAct++;
                tiempo[j]+= 2;
            }
        }
    }
    for (int i = 0; i < set; i++)
        cout << tiempo[i] << endl;
    
}