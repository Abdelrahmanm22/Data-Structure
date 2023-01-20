#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define N nullptr
///To Implement a compact Suffix Tree data structure
//----------------------------prototypes-----------------------------------
template <class t> class LlNode;
template <class t> class linkedList;
class TreeNode;
class SuffixTree;
//----------------------------prototypes-----------------------------------
template <class t>
class LlNode{ //class for each node in linkedList
public:
    //To Avoid O(n^2) Edges are labelled with the start position and the length of a substring inside the original string
    //A suffix of a string is a substring that ends at the last location(n-1)
    int *position; //array of starting location inside the original string
    int length;
    char symbol; //to save charachters
    LlNode *next; //for next child
    t *trie; // we use to return it when add at linkedList
    LlNode(){//Constructor initialization 2 attributes
        position = N;
        length = 0;
    }
};

// Array of pointers to children nodes. The array size equals to the alphabet size (Method 1 in trie lecture)
//In each node we create array with size == length of a substring
//this function to add element in dynamic array
int *insert(int &S,int elem,int *array){ //we pass reference Size to change it
    int *newArray = new int[S+1];//We create new arr for newIndex with Size+1
    S+=1;
//    std::cout<<elem;
//    std::cout<<"\n";

    //we will copy the array and add new element
    for (int i = 0; i <S ; ++i)
    {
        //when iterator i==Size - 1 ==>add new element then break from loop
        if (i == S-1 )
        {
            newArray[i] = elem;
            break;
        }
        newArray[i] = array[i];
    }
//    for (int i = 0; i <S ; ++i) {
//        std::cout<<newArray[i]<<" ";
//    }
//    std::cout<<"\n";
    return newArray;
}
template <class t>
class linkedList{
public:
    LlNode<t> *top; //pointer to head linkedlist
    linkedList(){
        top = N;
    }
    LlNode<t> *Search_in_linkedList(char symbol){
//        std::cout<<symbol<<"\n";
        LlNode<t> *node = top;//to search in linked list then return when we find the character
        while (true)
        {
            if(node!= N)
            {
                if(symbol == node->symbol)
                {
                    return node;
                }
                node = node->next;
            }
            else break;
        }
        //if char not found ==>return Null
        return N;
    }
    t *addAtlinkedList(int index,char symbol){
        //create new node
        LlNode<t> *New = new LlNode<t>();
        New->next = N;//we link the next with null
        New->trie = new t(); //to initialize trie node
        New->symbol = symbol;//to save char

///we have Three cases:
        ///(1)First time: when linkedlist is empty
        if(top == N)
        {
            //link new node with the head
            top = New;
            //call function to add element in dynamic array
            top->position = insert( top->length,index,top->position);
            return top->trie;
        }

        ///(2)if the symbol already exist
        LlNode<t> * x = Search_in_linkedList(symbol);
        if(x != N)
        {
            //call function to add element in dynamic array
            x->position = insert( x->length,index,x->position);
            return x->trie;
        }
        ///(3)If the symbol wasn't there before that
        LlNode<t> *temp=top;
        //to get last node
        while (true)
        {
            if(temp->next != N)
            {
                temp = temp->next;
            }
            else break;
        }
        //to link new node with next child
        temp->next = New;
        //call function to add element in dynamic array
        New ->position  = insert( New->length,index,New->position);
        return New->trie;
    }
};
//to make trieNode
class TreeNode{
private:
    //we have arr of linked list with type TreeNode
    linkedList<TreeNode> *arr =new linkedList<TreeNode>();
public:

    //That result O(m) is needed as initiall traversal,then O(occ) is needed for a depth first search starting from the internal node or the place where we stopped
    LlNode<TreeNode> *searcAtTreeNode( int index,char *ch){
//        std::cout<<index<<" "<<ch[index];
//        std::cout<<"\n";
        LlNode<TreeNode> *New;
        if(arr->Search_in_linkedList(ch[index])!= N)//check if character in arr of linked list
        {
            if(ch[index+1]== NULL)//check if last char
            {
                New =  arr->Search_in_linkedList(ch[index]);
            }
            New =  arr->Search_in_linkedList(ch[index])->trie->searcAtTreeNode(index+1, ch);
        }
        return New;
    }
    //function to add in tree node
    void addatTreeNode( int index,char *word){
        if(word[index-1]=='$')return; //we check if end of characters
        TreeNode *node = arr->addAtlinkedList(index,word[index]);//we call insert at linked list and pass each character
        node->addatTreeNode( index+1,word); //make recursion at all String
    }
};
class SuffixTree{
public:
    TreeNode myRoot;//we have initial root to build suffixTree

