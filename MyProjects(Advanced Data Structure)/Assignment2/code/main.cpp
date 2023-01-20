#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define N NULL
class Interval{
public:
    int lo,hi;
    Interval(Interval *i){
        this->lo=i->lo;
        this->hi=i->hi;
    }
    Interval(int low,int high){
        this->lo=low;
        this->hi=high;
    }
};
class Node{
public:
    Interval *myInterval;
//    int key;
    int height;
    int MAX;
    Node *left,*right;
  void inOrder(Node *root)
    {
        if (root == N) {
            return;
        }
        inOrder(root->left);
        std::cout << "[" << root->myInterval->lo << ", " << root->myInterval->hi << "]"
             << " max = " << root->MAX << "\n";
        inOrder(root->right);
    }
};
class AVl{
public:
//    Node Myroot;


    int getHeight(Node *myNode){
        if(myNode == N )return 0;
        return myNode->height;
    }
    Node *insertAtAvlTree(Interval interval,Node *myNode){
        //first case
        if(myNode==N)
        {
            //create new node
            Node *newNode = new Node();
            myNode->myInterval = new Interval(interval);
            newNode->MAX=interval.hi;
            newNode->right=N;
            newNode->left=N;
            return newNode;
        }

        //second case
        if(interval.lo<myNode->myInterval->lo){
            myNode->left = insertAtAvlTree(interval,myNode->left);
        }else if(interval.lo>myNode->myInterval->lo){
            myNode->right = insertAtAvlTree(interval,myNode->right);
        }else {
            return myNode;
        }

        if(getHeight(myNode->left)> getHeight(myNode->right)){
            myNode->height=getHeight(myNode->left)+1;
        }else{
            myNode->height=getHeight(myNode->right)+1;
        }

        int ourBalance=0;
        if(myNode!=N){
            ourBalance = getHeight(myNode->left)- getHeight(myNode->right);
        }

        //case 1(left Rotation)
        if(interval.lo> myNode->left->myInterval->lo and ourBalance<-1){
            return RotationToLeft(myNode);
        }

        //case 2(right Rotation)
        if(interval.lo< myNode->left->myInterval->lo and ourBalance>1){
            return RotationToRight(myNode);
        }
        //case 3(double Rotation ==>right then left)
        if(interval.lo< myNode->left->myInterval->lo and ourBalance>1){
            myNode->right= RotationToRight( myNode->right);
            return RotationToLeft(myNode);
        }

        //case 3(double Rotation ==>left then Right)
        if(interval.lo< myNode->left->myInterval->lo and ourBalance>1){
            myNode->left= RotationToLeft( myNode->left);
            return RotationToRight(myNode);
        }
        return myNode;

    }
    Node *RotationToLeft(Node *n)
    {
        Node *root =n->right;
        Node *temp = root->left;
        root->left=n;
        n->right=temp;

        if(getHeight(n->left)> getHeight(n->right)+1)
        {
            n->height=getHeight(n->left);
        }
        else
        {
            n->height=getHeight(n->right)+1;
        }

        if(getHeight(root->left)>getHeight(root->right)+1)
        {
            root->height=getHeight(root->left);
        }
        else
        {
            root->height=getHeight(root->right)+1;
        }
        return root;
    }
    Node *RotationToRight(Node *n){
        Node *root = n->left;
        Node *temp = root->right;
        root->right=n;
        n->left=temp;
        if(getHeight(n->left)> getHeight(n->right)+1)
        {
            n->height=getHeight(n->left);
        }
        else
        {
            n->height=getHeight(n->right)+1;
        }

        if(getHeight(root->left)>getHeight(root->right)+1)
        {
            root->height=getHeight(root->left);
        }
        else
        {
            root->height=getHeight(root->right)+1;
        }
        return root;
    }

};

int main()
{
    AVl *tree = new AVl();
    Node *root = NULL;
    root= tree->insertAtAvlTree(new Interval(15,20),root);
    root= tree->insertAtAvlTree(new Interval(10,30),root);
    root= tree->insertAtAvlTree(new Interval(17,19),root);
    root= tree->insertAtAvlTree(new Interval(5,20),root);
    root= tree->insertAtAvlTree(new Interval(12,15),root);
    root= tree->insertAtAvlTree(new Interval(30,40),root);
    root->inOrder(root);
    return 0;
}
