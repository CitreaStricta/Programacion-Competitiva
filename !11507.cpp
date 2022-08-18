//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)

#include <iostream>

using namespace std;

// si es "+y"
int dpy(int dir){
    if(dir == 1) return 3;
    if(dir == 2) return 4;
    if(dir == 3) return 2;
    if(dir == 4) return 1;
    return dir; // si "dir" es 5 o 6 los devuelve
}

// si es "-y"
int dny(int dir){
    if(dir == 1) return 4;
    if(dir == 2) return 3;
    if(dir == 3) return 1;
    if(dir == 4) return 2;
    return dir; // si "dir" es 5 o 6 los devuelve
}

// si es "+z"
int dpz(int dir){
    if(dir == 1) return 5;
    if(dir == 2) return 6;
    if(dir == 5) return 2;
    if(dir == 6) return 1;
    return dir; // si "dir" es 3 o 4 los devuelve
}

// si es "-z"
int dnz(int dir){
    if(dir == 1) return 6;
    if(dir == 2) return 5;
    if(dir == 5) return 1;
    if(dir == 6) return 2;
    return dir;
}

int main(){
    int j = 0;
    string aux;
    int res[1000];
    while(true){
        int l;
        cin >> l;
        if(l == 0) break;
// La direccion inicial es +x = 1
        int dir = 1;

// tradusco a las direcciones en numeros del 1 al 6
// +x = 1, -x = 2, +y = 3,
// -y = 4, +z = 5, -z = 6
// Y les aplico una transformacion acorde
// a la direccion actual y a la de doblado
// Las transformaciones fueron hardcodeadas
// en las funciones dpy(), dny(), dpz(), dnz().
// d(direccion) p(plus)/n(negative) y/z
        for(int i = 0; i < l-1; i++){
            cin >> aux;
            if(aux == "No") continue;
            if(aux == "+y") dir = dpy(dir);
            if(aux == "-y") dir = dny(dir);
            if(aux == "+z") dir = dpz(dir);
            if(aux == "-z") dir = dnz(dir);
        }
        res[j] = dir;
        j++;
    }

// Revisa los numeros en el arreglo "res" y printea acorde
// +x = 1, -x = 2, +y = 3, -y = 4, +z = 5, -z = 6
    for(int i = 0; i < j; i++){
        if(res[i] == 1) aux = "+x";
        if(res[i] == 2) aux = "-x";
        if(res[i] == 3) aux = "+y";
        if(res[i] == 4) aux = "-y";
        if(res[i] == 5) aux = "+z";
        if(res[i] == 6) aux = "-z";
        cout << aux << endl;
    }
}