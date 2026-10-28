#include <bits/stdc++.h>
using namespace std;

/*1. Fundamental Terminology
Valid Parentheses String (VPS)

A string where brackets are balanced correctly.

Examples:

()
(())
()()
(()())

Invalid:

(()
)(
())(


Primitive Parentheses String

A valid parentheses string that CANNOT be split into two non-empty valid valid-parentheses strings.

Primitive Examples
Primitive ✅
(())

Cannot split into:

valid + valid
Non-Primitive ❌
()()

Can split into:

() + ()

So NOT primitive.

Core Observation

Whenever:

balance == 0

one primitive component ends.

Balance Concept
( → balance++
) → balance--

Example:

(()())

Tracking:

( -> 1
( -> 2
) -> 1
( -> 2
) -> 1
) -> 0

Primitive ends when balance becomes 0.

Problem Statement in Simple Words
Find every primitive component
Remove first and last bracket from each primitive
Join remaining parts
Example 1

Input:

((()))

Primitive:

((()))

Remove outermost:

(())

Output:

(())
Example 2

Input:

()(()())(())

Primitive decomposition:

()   (()())   (())

Remove outermost:

()       -> ""
(()())   -> ()()
(())     -> ()

Final:

()()()
2. Important C++ Concept
substr()

Syntax:

s.substr(start, length)

NOT:

s.substr(start, end)

Example:

string s = "abcdef";

s.substr(2,3);

Result:

cde

because:

start at index 2
take 3 characters
3. Algorithm
Step 1

Create:

answer string
balance variable
Step 2

Traverse string.

Whenever:

balance == 0

before processing current char,

store:

start = i

meaning:
new primitive starts here.

Step 3

Update balance:

( → increment
) → decrement
Step 4

When:

balance == 0

primitive ends.

Store:

end = i
Step 5

Append inside part only:

str += s.substr(start+1 , end-start-1);

Why?

Removes outermost brackets.

4. Formula Understanding

Primitive:

(()())
012345

Need:

index 1 to 4

Start:

start+1

Length:

end-start-1

because:

5 - 0 - 1 = 4

Need 4 characters.
*/



string removingOutmstPrnthesis(const string &s){
    string str;

    int start;
    int end;
    int balance =0;


    for (int i = 0; i < s.size(); i++) {
        if(balance==0)start=i;
        
        if(s[i]=='(')balance++;
        else if(s[i]==')'){
            balance--;
            if(balance==0){
                end=i;
                str+=s.substr(start+1 , end-start+1); // this is stl
                //s.substr(start, length)

            }
        }

 
    }


    return str;

    

}

int main() {
    
    return 0;
}