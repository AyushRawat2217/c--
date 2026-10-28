#include <bits/stdc++.h>
using namespace std;

bool operand(char ch){}

string postfix2infix(string &oprtn){
    
    stack<string>st;
    int i=0;

    while(i<oprtn.size()){
        if(operand){//i pushed operands into the stack
            st.push(string(1 , oprtn[i]));//this because if i just send the oprtn[i] thst i a character
            //and stack will not accep it
        }
        else{//if elemnt is an operation , take last two operands join them using that operator
            //and enclose them in bracket

            string ch1=st.top();
            st.pop();
            string ch2=st.top();
            st.pop();

            st.push('('+ch2+oprtn[i]+ch1+')');//notice we merge last second and last elemnt . last second comes first
        }

        i++;

    }

    return st.top();

//tc is ON+O(N1+N2) , ON FOR BIGGER WHILE LOOP AND N1+N2 KYUKI ADDITION OF STRINGS TAKE TIM , N1 IS LEN
//OF FIRST STRIG AND N2 IS LENGHT OF 2ND STRING
//SC IS ON
}


int main() {
    
    return 0;
}