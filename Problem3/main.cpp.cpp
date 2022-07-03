#include <iostream>
using namespace std;
#include <queue>
template <class T>
class node{
public:
    T v; // data
    node<T> *next; // pointer to next node

    node(T x)
    {
        v = x;
        next = NULL;
    }

};
//implementation of the queue
template <class T>
class Queue{

    node<T> *start;
    node<T> *end;
    int size;

public:

    Queue()
    {
        start = end = NULL;
        size=0;
    }
    bool empty()
    {
        return start==NULL;
    }
    void push(T v)
    {
        node<T> *temp = new node<T>(v);
        if(empty())
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        size++;

    }

    T front()
    {
        if(empty())
            return NULL;
        else
            return start->v;
    }

    void pop()
    {
        if(empty())
        {
            cout<<"Queue is Empty"<<endl;
        }
        else if(start==end)
        {
            delete start;
            start = end = NULL;
        }
        else
        {
            node<T> *temp = start;
            start = start->next;
            delete temp;
        }
        size--;
    }
int getsize(){
    return size;
    }

};
//implementation of stack using queue
class Stack{
    Queue<int>que;
public:
    void push(int item){
        que.push(item);
        for (int i = 0; i < que.getsize()-1; ++i) {
            que.push(que.front());
            que.pop();
        }
    }
    void pop(){
        if(!que.empty()){
            que.pop();
        }
        else{
            cout<<"stack is empty\n";
        }
    }
    int top(){
        if(!que.empty())
            return que.front();
        else
            return -1;
    }
    bool empty(){
        if(que.empty())
            return true;
        else
            return false;
    }
void print(){
    while (!que.empty()){
        cout<<que.front()<<" ";
        que.pop();
    }
    cout<<"\n";
    }

};
int main() {
    Stack s;
    s.push(5);
    s.push(8);
    s.push(5);
    s.push(9);

    s.print();

    s.pop();

    s.push(8);
    s.push(9);
    s.push(2);
    cout<<s.top()<<"\n";
    s.pop();
    s.print();

    return 0;
}
