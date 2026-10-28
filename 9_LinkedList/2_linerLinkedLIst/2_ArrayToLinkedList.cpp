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

Node*convertingArrayToLLThenReturningHead(vector<int>&arr){
    Node*head=new Node(arr[0]);//returns the adress of the node where value is arr[0] and which is pointing to null
    Node*mover=head;//mover works as a setter to join nodes , it will be the pointer which
    //will travel all across the array

    for (int i = 1; i < arr.size(); i++) {
      Node*temp=new Node(arr[i]);//returns address of node with arr[1] as data at first iteration and stored in temp , temp stores the adress where the node containing arr[i] is saved
      mover->next=temp;//mover points to the adress which hold node which store arr[i]
      //if this is first iteration then the node which hold arr[0] now holds adress of node which store [arr[1]]
      mover=temp; //lets move the mover to the temp do that we can point it to next node in next iteration
    }

    return head;

}


int main() {
    vector<int>arr={1,2,3,4,5};
    Node*head=convertingArrayToLLThenReturningHead(arr);
    cout<<head->data;
    
    return 0;
}