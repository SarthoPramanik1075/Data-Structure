#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->marks = marks;
        this->roll = roll;
        this->name = name;
    }
};
class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks > b.marks)
            return false;
        else if (a.marks < b.marks)
            return true;
        else
        {
            if (a.roll > b.roll)
                return true;
            else
                return false;
        }
    }
};
int main()
{
    int num;
    cin >> num;
    priority_queue<Student, vector<Student>, cmp> pq;
    for (int i = 0; i < num; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            pq.push(obj); 
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks<<endl;
        }
        else if (c == 1)
        {
            if(pq.size() != 0)  
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks<<endl;
            else  cout<<"Empty" << endl;
        }
        else if(c == 2)
        {
            if(pq.size() != 0)
            {
                pq.pop();
                if(pq.size() != 0)  
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks<<endl;
                else cout<<"Empty" << endl;
            }
            else  cout<<"Empty" << endl;
    }
    }
    return 0;
}