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

int depth;
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

void level_order(Node *root, int x)
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
            frq[level]=true;
            depth=level; 
        }
        if(node->left)
        q.push({node->left,level+1});
        if(node->right)
        q.push({node->right,level+1});
        if(depth==x){
            cout << node->val  << " ";
        }

    }
    if(x>depth)
    cout << "INVALID";

}

int main()
{
    Node* root=input_tree();
    int x;
    cin >> x;
    level_order(root,x);
 
return 0;
}