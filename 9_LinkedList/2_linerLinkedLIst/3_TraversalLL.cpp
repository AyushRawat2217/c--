#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
    
        Node(int val , Node*ptr){
            data=val;
            next=ptr;
        }
        Node(int val){
            data=val;
            next=NULL;
        }
};


int main() {
    /*lets suppose we created a linked list using an array
    now we have acces to head of the array
    
    Node*temp=head; // we creating a temp ptr which points to first elemnt what head does , it will work like a mover

    while(temp(or we can write temp!=NULL)){
        cout<<temp->data;
        temp=temp->next;
    }

    */
    
    return 0;
}