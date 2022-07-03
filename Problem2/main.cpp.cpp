#include <iostream>
using namespace std;
template <class T>
class Node{
public:
    T value;
    Node<T> *next;
    Node(T num){
        value = num;
        next = nullptr;
    }
};

template <class T>
class Queue {
    T *ticket;
    Node<T> *first;
    Node<T> *last;

public:

    Queue() {
        first = last = nullptr;
    }
    bool isEmpty() {
        return first == nullptr;
    }
    void enqueue(T data) {
        Node<T> *temp = new Node<T>(data);
        if (isEmpty()) {
            first = last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "queue is empty \n";
        } else if (first == last) {
            delete first;
            first = last = nullptr;
        } else {
            Node<T> *temp = first;
            first = first->next;
            delete temp;
        }
    }
    T front() {
        if (isEmpty())
            return NULL;
        else
            return first->value;
    }

    ~Queue() {
        delete[] ticket;
    }
};

int main() {
    Queue<int>q;
    int size;
    cout<<"enter number of people : ";
    cin>>size;
    int ticket[size];
    for (int i = 0; i < size; ++i) {
        cin>>ticket[i];
        q.enqueue(i);
    }

    int k ; cin>>k;
    int time=0;
        while(!q.isEmpty()) {
              time++;
              int top=q.front();
              q.dequeue();
              if(ticket[top]>0) {
                  ticket[top]--;
              }
              if(top!=k && ticket[top]==0 ) {
                  continue;
              }
              if(top==k && ticket[top]==0) {
                  break;
              }
              q.enqueue(top);
       }

        cout<<time;
    return 0;
}


