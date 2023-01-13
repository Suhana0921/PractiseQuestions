#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *left, *right;
};
class Tree
{
    public:
        struct node *root;
        struct node *createnode(int key);
        void PostOrder(struct node *root);
        Tree()
        {
            root = NULL;
        }
};

struct node* Tree :: createnode(int key)
{
    struct node *newnode = new node;
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}

void Tree :: PostOrder(struct node *root)
{
     if(root != NULL)
     {
          PostOrder(root->left);
          PostOrder(root->right);
          cout<<root->info<<" ";
     }
}

int main()
{
    Tree t;
    struct node *newnode = t.createnode(25);
    newnode->left = t.createnode(27);
    newnode->right = t.createnode(19);
    newnode->left->left = t.createnode(17);
    newnode->left->right = t.createnode(91);
    newnode->right->left = t.createnode(13);
    newnode->right->right = t.createnode(55);
 

    cout<<"Post Order Traversal of  tree 1 is \n";
    t.PostOrder(newnode);

    struct node *node = t.createnode(1);
    node->right = t.createnode(2);
    node->right->right = t.createnode(3);
    node->right->right->right = t.createnode(4);
    node->right->right->right->right = t.createnode(5);
 

    cout<<"\n\nPost Order Traversal  of tree 2 is\n" ;
    t.PostOrder(node);
 
    struct node *root = t.createnode(15);
 
    cout<<"\n\nPost Order traversal of tree 3 is\n";
    t.PostOrder(root);
    return 0;
}
