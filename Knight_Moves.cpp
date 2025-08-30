#include <bits/stdc++.h>
using namespace std;

bool vis[101][101];
int level[101][101];
char a[101][101];
vector<pair<int, int>> d = {{-1, -2}, {1, -2}, {2, -1}, {2, 1},{-2,-1},{-2,1},{-1,2},{1,2}};
int n, m;
int k1,k2,q1,q2;

bool valid(int i, int j)
{ 
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs(int k1, int k2,int q1,int q2)
{
    queue<pair<int, int>> q;
    q.push({k1, k2});
    vis[k1][k2] = true;
    level[k1][k2] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int a = parent.first;
        int b = parent.second;
        q.pop();
        if(a==q1 && b==q2)
        {
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[a][b] + 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        cin >> n >> m;
        cin >> k1 >> k2;
        cin >> q1 >> q2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j]='.';
            }
        }
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(k1,k2,q1,q2);
        cout<<level[q1][q2] << endl;;
    }    
    return 0;
}