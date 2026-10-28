#include <bits/stdc++.h>
using namespace std;
//ek string of number diya hogaa aur ek nr n  diya hoga 
//jiska mlb hai hame n digits htani hai string se such that sbse chota nr bacha rhee

//957

void trimLeadingZeroes(string &str){
    int index=0;

    while(str[index]=='0'){
        str.erase(index , 1);
        index++;
    }

    if(str.empty())str="0";

}

string resStr(string &str , int target){
    if(target==str.size())return "0";

    string result;
    stack<char>st;
    st.push(str[0]);
    int k=target;



    for (int i = 1; i < str.size(); i++) {//for creating a stack which has smaller to bigger digit , bottom to up

        while(!st.empty() && k>0 && st.top()>str[i]){//until k>
            st.pop();
            k--;
        }
        
        st.push(str[i]);

    }


    if(k>0){
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
    }


    while(!st.empty()){
        result+=st.top();
        st.pop();
    }



    reverse(result.begin() , result.end());
    trimLeadingZeroes(result);

     return result;
     
}

/*// ============================================================
// LOGIC: Remove 'target' digits to make the smallest number
// ============================================================
//
// Core idea:
// If a bigger digit comes before a smaller digit,
// removing the bigger digit makes the number smaller.
//
// Example:
// 1432219
//   ↑ ↑
//   4 > 3
//
// Remove 4:
// 132219
//
// We use a stack to keep track of the digits we want to keep.
// The stack should preferably have digits in increasing order.
//
// ------------------------------------------------------------
//
// Example: str = "1432219", target = 3
//
// Initially:
// stack = [1]
// k = 3
//
// Current digit = 4
// 1 > 4 ? NO
// Push 4
// stack = [1,4]
//
// Current digit = 3
// 4 > 3 ? YES
// Remove 4 because it is better to have 3 before 4.
// stack = [1]
// k = 2
//
// Push 3
// stack = [1,3]
//
// Current digit = 2
// 3 > 2 ? YES
// Remove 3.
// stack = [1]
// k = 1
//
// Push 2
// stack = [1,2]
//
// Current digit = 2
// 2 > 2 ? NO
// Equal digits are NOT removed.
// stack = [1,2,2]
//
// Current digit = 1
// 2 > 1 ? YES
// Remove 2.
// stack = [1,2]
// k = 0
//
// Push 1
// stack = [1,2,1]
//
// Current digit = 9
// k = 0, so no more digits can be removed.
// stack = [1,2,1,9]
//
// Final answer = 1219
//
// ------------------------------------------------------------
//
// Why do we check:
//
//     stack.top() > current_digit
//
// Because a bigger digit on the left increases the number.
//
// Example:
//
//     52
//
// If we remove 5:
//
//     2
//
// This is smaller than 52.
//
// Therefore, whenever:
//
//     previous digit > current digit
//
// we try to remove the previous digit.
//
// ------------------------------------------------------------
//
// IMPORTANT:
//
// We can remove a digit only while k > 0.
//
// Once k becomes 0, we must keep all remaining digits.
//
// ------------------------------------------------------------
//
// What if we still have digits left to remove after
// processing the entire string?
//
// Example:
//
//     str = "12345"
//     target = 2
//
// Digits are already increasing:
//
//     1 < 2 < 3 < 4 < 5
//
// So there was never a bigger digit before a smaller digit.
//
// Therefore, nothing was removed during traversal.
//
// k is still 2.
//
// To get the smallest number, remove digits from the END:
//
//     12345 -> 1234 -> 123
//
// Answer = 123
//
// ------------------------------------------------------------
//
// After processing, the stack contains the answer,
// but popping from a stack gives the digits in reverse order.
//
// Example:
//
// Stack (bottom -> top):
//
//     1 2 1 9
//
// Popping gives:
//
//     9 1 2 1
//
// So we reverse the result to get:
//
//     1219
//
// ------------------------------------------------------------
//
// Leading zeroes:
//
// Example:
//
//     10200
//
// Remove 1:
//
//     0200
//
// Numerically, 0200 = 200.
//
// Therefore, after constructing the result,
// remove all leading zeroes.
//
// Example:
//
//     000123 -> 123
//     00100  -> 100
//     000    -> 0
//
// ------------------------------------------------------------
//
// Edge case:
//
// If target >= number of digits,
// all digits can be removed.
//
// Example:
//
//     123, target = 3
//
// Nothing remains, so return "0".
//
// ------------------------------------------------------------
//
// COMPLEXITY:
//
// Every digit is pushed into the stack once
// and popped at most once.
//
// Time  = O(n)
// Space = O(n)
//
// ------------------------------------------------------------
//
// ONE-LINE REVISION RULE:
//
// "If the previous kept digit is bigger than the current
// digit, remove the previous digit if I still can."
//
// ============================================================
```
*/

int main() {
    
    return 0;
}