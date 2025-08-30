#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 10;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
   return a.w < b.w;
}

int leader[N];
int group_size[N];

void dsu_initialize(int n)
{

    for (int i = 1; i <= n; i++)
    {
        leader[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (leader[node] == -1)
        return node;

    int l = dsu_find(leader[node]);
    leader[node] = l;
    return l;
}

void dsu_union_by_size(int x, int y)
{

    int leaderA = dsu_find(x);
    int leaderB = dsu_find(y);

    if (group_size[leaderA] > group_size[leaderB])
    {

        leader[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        leader[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    dsu_initialize(n);

    vector<Edge> EdgeList;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        EdgeList.push_back(Edge(u, v, w));
    }

    sort(EdgeList.begin(), EdgeList.end(), cmp);

    long long cost = 0;

    int edge_lagbe = 0;

    for (Edge ed : EdgeList)
    {
        int u_er_leader = dsu_find(ed.u);
        int v_er_leader = dsu_find(ed.v);

        if (u_er_leader != v_er_leader)
        {
            dsu_union_by_size(ed.u, ed.v);
            cost += ed.w;
            edge_lagbe++;
        }
    }

    int leader_hote_hobe = dsu_find(1);

    bool shobai_connected = true;

    for (int i = 1; i <= n; i++)
    {
        if (dsu_find(i) != leader_hote_hobe)
        {
            shobai_connected = false;
        }
    }

    if (shobai_connected)
        cout << cost << endl;
    else
        cout << "-1" << endl;

    
}