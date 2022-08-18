// Juez: Online Judge
// Compilador C++11
// Online Judge ID: 1134306 (User: Chulz)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    while(true)
    {
        int n;
        cin >> n;
        if(!n) break;
        int N;
        for (int i = 0; i < n; i++)
        {
            cin >> N;
            pq.push(N);
        }

        int total = 0;
        int a, b;
        a = b = 0;
        while(pq.size() > 1)
        {
            a = pq.top();
            pq.pop();

            b = a + pq.top();
            pq.pop();

            total += b;

            pq.push(b);
        }
        cout << total << endl;
        pq.pop();
    }
    return 0;
}