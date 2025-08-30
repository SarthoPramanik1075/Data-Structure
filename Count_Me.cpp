 #include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while(t--)
    {
        string sen;
        getline(cin,sen);
        string word;
        stringstream ss(sen);

        string max_word;
        int mx=0;
        map<string,int> mp;

        while(ss >> word)
        {
            mp[word]++;

            if(mp[word] > mx)
            {
                mx=mp[word];
                max_word=word;
            }
            
            else if(mp[word]==mx && max_word.empty())
            {
                max_word=word;
            }
        }
        
       cout << max_word << " " << mx << endl;

    }
   
    
 
return 0;
}