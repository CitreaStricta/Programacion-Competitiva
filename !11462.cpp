/**
 *Juez: Online Judge
 *Compilador C++11
 *Online Judge ID: 1134306 (User: Chulz)
**/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    { 
        int n;
        cin >> n;
        if(n == 0) break;
        int arr[n];
        int j = n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+n);
        
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if(i<n-1) cout << " ";
        }
        cout << endl;
    }
}