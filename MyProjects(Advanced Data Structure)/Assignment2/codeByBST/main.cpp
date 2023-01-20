#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define N NULL
// to implementation of everything.
/// class for represent an interval [lo,hi] consists of range between low and high inclusive
class Interval{
public:
    int lo,hi;//interval [lo,hi] consists of range between low and high inclusive
    Interval()//default constructor
    {
        lo = 0;
        hi = 0;
    }
    Interval(Interval *i)//constructor take interval as a parameter
    {
        this->lo=i->lo;
        this->hi=i->hi;
    }
    Interval(int low,int high) //constructor take low and high as a parameter
    {
        this->lo=low;
        this->hi=high;
    }
    void toString() //overriding function to string to print low and high
    {
        std::cout<<"low:"<<lo<<", high"<<hi<<"\n";
    }
};
///class for represent a node in interval search tree
class Node{
public:
    Interval *myInterval; //to access low ,high
    int MAX; //max attribute which equals to the maximum high of all intervals stored in the subtree rooted at node.
    Node *left,*right;
};
///For simplicity, the underlying binary search tree structure must be your implementation of an unbalanced binary search tree.
class BSTUnBalanced{
public:
    Node *Myroot;
    BSTUnBalanced()
    {
        Myroot = N;
    }
    //function to insert node in Binary search tree
    Node *insertAtAvlTree(Interval interval,Node *myNode)
    {
        //first case if tree is empty
        if(myNode==N)
        {
            //create new node with insert new interval
            myNode =new Node();
            myNode->myInterval = new Interval(interval);
            myNode->MAX=interval.hi;
            myNode->right=N;
            myNode->left=N;
            //create new node with insert new interval
            return myNode;//then return the node
        }

        //second case ==>recurrence down the tree
        if(interval.lo<myNode->myInterval->lo) // in BST if newkey less than key of node ==>go to left
        {
            myNode->left = insertAtAvlTree(interval,myNode->left);
        }else if(interval.lo>myNode->myInterval->lo)//in BST if newkey greater than key of node ==>go to right
        {
            myNode->right = insertAtAvlTree(interval,myNode->right);
        }

        if(myNode->MAX<interval.hi)//to update MAX
        {
            myNode->MAX = interval.hi;
        }

        return myNode;//then return node
    }
    void insert(Interval i) //function to call insertAtAvlTree from main
    {
        Myroot = insertAtAvlTree(i, Myroot);
    }
    //function to delete node in Binary search tree
    Node* deleteNode(Node* root, Interval i)
    {
        //first case if tree is empty
        if (root == NULL)
            return root;

        // Recursive calls for ancestors of
        // node to be deleted ==>if interval=>low to be deleted is smaller than the root's key, then it lies in left subtree
        if (root->myInterval->lo > i.lo)
        {
            root->left = deleteNode(root->left, i);
            return root;
        }
        else if (root->myInterval->lo < i.lo)// node to be deleted ==>If the key to be deleted is greater than the root's key, then it lies in right subtree
        {
            root->right = deleteNode(root->right, i);
            return root;
        }

        // We reach here when root is the node
        // to be deleted.
        // If one of the children is empty
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // If both children exist
        else {

            Node* successor = root;

            // Find successor
            Node* succ = root->right;
            while (succ->left != NULL) {
                successor = succ;
                succ = succ->left;
            }

            // Delete successor.  Since successor
            // is always left child of its parent
            // we can safely make successor's right
            // right child as left of its parent.
            // If there is no succ, then assign
            // succ->right to succParent->right
            if (successor != root)
                successor->left = succ->right;
            else
                successor->right = succ->right;

            // Copy Successor Data to root
            root->myInterval = succ->myInterval;

            // Delete Successor and return root
            delete succ;
            return root;
        }
    }
    //Given a binary tree, print its nodes according to the "bottom-up" postorder traversal.
    void printPostorder(Node *root)
    {
        if (root == N) {
            return;
        }
        printPostorder(root->left);
        printPostorder(root->right);
        std::cout << "[" << root->myInterval->lo << ", " << root->myInterval->hi << "]"
                  << " max = " << root->MAX << "\n";
    }
    //function to call printPostorder from main
    void postOrder() { printPostorder(Myroot); }
    //function  SearchInterval must return all intervals overlapping with the parameter interval, by first getting one overlapping interval, then deleting it, and so on. Then, all such intervals must be inserted again in the tree to restore its status.
    void DoOverlapSearch(Interval myInterval,Node *myNode, Interval intervals[], int &counter)// parameter (counter) as index to
    {
        //first case ==>if tree is empty
        if(myNode==N)
            intervals[counter]=N;

        if((myNode->myInterval)->lo<=myInterval.hi && myInterval.lo<=(myNode->myInterval)->hi)//to check if given two intervals overlap
        {
            //If given interval overlaps with root
            intervals[counter] = myNode->myInterval;//store interval in array
            counter++;
        }
        if(myNode->left != N && myNode->right != N)
        {
            // If left child of root is present and max of left child is greater than or equal to given interval, then i may overlap with an interval is left subtree
            if(myInterval.lo>myNode->left->MAX)
                DoOverlapSearch(myInterval, myNode->right, intervals, counter);
            else
            {
                DoOverlapSearch(myInterval, myNode->left, intervals, counter);
                DoOverlapSearch(myInterval, myNode->right, intervals, counter);
            }
        }
        //else interval can overlap with right subtree
        else if(myNode->left != N)
            DoOverlapSearch(myInterval, myNode->left, intervals, counter);
        else if (myNode->right != N)
            DoOverlapSearch(myInterval, myNode->right, intervals, counter);
    }
    //function to call DoOverlapSearch in main
    void search(Interval *i, Interval intervals[]){
        int counter =0;
        //we pass parameter (counter = 0) every one
        DoOverlapSearch(i,Myroot, intervals, counter);
    }
    //function to call deleteNode in main
    Interval *deleteInterval(Interval i){
        Myroot = deleteNode(Myroot, i);
        return Myroot->myInterval;
    }
};


