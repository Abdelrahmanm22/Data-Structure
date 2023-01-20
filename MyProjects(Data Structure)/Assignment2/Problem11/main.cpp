#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//----------------------------prototypes-----------------------------------
template <class t> class BSTNode;

template <class t> class BSTFCI;

template <class t>
int checkHeightBalance(BSTNode<t>* node);
template <class t>
bool isBalance( BSTNode<t> *root);



template<class t>
bool   isSameTree(BSTNode<t> *p, BSTNode<t> *q);
template<class t>
bool isSubTree(BSTNode<t> *tree1, BSTNode<t> *tree2);



template<class t>
void Range(int num1,int num2,BSTNode<t> *root);
//----------------------------prototypes-----------------------------------





template<class t>
class BSTNode
{
public:
    t data;
    BSTNode* right,* left;
};

//class with all used functions .
template<class t>
class BSTFCI
{
public:
    BSTNode<t>* root;
public:
    BSTFCI()
    {
        root = NULL;
    }




    BSTNode<t>* AddNode(t item, BSTNode<t>* node)
    {
        ///create root...
        if (node == NULL)
        {
            node = new BSTNode<t>;
            node->data = item;
            node->left = node->right = NULL;
        }
///if given data > parent data, we put it at right
        else if (item > node->data)
            node->right = AddNode(item, node->right);

///if given data < parent data, we put it at left
        else if (item < node->data)
            node->left = AddNode(item, node->left);

        return node;
    }

    //to access at main and pass root
    void makeNode(t item)
    {
        root = AddNode(item, root);
    }

