//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)

#include <iostream>

using namespace std;

int main(){
    char str;
    int aux;
    int robInstr;

// cantidad de casos
    int rCase;
    cin >> rCase;

// localizacion de cada robot
    int robLoc[rCase];
    for(int i = 0; i < rCase; i++) robLoc[i] = 0;

// Inicia el chequeo de los caso
    for(int i = 0; i < rCase; i++){
        //cantidad de instrucciones entregadas al robot
        cin >> robInstr;
        getchar(); // necesario para limpiar el buffer
        int instructions[robInstr];

// Revisa la 1era letra de cada frase entregada al programa
// Si es "LEFT" o "RIGHT" comparo sus iniciales y guardo un '-1'
// o un '1' en el arreglo "instructions". Y, si es "SAME AS X" 
// repito el valor que se encuentra en instructions[X-1]
// en la instruccion que toca ahora
// (NOTA: Uso la funcion "cin.ignore()" para para
// desascerme de lo inutil en el buffer)
        for(int j = 0; j < robInstr; j++){
            str = cin.get();
            if(str == 'L' || str == 'R'){
                cin.ignore(7,'\n');
                if(str == 'L'){
                    instructions[j] = -1;
                    continue;
                }
                instructions[j] = 1;
                continue;
            }
            cin.ignore(7);
            cin>>aux;
            getchar(); // necesario para limpiar el buffer
            instructions[j] = instructions[aux-1];
        }
// sumo todo de "instructions" y lo guarda el resultado
// en "robLoc"
        for(int j = 0; j < robInstr; j++){
            robLoc[i] += instructions[j];
        }
    }
// escribe los numeros encontrados en "robLoc"
    for(int i = 0; i < rCase; i++)
        cout<< robLoc[i]<< endl;
}