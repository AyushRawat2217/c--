#include <bits/stdc++.h>
using namespace std;

/*nge 2
here we take the cycle of array
liek suppose the array is
1 2 5 3 6  
so we can take the search space as
1 2  5 3 6 1 2 3 3 6
eventually the game is not only of right elemnts but we cn intake the left 
elemnts like when we move father from the array's last element*/

void nextGreaterEleBf(vector<int>&arr , vector<int>&res){

    int index;

    for (int i = 0; i < arr.size(); i++) {

        bool greaterFound=false;

      for (int j = i+1; j < i+arr.size(); j++) {//i+arr.size() tkk cycle complete ho skti hai
        
        index=j%i;

        if(arr[index]>arr[i]){
            greaterFound=true;
            res.push_back(arr[j]);
            break;
        }
      }

      if(!greaterFound)res.push_back(-1);

    }
    
}

void nextGreaterELeStriverOpt(vector<int>&arr , vector<int>&res){//res is already initialised by -1
    stack<int>st;

    //for the last elemnt
    st.push(arr[arr.size()-1]);
   
    int index;

    //in this i eliminte the if else fomat
    // i directly use the while loop to get to the next biggest elemnt

    for(int i = 2*arr.size()-1;i>=0;i--){
        index=i%(arr.size());
        while(!st.empty() && arr[index]>st.top()){//keep popping until largest elemnt is found or stack gets empty
            st.pop();
        }

        if(i<arr.size()&&!st.empty())res[i]=st.top();//if stack is not empty just mark the elemnent if its empty means
        //no greater elemnt ws there , so leave it marked as -1
    // if cycle was not there then last elemnt -1 hota
    //prr cycle i kelp se ham 2 time arr.size se start krenge and stack bnanege
    //jo hame last elemnt ke liye ek greater elemnt dene ki help krega ho bhi skta hai ya nhi
    //prr ham result ke and i<n se hi dLENEGE
        st.push(arr[index]);//push the element

    }

}

int main() {
    
    return 0;
}