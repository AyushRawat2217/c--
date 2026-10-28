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

/*logic is we will issue head to temp , move
head to next position free the temp and then return head*/
Node*deleteCurrentHead(Node*head){
    if(head==NULL)return head;
Node*temp=head;
head=head->next;
delete(temp);
return head;
}

/*logic is we will move to last second elemnt then from
there we will remove the mover->next then we will point mover to NULL c */
Node*deleteCurrentTail(Node*head){
    if(head==NULL ){//as we need atleast two values
        return NULL;
    }

    // Delete the only node; otherwise returning NULL would
// lose the node's address and leak memory.
    if(head->next==NULL){
        delete head;
        return NULL;
    }

    Node*mover=head;

    while(mover->next->next!=NULL)mover=mover->next;
    delete(mover->next);
    mover->next=NULL;

    return head;

}


Node*deleteKthElement(Node*head , int k){//we are given the kth position which we have to delete 
    if(head==NULL ){//as we need atleast two values
        return NULL;
    }

    if(k==1){//means we have to delete the first elemnent , so move head to 2nd element 
        Node*temp=head;
        head=temp->next;
        delete temp;
        return head;
    }

    

    /*logic is we move to k-1 th node then from there we put kth node as temp then we join k-1 
    and k+1 node then we remove kth node at least and return head at last*/
        int count=1;
        Node*mover=head;
        while(mover && count<k-1){//so that it  runs k-2 and and it moves to k-1
            count++;
            mover=mover->next;
        }

        //at this point we are at k-1 node

        if(mover==NULL || mover->next==NULL)return head;//IT MEANS EITHER K-1 NODE DOESNT EXIST , OR K-1 ExXIST BUT KTH NODE DOESNT EXIST

        Node*temp=mover->next;
        mover->next=temp->next;
        delete temp;



        return head;


}


int main() {
    
    return 0;
}