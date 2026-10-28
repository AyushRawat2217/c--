#include <bits/stdc++.h>
using namespace std;

/*Important:
Opposite directions do NOT always mean a collision.

A collision happens only when:
    top > 0 && nextNr < 0

Why?
    top > 0  -> top asteroid is moving right
    nextNr < 0 -> next asteroid is moving left

They are moving towards each other.

Example:
    5   ->    <-   -10   => COLLISION

But:
   -5   <-    ->   10   => NO COLLISION
   They are moving away from each other.
*/

bool isOppositeDirctn(int top, int nextNr) {
    return top > 0 && nextNr < 0;
}


//142

/*Asteroid Collision Process:

- Positive asteroid moves to the right.
- Negative asteroid moves to the left.

- A collision can happen ONLY when:
      stack top is positive
      AND
      current asteroid is negative

- If they are not moving towards each other:
      current asteroid is simply added to the stack.

- If a collision happens:
      1. If the current asteroid is bigger:
             stack top is destroyed.
             Pop it and keep checking because the current
             asteroid may collide with another asteroid.

      2. If both asteroids have equal size:
             Both are destroyed.
             Pop the stack top and do not add the current asteroid.

      3. If the stack-top asteroid is bigger:
             Current asteroid is destroyed.
             Do nothing.

- If the stack becomes empty after popping:
      current asteroid survived, so add it to the stack.

- At the end, the stack contains all surviving asteroids.
*/
stack<int>asteroidCollision(vector<int>&arr ){
    stack<int>st;
    st.push(arr[0]);

    for (int i = 1; i < arr.size(); i++) {

        if(!st.empty() && isOppositeDirctn(st.top() , arr[i])){//here the collision will occur

           
          while( !st.empty()  &&  (abs(arr[i])>abs(st.top())  )){//keep removing smaller asteriods , 
                    st.pop();
            }

            if(st.empty())st.push(arr[i]);//if stack is empty means the current asteriod destroyed all , just pop it
            //if it wouldnt have beeen empty it means current asteriod got fucked by some bugger opposite direction aesteriod

            else if(abs(arr[i])==abs(st.top()))st.pop();//if current and top are of same size , just pop the top and move on

             
     }

     st.push(arr[i]);//keep inserting same size aesteriods
        }

          return st;

    }
    
  


int main() {
    
    return 0;
}