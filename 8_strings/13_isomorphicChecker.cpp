#include <bits/stdc++.h>
using namespace std;
/*logic used here is
if key is repeated check its previous value if its same move otherwise return false
if key is unique then add the key so in future we check again*/

bool isomorphicStringsCheckerBr(string &s1 , string &s2){
    int n1= s1.size();
    int n2=s2.size();
    if(n1!=n2) return false;

    unordered_map<char , char>mpp1;
    unordered_map<char , char>mpp2;

    for (int i = 0; i < n1; i++) {
        char key=s1[i];
        char value = s2[i];

        //map.count(key) , to tell if key exist or not , if exist then give 1 , if not then 0
        if(mpp1.count(key)  &&  mpp1[key]!=value){//instead of nested i used and
            return false;//value in this case is the current value of repeated key
        }
        else mpp1[key]=value;


        /*we need second map becuase sometime
        Why do we need TWO maps?

Look at:

s1 = "ab"
s2 = "aa"
Index 0
a -> a

Store.

Index 1
b -> a

Now:

a -> a
b -> a

Two different letters are trying to become the same letter.

Not allowed.

❌ Return false.

A single map s1 -> s2 won't easily catch this. That's why we also keep:

s2 -> s1

Think of the maps as two attendance registers:

mp1:
s1 letter → corresponding s2 letter

mp2:
s2 letter → corresponding s1 letter

At every step we verify:

Have I made this promise before?
If yes, am I keeping the same promise?

That's the entire algorithm. */

        if(mpp2.count(value)&&mpp2[value]!=key){//value for mpp1 is key for mpp2 in this case
            return false;//value in this case is the current value of repeated key
        }
        else mpp2[value]=key;

    }
    
    return true;
}

//tc is o N , space is o N

/*Forward map:
same character in s1 must always map to same character in s2

Reverse map:
two different characters in s1 cannot map to the same character in s2*/


/*logic is-:
we created two array , to encouter all ascii charcaters
lets say two charcter comes we store them as both have 0 and 0 value 
we store them as i+1 if both occured toegther then they will have i+1 as values 
but if any of them has occured before with other they will be havein (that differt i)+1 as its values
and when its detected then it will return false  */

bool isomorphicStringsCheckerOpt(string &s1 , string &s2){
    int n1= s1.size();
    int n2=s2.size();
    if(n1!=n2) return false;

    /*as string elemnent can be any ascii charaters
    and ascii has 256 different characters ranging 0-255
    so we use two hash array with 256 space*/

    int arr1[256]={0};
    int arr2[256]={0};

    for (int i = 0; i < n1; i++) {
        
        if(arr1[s1[i]]!=arr2[s2[i]])return false;

        arr1[s1[i]]=i+1;
        arr2[s2[i]]=i+1;

        /*why i+1 , not ++ ?
        because Very important question.

The reason is:

```cpp
0
```

is being used as a special marker meaning:

```text
"Never seen before"
```

---

Suppose we used:

```cpp
m1[s[i]] = i;
m2[t[i]] = i;
```

instead of:

```cpp
m1[s[i]] = i + 1;
m2[t[i]] = i + 1;
```

Let's dry run:

```cpp
s = "ab"
t = "aa"
```

Initially:

```text
all entries = 0
```

---

### i = 0

```text
a   a
```

Check:

```text
m1[a] = 0
m2[a] = 0
```

Pass.

Now store:

```cpp
m1[a] = 0;
m2[a] = 0;
```

because `i = 0`.

---

### i = 1

```text
b   a
```

Check:

```text
m1[b] = 0
m2[a] = 0
```

Still equal!

The algorithm would think:

```text
b and a are both unseen
```

which is WRONG.

Actually:

```text
a was already seen at index 0.
```

But because we stored `0`, we can't distinguish:

```text
seen at index 0
```

from

```text
never seen
```

Both look like `0`.

---

That's why we store:

```cpp
i + 1
```

instead.

Now:

### i = 0

Store:

```cpp
m1[a] = 1;
m2[a] = 1;
```

---

### i = 1

Check:

```text
m1[b] = 0
m2[a] = 1
```

Now:

```text
0 != 1
```

Correctly detected as invalid.

---

So:

```cpp
i + 1
```

is not about indexing.

It's a trick to reserve:

```text
0 = never seen
```

and

```text
1,2,3,... = seen before
```

Without `+1`, index `0` and "never seen" would become indistinguishable.

        */
      
    }



   
    
    return true;
}


int main() {
    
    return 0;
}