#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
vector< pair<int,int> > d={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
int flag=0;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m || a[i][j]=='-')
    return false;
    return true;
}

void dfs(int si, int sj, int di, int dj)
{
    
    if(si==di && sj==dj)
    {
        flag=1;
    }
    vis[si][sj]=true;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(valid(ci,cj)==true && vis[ci][cj]==false)
        {
            dfs(ci,cj,di,dj);
        }
    }
   
}
int main()
{
    cin >> n >> m;
    int si,sj,di,dj;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
memset(vis,false,sizeof(vis));
cin >> si >> sj >> di >> dj;
dfs(si,sj,di,dj);
 if(flag==1)
    {
        cout << "YES" << endl;
    }
    else
    cout << "NO" << endl;
return 0;
}