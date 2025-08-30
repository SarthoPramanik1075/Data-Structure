#include <bits/stdc++.h>
#define ll = long long;
using namespace std;



const int N = 1e5 + 10;

class Edge
{
public:
    int u, v;
    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }
};

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
        int u, v;
        cin >> u >> v;

        EdgeList.push_back(Edge(u, v));
    }


    int edge_lagbe = 0;

    for (Edge ed : EdgeList)
    {
        int u_er_leader = dsu_find(ed.u);
        int v_er_leader = dsu_find(ed.v);

        if (u_er_leader == v_er_leader)
        {
            edge_lagbe++;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
        }
    }
    cout<<edge_lagbe;
    return 0;
}