int main() {
    std::cout<<"First Tree: \n";
    BSTUnBalanced *tree= new BSTUnBalanced();

    tree->insert(new Interval (15,20));
    tree->insert(new Interval (10,30));
    tree->insert(new Interval (17,19));
    tree->insert(new Interval (5,20));
    tree->insert(new Interval (12,15));
    tree->insert(new Interval (30,40));

    tree->postOrder();

    Interval intervals[6];

    Interval *interval;
    //interval = new Interval(30,50);
    //interval = new Interval(17,19);
    //interval = new Interval(6,7);
    //interval = new Interval(6,12);
//    interval = new Interval(0,27);
//    interval = new Interval(31,50);
//    interval = new Interval(7,16);
//    interval = new Interval(35,55);
//    interval = new Interval(19,20);
    interval = new Interval(22,44);


    tree->search(interval, intervals);
    std::cout<<"Searching for interval ["<<interval->lo<<", "<<interval->hi<<"]";
    int i=0;

    while (intervals[i].hi!= N){
        std::cout << "\nOverlaps with [" << intervals[i].lo << ", " << intervals[i].hi << "]";
        tree->deleteInterval(intervals[i]);
        i++;
    }
    if(i==0){
        std::cout << "\nNo Overlapping Interval";
    }
    //std::cout << "\n After Deletion \n";
    //tree->postOrder();

    i=0;
    std::cout << "\n";
    while (intervals[i].hi!= N){
        tree->insert(intervals[i]);
        i++;
    }
    //std::cout << "\n After Insertion \n";
    //tree->postOrder();
    std::cout<<"\n\nSecond Tree: \n";
    BSTUnBalanced *tree2= new BSTUnBalanced();

    tree2->insert(new Interval (19,22)); //<==
    tree2->insert(new Interval (10,11));
    tree2->insert(new Interval (27,35));//<==
    tree2->insert(new Interval (7,10));
    tree2->insert(new Interval (15,21));//<==
    tree2->insert(new Interval (20,21));//<==
    tree2->insert(new Interval (25,30));//<==
    tree2->insert(new Interval (0,4));
    tree2->insert(new Interval (8,13));
    tree2->postOrder();
    Interval intervals2[9];
    Interval *interval1;
//interval1 = new Interval(30,50);
//    interval1 = new Interval(17,19);
//    interval1 = new Interval(6,7);
//    interval1 = new Interval(6,12);
//    interval1 = new Interval(0,27);
//    interval1 = new Interval(31,50);
//    interval1 = new Interval(7,16);
//    interval1 = new Interval(35,55);
    interval1 = new Interval(50,60);
//    interval1 = new Interval(22,44);
    tree2->search(interval1, intervals2);
    std::cout<<"Searching for interval ["<<interval1->lo<<", "<<interval1->hi<<"]";
     i=0;

    while (intervals2[i].hi!= N){

        std::cout << "\nOverlaps with [" << intervals2[i].lo << ", " << intervals2[i].hi << "]";
        tree2->deleteInterval(intervals2[i]);
        i++;
    }
    if(i==0) {
        std::cout << "\nNo Overlapping Interval";
    }
    i=0;
    std::cout << "\n";
    while (intervals2[i].hi!= N){
        tree2->insert(intervals2[i]);
        i++;
    }




    std::cout<<"\n\nThird Tree: \n";
    BSTUnBalanced *tree3= new BSTUnBalanced();

    tree3->insert(new Interval (20,36)); //<==
    tree3->insert(new Interval (3,41));
    tree3->insert(new Interval (29,99));//<==
    tree3->insert(new Interval (0,1));
    tree3->insert(new Interval (10,15));//<==

    tree3->postOrder();
    Interval intervals3[5];
    Interval *interval2;
//interval2 = new Interval(30,50);
//    interval2 = new Interval(17,19);
//    interval2 = new Interval(6,7);
//    interval2 = new Interval(6,12);
//    interval2 = new Interval(0,27);
//    interval2 = new Interval(31,50);
//    interval2 = new Interval(7,16);
//    interval2 = new Interval(35,55);
//    interval2 = new Interval(50,60);
    interval2 = new Interval(28,99);
    tree3->search(interval2, intervals3);
    std::cout<<"Searching for interval ["<<interval2->lo<<", "<<interval2->hi<<"]";
    i=0;

    while (intervals3[i].hi!= N){

        std::cout << "\nOverlaps with [" << intervals3[i].lo << ", " << intervals3[i].hi << "]";
        tree3->deleteInterval(intervals3[i]);
        i++;
    }
    if(i==0) {
        std::cout << "\nNo Overlapping Interval";
    }
    i=0;
    std::cout << "\n";
    while (intervals3[i].hi!= N){
        tree3->insert(intervals3[i]);
        i++;
    }
    return 0;
}
