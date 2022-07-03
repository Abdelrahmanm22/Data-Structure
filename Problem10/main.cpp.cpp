#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* right;
    Node* left;
};

struct Node *setNewNode(int val){
    Node * newNode = new Node;
    newNode->value = val;
    newNode->right = nullptr;
    newNode->left = nullptr;

    return newNode;
}

struct Node * insert(struct Node *root, int val){
    if (!root)     //if tree is empty
        return setNewNode(val);

    if (val > root->value )
        root->right = insert(root->right, val);

    else if (val < root->value )
        root->left = insert(root->left, val);

    return root;
}

int smallest_k_sum( struct Node *root, int k, int & cnt){
    if (!root)    
        return 0;
    if (cnt > k)
        return 0;

    int sum = smallest_k_sum(root->left, k, cnt);
    if (cnt == k)
        return sum;

    sum += root->value;

    cnt++;
    if (cnt >= k)
        return sum;

    return sum + smallest_k_sum(root->right, k, cnt);
}

int smallest_k(struct Node *root, int k){
    int cnt = 0;
    smallest_k_sum(root, k, cnt);
}

int main(){
    Node *root = nullptr;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 22);
    root = insert(root, 25);

    cout <<  smallest_k(root, 3) <<endl;
    cout<<"---------"<<endl;

    Node *root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 8);
    root1 = insert(root1, 9);
    root1 = insert(root1, 15);
    root1 = insert(root1, 20);

    cout <<  smallest_k(root1, 2) <<endl;

    cout<<"---------"<<endl;

    Node *root2 = nullptr;
    root2 = insert(root2, 100);
    root2 = insert(root2, 81);
    root2 = insert(root2, 9);
    root2 = insert(root2, 15);
    root2 = insert(root2, 20);
    root2 = insert(root2, 55);
    root2 = insert(root2, 80);
    root2 = insert(root2, 22);
    root2 = insert(root2, 30);
    root2 = insert(root2, 44);

    cout <<  smallest_k(root2, 4) <<endl;

    cout<<"---------"<<endl;

    Node *root3 = nullptr;
    root3 = insert(root3, 8);
    root3 = insert(root3, 9);
    root3 = insert(root3, 15);


    cout <<  smallest_k(root3, 4) <<endl;
    cout<<"---------"<<endl;

    Node *root4 = nullptr;
    root4 = insert(root4, 1);
    root4 = insert(root4, 5);
    root4 = insert(root4, 15);
    root4 = insert(root4, 85);
    root4 = insert(root4, 90);
    root4 = insert(root4, 55);


    cout <<  smallest_k(root4,3)<<endl;
    return 0;
}

