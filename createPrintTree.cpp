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

// pre order traversal
// void preOrder(Node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     cout << root->val << " ";
//     preOrder(root->left);
//     preOrder(root->right);
// }

//post order traversal
//void postOrder(Node* root)
//{
//     if(root==NULL)
//     {
//         return;
//     }
//     postOrder(root->left);   
//     postOrder(root->right); 
//     cout << root->val << " ";    
// }

void inOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);

}

int main()
{
    Node* root=new Node(10);
    Node* a=new Node(20);
    Node* b=new Node(30);
    Node* c=new Node(40);
    Node* d=new Node(50);
    Node* e=new Node(60);
 // connection 
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;

    //preOrder(root);

    //postOrder(root);

    inOrder(root);
 
return 0;
}