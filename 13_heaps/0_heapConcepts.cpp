/*====================== HEAP CONCEPTS ======================

1. HEAP
   A complete binary tree stored usually in an array.

   Max Heap:
       Parent >= Children

   Min Heap:
       Parent <= Children


2. ARRAY REPRESENTATION (1-INDEXED)

   Parent of i      = i / 2
   Left child       = 2 * i
   Right child      = 2 * i + 1


3. INSERTION IN MAX HEAP

   Steps:
   1. Put the new element at the last position.
   2. Compare it with its parent.
   3. If child > parent, swap.
   4. Move index to the parent's position.
   5. Repeat until:
        - parent >= child, OR
        - element reaches the root.

   This is called HEAPIFY-UP / SIFT-UP.

   Example:

          50
         /  \
       30    40
      /
     10

   Insert 45 at the bottom.

          50
         /  \
       30    40
      /     /
     10    45

   45 > 40 → swap

          50
         /  \
       30    45
      /     /
     10    40

   45 < 50 → stop.


4. DELETION FROM MAX HEAP

   Usually means deleting the ROOT (maximum element).

   Steps:
   1. Replace root with the last element.
   2. Decrease size.
   3. Compare the new root with BOTH children.
   4. Find the LARGER child.
   5. If larger child > current element, swap.
   6. Move index to the position where the old element moved.
   7. Repeat.

   This is called HEAPIFY-DOWN / SIFT-DOWN.


5. WHY CHOOSE THE LARGER CHILD?

   Max Heap requires:

       Parent >= BOTH children

   Therefore, when moving an element down,
   we swap with the LARGER child.

   Example:

          20
         /  \
       40    50

   Choose 50, NOT 40.

   Result:

          50
         /  \
       40    20


6. IMPORTANT: LEFT CHILD VS RIGHT CHILD

   There is NO rule that:

       left child < right child

   or:

       left child > right child

   The only rule is:

       Parent >= left child
       Parent >= right child


7. HEAPIFY

   Standard heapify means:

       Restore the heap property of the subtree
       rooted at a particular index.

   It assumes the child subtrees are already heaps.

   If a swap happens, the OLD parent moves downward.

   Therefore:

       index = larger;

   We continue from the position where the old
   parent moved.

   We do NOT heapify the sibling subtree because
   it was already a valid heap and we did not change it.


8. HEAPIFY LOGIC

          Parent
         /      \
       Left     Right

   Find the largest among:

       Parent
       Left
       Right

   If Parent is already largest:
       STOP

   Otherwise:
       SWAP Parent with largest child
       Move index to that child's position
       Continue


9. BUILD HEAP

   Build Heap means converting an arbitrary array
   into a valid heap.

   We start from the LAST NON-LEAF NODE
   and move backwards toward the root.

   For 1-indexed heap:

       Last non-leaf = size / 2

   Example:

       for(int i = size/2; i >= 1; i--)
           heapify(arr, size, i);

   Why?

   Leaf nodes are already heaps by themselves.


10. HEAPIFY VS BUILD HEAP

   HEAPIFY:
       Fix one subtree.

   BUILD HEAP:
       Call heapify on all non-leaf nodes
       from bottom to top.


11. HEAPIFY-UP VS HEAPIFY-DOWN

   INSERTION:
       Element moves UP.
       Compare with PARENT.

       child > parent → swap (Max Heap)

   DELETION:
       Element moves DOWN.
       Compare with CHILDREN.

       choose larger child → swap (Max Heap)


12. TIME COMPLEXITY

   Heap insertion:
       O(log n)

   Heap deletion:
       O(log n)

   Heapify:
       O(log n)

   Build Heap:
       O(n)

   Access maximum in Max Heap:
       O(1)

   Search for arbitrary element:
       O(n)


13. KEY FORMULAS — 1 INDEXED

       Parent = i / 2
       Left   = 2 * i
       Right  = 2 * i + 1


14. MAX HEAP CORE RULE

       Bigger elements move UP.

   INSERT:
       Put at bottom → move UP

   DELETE:
       Last element to root → move DOWN


============================================================
*/