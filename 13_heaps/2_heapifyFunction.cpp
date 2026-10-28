#include <bits/stdc++.h>
using namespace std;


void heapify(vector<int>&arr , int size , int index){//from the index to bottom down heapify everything , means all its descendants not the sibling

   int leftChild=2*index;
   int rightChild=2*index +1;
   if(index>=size)return;

   while(index<=size){
        int larger=size;
        if(leftChild<=size && arr[leftChild]>arr[larger]){
            larger=leftChild;
        }

        if(rightChild<=size && arr[rightChild]>arr[larger]){
            larger=rightChild;
        }
        else{
            return;
        }

        swap(arr[size] , arr[larger]);
        index=larger;
        
   }

}

int main() {
    
    return 0;
}