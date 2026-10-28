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
/*Important 
For singly linked lists, intersection means both lists share
the same node (same memory address).

Once two lists intersect, they cannot split again because
each node has only one next pointer.

Therefore, intersection implies a common tail.
*/

/*IMPORTANT:

Intersection in linked lists means both pointers point to the SAME NODE
(same memory address), NOT nodes having the same value.

Example:

A: 1 -> 3 -> 1 \
                2 -> 4
B:      3 -----/

The nodes containing 2 and 4 are physically shared by both lists.

Check:
ptrA == ptrB          // Correct (same node/address)

NOT:
ptrA->data == ptrB->data   // Wrong (same value doesn't imply intersection)

Key Observation:
Once two singly linked lists intersect, they share the entire remaining tail
because each node has only one next pointer.

Recognition Pattern:
- Intersection of Two Linked Lists
- Common Node of Two Linked Lists
- Y-Shaped Linked List
- Lists Merge Into One

Always compare node addresses, not node values.
*/


Node*intersectionOfLLbF(Node*head1 , Node*head2){
     if(head1==NULL || head2==NULL)return NULL;
     Node*mover1=head1;
     Node*mover2=head2;

     while(mover1){

        while(mover2){
            if(mover1==mover2)return mover1;
            mover2=mover2->next;
        }
        mover1=mover1->next;
     }

     return NULL;
}


Node*intersectionOfllBr(Node*head1 , Node*head2){
     if(head1==NULL || head2==NULL)return NULL;
     Node*mover1=head1;
     Node*mover2=head2;

     unordered_set<Node*>st;

     while(mover1){
        st.insert(mover1);
        mover1=mover1->next;
     }

     while(mover2){
        if(st.find(mover2)!=st.end())return mover2;
        mover2=mover2->next;
     }

     return NULL;

}


int lengthOfLL(Node*head){

}



/*OPTIMAL APPROACH 1 : LENGTH DIFFERENCE METHOD

Key Observation:
Intersection in a singly linked list means both pointers point to
the SAME NODE (same memory address), not nodes with the same value.

Once two lists intersect, they must share the entire remaining tail
because a node has only one next pointer.

Example:

A: 1 -> 2 -> 3 \
                 7 -> 8 -> 9
B:      4 -> 5 /

Intersection = node 7 (same node in memory)

--------------------------------------------------

Problem:
The two pointers may start at different distances from the
intersection because the lists can have different lengths.

Example:

A: 1 -> 2 -> 3 -> 4 -> 5 -> 6
B:           8 -> 5 -> 6

lenA = 6
lenB = 3

Pointer A is 3 nodes farther from the end than Pointer B.

--------------------------------------------------

Idea:

1. Find lengths of both lists.
2. Compute difference = abs(lenA - lenB).
3. Move the pointer of the longer list ahead by 'difference' nodes.
4. Now both pointers are equally far from the end.
5. Move both pointers one step at a time.
6. First node where ptrA == ptrB is the intersection.

--------------------------------------------------

Why does alignment work?

The extra nodes in the longer list are guaranteed to belong to
its private (non-shared) part.

By skipping those extra nodes, both pointers become the same
distance away from the shared tail.

Therefore:
- If an intersection exists, both pointers will reach it together.
- If no intersection exists, both pointers will become NULL together.

--------------------------------------------------

Check:

ptrA == ptrB        // Correct (same node/address)

NOT

ptrA->data == ptrB->data   // Wrong (same value != intersection)

--------------------------------------------------

Time Complexity : O(N + M)
Space Complexity: O(1)

N = length of first list
M = length of second list
*/


Node*intersectionOfllOpt1(Node*head1 , Node*head2){
     if(head1==NULL || head2==NULL)return NULL;
     Node*mover1=head1;
     Node*mover2=head2;

     int len1=lengthOfLL(head1);
     int len2=lengthOfLL(head2);

     if(len1>=len2){
        int diff=len1-len2;

        while(diff>0){
            mover1=mover1->next;
            diff--;
        }
    }

       

     else {//len1<len2
        int diff=len2-len1;

        while(diff>0){
            mover2=mover2->next;
            diff--;
        }
    }



    while(mover1){
            if(mover1==mover2){
            return mover1;
            mover1=mover1->next;
            mover2=mover2->next;
        }
    }


        return NULL;
}

/*Example:

A: 1 -> 2 -> 3 \
                 7 -> 8 -> 9
B:      4 -> 5 /

dekh mover 1 pehle travel krega A part(1 2 3) fir C part(7 8 9)  null hone k baad  head 2 se start kega and travel kreg B part(4 5 )
mover 2 ttavel krega B part(4 5) fir travel krega c part(7 8 9) similarly mover 2 null hone k baad travel krega A part (1 2 3)\

mover 1=a+c+b
mover2=b+c+a
dono same jgh m intersect krenge 
*/ 
Node*intersectionOfllOpt2(Node*head1 , Node*head2){
     if(head1==NULL || head2==NULL)return NULL;
     Node*mover1=head1;
     Node*mover2=head2;


    while(mover1!=mover2){
        mover1=(mover1==NULL)?head2:mover1->next;//agr mover1==null true h toh mover ki value head otherwise next
        mover2=(mover2==NULL)?head1:mover2->next;
    }

    
    return mover1;
   
    /*Case 1: Intersection exists
-> pointers meet at the intersection node.

Case 2: No intersection exists
-> pointers meet at NULL.

In both cases, the loop terminates.
*/

}





int main() {
    
    return 0;
}