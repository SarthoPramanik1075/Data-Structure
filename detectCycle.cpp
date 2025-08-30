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
    node *newNode=new node(val);
    if(tail==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=tail->next;
    if(tail->next==NULL)
    { 
        return *head;
        return *tail;
    }
}

void detect_at_pos(node *head, node *tail)
{
    node *tmp=head;
    int index;
    cin >> index;

    for(int i=0;i<index;i++)
    {
        tmp=tmp->next;
    }
    tail->next=tmp;
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
            detect_at_pos(head,tail);
            break;
        }
        insert_tail(head,tail,val);
    }

    // node *head=new node(10);
    // node *a=new node(20);
    // node *b=new node(30);
    // node *c=new node(40);

    // head->next=a;
    // a->next=b;
    // b->next=c;
    // c->next=a;

    node *slow=head;
    node *fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
         if(slow==fast)
    {
        cout << "Cycle Detect";
        break;
    }
    }
   
 
return 0;
} 