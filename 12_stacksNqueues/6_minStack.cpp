#include <bits/stdc++.h>
using namespace std;

                            //BRUTE FORCE

//implemnting stack using arr , push pop vgrh krlenge prr min stack ke liye 
//prr iss se better method is to keep a stakc of pair where the second elemnt stores the min
//we will implemnt stack using a stack where lemnts are pair

class Stack{
    
    stack<pair<int , int>>st;

    public:
        void push(int val){
            if(st.empty())st.push({val , val});//kuch computation ki jrurat ni hai just value daal do
            //otherwise

            st.push({val , min(val , st.top().second) });

        }

        int minStack(){
            return st.top().second;
        }

        int top(){
            return st.top().first;
        }
        
};//here is sc is o 2n  because we are storing pairs



                        //BETTER APPROACH

//we will go for better approach
//this has two stack , one to store elemnts other to track min elemnts
//acc to push and pop the min elemnt holding stack changes
class Stack{
    
    stack<int>mainSt;
    stack<int>min;

    public:
        void push(int val){
            mainSt.push(val);
            if(min.empty() || min.top()>val)min.push(val);
            
        }

        void pop(){
            if(mainSt.top()==min.top())min.pop();//min store wale stack se hata do wo elemnt jo ki main stack ki trh hai
            //iss treeke se ham pop ke time stack ko update krte hai

            mainSt.pop();
            //min elemnt wale stack ko update krne ke baad pop krdo4
        }

        int minStack(){
            return min.top();
        }

        int top(){
            return mainSt.top();
        }
        
};//in this case SC is O N , because we use stack to store elemnt single digit



                    //OPTIMAL APPROACH
class Stack{
    
    stack<long long>mainSt;//ONLY STACK TO STORE MAIN ELEMNTS and previous min in encoded form
    long long minn;
    

    public:
        void push(int val){
            if(val<minn){//val jbh bhi minimun ho , previous min ko encode krdo stack ke andr
                mainSt.push(2LL*val-minn);//ye ek encoded form hai , isme hamm previous minimum , minn ko storre kkre hai along with val , or ham ye baad mai nikaal lenge
                //kyuki hampr minimum value toh hogi hi
                //when val is less , its like 2*newMinm - oldMinm
                minn=val;
            }

            mainSt.push(val);
            
        }

        void pop(){
            //koi stack ki value encoded usko pta krne ka treeka ye hai ki wo value will be smaller than the minn value
                         
            /*Example
                oldMin = 5
                x = 3

                Encoded:

                2(3) - 5 = 1

                So:

                encoded = 1
                actual popped element = 3
                current min = 3


                1 < 3*/
            
            if(mainSt.top()<minn){//this means that top val is encoded , so decode and minn element replace krdo
                minn=2LL*(minn)-mainSt.top();
                //the val at LHS of minn is old minm we got after decoding and mains.top was old value
                
                /*Start with:

                encoded = 2 * newMin - oldMin

                Move things around:

                oldMin = 2 * newMin - encoded
                */
            
                
            }
                
            mainSt.pop();
        }



        int minStack(){
            return minn;
        }

        int top(){//if the top value is encoded we have to return the decoded value
             if(mainSt.top()<minn){
                 return minn; //if top is encoded then that means its real value is stored in MINN , IT was encoded because it the 
                 //last minimum value , so i could store the previous min as well
             }
             return mainSt.top();
        }
    

        
};

/*APPROACH EXPLAINATION
// ONE-STACK MIN STACK — 2*x - min trick
//
// We maintain:
//   st     -> one stack containing normal OR encoded values
//   minVal -> current minimum element
//
// Normal push (x >= minVal):
//   Push x normally.
//
// New minimum (x < minVal):
//   We cannot simply push x because we also need to remember
//   the PREVIOUS minimum. So encode both pieces of information
//   into one number:
//
//       encoded = 2*x - minVal
//
//   Then:
//       st.push(encoded)
//       minVal = x
//
// Why does encoded < minVal?
//   Since x < old min:
//
//       2*x - oldMin < x
//
//   Therefore, after minVal = x:
//
//       st.top() < minVal
//
//   This tells us that st.top() is an ENCODED value.
//
// TOP:
//   If st.top() < minVal:
//       top is encoded, so the actual top element is minVal.
//   Otherwise:
//       top is a normal value, so return st.top().
//
// POP:
//   If st.top() < minVal, it is encoded.
//   The current minVal is the element being popped.
//   Recover the OLD minimum using:
//
//       oldMin = 2*minVal - encoded
//
//   Then set:
//       minVal = oldMin
//
// Example:
//   oldMin = 5, push x = 3
//   encoded = 2*3 - 5 = 1
//   st = [5, 1], minVal = 3
//
//   On pop:
//   encoded = 1, minVal = 3
//   oldMin = 2*3 - 1 = 5
//
// Key idea:
//   The encoded value is NOT the actual element.
//   It is a marker that stores enough information to recover
//   the previous minimum. minVal stores the actual new minimum.
//
// All operations: O(1)
// Extra stack space: O(n)
*/


int main() {
    
    return 0;
}