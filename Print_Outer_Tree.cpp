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
vector<int>v1;
vector<int>v2;

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

void left_tree(Node* root)
{
    bool frq[100001]={false};
    queue< pair<Node*,int> >q;
    if(root)
    q.push({root,0});

    while(!q.empty())
    {
        pair<Node*,int> pr=q.front();
        q.pop();

        Node* node=pr.first;
        int level=pr.second;
        if(level!=0)
        {
       if(frq[level]==false)
        {
            v1.push_back(node->val);
            frq[level]=true;
        }
        }
        
        if(node->left)
        q.push({node->left,level+1});
        if(node->right)
        q.push({node->right,level+1});
    }
}

void right_tree(Node* root)
{
    bool frq[100001]={false};
    queue< pair<Node*,int> >q;
    if(root)
    q.push({root,0});

    while(!q.empty())
    {
        pair<Node*,int> pr=q.front();
        q.pop();

        Node* node=pr.first;
        int level=pr.second;

        if(frq[level]==false)
        {
            v2.push_back(node->val);
            frq[level]=true;
        }
        
        if(node->right)
        q.push({node->right,level+1});
        if(node->left)
        q.push({node->left,level+1});
    }
}
int main()
{
    Node* root=input_tree();
    left_tree(root);
    right_tree(root);

    for(int i=0;i<v1.size();i++)
    {
        cout << v1[i] << " ";
    }

    for(int i=0;i<v2.size();i++)
    {
        cout << v2[i] << " ";
    }
 
return 0;
}