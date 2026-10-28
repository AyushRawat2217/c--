

#include <bits/stdc++.h>
using namespace std;


void merge_sort(int arr[],int low ,int mid,int high){

    vector<int> temp;
     int left=low;
    int right=mid+1;



//comparing elemts of left and right sub array
       while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }


        // Add remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Add remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        

    //copying the element of temp to array
    for (int i = low; i <= high; i++)arr[i] = temp[i - low];
    

} 

//this breaks the array into pairs recursively and at the last stage when
//there are only 2 elemnts remaining then it recuses back to main array getting everthing sorted
void break_arr(int arr[],int low ,int high){

    if(low>=high) return;
    int mid= (low+high)/2;

    break_arr(arr, low,mid);
    break_arr(arr, mid+1,high);

    merge_sort(arr,low,mid,high);

}


/*

mergeSort(0,5)
 ├── mergeSort(0,2)
 │    ├── mergeSort(0,1)
 │    │    ├── mergeSort(0,0)
 │    │    └── mergeSort(1,1)
 │    │    → merge(0,0,1)
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



int main() {

     int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "enter" << i;
        cin >> arr[i];
    }

    break_arr(arr,0,n-1);


    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

return 0;
}