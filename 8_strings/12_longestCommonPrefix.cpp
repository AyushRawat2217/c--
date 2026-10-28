#include <bits/stdc++.h>
using namespace std;

/*the logic is we use sorting for this , we arrange all
string in array lexographically then we weill compare first and last
as the words which are common bw first and last they will obviosly be in mid ones too

first has i and last has i , then mid ones will have i tpo
first has ib last has ic ,then mid ones would be having b and c , no toher if first is ib
and last is ic then common is i only 

tc is o nlogn*m*/
string longestCommonPrefixBr(vector<string>&arr){//arr is the list of strings given 

    int n=arr.size();
    int i=0;

    sort(arr.begin() , arr.end());

    string first=arr[0];
    string last= arr[n-1];
    int o=first.size();
    int m=last.size();
    string str;


    for (int i = 0; i < o; i++) {
        if(first[i]==last[i] && i<m)str+=first[i];
        //instead of using i<m , i could take the string which is min inn length using 
        //int minLen = min(first.size(), last.size());

        else break;
    }


    return str;

}


string longestCommonPrefixOpt(vector<string>&arr){//arr is the list of strings given 

    int n=arr[0].size();
    int i=0;

    string str;
    while(i<n){
        int count=1;
        char word=arr[0][i];
        for (int j = 1; j <arr.size(); j++) {
           // stop if string ends OR mismatch occurs
            if(word!=arr[j][i] || i>arr[j].size())return str;
        }
        str+=word;
        i++;
        
    }

    return str;



}

string longestCommonPrefixOpt(vector<string>&arr){//arr is the list of strings given 

    int n=arr[0].size();
    int i=0;

    string str;
    while(i<n){
        int count=1;
        char word=arr[0][i];
        for (int j = 1; j <arr.size(); j++) {
           // stop if string ends OR mismatch occurs
            if(word!=arr[j][i] || i>arr[j].size())return str;
        }
        str+=word;
        i++;
        
    }

    return str;



}

int main() {
    
    return 0;
}