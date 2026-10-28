#include <bits/stdc++.h>
using namespace std;

vector<int>nextSmallerELemntBf(vector<int>&arr ){
    vector<int>res(arr.size() , -1);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i+1; j< arr.size(); j++) {
            if(arr[j]<arr[i]){//jese hi chota elemnt mile , push krdo
                res[i]=arr[j];
                break;
            }
        }
    }
    return res;
}// tc is on2  , sc is on

void nextSmallerELemntOpt(vector<int>&arr){
    vector<int>res(arr.size() , -1);

    stack<int>st;
    st.push(arr[arr.size()-1]);

    for (int i = arr.size()-2; i >=0; i--) {
        while(!st.empty() && arr[i]<=st.top()){
            st.pop();
        }

        if(!st.empty())res[i]=st.top();
        
        st.push(arr[i]);
    }
}

int main() {
    
    return 0;
}