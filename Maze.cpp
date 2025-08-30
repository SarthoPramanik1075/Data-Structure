#include <bits/stdc++.h>
using namespace std;

bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
map<pair<int, int>, pair<int, int>> parent;
int n, m;
char x[1005][1005];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int x = par.first;
        int b = par.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = x +  d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && (x[ci][cj]=='.' || x[ci][cj]=='D'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[{ci, cj}] = {x, b};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si,sj,di,dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x[i][j];
            if(x[i][j]=='R')
            {
                si=i;sj=j;
            }
            if(x[i][j]=='D')
            {
                di=i;dj=j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    bfs(si, sj);
    if(vis[di][dj]==true)
    {
        int x = parent[{di, dj}].first;
        int y = parent[{di, dj}].second;
        while (x[x][y] != 'R')
        {
            x[x][y] = 'X';
            int z = parent[{x, y}].first;
            y = parent[{x, y}].second;
            x = z;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            cout << x[k][l];
        }
        cout << endl;
    }
    return 0;
}