#include <bits/stdc++.h>
using namespace std;

bool palindromeChecker2ptr(const string &s){//use original directly to acoid copy but do not allowa chnages that what const + & means
    int left=0;
    int right= s.size()-1;

    while(left<right){
        if(s[left]!=s[right]) return false;
        left++;
        right--;
    }

    return true;
}

int main() {
    string s;
    cin>>s;
    return 0;
}