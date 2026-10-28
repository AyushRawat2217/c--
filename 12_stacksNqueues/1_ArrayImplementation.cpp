#include <bits/stdc++.h>
using namespace std;
                    
                          //IMPLEMENTATION OF STACK AND QUEUE USING ARRAY



//implemntation of stack using array
class Stack{
    int arr[100];
    int topInd=-1;
    int size=100;

    public:
        void push(int x){
            if(topInd==size-1){
                cout<<"stack overflow";
                return;
            }
            topInd++;
            arr[topInd]=x;
        }

        void pop(){
            if(topInd==-1){
                cout<<"underflow";
            }

            topInd--;

        }

        int top(){
            if (topInd == -1) {
            cout << "Stack is empty" << endl;
            return;//when no elemnt return
            }22:25
PUSSY NDEX

            cout<<arr[topInd];
        }

};


//implementation of queue using arrays
class Queue{
    int q[100];
    int size=100;
    int start=1;//front //tells the front/first element when pop happen remove first elemnt
    int end=-1;//to show the last elemnt//tthis is the pointer which helps us to push elemnts inside the queue
    int currSize=0;//helps us to keep track of size for underflow and overflow

    public:
        void push(int x){
           if(currSize==size){ //for overflow case
            cout<<"overflow";
            return;
           }
          
           if(currSize==0){
                end=0;
                start=0;
           }

           else {//for condn where currsize!=0 and we need to inser elemnt ahead or  the end is at last index but we got space remaing at front
             end=(end+1)%size;//this modular works for normal increment end++ for space at right side remaining along with space at left remaining
           }

           /*// IMPORTANT: The `else` here does NOT mean "currSize > size" or "overflow".
//
// `if (currSize == 0)` asks:
//     "Is the queue EMPTY?"
//
// Therefore `else` simply means:
//     "Queue is NOT empty"  →  currSize != 0
//
// Example: size = 5
//
// currSize = 0  → EMPTY
// currSize = 1  → NOT EMPTY → else
// currSize = 2  → NOT EMPTY → else
// currSize = 3  → NOT EMPTY → else
// currSize = 4  → NOT EMPTY → else
// currSize = 5  → FULL      → else (unless caught by the
//                              overflow check ABOVE)
//
// That's why we check overflow FIRST:
//
// if (currSize == size) {
//     cout << "Overflow";
//     return;                  // stops here, so full queue
// }                            // never reaches the next if/else
//
// if (currSize == 0) {
//     start = 0;
//     end = 0;
// }
// else {
//     end = (end + 1) % size;
// }
//
// ---------------------------------------------------------
// Circular queue example:
//
// size = 5
//
//       0    1    2    3    4
//     ┌────┬────┬────┬────┬────┐
//     │    │    │ 30 │ 40 │ 50 │
//     └────┴────┴────┴────┴────┘
//       ↑                   ↑
//     free                 end
//
// Here:
//     currSize = 3
//     size = 5
//
// So it is NOT full.
//
// `end` is at index 4, but positions 0 and 1 are free.
//
// Therefore:
//
//     end = (4 + 1) % 5
//         = 0
//
// We wrap around and reuse index 0:
//
//       0    1    2    3    4
//     ┌────┬────┬────┬────┬────┐
//     │ 60 │    │ 30 │ 40 │ 50 │
//     └────┴────┴────┴────┴────┘
//       ↑
//      end
//
// KEY IDEA:
// `currSize` = number of elements currently in queue
// `end`      = array INDEX of the last element
// `size`     = total capacity
//
// So `end == size-1` does NOT mean overflow.
// Only `currSize == size` means the queue is full.*/
          
           q[end]=x;
           currSize++;
        }

        int pop(){//in queue pop happens from front side so we have to remove elmnt from start
            if(currSize==0){
                cout<<"underwear";
                return -1;
            }

            int ele=q[start];//store the elemnt in variable to return at the end
            if(currSize==1){
                //reset both start and end
                start=-1;
                end=-1;
            }

            else{//current size>1
                start=(start+1)%size;
                //modularising start so that if its at last index it can move to first place 
            }

            currSize--;
            return ele;

        }

        void top(){//to show the frontmost elemnt , start in this case
            if(start==-1){
                return;
            }
            cout<<q[start];

        }

        int size(){
            return currSize;
        }

};


int main() {
    Stack s;
    s.push(10);
    s.pop();

    //similarly for queue
    Queue q;
    q.push(1);
    //etc etc
    
    return 0;
}