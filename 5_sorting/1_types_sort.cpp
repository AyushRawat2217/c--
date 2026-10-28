#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{

    for (int i = 0; i <= n - 2; i++)
    {

        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void bubble_sort(int arr[], int n)
{

    for (int i = (n - 1); i >= 1 - 2; i--)
    {

        for (int j = 0; j <= i; j++)
        { // here max element goes at last automatically
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "enter" << i;
        cin >> arr[i];
    }

    // selection_sort(arr,n);

    // bubble_sort(arr,n);

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}