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

void insert_tail(node *&head,int val)
{
    node *newnode=new node(val);
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

void insert_pos(node *head,int pos,int val)
{
    node *newnode=new node(val);
    node *tmp=head;
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;
    cout << endl << "Inserted at position: " << pos << endl << endl;
}

void print_list(node *head)
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
        cout << "Option 2: Insert at position" << endl;
        cout << "Option 3: Print linked list" << endl;
        cout << "Option 4: Terminate" << endl;

         int op;
        cin >> op;

        if(op==1)
        {
            cout << "please enter the value: ";
            int val;
            cin >> val;
            insert_tail(head,val);
        }
        else if(op==2)
        {
            int pos,val;
            cin >> pos >> val;
            insert_pos(head,pos,val);
        }
        else if(op==3)
        {
            print_list(head);
        }
        else if(op==4)
        {
            break;
        }

    }

 
return 0;
}