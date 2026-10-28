#include <bits/stdc++.h>
using namespace std;

void phoneBookCombo(string num ,int index ,string val , vector<string>&result , string combos[]){

    if(index==num.size()){
        result.push_back(val);
        return ;
    }

    int digit = num[index]-'0';

    for (int i = 0; i < combos[digit].size(); i++) {
      
        phoneBookCombo(num , index+1 ,val+combos[digit][i] , result , combos);
    }
}

vector<string>helperFunct(string num , vector<string>&result){
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    //from 0 -9 , indexes are mapped to their respective strings
    phoneBookCombo(num ,0,"" , result , combos);

    return result;
}

int main() {
    
    return 0;
}