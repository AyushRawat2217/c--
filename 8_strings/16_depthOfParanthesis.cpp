#include <bits/stdc++.h>
using namespace std;

/*logic is so whenver i face ( it means im one level deepr and 
whenver i face ) im above one level

'(' → go one floor deeper
')' → come one floor up


((()))


(  depth = 1
(  depth = 2
(  depth = 3
)  depth = 2
)  depth = 1
)  depth = 0


*/


int depthOfParenthesis(const string &s){

    int depthCount=0;
    int maxDepth=0;
//dont use INT_MIN because what if no parenthesis arehtere then program will return INT MIN
//its always better to give a realistic value to whatver variable u r initialiosing
    

for(char ch:s){
        if(ch=='(')depthCount++;
        else if(ch==')')depthCount--;

        maxDepth=max(maxDepth,depthCount);
    }

    return maxDepth;
}

int main() {
    
    return 0;
}