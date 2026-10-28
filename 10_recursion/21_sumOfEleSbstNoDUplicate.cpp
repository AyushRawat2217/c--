#include <bits/stdc++.h>
using namespace std;

//isme duplicates elemntns honge orr hame subset duplicate

//1049


//though no base condition , when the code end or the last bracket of block that means return only
//and dry runn is imp

/*UNIQUE SUBSETS DRY RUN + RECURSION UNDERSTANDING

Example:

arr = [1,1,2]

---

## IMPORTANT REALIZATION

A recursive call returning DOES NOT mean
the current function is finished.

It only means ONE branch of the current
function has finished.

After a recursive call returns, execution
continues from the NEXT LINE and the
current loop keeps running.

Think:

for(...)
{
recursiveCall();

```
// execution resumes here after return
```

}

The function ends only when:

1. All loop iterations are finished
2. Execution reaches '}'

---

## DRY RUN

Call 1:

uniqueSubsets(0, [])

Store:
[]

Loop:
i=0,1,2

---

## i=0

Take first 1

ds = [1]

Call:

uniqueSubsets(1,[1])

---

## Call 2

Store:
[1]

Loop:
i=1,2

---

## i=1

Take second 1

ds = [1,1]

Call:

uniqueSubsets(2,[1,1])

---

## Call 3

Store:
[1,1]

Loop:
i=2

---

## i=2

Take 2

ds = [1,1,2]

Call:

uniqueSubsets(3,[1,1,2])

---

## Call 4

Store:
[1,1,2]

index=3

Loop becomes:

for(i=3; i<3; i++)

Condition false immediately.

No iteration.

Function ends.

RETURN

---

## Back to Call 3

We DO NOT restart Call 3.

We continue from the line after
the recursive call:

ds.pop_back()

[1,1,2]
↓
[1,1]

Loop state:

i=2 already completed

No more iterations left.

Function ends.

RETURN

---

## Back to Call 2

Again, execution resumes after
the recursive call.

ds.pop_back()

[1,1]
↓
[1]

IMPORTANT:

Call 2 is NOT finished.

Its loop was:

for(i=1; i<3; i++)

Possible values:

i=1
i=2

We only completed i=1.

The loop continues.

---

## Next Iteration

i becomes 2

Take arr[2]

ds = [1,2]

Call:

uniqueSubsets(3,[1,2])

Store:
[1,2]

Return immediately.

Pop:

[1,2]
↓
[1]

Loop finished.

Function ends.

RETURN

---

## Back to Call 1

Pop:

[1]
↓
[]

Loop continues.

Next:

i=1

Duplicate check:

i > index
1 > 0

AND

arr[1]==arr[0]

1==1

TRUE

continue;

Skip branch.

No recursion created.

---

## Next Iteration

i=2

Take 2

ds=[2]

Call:

uniqueSubsets(3,[2])

Store:
[2]

Return

Pop:

[2]
↓
[]

Loop finished.

Function ends.

---

## FINAL ANSWERS

[]
[1]
[1,1]
[1,1,2]
[1,2]
[2]

---

## MOST IMPORTANT RECURSION LESSON

Recursive Return != Function Finished

Recursive Return means:

"One branch finished.
Continue execution from the next line."

Therefore:

[1,1,2]
↓ return
[1,1]
↓ pop
[1]
↓ continue loop
[1,2]
↓ return
[1]
↓ finish loop
[]
*/

void sumOfSbstDuplicateHandling(vector<int>&arr , int index ,  vector<int>&subSet , vector<vector<int>>&powerSet){

    powerSet.push_back(subSet);

    for (int i = index; i < arr.size();i++) {
      if(i>index && arr[i]==arr[i-1])continue;
    
      sumOfSbstDuplicateHandling(arr , i+1 , subSet , powerSet);
      subSet.pop_back();
    }
}

int main() {
    
    return 0;
}