/*  name: Ahmed said   id : 20200017
    name: Aya mohamed mounir id: 20200107 
    name: Shrouk ayman ali id: 20200251
    name: Abdelrahman mohamed id: 20200293
    name: Weam samy taie id: 20200627
*/

#include <iostream>

using namespace std;

bool postOrder(string preorder,string inorder){
    int size=inorder.length();//size of string
    int index=0;
    for (int i = 0; i < size; ++i) {//get the root index in inorder
        if(preorder[0]==inorder[i])
            index=i;
    }
    string pre="";
    string pre2="";
    string in="";
    string in2="";
    for (int i = 0; i <index ; ++i) {//the new string before the root in inorder
        in+=inorder[i];
    }
    for (int i = index+1; i <size ; ++i) {//the new string after the root in inorder
        in2+=inorder[i];
    }
    for (int i = 1; i < size-in2.length() ; ++i) {//the new string matching with from preorder
        pre+=preorder[i];
    }for (int i = 1+in.size(); i < size ; ++i) {//the new string matching with from preorder
        pre2+=preorder[i];
    }
    if(index)//check if the root not in index 0 and pass the in and pre into recursion function
        postOrder(pre,in);
    if(index<size-1)//check if the root not the last element and pass the in and pre into recursion function
        postOrder(pre2,in2);
    cout<<preorder[0];//printing the new string
}
int main() {
    postOrder("ABFGC","FBGAC");//FGBCA
    cout<<endl;
    postOrder("ABCDEF","CBDAEF");//CDBFEA
    cout<<endl;
    postOrder("ABDECFGH","DBEAFCGH");//DEBFHGCA
    cout<<endl;
    postOrder("ABDFGECHJI","FGDBEAJHCI");//GFDEBJHICA
    cout<<endl;
    postOrder("ABDFEGHCIJ","FDBGEHAICJ");//FDGHEBIJCA
    return 0;
}
