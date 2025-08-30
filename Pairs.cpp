#include<bits/stdc++.h>
using namespace std;


class cmp {
public:
    bool operator()(pair<string, int>& a,  pair<string, int>& b)
     {
       
        if (a.first == b.first) 
        {
            return a.second < b.second;
        }
     return a.first > b.first;
    }
};

int main() {
    int n;
    cin >> n;
    
    
    priority_queue<pair<string, int>, vector<pair<string, int> >, cmp> pq;
    
    for (int i = 0; i < n; ++i) {
        string name;
        int val;
        cin >> name >> val;
        pq.push({name, val});
    }
    
    
   while (!maxHeap.empty()) {
        auto p = maxHeap.top();
        maxHeap.pop();
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}