    //Constructor take String from main and add each char in treeNode by root
    SuffixTree(char *String){// Do not use string class, use char arrays.
        int index=0;//for position for each char
        while (true)
        {
            if(index==0 or String[index-1]!='$')
            {
                myRoot.addatTreeNode( index,String);
                index++;
            }
            else break;
        }
    }
    //The search complexity must be O(m+occ) where m is the length of the searched pattern,
    // and occ is the number of occurrences of the pattern inside the string.
    void Search(char *substring){// Do not use string class, use char arrays.
        int lengthOfSubstring=getLength(substring);//to count length of substring
        LlNode<TreeNode> * x =myRoot.searcAtTreeNode( 0,substring);//search on substring atTreeNode from index 0 and save it in variable x with type linked list Node
        int i=0;
        while (true)
        {
            if(i<x->length)//to loop on indexSize
            {
//                std::cout<<x->position[i]<<" ";
                int ans =x->position[i]-lengthOfSubstring;
                std::cout<<ans+1<<" ";
                i++;
            }
            else break;
        }
        std::cout<<std::endl;
    }

    int getLength(char *sub){
        int cnt=0;
        while (true)
        {
            if(*sub!=NULL)
            {
                sub++;
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }

};
int main()
{
//    SuffixTree t1("banana$");
//    t1.Search("ana");  // 1 3 7
////    t1.Search("naba"); // 4 8
////    t1.Search("bana"); // 0 6
//    std::cout<<"\n";

    std::cout<<"Test 1 : \n";
    SuffixTree t1("bananabanaba$");
    t1.Search("z");  // 1 3 7
    t1.Search("aba"); // 4 8
    t1.Search("nabn"); // 0 6
    std::cout<<"\n";

    std::cout<<"Test 2 : \n";
    SuffixTree t2("papatpappa$");
    t2.Search("pap"); // 0 5
    t2.Search("pa"); // 0 2 5 8
    t2.Search("atp"); // 3
    std::cout<<"\n";

    std::cout<<"Test 3 : \n";
    SuffixTree t3("nonsense$");
    t3.Search("nse"); // 2 5
    t3.Search("se"); // 3 6
    t3.Search("ons"); // 1
    std::cout<<"\n";

    std::cout<<"Test 4 : \n";
    SuffixTree t4("mississippi$");
    t4.Search("ssi"); // 2 5
    t4.Search("miss"); // 0
    t4.Search("si"); // 3 6
    std::cout<<"\n";

    std::cout<<"Test 5 : \n";
    SuffixTree t5("xabxa#babxba$");
    t5.Search("ba"); // 6 10
    t5.Search("#b"); // 5
    t5.Search("xa"); // 0 3
    std::cout<<"\n";

    std::cout<<"Test 6 : \n";
    SuffixTree t6("bearbellbidbullbuysellstockstop$");
    t6.Search("sto");
    t6.Search("ll");
    t6.Search("bea");
    std::cout<<"\n";

    std::cout<<"Test 7 : \n";
    SuffixTree t7("ggcgtccgcgcacacctccc$");
    t7.Search("gc"); // 1 7 9
    t7.Search("tcc"); // 4 16
    t7.Search("cc"); // 5 14 17 18
    std::cout<<"\n";

    std::cout<<"Test 8 : \n";
    SuffixTree t8("ababbabbaabbabb$");
    t8.Search("abba"); // 2 5 9
    t8.Search("bb"); // 3 6 10 13
    t8.Search("aba"); // 0
    std::cout<<"\n";

    std::cout<<"Test 9 : \n";
    SuffixTree t9("codercohackdollercerc$");
    t9.Search("co"); // 0 5
    t9.Search("erc"); // 3 15 18
    t9.Search("code"); // 0
    std::cout<<"\n";

    std::cout<<"Test 10 : \n";
    SuffixTree t10("aagaagcfagaagtfcgaagc$");
    t10.Search("gaag"); // 2 9 16
    t10.Search("aa"); // 0 3 10 17
    t10 .Search("cfa"); // 6
    std::cout<<"\n";

    return 0;
}
