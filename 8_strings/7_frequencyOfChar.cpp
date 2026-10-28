#include <bits/stdc++.h>
using namespace std;
/*given a string and we have to find frequency of every elemnt
from the string*/
vector<int>frquencyArray(const string &s){
    vector<int>freq(26 , 0);
    for(char ch:s) {
            if(islower(ch)) {
        freq[ch - 'a']++;
    }

    }
    return freq;
}


int main() {
    string s;
    cin>>s;
    return 0;
}