#include <bits/stdc++.h>
using namespace std;
string pldrm(string &word,int i, int j){
    if(i>=j){
        return "yes";
    }
    if(word[i]!=word[j]) return "no";
    return pldrm(word,i-1,j+1);


}
int main() {
string word;

cin>>word;

string str=pldrm(word,word.size()-1,0);
cout<<str;
return 0;
}