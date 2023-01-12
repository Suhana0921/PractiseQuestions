#include<iostream> 
using namespace std;

typedef struct Node
{ 
  int data; 
  Node* left; 
  Node* right; 
}Node; 
Node* new_node(int );
void morris_preorder_traversal(Node*);
Node* find_preorder_predecessor(Node*);
int main() 
{ 
  Node* root = new_node(1); 
  root->left = new_node(2); 
  root->right = new_node(5); 
  root->left->left = new_node(3); 
  root->left->right = new_node(4);
  /* this input tree is shown in above figure */ 
  cout<<"Morris Preorder Traversal of the graph: ";
  morris_preorder_traversal(root);
  
  return 0; 
} 

Node* new_node(int data) 
{ 
  Node* node = new Node; 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return node; 
}
Node* find_preorder_predecessor(Node* root)
{
  Node* curr=root->left; 
  while (curr->right && curr->right != root) 
    curr=curr->right; 
  
  return curr;
}
void morris_preorder_traversal(Node* root) 
{ 
  while (root) 
  { 
    if (root->left==NULL) 
    { 
      cout<<root->data<<" "; 
      root=root->right; 
    } 
    else
    { 

      Node* curr=find_preorder_predecessor(root);

      if (curr->right == root) 
      { 
        curr->right = NULL; 
        root=root->right; 
      } 
      else
      { 
        cout<<root->data<<" "; 
        curr->right = root; 
        root = root->left; 
      } 
    } 
  } 
}
