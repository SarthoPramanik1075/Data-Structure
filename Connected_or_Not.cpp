#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    int mat[n][n];
    memset(mat,0,sizeof(mat));
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        mat[a][b]=1;
    }
   int q;
   cin >> q;
   while(q--)
   {
     int src,dis;
     cin >> src >> dis;
     if(src==dis)
     {
        cout << "YES" << endl;
     }
     else if(mat[src][dis]==1)
     {
        cout<<"YES" << endl;
     }
     else
     cout << "NO" << endl;
   }
    
 
return 0;
}