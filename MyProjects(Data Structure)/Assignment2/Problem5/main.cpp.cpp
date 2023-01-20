/*  name: Ahmed said   id : 20200017
    name: Aya mohamed mounir id: 20200107 
    name: Shrouk ayman ali id: 20200251
    name: Abdelrahman mohamed id: 20200293
    name: Weam samy taie id: 20200627
*/

#include <iostream>
using namespace std;
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {

    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

    }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),right(right) {
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

class Solution {
public:

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) { //if two trees are empty returns are same
            return true;
        }

        if (p == nullptr || q == nullptr) {//if only one of them empty returns not same
            return false;
        }
        //else check the first value pointer to it
        return (p->val == q->val &&
                isSameTree(p->left, q->left) &&//with recursion in left node
                isSameTree(p->right, q->right));//with recursion in right node
    }
};
int main() {

//test case if input is array
    vector<string> arr;
    cout << "Enter the number of nodes of the first Tree: ";
    int n;
    cin >> n;
    cout<<"Enter tree values\n";
    while (n--) {
        string num;
        cin >> num;
        arr.push_back(num);
    }
    TreeNode *p = levelOrderCreateTree(arr);

    cout << "Enter the number of nodes of the Second Tree: ";
    vector<string> arr1;
    cin >> n;
    cout<<"Enter tree values\n";
    while (n--) {
        string num;
        cin >> num;
        arr1.push_back(num);
    }
    TreeNode *q = levelOrderCreateTree(arr1);

    Solution s;
    if (s.isSameTree(p, q))
        cout << "Same Tree\n";
    else
        cout << "Not same tree\n";


        Solution ss;
    // test  1
    TreeNode* root1= new TreeNode(1);
    TreeNode* root2= new TreeNode(1);

    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);
    if(ss.isSameTree(root1,root2)){
        cout<<"Same Tree\n";
    }
    else{
        cout<<"Not identical \n";
    }
        //test 2 left node different
    TreeNode* root3= new TreeNode(1);
    TreeNode* root4= new TreeNode(1);

    root3->left=new TreeNode(2);

    root4->left=new TreeNode(NULL);
    root4->right=new TreeNode(2);
    Solution sss;
    if(sss.isSameTree(root3,root4)){
        cout<<"Same Tree\n";
    }
    else{
        cout<<"Not Same Tree\n";
    }

    //test 3
    TreeNode* root5= new TreeNode(1);
    TreeNode* root6= new TreeNode(1);

    root5->left=new TreeNode(2);
    root5->right=new TreeNode(1);
    root6->left=new TreeNode(1);
    root6->right=new TreeNode(2);
    Solution ssss;
    if(ssss.isSameTree(root5,root6)){
        cout<<"Same Tree\n";
    }
    else{
        cout<<"Not Same Tree\n";
    }

}
