#include <bits/stdc++.h>
using namespace std;

//creating the node data type
class Node{

    public:
        int data;
        Node*next;
    
    Node(int val , Node*ptr=NULL){
        data=val;
        next=ptr;
    }

};

                    //IMPLEMENTATION OF STACK AND QUEUE USING LL

class Stack{
    Node*top;
    int size=0;

    public:
        void push(int x){
            Node*temp=new Node(x);
            temp->next=top;
            top=temp;
            size++;
        }

        void pop(){//removinf the top node
            Node*temp=top;
            top=top->next;
            delete temp;
            size--;
        }

        int top(){
            return top->data;
        }

        int size(){
            return size;
        }


};


class Queue{
    
    int size=0;
    Node*start;
    Node*end;

    public:
        void push(int x){
            Node*temp=new Node(x);

            if(start==NULL){// MEANS end is null as well , make them both point to temp as this temp is the first node of queue
                start=end=temp;
            }
            else{//when start is sorted at its place and end is fkin around somehwere just put the temp ahead of end
                end->next=temp;
            }
            size++;
        }

        void pop(){
            if(start==NULL){
                cout<<"underflow";
                return;
            }
            Node*temp=start;
            start=start->next;
            delete temp;
            size--;
        }

        int front(){//queue ka top ni hota front hota hai
            if(start==NULL){
                cout<<"no element present";
                return;
            }
            return start->data;
        }

        int size(){
            return size;
        }


};

int main() {
    
    return 0;
}