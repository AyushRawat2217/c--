#include <bits/stdc++.h>
using namespace std;


int precedence(char ch){
    if(ch=='+' || ch=='-')return 1;
    else if (ch == '*' || ch == '/') return 2;
    else return 3;

}

string infix2postfix(string &s){// a prefix string would be given to me 
    string ans;
    int index=0;
    stack<char>operators;

    while(index<s.size()){

        if((s[index]>='A'&&s[index]<='Z')
                ||
         (s[index]>='a'&&s[index]<='z')
                ||
         (s[index]>=0 &&s[index]<=9)
                
        )
         { //if its a operand then just put it inside the answer string
           
            ans+=s[index];
         }

         else if((s[index]=='(')) {//if its a opening bracket too)
            operators.push(s[index]);
         }

         else if(s[index==')']){
            while(!operators.empty() && operators.top()!='('){
                ans+=(operators.top());
                operators.pop();
            }
         }

         else{//if the s[index] is operator 

            //check sign bw both precendence is less than = , even if priority is same we pop the operator out of stack
            while(!operators.empty() && precedence(s[index]) <precedence(operators.top())   
                          ||
          (precedence(s[index]) == precedence(operators.top()) && s[index] != '^')){//jbtk precendece choti hai top wale se krte rho pop
                
                ans+=(operators.top());//add that high precendence operator in aside ans
                operators.pop();//pop that thing
            }

            //at the end push krdo or isme normal condition bhi incorporate hai
            operators.push(s[index]);

         }

         index++;
        }

        //agr last mai element bach jaate hai toh ?
        while(!operators.empty()){
             ans+=(operators.top());
            operators.pop();
        }

        return ans;
}
//tc is on for bigger while , and on for outer while , so on+on
//sc is on + on , one operators stack and another string



int main() {
    
    return 0;
}