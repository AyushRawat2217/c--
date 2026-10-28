#include <bits/stdc++.h>
using namespace std;

bool operand(char ch){

}

string postfix2prefix(string &oprtn){
    stack<string>st;
    int i=0;

    while(i<oprtn.size()){


        if(operand){// push operands into the stack
            st.push(string(1 , oprtn[i]));//this because if i just send the oprtn[i] thst i a character
            //and stack will not accep it
        }

        else{//if elemnt is an operator , put the operator before then take the last secoand the last element of stakc
            //then all alll three operator n last 2nd ele and last elemnt and push it into the stack

            string ch1=st.top();
            st.pop();
            string ch2=st.top();
            st.pop();

            st.push(oprtn[i]+ch2+ch1);//notice we merge  oprtr , last second last and last  elemnt

        }
        i++;

    }

    return st.top();

}// tc is on +o (n1+n2) , sc is on

int main() {
    
    return 0;
}