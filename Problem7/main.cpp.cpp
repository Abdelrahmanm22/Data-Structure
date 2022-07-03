#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
};
int i;
Node *create()
{
    int l;
    Node *newnode;
    // allocate memory of int size to an int pointer
    newnode = (Node *) malloc(sizeof (Node));
    if(i==0)
    {
        cout<<"Enter data of root:";
        i++;
    }else{
        cout<<" (-1 for no node):";
    }

    cin>>l;
    if(l==-1)
    {
        return 0;
    }
    newnode->data=l;
    cout<<"Enter left child of "<<l;
    newnode->left=create();
    cout<<"Enter right child of "<<l;
    newnode->right=create();
    return newnode;
}
void flip(Node* node=NULL)
{
    if(node!=NULL)
    {
        Node *swap;

        flip(node->left);
        flip(node->right);

        swap = node->left;
        node->left =node->right;
        node->right = swap;
    }else{
        return;
    }
}
void preOrder(Node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
int main() {
    Node *root;
    root = NULL;
    root = create();
    cout<<"Print Tree Before flip it using preOrder(root-left-right): ";
    preOrder(root);
    cout<<endl;
    //flip();
    flip(root);

    cout<<"Print Tree After flip it using preOrder(root-left-right): ";
    preOrder(root);
    return 0;
}

