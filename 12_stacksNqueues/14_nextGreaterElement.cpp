#include <bits/stdc++.h>
using namespace std;

void nextGreaterEleBf(vector<int>&arr , vector<int>&res){

    //greater found variable can be eleiminated if i initialise my res array with -1 , 
    //then simply susitue res[i] with arr[j] which is greater elemnt
    

    for (int i = 0; i < arr.size(); i++) {
        bool greaterFound=false;
      for (int j = i+1; j < arr.size(); j++) {
        if(arr[j]>arr[i]){
            greaterFound=true;
            res.push_back(arr[j]);
            break;
        }

        
      }
      if(!greaterFound)res.push_back(-1);
    }
    
}

/*logic
start from the right (back traversal) of array 
then mark last elemnt as -1 in result array
and put it into stack , then last second elemnt , check the stack that whther the 
top elemnt is greater , if yes keep the top of stack in result
if no then keep popping the top elemnts until u find the biggest the elemnt

does removing elemnts destroys choices of a elemnt which is at left ?
no

suppose 3 1 2 4 6
6 is marked as -1 stakc =6
then 4 marked as 6 , stack = 6 4
2 marked as 4 , stack = 2 4 6
1 marked as  2  , stck= 1 2 4 6
3 see that top of stack is 1 
remove it , then it see 2 , remove it 
now 4 comes , mark 3 as 4 , and put 3 in stack

stack = 3 4 6
now if left elemnt comes which is less than 3 , iske rightmoset toh 3 hi rhega naa ki  1 or 2 ya removed leemnt
and agr koi bada elemnt has 3 se , toh wo toh 1 2 pe hi ni jaaega kyuki 3 se hi bada hai . koi point ni reh jaaaega 1 , 2 ka
fir 
 
*/




void nextGreaterELeStriverOpt(vector<int>&arr , vector<int>&res){//res is already initialised by -1
    stack<int>st;

    //for the last elemnt
    st.push(arr[arr.size()-1]);


    //in this i eliminte the if else fomat
    // i directly use the while loop to get to the next biggest elemnt

    for(int i = arr.size()-1;i>=0;i--){//start from twice the index
        
        
        while(!st.empty() && arr[i]>st.top()){//keep popping until largest elemnt is found or stack gets empty
            st.pop();
        }

        if(!st.empty())res[i]=st.top();//if stack is not empty just mark the elemnent if its empty means
        //no greater elemnt ws there , so leave it marked as -1
    
        st.push(arr[i]);//push the element

    }

}

//tc on for bigger for loop and inside the worst casse is while loop moving ON TIME
///SO TC BECOME O2N 
//SC IS ON

void  nextGreaterEleMyOpt(vector<int>&arr , vector<int>&res){
   
    stack<int>st;
   
    st.push(arr[arr.size()-1]);
   
    for(int i = arr.size()-2;i>=0;i--){

        if(arr[i]<st.top()){
            res[i]=st.top();
        }
        else{
            while(!st.empty() && arr[i]>st.top()){// so that i dont pop in empty stack
                //if all right elements are small , then everyone will get popped
                //but right a point when stack becomes empty then while loop will stop
                st.pop();
            }


            //there is a case when i could be having an empty case , case which i have already commented
            if(!st.empty())res[i]=st.top();
        }
        st.push(arr[i]);
    }
}//tc on for bigger for loop and inside the worst casse is while loop moving ON TIME
///SO TC BECOME O2N 
//SC IS ON

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>res;

    nextGreaterEleBf(arr , res);

    for(int i:res){
        cout<<i<<endl;
    }
    
    return 0;
}