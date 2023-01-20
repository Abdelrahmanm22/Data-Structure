/*  name: Ahmed said   id : 20200017
    name: Aya mohamed mounir id: 20200107
    name: Shrouk ayman ali id: 20200251
    name: Abdelrahman mohamed id: 20200293
    name: Weam samy taie id: 20200627
*/


/*
    -The path starts with a single slash '/'
    -Any two directories are separated by a single slash '/'
    -The path does not end with a trailing '/'
    -The path only contains the directories on the path from the root directory to the
    target file or directory
*/
#include <iostream>
#define N 100
using namespace std;
class stack{
    int top;
    string arr[N];
public:
    stack()
    {
        top =-1;
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        return 0;
    }
    void push(string elem)
    {
        if(top>=N-1)
        {
            cout<<"Overflow\n";
        }else{
            top++;
            arr[top]=elem;
        }

    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty..!\n";

        }else{
            top--;
        }
    }
    int Size()
    {
        return top+1;
    }
    string Top()
    {
        if(isEmpty())
        {
            return 0;
            cout<<"Stack is Empty..!\n";
        }else{
            return arr[top];
            //cout<<arr[top]<<"\n";
        }
    }
    void display()
    {

        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }

    stack revese()
    {
        stack s3;
        while(!isEmpty())
        {
            s3.push(arr[top]);
            top--;
        }
        return s3;
    }
};
/*bool balanced(string x)
{
    stack s;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='(' || x[i]=='{' || x[i]=='[')
        {
            s.push(x[i]);
        }else if(x[i]==')' || x[i]=='}' || x[i]==']')
        {
            if(s.isEmpty())
            {
                return false;
            }else{
                s.pop();
            }
        }
    }
    if(s.isEmpty())
    {
        return true;
    }else{
        return false;
    }
}*/

string UnixStyleFileSystem(string path)
{
    stack s;
    /// "check" may contain 'home'or 'd' or '.' or '..'
    /// "simplyPath" we will return it as a result
    string check,simplyPath="";
    int cnt=0;
    //cout<<cnt<<endl;
    for(int i=0;i<path.length();i++)
    {
        //cout<<cnt<<endl;
        while(path[i]=='/')
        {
            i++;
        }


        //cout<<i<<endl;
        //store file/directory names
        for(i,check="";i<path.length()&&path[i]!='/';i++)
        {
            check+=path[i];
        }



        //if check equal '..' we will pop the top element of stack
        if(check=="..")
        {
            if(!s.isEmpty())
            {
                s.pop();
            }

        }else{
            //if check equal '.' we will not push it
            if(check==".")
            {
                continue;
            }
            //cout<<check<<endl;
            s.push(check);
        }
    }
    //s.display();
    stack s2;
    s2=s.revese();
    //s2.display();

    while(!s2.isEmpty())
    {
        if(s2.Size()==1)
        {
            simplyPath+=s2.Top();
        }else{
            simplyPath+=s2.Top()+"/";
        }
        s2.pop();
    }
    simplyPath="/"+simplyPath;
    return simplyPath;
}




int main()
{
    string str= "/home//fo/";
    cout << UnixStyleFileSystem(str)<<endl<<endl;


    string str2= "/home/";
    cout << UnixStyleFileSystem(str2)<<endl<<endl;

    string str3= "/../";
    cout << UnixStyleFileSystem(str3)<<endl<<endl;

    string str4= "/../abc//././def/";
    cout << UnixStyleFileSystem(str4)<<endl<<endl;




    return 0;
}
