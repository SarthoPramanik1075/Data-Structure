#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
       cin >> a[i];  
    }
    sort(a,a+n);
    int q;
    cin >> q;
    while(q--)
    {
        int findValue;
        cin >> findValue;
        bool flag=false;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid]==findValue)
            {
                flag=true;
                break;
            }
            if(findValue > a[mid])
            {
                l=mid+1;
            }
            else 
            {
                r=mid-1;
            }
        }
        if(flag==true)
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
 
return 0;
}