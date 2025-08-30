#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int main()
{
    ll n,e;
    cin >> n >> e; 
    ll adj[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=1e18;
            if(i==j)
            {
                adj[i][j]=0;
            }
        }
    }

    while(e--)
    {
        ll a,b,w;
        cin >> a >> b >> w;
        adj[a][b]=w;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][k]+adj[k][j] < adj[i][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }

    int src,dst;
    cin >> src >> dst;

    cout << adj[src][dst];

    // int q;
    // cin >> q;

    // while(q--)
    // {
    //     int src,dst;
    //     cin >> src >> dst;
    //     if (adj[src][dst] == 1e18) {
    //         cout << "-1" << endl;
    //     } else {
    //         cout << adj[src][dst] << endl;
    //     }
    // }

    // cout << "AFTER" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (adj[i][j] == 1e18)
    //             cout << "INF ";
    //         else
    //             cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
 
return 0;
}