#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*left ,TreeNode*right):val(x),left(left),right(right){}
};
class Solution {
public:
    Solution(){};//default constructor
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) //check if the tree is empty and return that is symmetric
            return true;
        else
            return isSymmetric(root->left, root->right);//calling function to check if the tree symmetric
        //and return true if symmetric or false if not
    }

    bool isSymmetric(TreeNode *subtree1, TreeNode *subtree2){ //divide the tree into 2 subtrees
        if (subtree1== nullptr && subtree2== nullptr)//check if the subtrees is empty return symmetric
            return true;
        else if((subtree2->val!= subtree1->val)//return false after if the value of node not equal to the value in the opposite node
                ||(subtree1->left== nullptr && subtree2->right!= nullptr)//or if left in first null and right in second not null
                ||(subtree1->right== nullptr && subtree2->left!= nullptr)//or if right in first null and left in second not null
                ||(subtree2->left== nullptr && subtree1->right!= nullptr)//or if left in second null and right in first not null
                ||(subtree2->right== nullptr && subtree1->left!= nullptr))//or if right in second null and left in first not null
            return false;
        else
            return isSymmetric(subtree1->left, subtree2->right) &&
                   isSymmetric(subtree1->right, subtree2->left);//if the subtrees is not empty check them again and divide them again to check the
                                                                //left subtree and the right subtree and return true or false


    }
};
void createTree(TreeNode* node, int i, vector<string>& arr) {
    //left child of the node at index 2*i+1
    if (node != nullptr) {
        if (2 * i + 1 < arr.size()) {
            if (arr[2 * i + 1] == "null")//check if there is no left node
                node->left = nullptr;
            else
                node->left = new TreeNode(stoi(arr[2 * i + 1]));//convert value to integer then set this value
            createTree(node->left, 2 * i + 1, arr);//recursion start from left node
        }

        //right child of the node at index 2*i+2
        if (2 * i + 2 < arr.size()) {
            if (arr[2 * i + 2] == "null")//check if there is no right node
                node->right = nullptr;
            else
                node->right = new TreeNode(stoi(arr[2 * i + 2]));//convert value to integer then set this value
            createTree(node->right, 2 * i + 2, arr);//recursion start from right node
        }
    }
}


TreeNode* levelOrderCreateTree(vector<string>& arr) {
    if (arr.size() == 0)//check if no elements
        return nullptr;
    TreeNode* head = new TreeNode(stoi(arr[0]));//set root value
    createTree(head, 0, arr);
    return head;
}

int main() {
    //test case if input is array
    vector<string> arr;
    cout << "Enter the number of nodes of the Tree: ";
    int n;
    cin >> n;
    cout<<"Enter tree values\n";
    while (n--) {
        string num;
        cin >> num;
        arr.push_back(num);
    }
    Solution s;
    TreeNode *p = levelOrderCreateTree(arr);
    if (s.isSymmetric(p))
        cout << "True\n";//true if symmetric
    else
        cout << "False\n";//false in the other case


    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution test;
    if (test.isSymmetric(root))
        cout << "True\n";//true if symmetric
    else
        cout << "False\n";//false in the other case

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left=new TreeNode(NULL);
    root1->left->right = new TreeNode(3);
    root1->right->left=new TreeNode(NULL);
    root1->right->right = new TreeNode(3);
    if (test.isSymmetric(root1))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}