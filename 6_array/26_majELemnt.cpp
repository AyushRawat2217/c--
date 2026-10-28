#include <bits/stdc++.h>
using namespace std;

//gareeb method , method used by small kids
void majEleBf(vector<int>&arr){
    int n=arr.size();
    int count;
    for (int i = 0; i < n; i++) {
        count=0;

      for (int j= i; j < n; j++) {
        if(arr[i]==arr[j]){
            count++;
        }
        
      }
      if(count>(n/3)){
        cout<<arr[i]<<endl;
      }
      count=0;
    }

}





//brute force but cool shit

/*logic is we know a array cant have more than two majority elemnts 
as suppose a >n/3 , b>n/3 , c>n/3 ? this c thing is not possible 
so we use this when we get elemnts more than 2 we break and move out
*/
vector <int> majEleBf2(vector<int>&arr){
    int n=arr.size();
    vector<int>newArr;
    int count;
    for (int i = 0; i < n; i++) {
        count=0;

        if(newArr.size()==0||newArr[0]!=arr[i]){ //to eliminate duplicate elemnts

      for (int j= i; j < n; j++) {
        if(arr[i]==arr[j]){
            count++;
        }
        
      }
      if(count>(n/3)){
        newArr.push_back(arr[i]);
      }
      if(newArr.size()==2){
        break;
      }
    
    }
}
return newArr;

}




/*
logic is we use hash map , we store frewuency of elemnts
it reduce tc to o(n.logn) logn for insertion inside the map
and

another approach to reduce space complexity to o1 , we can first
sort the array then use a single loop
*/
void majEleBr(vector<int>&arr){
    int n=arr.size();

    unordered_map<int,int>mpp;

    for (int i = 0; i < n; i++) {
      mpp[arr[i]]++;
    }

    for(auto &it:mpp){
      if(it.second>(n/3)){
        cout<<it.first<<endl;
      }
    }
}

void majEleBr(vector<int>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int count=1;
    vector<int>result;

    for (int i = 0; i < n-1; i++) {
      if(arr[i]==arr[i+1]){
        count++;
      }

      else{
        if(count>(n/3)){
          cout<<arr[i]<<endl;
        }
        count=1;
      }
    }
      

}




/*logic - dekh hamne ek baar elemnt greater than n/2  times wala code solve kiya tha
ki ek elemnt lo , agr nrxt elemnt uske equal ni h toh uska count reduce krdo , agr count 0 hogya toh 
potential elemnt ki value chnage
toh same concept we will use with n/3 wala concept , we will use 2 variables 2 counts


n/n1
n1-1
*/
vector<int>majEleOPt(vector<int>&arr){
  int n=arr.size();
  int ele1 , ele2 , cnt1 , cnt2;
  ele1=INT_MIN;
  ele2=INT_MIN;
  cnt1=0;
  cnt2=0;

  for (int i = 0; i < n; i++) {


    if(cnt1==0 && ele2!=arr[i]){ //if cnt =0 . n ele1 n ele 2 are diff(so both dont store same vale) then assign ele1 as arri
      ele1=arr[i];
    }
    else if(cnt2==0 && ele1!=arr[i]){// ,,
      ele2=arr[i];
    }
    else if(arr[i]==ele1){
      cnt1++;
    }
     else if(arr[i]==ele2){
      cnt2++;
    }

    else{ //if current elemnt doesnt match , deduct the value
      cnt1--;
      cnt2--;
    }
    
  }

}






int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // vector<int>result=majEleBf2(arr);
    majEleBr(arr);
    return 0;
}