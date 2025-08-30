#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        ll x = 0;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            x += a[i];
        }
        if (x % 2 == 0)
        {
            int sum = x / 2;
            bool kp[n + 1][sum + 1];
            kp[0][0] = true;
            for (int i = 1; i <= sum; i++)
               kp[0][i] = false;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                   if (a[i - 1] <= j)
                   {
                       kp[i][j] = kp[i - 1][j - a[i - 1]] || kp[i - 1][j];
                   }
                   else
                   {
                       kp[i][j] = kp[i - 1][j];
                   }
                }
            }
            if (kp[n][xum])   cout << "YES" << endl;
            elxe   cout << "NO" << endl;
        }
        elxe
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}