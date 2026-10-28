#include <bits/stdc++.h>
using namespace std;
/*generate("",0)
│
├── generate("0",1)
│   │
│   ├── generate("00",2)
│   │       Base Case
│   │       push "00"
│   │
│   └── generate("01",2)
│           Base Case
│           push "01"
│
└── generate("1",1)
    │
    ├── generate("10",2)
    │       Base Case
    │       push "10"
    │
    └── generate("11",2)
            Base Case
            push "11"
            

        
            
generate("",0)

    generate("0",1)

        generate("00",2)
        push "00"
        return

        generate("01",2)
        push "01"
        return

    return

    generate("1",1)

        generate("10",2)
        push "10"
        return

        generate("11",2)
        push "11"
        return

    return

return*/

/*
Let's dry run for:

n = 2

Initial call:

generateBinString(2, 0, "", arr);

---

CALL 1

generateBinString(2,0,"")

index != n

So we execute the FIRST recursive call:

generateBinString(2,1,"0");

IMPORTANT:

The second line

generateBinString(2,1,"1");

has NOT executed yet.

Why?

Because recursion is depth-first.

The first call must finish completely before execution can move to the next line.

---

CALL 2

generateBinString(2,1,"0")

Again index != n

Execute first recursive call:

generateBinString(2,2,"00");

The call for "01" is still waiting.

---

CALL 3

generateBinString(2,2,"00")

Base Case:

arr.push_back("00");

arr = ["00"]

return;

---

BACK TO CALL 2

We returned from:

generateBinString(2,2,"00");

Now execution resumes from the NEXT line.

So now we execute:

generateBinString(2,2,"01");

Notice:

We do NOT restart Call 2.

We continue exactly where it was paused.

---

CALL 4

generateBinString(2,2,"01")

Base Case:

arr.push_back("01");

arr = ["00","01"]

return;

---

BACK TO CALL 2

Nothing left to execute.

So:

return;

---

BACK TO CALL 1

We returned from:

generateBinString(2,1,"0");

Now execution resumes from the NEXT line.

So now we execute:

generateBinString(2,1,"1");

---

CALL 5

generateBinString(2,1,"1")

index != n

Execute first recursive call:

generateBinString(2,2,"10");

---

CALL 6

generateBinString(2,2,"10")

Base Case:

arr.push_back("10");

arr = ["00","01","10"]

return;

---

BACK TO CALL 5

We returned from:

generateBinString(2,2,"10");

Now execution resumes from the NEXT line.

So we execute:

generateBinString(2,2,"11");

---

CALL 7

generateBinString(2,2,"11")

Base Case:

arr.push_back("11");

arr = ["00","01","10","11"]

return;

---

BACK TO CALL 5

Nothing left.

return;

---

BACK TO CALL 1

Nothing left.

return;

Program Ends.

==================================================

MENTAL MODEL

Call("",0)

↓

Call("0",1)

↓

Call("00",2)

↓

return

↓

Call("01",2)

↓

return

↓

return to root

↓

Call("1",1)

↓

Call("10",2)

↓

return

↓

Call("11",2)

↓

return

↓

return to root

↓

program ends

==================================================

MOST IMPORTANT IDEA

When a recursive call returns:

Execution does NOT start from the beginning.

It resumes from the next line after the call.

Think:

Place Bookmark
↓
Go into Recursive Call
↓
Return
↓
Continue From Bookmark

That's why after "10" returns, execution immediately goes to "11".
*/
void generateBinString(int n , int index , string str , vector<string>&arr)// n is the digit , str is tring generated so far
{
  if(index==n){
    arr.push_back(str);
    return ;
    }

//this is the pattern to generate combination og 2 element 
  generateBinString(n , index+1 , str+"0" , arr);
  generateBinString(n , index+1 , str + "1" , arr);
  
}

int main() {

   int n;
   cin>>n;

   vector<string>arr;
   generateBinString(n , 0 , "" , arr);
   for(auto it:arr){
        cout<<it<<" ";
   }



    return 0;
}