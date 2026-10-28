/*starting from the changing array to linkedlist

then deletion 

then insertion
*/

#include <bits/stdc++.h>
using namespace std;

class Node{ //initialising double linked list
    public:
        int data;
        Node*next;
        Node*prev;

  /**IMp regarding constructors
 * @brief Node constructor using default arguments.
 * * This design handles 1, 2, or 3 parameters seamlessly:
 * - Pass 1 arg (val): Creates an isolated node (next and prev default to NULL).
 * - Pass 2 args (val, nextPtr): Links forward; prev defaults to NULL.
 * - Pass 3 args (val, nextPtr, prevPtr): Fully links the node in both directions.
 * * Note: If you frequently need to pass ONLY (val, prevPtr), reorder the parameters
 * to (int val, Node* prevPtr = NULL, Node* nextPtr = NULL).
 */
    Node(int val , Node*nextPtr=NULL, Node*prevPtr=NULL){
        data=val;
        next=nextPtr;
        prev=prevPtr;
    }


};

Node*convertingArrayToDLL(vector<int>&arr){
    Node*head=new Node(arr[0]);//created a memory in heap for arr[0]

    Node*mover=head;//this will let me attach node to previos one
    for (int i = 1; i < arr.size(); i++) {
      Node*temp=new Node(arr[i],NULL , mover);//i attached previous node to temp node
      mover->next=temp;//the mover will attach its next to the next node , so that next of the previous node attaches to the next node
      mover=temp;//same as mover=mover->next//mpving the mover to the next node so that it repeats the same process until last iteration is reached
    }

    return head;

}



//deletion

/*logic is first i will move the head to next element 
then delete it if no elemnt return null , if one elemnt delete head*/

Node*newHeadDeletingTheFirstElement(Node*head , vector<int>&arr){

   
    if(head==NULL)return head;
    if(head->next==NULL){
        delete head;
        return NULL;
    }

    Node*mover=head;

    mover=mover->next;
    head->next=NULL;
    mover->prev=NULL;

    delete head;

    return mover;
}



/*i move to last elemnent , then break the prev junction by making it NULL and
at last freee up the mover */
Node*newHeadDeletingTheLasttElement(Node*head ){

    if(head==NULL)return head;
    if(head->next==NULL){//just one element . delete that
        delete head;
        return NULL;
    }

    Node*mover=head;

    while(mover->next!=NULL)mover=mover->next;//move till last element 
    
    mover->prev->next=NULL;//nullify the next node of new tail
    mover->prev=NULL;//nullify prev node of ex tail
    delete mover;//fee the space
    return head;

    /*// IMPORTANT:
// Do NOT set mover->prev = NULL before updating mover->prev->next.
// Otherwise mover->prev becomes NULL, and accessing mover->prev->next
// would dereference a null pointer and cause undefined behavior.
*/
}


Node*newHeadDeletingTheKthElement(Node*head , int k){
/*edge case discussion

k can have value from 1 - n 
for k=1 , node prev ptr is null , that is head->prev=NULL
for (1, n) these node have both prev and next
and for the last node as well it has next = null
and if dll has 1 elemnt then it will have prev and next pointing to null

so i have to create cases for all these
*/
   
    if(head==NULL)return head;
    else if(head->next==NULL){//just one element , check k , if k==1 , delete that , else return head
        if(k==1){
            delete head;
            return NULL;
        }
        else return head;
    }

    
    else if(k==1){
        Node*mover=head;
        head=head->next;
        mover->next=NULL;
        head->prev=NULL;

        delete mover;
        return head;
    }

    int count=1;
    Node*mover=head;
    while(mover!=NULL && count<k){
        mover=mover->next;
        count++;
    } //jbtk last point p ni aajata and count bilkul k p khda ni hojata
    
    //is point p ham yaa toh kth node par hai(1,n) wali , ya nth wali ya ham out of bound h

    //1) out of bound
    if(mover==NULL)return head;

    //2)nth wali node
    else if(mover->next==NULL){
       
        delete mover;
        return head;
    }


    //3) (1, n) exclude 1 and n 

    /*logic is join the prev and next node of mover and nullify its junctions*/
    
    //ex 10 20 30 40 , i have to remove 30 suppose , mover is at 30
       
        Node*prevNode=mover->prev;//prev to mover (20)
        Node*nextNode=mover->next;//next to mover(40)

        prevNode->next=nextNode;
        nextNode->prev=prevNode;

        //these two lines can be omited as im deleting mover at last
        mover->prev=NULL;
        mover->next=NULL;

        delete mover;


    return head;

    
}


