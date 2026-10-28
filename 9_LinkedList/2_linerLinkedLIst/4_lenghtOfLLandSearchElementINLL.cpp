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

        Node(int val ){
            data=val;
            next=NULL;
        }
};

int lengthOfLinkedList(Node*head){//we are given the head ptr
Node*mover=head;//make mover the head as we dont want to tamper the head
int cnt=0;
 while(mover){
    cnt++;
    mover=mover->next;
 }

 return cnt;

}


int searchElementOfLinkedList(Node*head , int val){//we are given the head ptr and the cal we need 

Node*mover=head;//make mover the head as we dont want to tamper the head
 
while(mover){
    if(mover->data==val)return 1;
    mover=mover->next;
 }

 return 0;
}

int main() {
    
    return 0;
}