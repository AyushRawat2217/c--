#include <bits/stdc++.h>
using namespace std;

/*
A sequence of packages (weights array)
A fixed deadline → d days
A ship with limited capacity per day

➡️ Find the minimum ship capacity that still gets all packages delivered within d days

Weights = [5, 4, 5, 2, 3, 4, 5, 6]

either we can carry whole or nothing
we cant carry half
like if we choose capacity to be 2 , then weight 5 item cant be carried
so min capacity should be the max elemnt in the array
and max capacity will be maximum capacity = sum of all weights

Weights:
[5, 4, 5, 2, 3, 4, 5, 6]

Total sum = 34

🚚 Scenario: Capacity = 34

Let’s simulate:

Day 1

5 + 4 + 5 + 2 + 3 + 4 + 5 + 6 = 34
✔ All packages loaded in one go
📊 Result
Days used = 1
Always satisfies any d ≥ 1

*/
int minNrOfShips(vector<int>&arr , int Dday){
    int n= arr.size();
    int maxx=INT_MIN;
    int sum=0;
    for(int i:arr){
        maxx=max(maxx,i);
        sum+=i;
    }

    for (int i = maxx; i <=sum; i++) {//i is the capacity of ship
        int days=1;//start is day 1
        int capacity=0;
      for (int j = 0; j < n; j++) {//arr[j] is the wieght of the product
        if(capacity+arr[j]>i){ //old cap + new load if > i , then move to next day and reset cap for that particular weight
            days++;
            capacity=arr[j];
        }
        else{//capacity is less than i then keep stakcing
            capacity+=arr[j];
        }

      }

      if(days<=Dday){
        return i;
      }
    }

    return -1;

}



//opt approach

int nrOfDays(vector<int>&arr,int mid ,int Dday ){
    int n=arr.size();
    int days=1;
    int capacity=0;
    for (int i = 0; i < n; i++) {
        if(capacity+arr[i]<mid){
            capacity+=arr[i];
        }
        else{
            days++;
            capacity=arr[i];
        }
        if(days>Dday) return days; 
    }

    return days;
    

}
int minNrOfShipsOpt(vector<int>&arr , int Dday){
    int n= arr.size();
    int maxx=INT_MIN;
    int sum=0;
    for(int i:arr){
        maxx=max(maxx,i);
        sum+=i;
    }
    int low = maxx;
    int high=sum;
    int ans=-1;


    while(low<=high){
        int mid=low+(high-low)/2;//mid represents the capacity of ships we are taking

        if(nrOfDays(arr , mid , Dday)<=Dday){
          high=mid-1;
        }
        else{ 
           low=mid+1;
        }

    }

    return low;
}



int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}