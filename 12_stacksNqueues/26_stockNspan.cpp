#include <bits/stdc++.h>
using namespace std;

/*i have to find consecutive nr of days when stocks are less than
or equal to current day*/
vector<int> stockSPanBf(vector<int>&arr){
    vector<int>result(arr.size() , 1);

    for (int i = arr.size()-1 ; i >0; i--) {
       int  count=1;
      for (int j = i-1; j >0; j--) {
         if( arr[i]>=arr[j] )count++;
         else break;
      }
      result[arr.size()-i-1]=count;
    }

    return result;
}//its tc on2


            //OPTIMAL APPROACH
            //USING PGE(previous greater elemnent)

vector<int> stockSPanBf(vector<int>&arr){
    vector<int>pge(arr.size() , -1);
    vector<int>result(arr.size());
    stack<int>st;
    st.push(0);

    //function to find previous greater element
    for (int i = 1 ; i<arr.size(); i++) {
       while(!st.empty() && arr[st.top()]<=arr[i]){//we want to incli
        st.pop();
       }

       if(!st.empty())pge[i]=st.top();

       st.push(i);
    }

    for (int i = 0; i < arr.size();i++) {
      result[i]=i-pge[i];
    }
    return result;

}


int main() {
    
    return 0;
}