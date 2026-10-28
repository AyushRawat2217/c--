#include <bits/stdc++.h>
using namespace std;

bool balancedParenthesisUsingStack(string &str) {
    stack<char> st;
    string openBrackets = "([{";

    for (int i = 0; i < str.size(); i++) {

        // If current character is an opening bracket
        if (openBrackets.find(str[i]) != string::npos) {
            st.push(str[i]);
        }

        // Otherwise, it is a closing bracket
        else {
            // No opening bracket available
            if (st.empty())
                return false;

            char close = str[i];
            char open = st.top();

            // Check whether they form a valid pair
            if ((open == '{' && close == '}') ||
                (open == '(' && close == ')') ||
                (open == '[' && close == ']')) {

                st.pop();
            }
            else {
                return false;
            }
        }
    }

    // If stack is empty, every opening bracket was matched
    return st.empty();
}

int main() {

    string str = "{[()]}";

    if (balancedParenthesisUsingStack(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}