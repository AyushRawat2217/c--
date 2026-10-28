#include <bits/stdc++.h>
using namespace std;

class Node{
    
    public:
        int data;
        Node*next;
    
        Node(int val , Node*ptr=NULL){
            data=val;
            next=ptr;
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

/*logic is
set lelu ordered ek aur usme ll k elemnts insert krdu
fir wo sort hojaenge and unko reninsert krdu ll mai 


note IMPP   : THIS DOESNT WORKS FOR DUPLICATE ELEMNTS
IF LL HAS NODE DATA LIKE 1 , 2 ,2 ,3 , THEN SET APPEARS AS 1 ,2 , 3


ISLIYE I WILL USE VECTORR , INSER ELELMNTS IN IT THEN SORT IT

tc onlogn , becuase of set insertion , sc is on because n spaces taken by set*/
Node*headOfSOrtedLLforDistinctElements(Node*head){
    if(head==NULL||head->next==NULL)return head;
    set<int>st;
    Node*mover=head;
    
    while(mover!=NULL){
        st.insert(mover->data);
        mover=mover->next;
    }//hogya ye sort

    mover=head;
    for(auto it:st){
        mover->data=it;
        mover=mover->next;
    }

    return head;
}



/*logic
vector m elemnts daal dunga fir use sort krke uske elemnts 
ll m copy krdunga*/
Node*headOfSOrtedLLBF(Node*head){
    
    if(head==NULL||head->next==NULL)return head;
    vector<int>arr;
    Node*mover=head;
    
    while(mover!=NULL){
        arr.push_back(mover->data);
        mover=mover->next;
    }

    sort(arr.begin(),arr.end());

    for(auto it:arr){
        mover->data=it;
        mover=mover->next;
    }

    return head;
}








Node*mergedLL(Node*leftNode , Node*rightNode){
    Node dummy(-1); //is same as Node* dummy = new Node(-1); it means a node holding value -1 and adrees null , for now
    Node*tails=&dummy;

    while(leftNode!=NULL && rightNode!=NULL){
        if(leftNode->data <= rightNode->data){
            tails->next=leftNode;
            leftNode=leftNode->next;
        }
        else{
            tails->next=rightNode;
            rightNode=rightNode->next;
        }
        tails=tails->next; //move the tails so we can add elemnt at end in next iteration


    }

    while(leftNode!=NULL){
        tails->next=leftNode;
        tails=tails->next;
    }

     while(rightNode!=NULL){
        tails->next=rightNode;
        tails=tails->next;
    }
    
    return dummy.next;;
        

}



Node*findMid(Node*head){//we use this so that we get fist middle node in case of even nr of elemnts in a LL
    Node*slow=head;
    Node*fast=head->next;

    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }


}

Node*headOfSOrtedLLBygODoFSOrtingApproach(Node*head){
    if(head==NULL||head->next==NULL)return head;
    Node*mid=findMid(head);

    //i created a list which contains all the right elements 
    /*// Split the linked list into two halves.
// mid points to the last node of the left half.
// rightHead stores the start of the right half.
// Breaking mid->next separates the original list into:
//
// Left  : head -> ... -> mid -> NULL
// Right : rightHead -> ... -> NULL
//
// Example:
// 4->2->1->3
//      ^mid
//
// Left  : 4->2
// Right : 1->3
*/

    Node*rightList=mid->next;
    mid->next=NULL;
    
    Node*left=headOfSOrtedLLBygODoFSOrtingApproach(head);
    Node*right=headOfSOrtedLLBygODoFSOrtingApproach(rightList);

    
    
    return mergedLL(left , right);
}


int main() {
    vector<int>arr={5 , 4 , 3 , 2 ,1};
    Node*head=convertingArrayToLLThenReturningHead(arr);
    headOfSOrtedLLBF(head);

    Node*mover=head;
    while(mover!=NULL){
        cout<<mover->data<<endl;
        mover=mover->next;
    }

    return 0;
}