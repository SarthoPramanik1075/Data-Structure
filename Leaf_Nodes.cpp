#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
      int val;
      Node* left;
      Node* right;
 
  Node(int val)
   {
       this->val=val;
       this->left=NULL;
       this->right=NULL;
   }
};

Node* input_tree()
{
    int val;
    cin >> val;
    Node* root;
    if(val==-1)
    root=NULL;
    else
    root=new Node(val);

    queue<Node*>q;
    if(root)
    q.push(root);

    while(!q.empty())
    {
        Node* f=q.front();
        q.pop();

        int l,r;
        cin >> l >> r;
        Node *myleft, *myright;

        if(l==-1)
        myleft=NULL;
        else
        myleft=new Node(l);

        if(r==-1)
        myright=NULL;
        else
        myright=new Node(r);

        f->left=myleft;
        f->right=myright;

        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }

    }
   return root;
}

vector<int>v;
void level_order(Node *root)
{
    queue<Node*>q;
    if(root)
    q.push(root);

    while(!q.empty())
    {
        Node* p=q.front();
        q.pop();
        if(p->left==NULL && p->right==NULL)
        {
            v.push_back(p->val);
        }
        if(p->left)
        q.push(p->left);
        if(p->right)
        q.push(p->right);
    }
}
int main()
{
    Node *root=input_tree();
    level_order(root);
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
 
return 0;
}