    ///Pre-order (print root -> left -> right)
    void preOrder(BSTNode<t> *p)
    {
        if(p!=NULL)
        {
            cout<<p->item<<" ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }



///May error declaration of 't' shadows template parameter
//------------------------------------------------- Checking Tree Balance-------------------------------------------
    //The function Compute the "height" of a tree. Height is the number of nodes along the longest path from the root node down to the farthest leaf node.
    int checkHeightBalance(BSTNode<t>* node);

    //Function returns true if BST balanced.
    bool isBalance( BSTNode<t> *root);
//------------------------------------------------- Checking Tree Balance----------------------------








//--------------------------function that decides if a BSTFCI T2 is a subtree of another BSTFCI T1---------
    bool   isSameTree(BSTNode<t> *p, BSTNode<t> *q);
    bool isSubTree(BSTNode<t> *tree1, BSTNode<t> *tree2);
//--------------------------function that decides if a BSTFCI T2 is a subtree of another BSTFCI T1---------





//prints in sorted order all
//records whose key values fall between the two given keys.
    void displayRange(int num1,int num2,BSTNode<t> *root);

};

//------------------------------------------------- Checking Tree Balance implementation-------------------------------------------
template<class t>
int checkHeightBalance(BSTNode<t>* node)
{

    if(node == NULL)
        return 0;
    else{
        int x = 1 + max(checkHeightBalance(node->left),checkHeightBalance(node->right));
        return x;
    }
}

//Function returns true if BST balanced.
template<class t>
bool isbalanced( BSTNode<t> *root)
{
    int lefthight,righthight;

    if(root == NULL)
        return 1;
    lefthight = checkHeightBalance(root->left);
    righthight = checkHeightBalance(root->right);
    //difference between left and right must be between 1 and -1
    int d = lefthight - righthight;
    // d must be in range {-1,0,1}
    if( (d >= -1 && d<= 1) && isbalanced(root->left) && isbalanced(root->right))
        return 1;
    //otherwise tree not balanced
    return 0;
}
//------------------------------------------------- Checking Tree Balance implementation-------------------------------------------









//--------------------------function that decides if a BSTFCI T2 is a subtree of another BSTFCI T1---------

template<class t>
bool isSameTree(BSTNode<t> *r1, BSTNode<t> *r2) {
    if (r1 == NULL && r2 == NULL) {
        return true;
    }

    if (r1 == NULL || r2 == NULL) {
        return false;
    }

    return (r1->data == r2->data &&
            isSameTree(r1->left, r2->left) &&
            isSameTree(r1->right, r2->right));
}
template<class t>
bool isSubTree(BSTNode<t> *tree, BSTNode<t> *subTree)
{
    if (subTree == NULL)
        return true;

    if (tree == NULL)
        return false;

    if (isSameTree(tree, subTree))
        return true;

    if(isSubTree(tree->left, subTree) or isSubTree(tree->right, subTree))
    {
        return 1;
    }else
    {
        return 0;
    }
}
//--------------------------function that decides if a BSTFCI T2 is a subtree of another BSTFCI T1---------




template<class t>
void Range(int num1,int num2,BSTNode<t> *root)
{
    ///Step 1 : Compare the root node with the k1 and k2.

    if(NULL == root)
    {
        return;
    }
    ///Step 2 : If root is greater than k1. Call left subtree for the search recursively.
    if(root->data >num1)
    {
        Range(num1,num2,root->left);
    }


    ///Step 3 : If root is smaller than k2. Call right subtree for the search recursively.
    if(root->data <num2)
    {
      Range(num1,num2,root->right);
    }
    ///Step 4 : If the root of the tree is in the range. Then print the root’s value.
    if(root->data >= num1 and root->data<= num2)
    {
        cout<<root->data<<" ";
    }



}



int main() {
    BSTFCI <int> * t1 = new BSTFCI <int>();
    t1 ->makeNode(5);
    t1 ->makeNode(7);
    t1 ->makeNode(3);
    t1 ->makeNode(2);
    t1 ->makeNode(4);
    t1 ->makeNode(9);
    t1 ->makeNode(1);
    t1 ->makeNode(8);
    t1 ->makeNode(10);
    if(isbalanced(t1->root))
    {
        cout<<"Balanced\n";
    }else{
        cout<<"NotBalanced\n";
    }

    cout<<endl<<endl;

    BSTFCI <int> * test3 = new BSTFCI <int>();
    test3 ->makeNode(5);
    test3 ->makeNode(7);
    test3 ->makeNode(3);
    test3 ->makeNode(2);
    test3 ->makeNode(4);
    test3 ->makeNode(6);
    test3 ->makeNode(8);
    if(isbalanced(test3->root))
    {
        cout<<"Balanced\n";
    }else{
        cout<<"NotBalanced\n";
    }

    cout<<endl<<endl;

    BSTFCI <int> * test2 = new BSTFCI <int>();
    test2 ->makeNode(1);
    test2 ->makeNode(2);
    test2 ->makeNode(3);
    test2 ->makeNode(4);
    test2 ->makeNode(5);
    test2 ->makeNode(6);

    if(isbalanced(test2->root))
    {
        cout<<"Balanced\n";
    }else{
        cout<<"NotBalanced\n";
    }

    cout<<endl<<endl;
    BSTFCI <int> * test4 = new BSTFCI <int>();
    test4 ->makeNode(1);
    test4 ->makeNode(2);
    test4 ->makeNode(3);
    test4 ->makeNode(4);
    test4 ->makeNode(5);

    if(isbalanced(test4->root))
    {
        cout<<"Balanced\n";
    }else{
        cout<<"NotBalanced\n";
    }

    cout<<endl<<endl;
    BSTFCI <int> * test5 = new BSTFCI <int>();
    test5 ->makeNode(8);
    test5 ->makeNode(13);
    test5 ->makeNode(3);
    test5 ->makeNode(1);
    test5 ->makeNode(15);
    test5 ->makeNode(10);

    if(isbalanced(test5->root))
    {
        cout<<"Balanced\n";
    }else{
        cout<<"NotBalanced\n";
    }

    cout<<endl<<endl;

    BSTFCI <int> * t2 = new BSTFCI <int>();

    cout<<"\nCase for SubTree------:\n";
    cout<<"Enter Values of parent Tree: ";
    int x;
    for (int i = 0; i < 9; ++i) {
        cin>>x;
        t2->makeNode(x);
    }
    BSTFCI <int> * t3 = new BSTFCI <int>();
    cout<<"Enter Values of subTree: ";
    for (int i = 0; i < 3; ++i) {
        cin>>x;
        t3->makeNode(x);
    }
    isSubTree(t2->root, t3->root)? cout << "Found\n": cout << "NotFound\n";

    BSTFCI <int> * t4 = new BSTFCI <int>();

    cout<<"Case for SubTree------:\n";
    cout<<"Enter Values of parent Tree: ";
    int num;
    for (int i = 0; i < 9; ++i) {
        cin>>num;
        t4->makeNode(num);
    }
    BSTFCI <int> * t5 = new BSTFCI <int>();
    cout<<"Enter Values of subTree: ";
    for (int i = 0; i < 4; ++i) {
        cin>>num;
        t5->makeNode(num);
    }
    /*isSubTree(t4->root, t5->root)? cout << "Found\n": cout << "NotFound\n";

    BSTFCI <int> * t6 = new BSTFCI <int>();

    cout<<"Case for SubTree------:\n";
    cout<<"Enter Values of parent Tree: \n";
    int n;
    for (int i = 0; i < 9; ++i) {
        cin>>n;
        t6->makeNode(n);
    }
    BSTFCI <int> * t7 = new BSTFCI <int>();
    cout<<"Enter Values of subTree: \n";
    for (int i = 0; i < 3; ++i) {
        cin>>n;
        t7->makeNode(n);
    }
    isSubTree(t6->root, t7->root)? cout << "Found\n": cout << "NotFound\n";

    BSTFCI <int> * t8 = new BSTFCI <int>();

    cout<<"Case for SubTree------:\n";
    cout<<"Enter Values of parent Tree: \n";
    int y;
    for (int i = 0; i < 9; ++i) {
        cin>>y;
        t8->makeNode(y);
    }
    BSTFCI <int> * t9 = new BSTFCI <int>();
    cout<<"Enter Values of subTree: \n";
    for (int i = 0; i < 3; ++i) {
        cin>>y;
        t9->makeNode(y);
    }
    isSubTree(t8->root, t9->root)? cout << "Found\n": cout << "NotFound\n";

    BSTFCI <int> * t10 = new BSTFCI <int>();

    cout<<"Case for SubTree------:\n";
    cout<<"Enter Values of parent Tree: \n";
    int yy;
    for (int i = 0; i < 9; ++i) {
        cin>>yy;
        t10->makeNode(yy);
    }
    BSTFCI <int> * t11 = new BSTFCI <int>();
    cout<<"Enter Values of subTree: \n";
    for (int i = 0; i < 3; ++i) {
        cin>>yy;
        t11->makeNode(yy);
    }
    isSubTree(t10->root, t11->root)? cout << "Found\n": cout << "NotFound\n";*/


    int a,b;
    cout<<"Enter two Keys to print range: ";cin>>a>>b;
    Range(a,b,t1->root);
    cout<<"\n";
    int c,d;
    cout<<"Enter two Keys to print range: ";cin>>c>>d;
    Range(c,d,test2->root);
    cout<<"\n";
    int e,f;
    cout<<"Enter two Keys to print range: ";cin>>e>>f;
    Range(e,f,test3->root);
    cout<<"\n";
    int g,h;
    cout<<"Enter two Keys to print range: ";cin>>g>>h;
    Range(g,h,test4->root);
    cout<<"\n";
    int r,rr;
    cout<<"Enter two Keys to print range: ";cin>>r>>rr;
    Range(r,rr,test5->root);

    return 0;
}
