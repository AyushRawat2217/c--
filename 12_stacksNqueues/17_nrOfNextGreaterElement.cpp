#include <bits/stdc++.h>
using namespace std;

vector<int> nrOfNxtGr8erELeBf(vector<int>&arr){
    vector<int>res(arr.size() , -1);
    int count;
    for (int i = 0; i < arr.size(); i++) {
         count=0;
        for (int j = i+1; i < arr.size(); j++) {
            if(arr[i]<arr[j])count++;
      }
      res[i]=count;
    }
    return res;
}


vector<int> nrOfNxtGr8erELeOpt(vector<int>&arr , vector<int>&res){
    stack<int>st;

    for (int i = 0; i < arr.size(); i++) {
      
    }

}


int main() {
    
    return 0;
}