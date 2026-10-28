#include <bits/stdc++.h>
using namespace std;

//1601
//we have to find a subaaray of size k with max sum
int fun(vector<int>&arr , int k , int n){
    int start=0;
    int end=k-1;

    int KeleSUm=0;
    for (int i = 0; i < k; i++) {
    KeleSUm+=arr[i];
    }
    int maxx=KeleSUm;

    for(int i=k;i<n;i++){
        KeleSUm=KeleSUm-arr[i-k]+arr[i];
        maxx=max(KeleSUm , maxx);
    }

    return maxx;

}

int main() {
    
    return 0;
}