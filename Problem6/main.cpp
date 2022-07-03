#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string info;
    Node* left= nullptr;
    Node *right= nullptr;
    Node(string x){
        info=x;
    }
};
int convertToInt(string s) {
    int number = 0;
    if (s[0] == '-')  {  // if the number is negative -> ignore the sign and put the sign at the end
        for (int i = 1; i < s.length(); i++) {
            number = number * 10 + (int(s[i]) - 48);
        }
         number = number * (-1);
    }
    else {
        for (int i = 0; i < s.length(); i++) // if number is not negative
            number = number * 10 + (int(s[i]) - 48);
    }
    return number;
}
int eval(Node* root) {
    if (!root)  //if tree is empty
        return 0;

    if (!root->right && !root->left)
        return convertToInt(root->info);

    int leftValue = eval(root->left);

    int rightValue = eval(root->right);

    if (root->info == "+")
        return leftValue + rightValue;

    if (root->info == "*")
        return leftValue * rightValue;

    if (root->info == "-")
        return leftValue - rightValue;

    return leftValue / rightValue;
}
void test1(){
    string s="+ 3 * 4 / 8 2";
    cout<<"testcase 1: "<<s;
    Node *root = new Node("+");
    root->left = new Node("3");
    root->right = new Node("*");
    root->right->left = new Node("4");
    root->right->right = new Node("/");
    root->right->right->left = new Node("8");
    root->right->right->right = new Node("2");
    cout<<endl;
    cout <<"result= " << eval(root) << endl;
    delete(root);
}

void test2(){
    string t="- * + 2 2 3 10";
    cout<<"testcase 2: "<<t;
    Node *root = new Node("-");
    root->left = new Node("*");
    root->left->left = new Node("+");
    root->left->left->left = new Node("2");
    root->left->left->right = new Node("2");
    root->left->right = new Node("3");
    root->right = new Node("10");
    cout<<endl;
    cout <<"result= "<< eval(root) << endl;
    delete(root);
}
void test3(){
    string s="* + 3 4 / 7 6";
    cout<<"testcase 3: "<<s;
    Node *root = new Node("*");
    root->left = new Node("+");
    root->left->left=new Node("3");
    root->left->right=new Node("4");
    root->right = new Node("/");
    root->right->left = new Node("7");
    root->right->right = new Node("6");

    cout<<endl;
    cout <<"result= "<< eval(root) << endl;
    delete(root);
}
void test4(){
    string s="* + 3 4 - 6 4";
    cout<<"testcase 4: "<<s;
    Node *root = new Node("*");
    root->left = new Node("+");
    root->left->left = new Node("3");
    root->left->right = new Node("4");
    root->right=new Node("-");
    root->right->left = new Node("6");
    root->right->right = new Node("4");
    cout<<endl;
    cout <<"result= "<< eval(root) << endl;
    delete(root);
}
void test5(){
    string s="/ + * 4 1 5 9";
    cout<<"testcase 5: "<<s;
    Node *root = new Node("/");
    root->left = new Node("+");
    root->left->left = new Node("*");
    root->left->left->left = new Node("4");
    root->left->left->right = new Node("1");
    root->left->right = new Node("5");
    root->right = new Node("9");
    cout<<endl;
    cout <<"result= "<< eval(root) << endl;
    delete(root);
}
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
