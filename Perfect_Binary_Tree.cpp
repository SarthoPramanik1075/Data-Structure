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

vector<int>v;
int depth;

Node *input_tree()
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
    {
        q.push(root);
        v.push_back(root->val);
    }
    

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
        {
            myleft=new Node(l);
            v.push_back(myleft->val);
        }
        

        if(r==-1)
        myright=NULL;
        else
        {
           myright=new Node(r);
           v.push_back(myright->val);
        }
        

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

void level_order(Node *root)
{
    bool frq[100001]={false};
    queue<pair<Node*,int> >q;
    if(root)
    q.push({root,1});

    while(!q.empty())
    {
        pair<Node*,int> pr=q.front();
        q.pop();
        Node* node=pr.first;
        int level=pr.second;
        

        if(frq[level]==false)
        {
           // v.push_back(node->val);
            frq[level]=true;
            depth=level;
        }


        if(node->left)
        q.push({node->left,level+1});
        if(node->right)
        q.push({node->right,level+1});
    }
    
}
int main()
{
    Node *root=input_tree();
    level_order(root);

    int ans=pow(2,depth)-1;
    int sz=v.size();
    if(ans==sz)
    {
        cout << "YES" << endl;
    }
    else
    cout << "NO" << endl;

  
return 0;
}