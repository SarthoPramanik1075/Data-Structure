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
    bool flag=false;
    int x;
    cin >> x;
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]==x && a[mid+1]==x)
        {
            flag=true;
            break;
        }
        else if(x>a[mid])
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
       cout << "True" << endl;
   }
   else
   {
    cout << "False" << endl;
   }
   
return 0;
}