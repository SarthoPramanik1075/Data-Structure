#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int val;
    node *next;
    node *prev;

    node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

void insert_tail(node *&head, node *&tail, int val)
{
    node *newNode=new node(val);
    if(tail==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=tail->next;
}

void insert_pos(node *head,node *tail, int pos, int val)
{
    if(pos==0)
    {
        insert_head(head,tail,val);
    }
    else
    {
node *newNode=new node(val);
    node *tmp=head;
    
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
//build by me
    newNode->next=tmp->next;
    tmp->next->prev=newNode;
    newNode->prev=tmp;
    tmp->next=newNode;

//build by phitron
    // newNode->next=tmp->next;
    // tmp->next=newNode;
    // newNode->next->prev=newNode;
    // newNode->prev=tmp;
    }
    
}

void insert_head(node *&head, node *&tail, int val)
{
    node *newNode=new node(val);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void print_list(node *head)
{
    node *tmp=head;
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp=tmp->next;
    }
    cout << endl;
}

int main()
{
    node *head=NULL;
    node *tail=NULL;

    while(true)
    {
        cout << endl << endl;
        cout << "Option 1: Insert at tail" << endl;
        cout << "Option 2: Insert at position" << endl;
        cout << "Option 3: Insert at head" << endl;
        cout << "Option 4: Print linked list" << endl;
        cout << "Option 5: Terminate" << endl;

         int op;
        cin >> op;

        if(op==1)
        {
            cout << "please enter the value: ";
            int val;
            cin >> val;
            insert_tail(head,tail,val);
        }
        else if(op==2)
        {
            int pos,val;
            cin >> pos >> val;
            insert_pos(head,tail,pos,val);
        }

        else if(op==3)
        {
            int val;
            cin >> val;
            insert_head(head,tail,val);
        }

        else if(op==4)
        {
            print_list(head);
        }

        else if(op==5)
        {
            break;
        }


    }
 
return 0;
}