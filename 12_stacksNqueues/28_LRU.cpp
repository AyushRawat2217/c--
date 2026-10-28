#include <bits/stdc++.h>
using namespace std;

class Node{
   

    public:
         int key;
         int value;
         Node*next;
         Node*prev;//ye sbh public rkhna hai taaki bahar access krske inn sbko



        Node(int val1 , int val2 , Node*nextPtr=NULL , Node*prevPtr=NULL){
            key=val1;
            value=val2;
            next=nextPtr;
            prev=prevPtr;
        }
};



class lruCache{
    int capacity;
    map<int , Node*>mpp;
    Node*head;
    Node*tail;

    public:
        //initiliasing lrucache , name of constructor should be same as name of class
        lruCache(int cap){//this is the constructor to initilise it , it helps me create 
            //head and tail and combine them for different objects
            capacity=cap;
            head=new Node(-1 , -1);
            tail=new Node(-1 , -1);

            head->next=tail;
            tail->prev=head;
        }

        void put(int key , int value){//putting key value pair recently , recent for me is near head

            Node*newNode;
            
            if(mpp.find(key)!=mpp.end()){//key is present
                Node*mover=mpp[key];

                mover->value=value;

                Node*prevPtr=mover->prev;
                Node*nxtPtr=mover->next;

                prevPtr->next=nxtPtr;
                nxtPtr->prev=prevPtr;

                newNode=mover;

            }

            else{
                newNode=new Node(key , value);
            }


            Node*temp=head->next;
            head->next=newNode;
            newNode->prev=head;
            newNode->next=temp;
            temp->prev=newNode;

            mpp[key]=newNode;
            
        }   

        int get(int key){//to access the value of the key
             if(mpp.find(key)!=mpp.end()){
                int val=mpp[key]->value;
                Node*mover=mpp[key];

                mpp.erase(key);//deleting the mapping from map
                
                //first delete the node 
                Node*prevPtr=mover->prev;
                Node*nxtPtr=mover->next;
                prevPtr->next=nxtPtr;
                nxtPtr->prev=prevPtr;
                
                //now adding it to recent
                Node*newNode=mover;
                Node*temp=head->next;
                head->next=newNode;
                newNode->prev=head;
                newNode->next=temp;
                temp->prev=newNode;


             }
             else return -1;
        }
    
};


int main() {
    
    return 0;
}