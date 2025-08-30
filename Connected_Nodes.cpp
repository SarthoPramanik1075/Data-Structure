#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    vector<int> mat[n];;

    while(e--)
    {
        int a,b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);

    }

    int q;
    cin >> q;

    while(q--)
    {
        int x;
        cin >> x;
        priority_queue<int> pq;
        for(int val:mat[x])
        {
            
            pq.push(val);
        }
        if(pq.empty())
        {
            cout << "-1";
        }
        while(!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
       
        cout << endl;
    }
 
return 0;
}