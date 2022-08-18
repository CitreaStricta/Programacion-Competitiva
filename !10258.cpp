/**
 *Juez: Online Judge
 *Compilador C++11
 *Online Judge ID: 1134306 (User: Chulz)
**/

#include <bits/stdc++.h>

using namespace std;

struct part
{
    bool inTur = false;
    int nPart;
    int time = 0;
    int qIncorr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool qCorrect[10] = {false, false, false, false, false, false, false, false, false, false};
    int correct = 0;
};

bool comparator(const part &a, const part &b)
{
    if(a.correct == b.correct)
        return a.time < b.time;
    return a.correct > b.correct;
}

int main()
{
    int n;
    int nPart, nPreg, nTime;
    
    // acceptacion de input
    cin >> n;
    getchar();
    getchar();
    while(n--)
    {
        //array de estructuras participantes "part"
        part contestant[101];
        while(true)
        {
            string arr[3];
            int num[3];
            string l;
            char judgeResp;

            // aqui se acepta el input
            getline(cin, l, '\n');
            // si se ingresa un "enter" entonces el string va a estar vacio
            // y terminara uno de los 'n' inputs a revisar
            if(l == "") break;

            
            // en este "for" se procesa lo entregado por consola por el juez
            // y se calcula el tiempo de cada participante
            for (int i = 0; i < 3; i++)
            {
                stringstream(l) >> arr[i];
                num[i] = stoi(arr[i]);
                l.erase(0, l.find_first_of(' ') + 1);
            }
            nPart = num[0];
            nPreg = num[1];
            nTime = num[2];
            judgeResp = l[0];
            contestant[nPart].nPart = nPart;
            contestant[nPart].inTur = true;

            // Si el problema esta Incorrecto/Correcto y no ha sido respondido correctamente aun, entonces entra a alguno de estos "if"s
            if(judgeResp == 'I' && contestant[nPart].qCorrect[nPreg] == false) contestant[nPart].qIncorr[nPreg]++;

            if(judgeResp == 'C' && contestant[nPart].qCorrect[nPreg] == false)
            {
                contestant[nPart].qCorrect[nPreg] = true;
                contestant[nPart].time += nTime + contestant[nPart].qIncorr[nPreg]*20;
                contestant[nPart].correct++;
            }
        }

        /**
         * utilizo una funcion sort con un comparador custom para ordenar segun
         * un criterio arvitrario inpuesto por mi para mantener la jerarquia de
         * [nPreguntas correctas] >> [tiempo total]
         * 
         *  Y como el proceso de sumar los tiempos y determinar las nRespuestas correctas
         * fue hecho en un arreglo utilizando como indice los id's de cada participante
         * entonces utilisando stable_sort, si es que dos pasticipantes tienen igual
         * cantidad de preguntas e igual cantidad de tiempo de penalisacion, el que
         * este por sobre el otro sea el participante con menor id.
        */
        stable_sort(contestant + 1, contestant + 101, comparator);

        // El printeo en consola
        for (int i = 1; i < 101; i++)
        {
            if(contestant[i].inTur)
            {
                cout
                << contestant[i].nPart << " "
                << contestant[i].correct << " "
                << contestant[i].time << endl;
            }
        }

        if(n) cout << endl;
    }

    return 0;
}
