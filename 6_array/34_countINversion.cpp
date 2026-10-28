#include <bits/stdc++.h>
using namespace std;

int countINverBf(vector<int>&arr){
    int n=arr.size();

    int count;
    
    for (int i = 0; i < n; i++) {
        for (int j= i+1; i<n; i++) {

            if(arr[i] > arr[j]){
                count++;
            }
          
        }
      
    }
}




//in opt approach we have to use merge sort


//step 3
int mergeAndSort(vector<int>&arr , int low , int mid , int high){
    vector<int>temp;

    int left=low;
    int right=mid+1;

    int count =0 ;


    while(left<=mid && right<=high){ //moving from left to mid and mid to highest to check elemnts

    if(arr[left]>arr[right]){
        count+=mid-left+1; //“Since left half is sorted, if arr[left] > arr[right], then all elements from left to mid are greater than arr[right]”
        temp.push_back(arr[right++]);
    }
    else{
        temp.push_back(arr[left++]);
    }
    }

    while(left<=mid){
        temp.push_back(arr[left++]);
    }

    while(right<=high){
        temp.push_back(arr[right++]);
    }

     //copying the element of temp to array
    for (int i = low; i <= high; i++)arr[i] = temp[i - low];

    /*
    point of copying the array elemnt is
    hrr baari jbh bhi recursive call hogi toh naya temp vector bnega for a specific low mid high
    toh jo elemnts sort kre h unko apni correct position m dalna hoga taaki progress continued
    rahe , jese 0,1,2 sort krne k liye 0,1 sorted hona chiye wo merge 0,0,1 wale case m hua hoga
    fir temp ne apni value arr m copy krdi.
    */
    return count;
}

//step 2
int breakToSmaller (vector<int>&arr , int low , int high){ //it will break array until individual elemnts
    
    if(low>=high){ //base condition when recursion will break
        return 0;
    }
    int mid=(high+low)/2;

    //Execution is depth-first ,Merge happens while coming back UP the recursion stack.
    int left= breakToSmaller(arr , low , mid); //breaking the left side 
    int right=breakToSmaller(arr , mid+1 ,high ); //breaking the right side
    
    int cross= mergeAndSort(arr, low  , mid , high); // for the full array , separated the mid elemnts so we get cross pairs



    /*we have to Take cross pairs too  , why?? because till now we were dealing with only
    cross pairs inside left and right block

    [6, 3, 2, 1]
    Left half:
    [6,3] → inversions = 1
    Right half:
    [2,1] → inversions = 1
    Cross:
    (6,2), (6,1), (3,2), (3,1) → 4
    TOTAL:
    1 + 1 + 4 = 6*/

    return left+right+cross;   
    
}

/*

how array gets broken down from 0-5 to 0-2 and 3,5 
then 0-2 broke to 0-1 , 2,2


mergeSort(0,5)
 ├── mergeSort(0,2)
 │    ├── mergeSort(0,1)
 │    │    ├── mergeSort(0,0)
 │    │    └── mergeSort(1,1)
 │    │    → merge(0,0,1)  //here merge happen
 │    └── mergeSort(2,2)
 │    → merge(0,1,2)
 │
 └── mergeSort(3,5)
      ├── mergeSort(3,4)
      │    ├── mergeSort(3,3)
      │    └── mergeSort(4,4)
      │    → merge(3,3,4)
      └── mergeSort(5,5)
      → merge(3,4,5)

→ merge(0,2,5)

*/


//step 1
int countINverOpt(vector<int>&arr){
    int n=arr.size();

    return breakToSmaller(arr , 0 , n-1); //recursion starts from here
 
}




int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result=countINverOpt(arr);
    cout<<result;


    return 0;
}