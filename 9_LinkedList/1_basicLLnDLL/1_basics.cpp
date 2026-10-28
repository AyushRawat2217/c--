/*

array is contiguous memory location and in order to insrt elemnt
elemnt is bwtween we need to move away the elemnts and which is a very complex
operation so linked list wins in this case


linkedlist has node which has data + adress of next node
as there is no such data type to store both we create our own data type


class → blueprint/template , class node helps to use node format of data+ pointer again and again?
Node → name of blueprint
public → members can be accessed directly
int data → stores value
Node* next → stores address of next node

we write 

class Node{
public:
    int data;
    Node*next;//it means that next store adress of a Node data structure
    //why not int*next
    //becuase then it would mean next stoe int but we want next to storre data strucutre of node that is int+a pointer , which is node itself
}


now we created the datatpe but to initilise
it we need to create a constructor aswell

class Node:{
public:
    int data;
    Node*next;


    Node(int value){
    data=value;
    next=NULL;
    }
    //THE VALUE OF node will be data and it will be pointing to null
//everytime only value is passed as parameter this way it will be initialised
    
    if we need a dyanmic next value then

    class Node{
    public:
        int data;
        Node*next;
    }
    
    public:
        Node(int data1 , Node*next1){
        data = data1;
        next=next1;
        }


}






STACK KA USE KRO IF U EVER WANT TO USE REVERSE values of linkedlist becuase of lifo propety of stack

when to use a)while(mover!=NULL) vs b)while(mover->next!=NULL)

while(node != NULL)
→ Process every node.

while(node->next != NULL)
→ Stop at the last node.
A quick recognition trick:

Want to visit every node?
while(node != NULL)
Want to stop at the last node?
while(node->next != NULL)

That's the rule I'd put in the revision sheet.
*/\

/*******************************************************
'.' vs '->'

Use '.' when the variable itself is an object.

    Node dummy(-1);
    dummy.next;      // Correct

Use '->' when the variable is a pointer to an object.

    Node* mover = head;
    mover->next;     // Correct

The arrow operator automatically dereferences
the pointer before accessing the member.

    mover->next
is equivalent to:
    (*mover).next

Examples:

    Node dummy(-1);
    dummy->next;     // Wrong (dummy is not a pointer)

    Node* mover = head;
    mover.next;      // Wrong (mover is a pointer)
*******************************************************/