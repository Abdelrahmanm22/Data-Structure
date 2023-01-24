# Data_Structures_Implementation


***************************************************************************************************
### Data structure  
  ## Assignment 1
* Problem 1: You will develop in C++ a class, BigInt that supports writing statements with extremely long integer values like these:
  ```
  BigInt num1("123456789012345678901234567890");
  BigInt num2("113456789011345678901134567890");
  BigInt num3 = num2 + num1;
  cout << "num1 = " << num1 << endl;
  cout << "num2 = " << num2 << endl;
  //236913578023691357802369135780
  cout << "num2 + num1 = " << num3 << endl;
  ```
* Problem 2: You will develop an application for performing calculations on fractions.
* Problem 3: You will develop an application for matrix calculations.
* Problem 4: The given function ListPermutations below prints all the permutations of a given string. 
             It is required to modify this function so that it only prints unique strings. The current function will do exhaustive 
             recursion to calculate all permutations. So, if the given string has duplicate characters, the output will
             have duplicate words. For example, if it is given the string “Makka”, it will print “Mkkaa” four times. Try this function and see how it works.


* Problem 5:You will develop an application for performing operations on strings.
* Problem 6: Write a program that handles an address book program, to process the following functions
              (1) First, write a class called PhoneDirectory. Add a first name, last name and phone number entry as a private.
              (2) The main program uses a simple text-based interface to give the user access to the directory. In a while loop, the program presents the user with a menu of options:
*Problem 7: If you have a list of songs in a music library and want to sort this list alphabetically. However,
            you want songs with the title “Untitled” to always appear at the top. Write a function called BiasedSort 
            that accepts a vector by reference and sorts the songs according to the explained rules above.
  ## Assignment 2
* Problem 1: In this problem, you should develop a stack class similar to that provided in the C++ STL. You cannot use any of the C++ STL classes in this problem.

* Problem 2: In this problem, you should develop a queue class similar to that provided in the
            C++ STL. You cannot use any of the C++ STL classes in this problem.
* Problem 3: In this problem, you must use your queue. Reimplement part of the stack data
              structure using only one queue as an underlying data structure. R
* Problem 4: (Tree) Given the following code
 ```
 struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
class Solution {
public:
bool isSymmetric(TreeNode* root) {
// write you code here
}
};
// add main method and test cases to test your code
           
 ```
Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
symmetric around its center).

* Problem 5:(Tree) Given the following code
 ```
 struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
class Solution {
public:
bool isSameTree(TreeNode* p, TreeNode* q) {
// write you code here
}
};
// add main method and test cases to test your code
 ```
Given the roots of two binary trees p and q, write a function to check if they are the
same or not.
Two binary trees are considered the same if they are structurally identical, and the
nodes have the same value.

* Problem 6:(Tree) Expression Tree Evaluation:
Write an algorithm that accepts an arithmetic expression written in prefix notation and builds an expression tree for it, then traverse to evaluate the expression. The
evaluation should start after the whole expression has been entered.

* Problem 7:(Tree) Tree Flipping
Assume a binary tree. Write a flip method that takes the node which the mirror
image of the tree will start from, if no parameter is sent to the function the default
value will be the root node.
* Problem 8:(Tree)Tree Traversal
Assume a binary tree of non-repeated characters. Write a function printPostOrder
that takes two strings representing the preorder traversal and the in-order traversal
of the tree. Then the function prints the post-order traversal. The function prototype
is: void printPostOrder (string preorder, string inorder)
A sample function call and the corresponding output is shown below:
printPostOrder ( "ABFGC", "FBGAC")
* Problem 9:(Tree) Tree Traversal
Assume a binary tree of non-repeated characters. Write a function printPostOrder
that takes two strings representing the preorder traversal and the in-order traversal
of the tree. Then the function prints the post-order traversal. The function prototype
is: void printPostOrder (string preorder, string inorder)
A sample function call and the corresponding output is shown below:
printPostOrder ( "ABFGC", "FBGAC")

***************************************************************************************************
### Advanced Data structure  
  ## Assignment 1 (Suffix Tree data structure)
  * Write a C++ code that does the following:
* You are not allowed to use any built-in functions except: <cstdlib>, <cstdio>, <cstring>, <iostream>.
* You are not allowed to use string class, vector, or anything from STL libraries.
* Implement a compact Suffix Tree data structure as described in our lecture with Search() operation for any substring.
* Each node in the tree must contain exactly the following:
* 1) Array of pointers to children nodes. The array size equals to the alphabet size. (Method 1 in trie lecture)
* 2) The starting index (in the original string) of the characters on the edge going to this node.
* 3) The starting index (in the original string) of the suffix ending at this node (used for leaf nodes only, otherwise it should be -1).
* The tree construction time complexity must be O(n^2) while the tree space complexity must be O(n), where n is the string length.
* The search complexity must be O(m+occ) where m is the length of the searched pattern, and occ is the number of occurrences of the pattern inside the string.
* Other methods are NOT allowed. Using edge structure is NOT allowed.
* Use your implementation of everything. Do not use string class, use char arrays.
* Your code must be general to handle any indexed string or query. The TA will test you code on arbitrary long strings.
* Use only standard C++, such that the following main() works. You are not allowed to modify the main() except for adding test cases.
* You are not allowed to include any files or built-in libraries, except for output.
* Write the main() in your submission after adding at least 10 tree test cases, and for each case at least 3 search patterns.

  ## Assignment 2 (dynamic interval tree data structure)
  * Write a C++ code that does the following:
* You are not allowed to use any built-in functions except: <cstdlib>, <cstdio>, <cstring>, <iostream>.
* You are not allowed to use string class, vector, or anything from STL libraries.
* Implement a dynamic interval tree data structure as described in our lecture. An interval is two integers.
* For simplicity, the underlying binary search tree structure must be your implementation of an unbalanced binary search tree.
* The dynamic interval tree must support InsertInterval(), DeleteInterval(), SearchInterval().
* SearchInterval() must return all intervals overlapping with the parameter interval, by first getting one overlapping interval, then deleting it, and so on. Then, all such intervals must be inserted again in the tree to restore its status.
* Other methods are NOT allowed.
* Use your implementation of everything.
* Use only standard C++.
* You are not allowed to include any files or built-in libraries, except for output.
* Write the main() in your submission after adding at least 30 test cases.

