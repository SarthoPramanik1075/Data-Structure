#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
const int N=1e3+5;
vector< pair <int, int> > v[N];
ll dis[N];

class cmp
{
    public:
    bool operator()(pair<int,int>a, pair<int,int>b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
   priority_queue< pair<int,int>,vector<pair<int,int>>, cmp> pq;
    pq.push({src,0});
    dis[src]=0;
    while(!pq.empty())
    {
        pair<int,int>par=pq.top();
        pq.pop();
        int node=par.first;
        ll cost=par.second;
        for(pair<int,int>child: v[node])
        {
            ll childNode=child.first;
            ll childCost=child.second;
            if(cost+childCost < dis[childNode])
            {
                dis[childNode]= cost+childCost;
                pq.push({childNode,dis[childNode]});
            }
        }
    }
}

int main()
{
    int n,e;
     cin >> n>> e;
    while(e--)
    {
       int a,b;
       ll w;
       cin >> a >> b >> w;
       v[a].push_back({b,w}); 
    }

     int src;
    cin>> src;
    
    int t;
    cin >> t;
    while(t--)
    {
 for(int i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
    }

   
    ll ds,c;
    cin >> ds >> c;
    dijkstra(src);


    if(dis[ds] <= c)
    cout << "YES" << endl; 
    else
    cout << "NO" << endl;
    }
   
return 0;
}