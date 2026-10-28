#include <bits/stdc++.h>
using namespace std;

int maxBwTheIndex(int left , int right , vector<int>&arr){
    int maxx=INT_MIN;
    for (int i = left; i <=right; i++) {
      maxx=max(maxx , arr[i]);
    }
    return maxx;
}

void maxNrOfWindowBf(vector<int>&arr , int size , vector<int>&result){
    int left=0;
    int right=size-1;

    while(right<arr.size()){
       result.push_back(maxBwTheIndex(left , right , arr));
        right++;
        left++;
    }

}


        //OPTIMAL APPROACH using monotonic deque

void maxNrOfWindowOpt(vector<int>&arr , int size , vector<int>&result){
    deque<int>dq;

    for (int i = 0; i < arr.size(); i++) {
      while(!dq.empty() && dq.front()<=(i-size)){//if elemnt is outiside the wimdow remove it , for index k , element 
        dq.pop_front();
      }

    
      while(!dq.empty() && arr[dq.back()]<arr[i]){
        dq.pop_back();
      }

      dq.push_back(i);

       if (i >= size - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
}




int main() {
    
    return 0;
}