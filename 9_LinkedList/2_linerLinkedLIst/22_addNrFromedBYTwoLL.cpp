#include <bits/stdc++.h>
using namespace std;


/*digits are stored in reverse order, reverse the numbers first to get 
the or original number and then add them as → 342 + 465 = 807. 
*/
class Node{
    public:
        int data;
        Node*next;
    
        Node(int val , Node*ptr=NULL){
            data=val;
            next=ptr;
        }
    
};



/*logic id
simple i take first node of l1 snd 2nd node of l2
then add if carry then pass it on to next sum of two nodes
i initiaise carry with 0*/

Node*addNodeToDummyLL(Node*tails , int data){
    tails->next=new Node(data);
    return tails->next;
}

Node*LLrepresntingSum(Node*head1 , Node*head2){
   Node*mover1=head1;
   Node*mover2=head2;

   Node*dummy=new Node(-1);
   Node*tails=dummy;
   int carry= 0;

    while(mover1 && mover2){
        int data1=mover1->data;
        int data2=mover2->data;

        int sum=data1+data2+carry;
        carry=sum/10;
        addNodeToDummyLL(tails , sum%10);

        mover1=mover1->next;
        mover2=mover2->next;

    }


    //if one of ll elemnts are still rmaing
     while (mover1) {

        int sum = mover1->data + carry;//if at end of iteration carry is stilll reamining

        carry = sum / 10;

        tails = addNodeToDummyLL(tails, sum % 10);

        mover1 = mover1->next;
    }

    while (mover2) {

        int sum = mover2->data + carry;

        carry = sum / 10;

        tails = addNodeToDummyLL(tails, sum % 10);

        mover2 = mover2->next;
    }


    //if carry is remaining at the end
    if (carry) {
        tails = addNodeToDummyLL(tails, carry);
    }


    return dummy->next;


}




//i can finish all the above 3 loops inside 1 loop only


/*OPTIMAL APPROACH : DIGIT-BY-DIGIT ADDITION WITH CARRY

Problem:
Digits of both numbers are stored in reverse order.

Example:

2 -> 4 -> 3  (342)
5 -> 6 -> 4  (465)

Answer:
7 -> 0 -> 8  (807)

--------------------------------------------------

Key Observation:

The least significant digit is already present at the head
of each linked list.

Therefore, the order matches the way we perform elementary
addition on paper.

No reversal, stack, or recursion is required.

--------------------------------------------------

Idea:

Traverse both linked lists simultaneously.

For every position:

sum = digit1 + digit2 + carry

digit = sum % 10
carry = sum / 10

Store 'digit' in the answer linked list.

--------------------------------------------------

Handling Unequal Length Lists:

If one list becomes NULL before the other:

- Treat the missing digit as 0.
- Continue processing the remaining list.
- Carry is still included in the sum.

--------------------------------------------------

Handling Final Carry:

Example:

9 -> 9
1

Step 1:
9 + 1 = 10
digit = 0
carry = 1

Step 2:
9 + 0 + 1 = 10
digit = 0
carry = 1

Both lists end but carry still exists.

Create a final node containing carry.

Result:

0 -> 0 -> 1

which represents 100.

--------------------------------------------------

Dummy Node Usage:

A dummy node simplifies insertion into the answer list.

tail always points to the last node of the answer.

Whenever a new digit is generated:

tail->next = new Node(digit);
tail = tail->next;

--------------------------------------------------

Loop Condition:

while(ptr1 || ptr2 || carry)

Continue while:
- first list has nodes, OR
- second list has nodes, OR
- carry still exists.

This automatically handles:
- equal length lists
- unequal length lists
- final carry

--------------------------------------------------

Time Complexity  : O(max(N, M))
Space Complexity : O(max(N, M))

N = length of first list
M = length of second list

Extra space is used only for the answer linked list.
*/
Node*LLrepresntingSum(Node*head1 , Node*head2){
   Node*mover1=head1;
   Node*mover2=head2;

   Node*dummy=new Node(-1);
   Node*tails=dummy;
   int carry= 0;

    while(mover1 && mover2){
        int sum =carry;

        if(mover1){
            int data1=mover1->data;
            sum+=data1;
            mover1=mover1->next;
        }

        if(mover2){
            int data2=mover2->data;
            sum+=data2;
            mover2=mover2->next;
        }

        carry=sum/10;
        tails=addNodeToDummyLL(tails,sum%10);

    }



    return dummy->next;


}

int main() {
    
    return 0;
}