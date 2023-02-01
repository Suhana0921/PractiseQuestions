#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
Node* create(int x){
  Node* temp=(Node*)malloc(sizeof(Node));
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
struct horizontal{
        Node* node;
        int hd;
    };
void topView(struct Node *root)
{
    horizontal temp;
    queue<horizontal>hr;
    map<int,int>m;
    map<int,int>::iterator it;
    temp.node=root;
    temp.hd=0;
    hr.push(temp);
    while(!hr.empty()){
        horizontal temp=hr.front();hr.pop();
        it=m.find(temp.hd);
        if(it==m.end()){
            cout<<temp.node->data<<" ";
            m.insert(pair<int,int>(temp.hd,(temp.node)->data));
        }
        if(temp.node->left!=NULL){
            horizontal n;
            n.node=(temp.node)->left;
            n.hd=(temp.hd)-1;
            hr.push(n);
        }
        if(temp.node->right!=NULL){
            horizontal n;
            n.node=(temp.node)->right;
            n.hd=(temp.hd)+1;
            hr.push(n);
        }
    }
}
int main(){
  Node* root=create(1);
  root->left=create(2);
  root->left->right=create(3);
  root->left->right->left=create(4);
  root->left->right->right=create(5);
  root->right=create(6);
  root->right->left=create(7);
  root->right->left->right=create(8);
  root->right->right=create(9);
  cout<<"Top view of the binary tree is: ";
  topView(root);
}
