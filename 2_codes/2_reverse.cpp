#include <bits/stdc++.h>
using namespace std;

bool reverse(int n)
{
    int a = 0;
    int b=n;
    while (b > 0)
    {
        a = a * 10 + (b % 10);

        b =  b/ 10;
    }

    return (a);
}
int main()
{
    int n;
    cin >> n;
    cout << (reverse(n));

    return 0;
}