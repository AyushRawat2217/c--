#include <bits/stdc++.h>
using namespace std;

int searchInsertPosn(vector<int>& arr, int x) {

    // SEARCH SPACE: indices of sorted array
    int low = 0;
    int high = arr.size() - 1;

    // DEFAULT ANSWER:
    // If no element >= x is found, insert at end
    int ans = arr.size();

    // BINARY SEARCH LOOP → keep shrinking search space
    while (low <= high) {

        // SAFE MID (avoids overflow, standard discipline)
        int mid = low + ((high - low) / 2);

        // CORE CONDITION:
        // We are looking for FIRST index where arr[mid] >= x
        if (arr[mid] >= x) {

            // mid is a VALID candidate position
            ans = mid;

            // BUT there might be a smaller valid index on the LEFT
            // so we continue searching left half
            high = mid - 1;

        } else {

            // arr[mid] < x → too small, discard left half
            // move to right half
            low = mid + 1;
        }
    }

    // FINAL ANSWER:
    // smallest index where arr[i] >= x
    return ans;
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