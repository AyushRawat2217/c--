#include <bits/stdc++.h>
using namespace std;

//hoare
  int partition(int arr[],int  low, int high){
   int  pivot = arr[low];
   int  i = low - 1;
    int j = high + 1;
    while(true){

        //move to next element before checking 
        do i++; while(arr[i] < pivot);
        do j--; while(arr[j] > pivot);

        if(i >= j) return j;
        swap(arr[i], arr[j]);
    }
}














    






void quick_sort(int arr[] , int low , int high){

    if(low>=high){
        return;
    }

    int pivotIndex=partition(arr ,low ,high);
    quick_sort( arr, low,pivotIndex);
    quick_sort(arr,pivotIndex+1 ,high );




}
int main() {

     int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "enter" << i;
        cin >> arr[i];
    }

    quick_sort(arr,0,n-1);


    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }



return 0;
}



