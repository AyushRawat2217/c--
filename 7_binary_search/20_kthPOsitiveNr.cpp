#include <bits/stdc++.h>
using namespace std;

int kthMissingBF(vector<int>&arr , int k){
    int n= arr.size();
    int maxx=INT_MIN;
    for(int i:arr){
        maxx=max(maxx,i);
    }

    int collectedNrs=0; 
    for (int i = 1; i <=maxx; i++) { //i is the number
        int flag=0;
        //int collectedNrs=0;   //this will be ouside because we store i values in it and we dont want it to rest for every new i
        for (int j=0;j< n;j++) {
          if(arr[j]==i){
            flag=1;
            break;
          }
        }
        if(flag==0){
            collectedNrs++;
            if(collectedNrs==k){
                return i;
            }
        }
      
    }
    return -1;


}

int kthMissingBr(vector<int>&arr , int k){
    int n= arr.size();
    if(arr[0]>k) return k; /* maan lo 4th missing nr nikaalna h
    and arr[0] 5 h toh uss se pehle 4 nr aayein h mlb 4 missing h
    toh 4 return krdo */

    for (int j=0;j< n;j++) {
        if(arr[j]<=k){/*
            dekh jese k=7 , h and array elemnts 5 , 6 8 9 h
            natural numbers m 7th nr p 7 h agr 1 to 7 missing h
            prr 5 missing na honek kaaran ek posn aaghe bd jaaega 7th missing 
            that is 8 hojaega 7th missing , abh 6 aagya toh similary ek upr or , 
            9 hojaega , 8 aagya toh 10, 9 aagya toh 11 , mlb present nr ki vjh se
            missing nr aaghe push hojaega
            
            */
            k++;
        }
        else{ //agr k pehle lie krra h arr[j] k toh k ki kth missing h
            return k;
        }
    }
    return -1;
}

int kthMissingOpt(vector<int>&arr , int k){
    int n= arr.size();
    int maxx=INT_MIN;
    for(int i:arr){
        maxx=max(maxx,i);
    }
    int low = 0;
    int high=n-1;
    int ans=-1;


    while(low<=high){ //mid is the index 0-n-1 of the array elemnt to find missing nrs
        int mid=low+(high-low)/2; 

        /*
        missing numbers till this index is
        a[i] - (i+1)

        for 2 , 5 , 6 ,7 
        missing nrs till number 5 are
        5-(1+1)or(numbers do far present)=3

    | i | arr[i] | expected (i+1) | missing(i)    |
    | - | ------ | -------------- | ------------- |
    | 0 | 2      | 1              | 2 - 1 = **1** |
    | 1 | 5      | 2              | 5 - 2 = **3** |
    |2  | 6       | 3              | 6 - 3 = **3** |
    | 3 | 7      | 4              | 7 - 4 = **3** |

        
        so what we do is we check , to a point where First index where missing(i) ≥ k
        mlb wo pt jaha pe missing nr jyada ho k se
        taaki ham uss point p aajaien jiske peeche present nrs ho
        mlb agr hame jese 2 nd mising nr nikaalna h 2 5 6 7 m
        toh ham bs ka use krke msng(i)>=2 jaayenge ham 3 p phuch jaaenge
        hamara low ptr just msng(i) tkk hoga
         jo btaega ki abhi tkk low jitne nrs present h

         taaki ham k+low krke apna nr nikaal le

         jese low=1 h iss case m(kyuki low<=high ek or baar chlega low<high hone k baad  = ki vjh se)
         fir low ek pt upr aajega
        
        */

        if((arr[mid]-(mid+1))<k) low=mid+1;
        else high=mid-1;
    }

    return low+k;
}

/*Good. Now we convert everything you fought through into **clean, weapon-grade notes**. No fluff. Just doctrine you can deploy anytime.

---

# 🪖 K-th Missing Number — Binary Search Notes

---

## 🎯 Problem Objective

Given a **sorted array of positive integers**, find the **k-th missing number**.

---

## 🧠 Core Insight

At index `i`, number of missing elements till there:

missing(i) = arr[i] - (i + 1)

👉 Why?
Because expected value at index `i` is `i+1` if nothing was missing.

---

## ⚔️ Key Observation

* `missing(i)` is **monotonically increasing**
* So we can apply **binary search**

---

## 🎯 What are we searching?

👉

> **First index where `missing(i) ≥ k`**

This is a **boundary problem (first TRUE)**

---

## 🔍 Binary Search Logic

```cpp
if (missing(mid) < k)
    move right  → low = mid + 1
else
    move left   → high = mid - 1
```

---

## 💣 After Binary Search


low = first index where missing(i) ≥ k   //very imp line


Also:

high = last index where missing(i) < k
```

---

## 🧠 Meaning of `low`

👉

> **Number of array elements present before the answer**

NOT missing count.
NOT index of answer.

---

## ⚡ Final Answer Formula

answer = low + k

---

## 🔥 Why this works

At answer `x`:

* Total numbers till `x` = `x`
* Present numbers = `low`
* Missing numbers = `x - low`

We want:

```text
x - low = k
→ x = low + k
```

---

## ⚔️ Mental Model

```text
[ present elements ] + [ missing elements ]
        low                    k
```

👉 Answer sits at position = `low + k`

---

## ⚠️ Critical Rules

* Do NOT search for the number directly
* Always search for **boundary condition**
* Binary search = eliminate zones, not step-by-step checking

---

## 💥 Loop Ending Condition

```text
low > high
```

👉 Means:

> Boundary found

---

## 🧠 Final Interpretation

| Variable     | Meaning                                  |
| ------------ | ---------------------------------------- |
| `missing(i)` | missing count till index i               |
| `low`        | number of present elements before answer |
| `k`          | required missing count                   |
| `low + k`    | actual answer                            |

---

## 🪖 Edge Case

If k is beyond last element:

```text
answer = n + k
```

---

## ⚔️ Code Template

```cpp
int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low + k;
}
```

---

# 🎯 Final Doctrine (memorize this line)

> Binary search finds **how many real elements exist before the k-th missing number**, then reconstructs the answer using `low + k`.

---

You’ve crossed the hardest conceptual barrier.

Next step—**speed and precision**.
If you want, I’ll give you 5 high-level variations to harden this into instinct.
*/



int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}