#include <bits/stdc++.h>
using namespace std;

int maxRec(vector<vector<int>>&arr){
    vector<int>height(arr[0].size() , 0);

    int maxArea=-1;
    for (int i = 0; i < arr.size(); i++) {
      
        for (int j = 0; j <arr[0].size(); j++) {
           if(arr[i][j]==1) height[j]++;
           else height[j] = 0;
        }

        maxArea=max(maxArea , maxAreaOfRecOpt1(height));
    }

    return maxArea;
}


int maxAreaOfRecOpt1( vector<int>&height){
    stack<int>st;
    st.push(0);
    int nse;
    int pse=-1;
    int maxArea;
    int element;

    for (int i =  1; i < height.size(); i++) {

        while(!st.empty() && height[st.top()]>height[i]){

                element=st.top();

                st.pop();
                nse=i;
                pse=(st.empty())?-1:st.top();//after popping the main element the last second is the element
                //which is maller than the popped elemnt

                maxArea=max(maxArea , height[element]*(nse-pse-1));//eleemnt is the index of the popped elemnt  , as that element was bigger
                
        }

        st.push(i);
         
    }

    //if there are elements remaining
    while(!st.empty()){//it means those elemnt didnt get any nse 
             element=st.top();

                st.pop();
                nse=height.size();
                pse=(st.empty())?-1:st.top();//after popping the main element the last second is the element
                //which is maller than the popped elemnt

                maxArea=max(maxArea , st.top()*(nse-pse-1));
    }

    return maxArea;
    
}

/*Absolutely. Here's the **logic visually**, using a matrix and histogram diagrams.

### 1. Start with the binary matrix

```text
Matrix

1  0  1  0  0
1  0  1  1  1
1  1  1  1  1
1  0  0  1  0
```

We process **row by row**.

---

### 2. First row

```text
1  0  1  0  0

Histogram:

█     █
█     █
────────────
1  0  1  0  0
```

Heights:

```text
[1, 0, 1, 0, 0]
```

Largest rectangle = `1`.

---

### 3. Second row

Current row:

```text
1  0  1  1  1
```

Update heights:

```text
Previous:  1  0  1  0  0
Current:   1  0  1  1  1
           ↓  ↓  ↓  ↓  ↓

Heights:   2  0  2  1  1
```

Diagram:

```text
        █
█       █ █ █
█   █   █ █ █
───────────────
2   0   2 1 1
```

Now largest rectangle:

```text
    █ █ █
    █ █ █
    ─────
    2 1 1

height = 1
width  = 3

area = 1 × 3 = 3
```

---

### 4. Third row

Current row:

```text
1  1  1  1  1
```

Update:

```text
Previous:  2  0  2  1  1
Current:   1  1  1  1  1
           ↓  ↓  ↓  ↓  ↓

Heights:   3  1  3  2  2
```

Diagram:

```text
█       █
█       █ █ █
█ █   █ █ █ █
──────────────
3 1 3 2 2
```

Now look at this rectangle:

```text
█ █ █
█ █ █
█ █ █
```

Actually columns `0,2,3,4` aren't continuous because column 1 has height 1. The best rectangle is:

```text
        █ █ █
        █ █ █
        █ █ █
        ─────
         3 2 2

height = 2
width  = 3

area = 2 × 3 = 6
```

So far:

```text
maximum = 6
```

---

### 5. How does the stack find this?

For:

```text
[3, 1, 3, 2, 2]
```

Think:

```text
index:    0  1  2  3  4
height:   3  1  3  2  2
```

When we reach `1`:

```text
3
↓
1   ← smaller
```

The `3` at index `0` must stop here.

```text
PSE = -1
NSE = 1

width = 1 - (-1) - 1
      = 1

area = 3 × 1
     = 3
```

Then later:

```text
3  2
  ↓
smaller than 3
```

For height `3` at index `2`:

```text
PSE = 1
NSE = 3

width = 3 - 1 - 1
      = 1

area = 3 × 1 = 3
```

But the height `2` at index `3` eventually gives:

```text
        █ █ █
        █ █ █
        ─────
        2 2 2
```

Its boundaries are:

```text
PSE = 1
NSE = 5   ← imaginary smaller element at end

width = 5 - 1 - 1
      = 3

area = 2 × 3
     = 6
```

---

### The whole idea

```text
        BINARY MATRIX
              ↓
       Process each row
              ↓
        Build histogram
              ↓
    ┌─────────────────────┐
    │ Largest Rectangle    │
    │     in Histogram     │
    └─────────────────────┘
              ↓
       Monotonic Stack
              ↓
       NSE + PSE
              ↓
      width = NSE-PSE-1
              ↓
      area = height × width
              ↓
       Keep maximum
```

**One-line revision:**

> **Each matrix row becomes a histogram; the stack finds the largest rectangle in that histogram using NSE and PSE.**
*/

int main() {
    
    return 0;
}