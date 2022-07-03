/*  name: Ahmed said   id : 20200017
    name: Aya mohamed mounir id: 20200107 
    name: Shrouk ayman ali id: 20200251
    name: Abdelrahman mohamed id: 20200293
    name: Weam samy taie id: 20200627
*/
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution {
public:
    Solution(){};//default constructor
    bool isFolable(TreeNode *root) {
        if (root == nullptr) //check if the tree is empty and return that is folable
            return true;
        else
            return isFolable(root->left, root->right);//calling function to check if the tree folable
        //and return true if folable or false if not
    }

    bool isFolable(TreeNode *subtree1, TreeNode *subtree2){ //divide the tree into 2 subtrees
        if (subtree1== nullptr && subtree2== nullptr)//check if the subtrees is empty return folable
            return true;
        else if((subtree1->left== nullptr && subtree2->right!= nullptr)//or if left in first null and right in second not null
                ||(subtree1->right== nullptr && subtree2->left!= nullptr)//or if right in first null and left in second not null
                ||(subtree2->left== nullptr && subtree1->right!= nullptr)//or if left in second null and right in first not null
                ||(subtree2->right== nullptr && subtree1->left!= nullptr))//or if right in second null and left in first not null
            return false;
        else
            return isFolable(subtree1->left, subtree2->right) &&
                   isFolable(subtree1->right, subtree2->left);//if the subtrees is not empty check them again and divide them again to check the
        //left subtree and the right subtree and return true or false


    }
};

int main() {
    //Test case1->>>>>Folable
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(3);
    Solution test;
    if (test.isFolable(root))
        cout << "Folable\n";//true if symmetric
    else
        cout << "Not Folable\n";//false in the other case

    //Test case2->>>>>Folable
    root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->right->right = new TreeNode(5);
    if (test.isFolable(root))
        cout << "Folable\n";
    else
        cout << "Not Folable\n";

    //Test case3->>>>>Not Folable
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(6);
    root->right->right = new TreeNode(5);
    if (test.isFolable(root))
        cout << "Folable\n";
    else
        cout << "Not Folable\n";

    //Test case4->>>>>Folable
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(7);
    root->right->right = new TreeNode(5);
    if (test.isFolable(root))
        cout << "Folable\n";
    else
        cout << "Not Folable\n";

    //Test case5->>>>>Not Folable
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->left->left->left=new TreeNode(1);
    root->right->right = new TreeNode(9);
    root->right->right->left=new TreeNode(8);
    root->right->right->right=new TreeNode(10);
    if (test.isFolable(root))
        cout << "Folable\n";
    else
        cout << "Not Folable\n";
    return 0;
}
