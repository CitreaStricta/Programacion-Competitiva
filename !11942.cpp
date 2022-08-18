//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)

#include <iostream>

using namespace std;

// Si en cualquier momento hay algun numero en la lista
// mayor al siguiente, devuelve 0 (desorden)
// Caso contrario 1 (orden)
int ordenAscendente(int* lumbs){
    int j = 1;
    while (j<10){
        if(lumbs[j-1]>lumbs[j]) break;
        j++;
    }
    if(j == 10) return 1;
    return 0;
}

// Si en cualquier momento hay algun numero en la lista
// menor al siguiente, devuelve 0 (desorden)
// Caso contrario 1 (orden)
int ordenDescendente(int* lumbs){
    int j = 1;
    while (j<10){
        if(lumbs[j-1]<lumbs[j]) break;
        j++;
    }
    if(j == 10) return 1;
    return 0;
}

int main(){
    int n;
    cin >> n;
    int orden[n];
    int lumbs[n][10];
// acepta 10n enteros y los coloca en el arreglo "lumbs"
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin >> lumbs[i][j];
        }
    }
// revisa si el orden de los arreglos se encuentra en orden Ascendente, Descendente o
// si todos los numeros son iguales
    for(int i = 0; i < n; i++){
        int j = 1;
        while(j < 10){
            //check si es de menor o mayor
            if(lumbs[i][j-1] < lumbs[i][j]){
                orden[i] = ordenAscendente(lumbs[i]);
                break;
            }
            //check si es de mayor o menor
            if(lumbs[i][j-1] > lumbs[i][j]){
                orden[i] = ordenDescendente(lumbs[i]);
                break;
            }
            j++;
        }
// Check para cuando el "while" termina
// Si j = 10 entonces los numeros son todos iguales (ordenado)
        if(j == 10) orden[i] = 1;
    }
    // 0 = desorden, 1 = orden
    cout<<"Lumberjacks:"<<endl;
    for(int i = 0; i < n; i++)
        if(orden[i] == 0) 
            cout<<"Unordered"<<endl;
        else
             cout<<"Ordered"<<endl;
}