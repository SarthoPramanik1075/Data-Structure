#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pq;
map<int, int> mp;

int minimum() 
{
    while (!pq.empty() && mp[pq.top()] == 0)
    {
        pq.pop();
    }
    if (pq.empty()) 
    {
        return -1;
    }
    return pq.top();
}

int main()
 {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pq.push(val);
        mp[val]++;
    }
    
    int q;
    cin >> q;
    
    while (q--) 
    {
        int cmd;
        cin >> cmd;
        
        if (cmd == 0)
         {
            int x;
            cin >> x;
            pq.push(x);
            mp[x]++;
            cout << minimum() << endl;
        } 
        else if (cmd == 1) 
        {
            int min_val = minimum();

            if (min_val == -1)
            {
                cout << "Empty" << endl;
            }
             else
           {
                cout << min_val << endl;
            }
        } 
        else if (cmd == 2) 
        {
            int min_val = minimum();
            if (min_val == -1)
            {
                cout << "Empty" << endl;
            } 
            else 
            {
                mp[min_val]--;
                int new_val = minimum();

                if (new_val == -1)
                {
                    cout << "Empty" << endl;
                } 
                else 
                {
                    cout << new_val << endl;
                }
            }
        }
    }
    
    return 0;
}
