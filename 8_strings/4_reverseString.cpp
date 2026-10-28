#include <bits/stdc++.h>
using namespace std;

//reverse(s.begin(), s.end())
//tc 0n , sc 01


string reverseStringBf(string &s){
    string s2="";
    for (int i = s.size()-1; i >=0 ; i--) {
      s2+=s[i];
    }

    return s2;

}

void reverseStringBr(string &s){//void because we pass the refrence so main string changes

    int left=0;
    int right= s.size()-1;

    while(left<right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
   

}



int main() {
    string s;
    cin>>s;

    cout<<reverseStringBf(s);

    return 0;
}