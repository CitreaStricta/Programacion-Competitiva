//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)

#include <iostream>

using namespace std;

int contrato(double* cont){
    // diferentes valores para diferentes cosas
    double arrDepreciacion[(int) cont[3]+1][2];
    double deuda = cont[2];   
    double preAuto = cont[1] + deuda;
    int mesActual = 0;
    int aux = 0;

/*ok... EN NINGUNA PARTE DEL PDF DEL EJERCICIO DICE QUE CADA PAGO MENSUAL ES (LA DEUDA)/(CANTIDAD DE MESES)
INCLUSO CUANDO LE PREGUNTE A LA PROFESORA ELLA ME DIJO QUE EL PAGO MENSUAL ERA EL PAGO INICIAL DEL AUTO
QUE SE IBA REPITIENDO (el 2do numero de los primeros inputs aceptados en el main)
NI ME ACUERDO COMO SE ME VINO A LA MENTE QUE EL PAGO MENSUAL TENIA QUE SER ESTE CALCULO*/
    double pagoMensual = deuda/cont[0];
/*HE ESTADO 3 DIAS PERDIENDO MI TIEMPO CON ESTE EJERCICIO
Y ENSERIO NECESITABA ESCRIBIR LO INCREIBLEMENTE ENOJADO QUE ESTOY CON EL
(Persona que revisa mi ejercicio: ruego me perdones quien quiera que seas)*/

    //inputs para la depreciacion gradual del auto
    for(int i = 0; i < cont[3]; i++){
        for(int j = 0; j < 2; j++)
            cin >> arrDepreciacion[i][j];
    }

    double depreciacionActual = arrDepreciacion[0][1];

    for(int i = 0; i < 2; i++) arrDepreciacion[(int) cont[3]][i] = 0;

//Esto es lo que hace todo el trabajo y es una absoluta atrocidad de "while"
//porque es el lugar donde he estado pensando (estos 3 dias) que estaba mi error.
//Basicamente:
//Disminuye la deuda,
//Revisa el mes en en el que se esta para aplicar la depreciacion respectiva, y
//Se asegura que el ciclo "while" se detenga cuando el precio del auto sobrepase al de la deuda
    while (mesActual < cont[0]){
        if(mesActual == 0){
            preAuto *= ((double)1 - depreciacionActual);
            if(preAuto > deuda) break;
        }else{
            deuda -= pagoMensual;
            if(mesActual == arrDepreciacion[aux+1][0]){
                depreciacionActual = arrDepreciacion[aux+1][1];
                aux++;
            }
            
            preAuto *= ((double)1 - depreciacionActual);
            if(preAuto > deuda) break;
        }
        mesActual++;
    }
    return mesActual;
}

int main(){
// en el ejercicio no aparece cuantas "deudas" se van a tener que manejar de a una
// asi que hice un arreglo lo suficientemente grande como para tomarlas a todas
    int meses[10000];
    double cont[4];
        int j = 0;
    while(true){
        //resivo los inputs de la primera persona endeudada
        for(int i = 0; i < 4; i++)
            cin>>cont[i];
        // si el mes es negativo esto detiene todo
        if(cont[0] < 0) break;
        // esta es la parte que hace todo el trabajo
        meses[j] = contrato(cont);
        j++;
    }
// el Output
    for (int i = 0; i < j; i++){
        string mes = "months";
        if(meses[i] == 1) mes = "month";
        cout<<meses[i]<< " "<< mes <<endl;
    }
}