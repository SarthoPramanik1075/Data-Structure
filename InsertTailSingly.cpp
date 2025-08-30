#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int val;
    node *next;
    node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

void insert_at_tail(node *&head,int val)
{
    node *newnode = new node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    node *tmp=head;
    while(tmp->next != NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=newnode;
}

void print_singly_list(node *head)
{
    cout << "Your linked list: ";
    node *tmp=head;
    while(tmp!=NULL)
    {
        cout << tmp->val << " ";
        tmp=tmp->next;
    }
    
}

int main()
{
    node *head=NULL;
    while(true)
    {
        cout << endl;
        cout << endl;
        cout << "Option 1: Insert at tail" << endl;
        cout << "Option 2: Print linked list" << endl;
        cout << "Option 3: Terminate" << endl;

        int op;
        cin >> op;

        if(op==1)
        {
            cout << "please enter the value: ";
            int val;
            cin >> val;
            insert_at_tail(head,val);
        }
        else if(op==2)
        {
            print_singly_list(head);
        }
        else if(op==3)
        {
            break;
        }
    }
 
return 0;
}