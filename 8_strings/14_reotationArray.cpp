#include <bits/stdc++.h>
using namespace std;

/*15:31 

how to rotate a string?
if rotating by 1 unit shift forward by 1 unit
if abc
rotate 1 unit
cab
*/
string rotatedStringByIunits(const string &s , int unit){
    
    int n= s.size();

    if(unit==0)return s;// rotate by 0 give same string 
    string duplicate(n, ' ');

    unit = unit%n;
    /*Example:

n = 6;
unit = 8;

unit %= n;   // unit = 8 % 6 = 2

Why?

Rotating a string of length 6 by 8 positions is the same as rotating it by 2 positions.

abcdef
rotate right by 6 -> abcdef  (back to original)
rotate right by 8 -> rotate right by 2*/


    for (int i = 0; i < n; i++) {
        if(i<unit)duplicate[i]=s[n-unit+i];

        //i>=unit
        else duplicate[i]=s[i-unit];


        /*instead wrting this if else we can simply write
        result[(i + unit) % n] = s[i];


        the patter in new_index = (old_index + unit) % n

        
        */
    }
    return duplicate;
}
/*creating every rotated array then checking it with orignal array 
then return true if mathc is found otherwise not returnoing match returning 
false
*/
bool isStringRotatedOrNotBf(string &original , string &rotated){
    int n1=original.size();
    int n2 = rotated.size();


    if(n1!=n2)return false;

    for (int i = 0; i < n1; i++) {
        if(rotatedStringByIunits(original,i)==rotated)return true;
    }
    return false;
}



/*now we will try to write a code where we dont need to 
write every possible rotation

logic we use is we double the orginal string
ad beauty is orginal+orignal contations all rotated combos
and find rotated string in double strings if found return true else false*/

bool isStringRotatedOrNotBr(string &original , string &rotated){
    int n1=original.size();
    int n2 = rotated.size();

    if(n1!=n2)return false;

    string doubleOriginal=original+original;

    return doubleOriginal.find(rotated)!=string::npos;



    
}




/*till now also space complexity is on
to reduce it we use reverse method logic is


The reverse method rotates a string **in-place** using 3 reversals.

Let's rotate right by `k = 2`.

```text
abcdef
```

Desired result:

```text
efabcd
```

### Step 1: Reverse the entire string

```text
abcdef
↓
fedcba
```

Code:

```cpp
reverse(s.begin(), s.end());
```

---

### Step 2: Reverse the first `k` characters

Here `k = 2`.

```text
fedcba
^^
```

Reverse `"fe"`:

```text
efdcba
```

Code:

```cpp
reverse(s.begin(), s.begin() + k);
```

---

### Step 3: Reverse the remaining characters

```text
efdcba
  ^^^^
```

Reverse `"dcba"`:

```text
efabcd
```

Code:

```cpp
reverse(s.begin() + k, s.end());
```

Result:

```text
efabcd
```

---

### Why does this work?

Suppose:

```text
abcdef
```

Split into:

```text
abcd | ef
```

For a right rotation by 2, we want:

```text
ef | abcd
```

The reversal trick rearranges these blocks without extra memory:

1. Reverse everything:

   ```text
   dcba | fe
   ```

2. Reverse first block:

   ```text
   ef | dcba
   ```

3. Reverse second block:

   ```text
   ef | abcd
   ```

Done.

---

### Complete code

```cpp
void rotateRight(string& s, int k) {
    int n = s.size();
    if (n == 0) return;

    k %= n;

    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
}
```

### Example

```cpp
string s = "abcdef";
rotateRight(s, 2);

cout << s;   // efabcd
```

### Complexity

* Time: **O(n)**
* Extra Space: **O(1)**

That's why this is considered the optimal in-place rotation algorithm.
*/

/*
void rotateRight(string& s, int unit) {
    int n = s.size();
    if (n == 0) return;

    unit %= n;

    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + unit);
    reverse(s.begin() + unit, s.end());
}

we  can use this method in burte force to keep space complexity
o1

*/



int main() {
    
    return 0;
}