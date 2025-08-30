#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class edge
{
    public:
    ll a,b,w;
    edge(ll a,ll b,ll w)
    {
        this->a=a;
        this->b=b;
        this->w=w;
    }
};
const ll N=1e18;
const ll max=1e18;
ll dis[N];

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   int n,e;
    cin >> n >> e;
    vector<edge>edgelist;
    
    while(e--)
    {
        ll a,b,w;
        cin >> a >> b >> w;
        edgelist.push_back(edge(a,b,w));
    }

    int src, t;
    cin >> src >> t;
    

    while (t--) 
    {
        int dst;
        cin >> dst;

          for(int i=1;i<=n;i++)
        {
            dis[i]=max;
        }
        dis[src]=0;
        for(int i=1;i<=n-1;i++)
        {
            for(edge ed:edgelist)
            {
                ll a,b,w;
                a=ed.a;
                b=ed.b;
                w=ed.w;
                if(dis[a] < max && dis[a]+w < dis[b])
                {
                    dis[b]=dis[a]+w;
                }
            }
        }

         bool cycle=false;
        for (edge ed : edgelist)
    {
        ll a, b, w;
        a = ed.a;
        b = ed.b;
        w = ed.w;
        if (dis[a] < max && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }

      if(cycle)
        { 
           cout << "Negative Cycle Detected" << endl;
           return 0;
        }
        else
         {
           
            if (dis[dst] == max) 
            {
                cout << "Not Possible" << endl;
            }
            else 
            {
                cout << dis[dst] << endl;
            }
        }
    }
        return 0;
    }

    

