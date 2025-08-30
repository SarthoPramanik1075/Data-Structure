#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int s;
        cin >> s;
        int sum = 1000-s;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        } 
        bool kp[n + 1][sum + 1];
        kp[0][0] = true;
        for (int i = 1; i <= sum; i++)
        {
            kp[0][i] = false;
        }
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
        if (kp[n][sum])
           cout << "YES"<< endl;
        else
           cout << "NO" << endl;
    }  
    return 0;
}