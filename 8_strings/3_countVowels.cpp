#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    string vowel="aeiouAEIOU";

    string test;
    cin>>test;
    int count=0;

    for(char ch:test){
        if(vowel.find(ch)!=string::npos){//npos means not found
            count++;
        }
    }

    cout<<count;

    return 0;
}

/*if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
THIS APPROACH IS WORKABLE AS WELL*/