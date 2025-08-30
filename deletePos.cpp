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

void insert_tail(node *&head,node *&tail,int val)
{
    node *newnode=new node(val);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    tail=tail->next;
}

void delete_head(node *&head)
{
    node *deleteNode=head;
    head=head->next;
    delete deleteNode;
}

void delete_pos(node *&head)
{
    int pos;
    cin >> pos;
    if(pos==0)
    {
        delete_head(head);
    }
    else
    {
        node *tmp=head;
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    node *deleteNode=tmp->next;
    tmp->next=tmp->next->next;
    delete deleteNode;
    }
    
}

void print_list(node *head)
{
    node *tmp=head;
   while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp=tmp->next;
    }

}

int main()
{
    node *head=NULL;
    node *tail=NULL;
    while(true)
    {
        int val;
        cin >> val;
        if(val==-1)
        {
            break;
        }
        insert_tail(head,tail,val);
    }
    cout << "Before Delete: ";
    print_list(head);
    cout << endl << endl;

    delete_head(head);
    cout << "Deleted Head: ";
    print_list(head);
    cout << endl << endl;

    delete_pos(head);
    cout << "After Delete: ";
    print_list(head);
return 0;
}