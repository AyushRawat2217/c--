
//stereo , i will be fkd up
#include <bits/stdc++.h>
using namespace std;

void lftRotateByDrev(vector<int>& arr, int n , int d){

    //time cplexity is o(d+n-d+n)=o2n , but extra space complexity is o1

    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.begin()+n);
    reverse(arr.begin(), arr.begin()+n);




    
}


void lftRotateByD(vector<int>& arr, int n , int d){

    // tc is o(d +n-d+d= o(n+d) extra space complexity is o(d)



    int temp[d];

    for (int i=0;i<d;i++){ // storing the first d elemnts
        temp[i]=arr[i];
    }


    for (int i=d;i<n;i++){
        arr[i-d]=arr[i]; // pushing elemnts d - n to 0-d place
 
    }

    for(int i=n-d ; i<n;i++ ){

        arr[i]=temp[i-(n-d)]; //inserting the elemnts which we put inside temp

    }
//dry run it

}

void lftRotateByOne(vector<int>& arr, int n) {
    int temp = arr[0];

    for(int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    for(int x : arr) {
        cout << x << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int d ;
    cin>>d;

    vector<int> arr(n); //rither specify size of vector or use pushback  

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    lftRotateByDrev(arr, n , d);

     for(int i = 0; i < n; i++) {
        cout<< arr[i]<<" ";
    }

    return 0;
}
