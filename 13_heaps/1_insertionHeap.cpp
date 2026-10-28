#include <bits/stdc++.h>
using namespace std;
/*heap basics
there is a binary tree 
and its feeded inside an array
where if node is at ith index
its left child will be at 2*i and right child at 2*i+1
and parent at i/2 */

class heaps{

    public:
    int arr[100];
    int size=0;

    void insertion(int val){
        /*
Put the new element at the last position.
Compare it with its parent.
If the new element is greater than its parent, swap.
Now check its new parent.
Keep doing this until the element is not greater than its parent or it reaches the root.*/
       
        
        size++;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent=index/2;//parent is at half the index of child

            if(arr[parent]<arr[index]){
                swap(arr[parent] , arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }

    }

    void deletion(){//i
        if(size==0)return;
        arr[1]=arr[size];//mount the max elemnt at the end

        size--;
        int index=1;
        while(index<=size){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            int larger;
            
            if(index<=size && arr[leftChild]>arr[larger]){
                larger=leftChild;
            }

            if(index<=size && arr[rightChild]>arr[larger]){
                larger=rightChild;
            }

            if(index==larger){//means parent is already bigger
                return;
            }

            swap(arr[index] , arr[larger]);
            index=larger;
        }


    }

};


int main() {
    
    return 0;
}