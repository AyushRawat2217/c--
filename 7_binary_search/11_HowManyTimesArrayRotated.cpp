#include <bits/stdc++.h>
using namespace std;

int NrOfTimesBF(vector<int>&arr){
    /*
    
    index of the smallest element will be the nr of times array is 
    rotated , dekh jb sorted rha hoga uska index zero hoga
    fir wo rotate hokr khi phucha toh jis index p phucha vhi nr of rotation h
    
    pehle arr[0] lko wo min ele maan lenge fir compare krke min elemnt find krenege sbse 
    uski index store krke return krdenge*/
}

int NrOfTimesBr(vector<int>&arr){
    /*
    jis point p order p order break hua whi tkk rotate hua h or kya

    */
}


int NrOfTimesOpt(vector<int>&arr){
    int low=0;
    int high=arr.size()-1;
    int mid;
    int nr;


    //we had to return the index of the minimum elemnt

    while(low<=high){
        mid=low+(high-low)/2;


 if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                // Else smallest element is at mid or to the left
                high = mid;
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