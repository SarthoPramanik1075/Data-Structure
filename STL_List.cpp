#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    list<int>mylist;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        mylist.push_back(x);
    }

//  for INSERT
    // int pos,value;
    // cin >> pos >> value;
    // mylist.insert(next(mylist.begin(),pos),value);
    
//  for ERASE(index)
    // int fpos,lpos;
    // cin >> fpos >> lpos;
    // mylist.erase(next(mylist.begin(),fpos),next(mylist.begin(),lpos));

//  for PRINT by ITERATOR
    // for(auto it=mylist.begin(); it!=mylist.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    for(int val:mylist)
    { 
        cout << val << " ";
    }
 
return 0;
}