/*edge cases were no elemt
1 elemnt node is hea d, node is tail node not found and node found in between*/
Node*DeleteGivenNodeFromDLL(Node*target , Node*head){//a target node is given
    /*edge case discussion
    target node can be head , tail , any node in between
    we will check for no elemnt 
    just one element and node found and not found as well
    */

    if(head==NULL)return NULL;
    else if(head->next==NULL){
        if(target==head){
            delete head;
            return NULL;
        }
        else return head;
    }
   

    

    
    Node*mover=head;
    while(mover!=NULL){
        if(mover==target)break;
        else mover=mover->next;
    }

    if(mover==NULL)return head;

    else if(mover->next==NULL){
        mover->prev->next==NULL;
        delete mover;
        return head;
    }

    else if(mover==head){
       head=head->next;
       head->prev=NULL;
       
       return head;
    }
    
    //the mover is on target node bw 1 and tail ,
    Node*prevNode=mover->prev;
    Node*nextNode=mover->next;

    prevNode->next=nextNode;
    nextNode->prev=prevNode;

    delete mover;
    return head;



    
}





//insertion



/*logic is
newHead head ko pint kre
head ka prev newHead ko
*/
Node*insertBeforeHead(int val , Node*head){
    Node*newHead=new Node(val);
    newHead->next=head;
    head->prev=newHead;

    return newHead;

}


Node*insertAtTail(int val , Node*head){

    Node*mover=head;
    while(mover->next!=NULL){
        mover=mover->next;
    }

     Node*newTail=new Node(val,NULL ,mover);
     mover->next=newTail;

     return head;
    
}

Node*insertB4KthElement(int k ,int val , Node*head){
    /*edge cases discussion(ec d)
    no elemnt 
    1 elemnent , if k==1 make val node head else return

    out of bound 
    elemnts between 1 to tail and before tail

    
    */

    ///ec 1

    ///ec 2 


    Node*mover=head;
    int count=1;

    while(mover!=NULL && count<k){
        mover=mover->next;
        count++;
    }//mover is at the kth node

    if(mover==NULL)return head;

    Node*prevNode=mover->prev;
    
    Node*newNode=new Node(val , mover , prevNode);//newNode ka next mover bna diya and prev prevnode bna diya
    //abh mover and prevnode ko bhi conncet krdete h
    mover->prev=newNode;
    prevNode->next=newNode;


    return head;


}


Node*insertB4givenNode(Node*target ,int val , Node*head){
    /*edge cases discussion(ec d)
    no elemnt 
    
    one node present , if its the taget node make the new node new head

    out of bound 

    node between 1 to tail and before tail

    */

    ///ec 1

    ///ec 2 


    Node*mover=head;

    while(mover!=NULL){
        if(mover==target)break;
        mover=mover->next;
    }//mover is at the target node

    if(mover==NULL)return head;//out of bounds , that is target node is not present

    Node*prevNode=mover->prev;
    
    Node*newNode=new Node(val , mover , prevNode);//newNode ka next mover bna diya and prev prevnode bna diya
    //abh mover and prevnode ko bhi conncet krdete h
    mover->prev=newNode;
    prevNode->next=newNode;


    return head;


}

int main() {
    vector<int>arr={1 , 2 ,3, 4};

    //printing the dll
    Node*head=convertingArrayToDLL(arr);

    Node*newHead=newHeadDeletingTheFirstElement(head , arr);
    
    return 0;
}