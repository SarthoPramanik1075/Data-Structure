//Running sum of an array
// #include<bits/stdc++.h>
// using namespace std;
// void fun(int n, vector<int>&v)
// {
//      int sum=0;
//      for(int i=0;i<n;i++)
//      {
//         sum=sum+v[i];
//         cout << sum << " ";
//      }
// }
// int main()
// {
//     int n;
//     cin >> n;
//    vector<int>v(n);
//    for(int i=0;i<n;i++)
//    {
//        cin >> v[i];
//    }
//    fun(n,v);
// return 0;
// }

// Equilibrium Index 
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int>v(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> v[i];
//     }

//     int totalSum=0,fsum=0,bsum,index=-1;
//     for(int i=0;i<n;i++)
//     {
//         totalSum=totalSum+v[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         bsum=totalSum-fsum-v[i];
//         if(fsum==bsum)
//         {
//             index=i;
//             break;
//         }
//         fsum+=v[i];
//     }

//     if(index!=-1)
//     {
//         cout << index << endl;
//     }
//     else
//     {
//         cout << "Not found" << endl;
//     }
 // return 0;
// }

//Search Query

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a,a+n);
//      int q;
//      cin >> q;
//       while(q--)
//       {
//          int x;
//          cin >> x;
//          int l=0,r=n-1;
//          bool flag=false;
//          while(l<=r)
//          {
//             int mid=(l+r)/2;
//             if(a[mid]==x)
//             {
//                 flag=true;
//                 break;
//             }
//             else if(x>a[mid])
//             {
//                 l=mid+1;
//             }
//             else
//             {
//                 r=mid-1;
//             }
//          }
//          if(flag==true)
//          {
//             cout << "YES" << endl;
//          }
//          else
//          {
//             cout << "NO" << endl;
//          }
//       }
 
// return 0;
// }

//sum of 1 to n by O(1) complexity

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int sum=(n*(n+1))/2;
    cout << sum;
 
return 0;
}