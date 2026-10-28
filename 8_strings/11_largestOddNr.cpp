

/*Good. Focus only on string handling first.

When a number is stored as a string:

```cpp
string s = "57249";
```

each character is stored separately:

```cpp
s[0] = '5'
s[1] = '7'
s[2] = '2'
```

These are **characters**, not integers.

To use them like numbers:

```cpp
int digit = s[i] - '0';
```

Example:

```cpp
char ch = '7';

int num = ch - '0'; // 7
```

Why this works:

* `'0'` → ASCII 48
* `'7'` → ASCII 55

So:

```cpp
55 - 48 = 7
```

Reverse conversion:

```cpp
int x = 5;

char ch = x + '0'; // '5'
```

Important checks for digit properties:

```cpp
if((s[i] - '0') % 2 == 1)
```

or shorter:

```cpp
if((s[i] - '0') & 1)
```

You can also compare directly with characters:

```cpp
if(s[i] == '5')
```

or:

```cpp
if(s[i] >= '0' && s[i] <= '9')
```

Do small experiments yourself now:

```cpp
string s = "82471";
```

Print:

* every character
* every integer digit
* check odd/even for each

That is the real step here.
*/


//odd&1 1 aata h , even &1 mai 0 aata h
#include <bits/stdc++.h>
using namespace std;

string largestOddNr(string &s){
    int n=s.size();
    int i=n-1;
    int start;


    while(i>=0){
    if((s[i]-'0')&1){ 
        start =i; 
        break;
    }
    else i--;
    }

    if(start==-1)return "";//no odd digit exist

    int end=0;

    while(end<=start && s[start]=='0'){//keep increasing until string has starting 0's and it doesnt surpas the odd nr found
        end++;
    }


    // all zeros case
    if(start > end) return "";

   

    return s.substr(end , start-end+1);

}

int main() {
    
    return 0;
}