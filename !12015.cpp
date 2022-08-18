//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)

#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    string webPage[10*t];// guarda las paginas
    int valor[10*t];//guarda el valor correspondiente a cada pagina
    int maxVal[t];//guarda los valores maximos encontrados en cada caso

// Acepta inputs para las paginas y sus valores respectivos
    for(int i = 0; i < t*10; i++)
        cin>>webPage[i]>>valor[i];

// Revisa cual es el mayor valor de cada caso.
// Al terminar con el caso, guarda el valor maximo encontrado
// en el arreglo "maxVal" y sigue con el siguiente caso
    for(int i = 0; i < t; i++){
        int j = 1;
        int max = valor[(10*i) + j-1];
        while(j < 10){
            if(max < valor[(10*i) + j])
                max = valor[(10*i) + j];
            j++;
        }
        maxVal[i] = max;
    }

// Imprime todas las paginas que tengan el mismo valor que "maxVal[i]"
    for(int i = 0; i < t; i++){
        cout<<"Case #"<< i+1 <<":"<<endl;
        int j = 0;
        while(j < 10){
            if(maxVal[i] == valor[(10*i) + j])
                cout<<webPage[(10*i) + j]<<endl;
            j++;
        }
    }
}