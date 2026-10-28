#include <bits/stdc++.h>
using namespace std;
void reverse (int arr[],int i,int j){
    

    if(i<=j){
        swap(arr[i],arr[j]);
        return reverse(arr,i+1,j-1);

    }
    else{
    
for(int i = 0; i < 5; i++) {
    cout << arr[i] << endl;
}
return;

}
}
int main() {
   
    int arr[5]={1,2,3,4,5};
    reverse(arr,0,4);
    return 0;


}