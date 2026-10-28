//using maps first to catch 0 1 2 then putting omn a array it takes up the space

#include <bits/stdc++.h>
using namespace std;

void sortit(vector<int>&arr){
    int left=0;
    int right=arr.size()-1;
    int mid=0;//suppose that first elemnt is 2 , i will firsthandly send it to the right

    while(mid<=right){
        if(arr[mid]==0)swap(arr[mid] ,arr[left]) , left++ , mid++;//we can safely increase mid becaus ebehind it everthing is sorted

        else if(arr[mid]==1)mid++;//if mid is stuck ar one while traversing and its value is 1 then move one up

        else swap(arr[mid] ,arr[right]) , right--;//we dont increase the mid because the swapped elemnt from right could be unsorted
       
    }

}

int main() {

    
    return 0;
}