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

//logic for all approaches is such as find the start point of loop then go through the end

int lengthOfLoop(Node*mover){
    int count=1;

    Node*start=mover->next;
    while(start!=mover){
        count++;
        start=start->next;
    }
    return count;

}

int lengthOfTheLoopBF(Node*head){
    Node*mover=head;

    unordered_set<Node*>st;


    while(mover!=NULL){
        if(st.find(mover)!=st.end()) return lengthOfLoop(mover);
        st.insert(mover);
        mover=mover->next;

    while(mover!=NULL){
        if(st.find(mover)!=st.end()) return lengthOfLoop(mover);
        st.insert(mover);
        mover=mover->next;
      }

    }

    return 0;
    
}




int startingPtOfLoopOpt(Node*head){
    
    Node*fast=head;
    Node*slow=head;

    while(fast!=NULL){

        slow=slow->next;
        fast=fast->next->next;


        /* i thought i would miss 1st or 2nd node as fast already moves to 2nd position
        but if there is a loop in 1st 2nd position then it will loop there itself nd slow will catch it once for all
        then will apply the meeting point and all the understanding we made*/
        if(fast==slow){
            Node*meetPoint=slow;//meetpoint
            Node*start=head;
        while(start!=meetPoint){//after x  or l-y steps they will be at start of loop
            start=start->next;
            meetPoint=meetPoint->next;
        }
        return lengthOfLoop(start); //LOOP START IS FOUND
            
        }
    }
    return 0;
}




int main() {
    
    return 0;
}