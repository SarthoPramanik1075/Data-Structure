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

void delete_head(node *&head, node *&tail)
{
    node *deleteNode=head;
    head=head->next;
    delete deleteNode;
    if(head==NULL)
    {
        tail=NULL;
        return;
    }
    head->prev=NULL;
}

void delete_tail(node *&tail)
{
    node *deleteNode=tail;
    tail=tail->prev;
    delete deleteNode;
    tail->next=NULL;
}

void print_list(node *head)
{
    node *tmp=head;
    while(tmp!=NULL)
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
        int val;
        cin >> val;
        if(val==-1)
        {
            break;
        }
        insert_tail(head,tail,val);
    }
    print_list(head);
    delete_head(head,tail);
    print_list(head);
    delete_tail(tail);
    print_list(head);
 
return 0;
}