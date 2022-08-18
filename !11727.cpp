//Juez: Online Judge
//Online Judge ID: 1134306 (User: Chulz)

#include <iostream>

using namespace std;

int sort(int* arr){ // algoritmo para sort'ear un arreglo de menor a mayor
    int temp;
    for(int i=0; i<(3-1); i++){
		for(int j=0; j<(3-i-1); j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
    return *arr;
}

int main(){
    int n;
    cin >> n;
    int arr[n][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }
// Ordeno los numeros
    for(int i = 0; i < n; i++) sort(arr[i]);
// Printeo el del medio de cada arreglo
    for(int i = 0; i < n; i++)
        cout<<"Case "<<i+1<<": "<<arr[i][1]<<endl;
}