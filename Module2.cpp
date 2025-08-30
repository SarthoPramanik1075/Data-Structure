#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   vector<int>v;
   for(int i=0;i<n;i++)
   {
     int x;
     cin >> x;
     v.push_back(x);
   }

   int re,repv;
   cin >> re >> repv;
   replace(v.begin(),v.end(),re,repv);
   for(int val:v)
   {
     cout << val << " ";
   }

   cout << endl;

   replace(v.begin(),v.end(),repv,re);

   int f;
   cin >> f;
   vector<int>::iterator it;
   it=find(v.begin(),v.end(),f);
   if(it!=v.end())
   {
      int index=it-v.begin();
      cout << index << endl;
   }
   else
   cout<< "-1" << endl;

return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//    int n;
//    cin >> n;
//    vector<string>v;
//    for(int i=0;i<n;i++)
//    {
//       string s;
//       cin >> s;
     
//       for(char c:s)
//       {
//          c=c-32;
//          cout << c;
         
//          break;
//       }
//    }
//    for(string val:v)
//    {
//       cout << val << " ";
//    }
 
// return 0;
// }