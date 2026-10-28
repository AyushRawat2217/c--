/*===============================================================================

                         BIT MANIPULATION - BASICS
===============================================================================

WHY BITS?
---------
- Every integer is stored in binary.
- Bit manipulation allows O(1) operations on individual bits.
- Frequently used in DSA, Competitive Programming, and interviews.

Bit Positions (0-indexed from RIGHT)
Example:
13 = 1101

Position : 3 2 1 0
Bits     : 1 1 0 1

===============================================================================
1. AND (&)
===============================================================================

Truth Table:
0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1

Rule:
- Result bit is 1 ONLY if both bits are 1.

Identification:
- Checking whether a bit is set.
- Keeping selected bits.
- Creating masks.

Templates:

// Check ith bit
if (n & (1 << i))

// Check odd/even
if (n & 1)    // Odd
else          // Even

// Extract last k bits
n & ((1 << k) - 1)

Complexity:
Time : O(1)
Space: O(1)

Interview Importance:
★★★★★ (Very Important)

===============================================================================
2. OR (|)
===============================================================================

Truth Table:
0 | 0 = 0
0 | 1 = 1
1 | 0 = 1
1 | 1 = 1

Rule:
- Result bit is 1 if ANY bit is 1.

Identification:
- Setting bits.
- Combining flags.
- Building masks.

Template:

// Set ith bit
n |= (1 << i);

Example:
1010
0010
----
1010

1000
0010
----
1010

Complexity:
O(1)

Interview Importance:
★★★★☆

===============================================================================
3. LEFT SHIFT (<<)
===============================================================================

Rule:
n << k

Moves every bit k places LEFT.
Zeros are inserted on the right.

Example:

5 = 00000101

5 << 1

00001010 = 10

5 << 2

00010100 = 20

Shortcut:
n << k = n × 2^k
(Only when overflow does not occur.)

Templates:

n << 1     // Multiply by 2
n << 2     // Multiply by 4
1 << i     // Create mask for ith bit

Identification:
- Create masks.
- Fast multiplication.
- Bit checking.

Complexity:
O(1)

Interview Importance:
★★★★★

===============================================================================
4. RIGHT SHIFT (>>)
===============================================================================

Rule:
n >> k

Moves every bit RIGHT by k places.

Positive Example:

20 = 00010100

20 >> 2

00000101 = 5

Shortcut:
n >> k = floor(n / 2^k)
(For non-negative integers.)

Templates:

n >> 1      // Divide by 2
n >> i      // Bring ith bit to LSB

Extract ith bit:

(n >> i) & 1

Complexity:
O(1)

Interview Importance:
★★★★★

===============================================================================
5. NOT (~)
===============================================================================

Rule:
Flips EVERY bit.

0 -> 1
1 -> 0

Example:

5

00000101

~

11111010

Result:
~5 = -6

IMPORTANT FORMULA:

~n = -(n + 1)

Reason:
Signed integers use TWO'S COMPLEMENT representation.

How to read a negative binary:

1. Check MSB
   If first bit = 1 → negative

2. Flip all bits

3. Add 1

4. Attach '-'

Example:

11111010

Flip

00000101

Add 1

00000110 = 6

Answer = -6

Common Use:

// Clear ith bit
n &= ~(1 << i);

Complexity:
O(1)

Interview Importance:
★★★★☆

===============================================================================
TWO'S COMPLEMENT
===============================================================================

Positive:
Stored normally.

5

00000101

Negative:

To store -5

Step 1:
00000101

Step 2:
Flip

11111010

Step 3:
Add 1

11111011

Computer stores:

11111011

Important:
Memory DOES NOT know signed/unsigned.

Same bits:

11111011

Signed   -> -5
Unsigned -> 251

Interpretation depends on variable type/instruction.

===============================================================================
MOST COMMON MASKS
===============================================================================

// ith bit mask
1 << i

// Lower k bits set
(1 << k) - 1

Example:

k = 4

10000 - 1

01111

===============================================================================
COMMON INTERVIEW TEMPLATES
===============================================================================

// Check ith bit
(n & (1 << i))

// Set ith bit
n |= (1 << i)

// Extract ith bit
(n >> i) & 1

// Clear ith bit
n &= ~(1 << i)

===============================================================================
IDENTIFICATION GUIDE
===============================================================================

Question asks...

"Is ith bit set?"
-> AND

"Turn ith bit ON"
-> OR

"Multiply by powers of 2"
-> <<

"Divide by powers of 2"
-> >>

"Create mask"
-> 1 << i

"Read ith bit"
-> (n >> i) & 1

"Clear ith bit"
-> AND + NOT

===============================================================================
COMMON MISTAKES
===============================================================================

1. Forgetting parentheses

Wrong:
n & 1 << i

Correct:
n & (1 << i)

-------------------------------------

2. Confusing << with <

<< is bit shift.
< is comparison.

-------------------------------------

3. Forgetting positions start from 0.

Bit positions:

7 6 5 4 3 2 1 0

-------------------------------------

4. Assuming ~5 = 250

No.

For signed integers:

~5 = -6

-------------------------------------

5. Assuming memory stores "negative"

Memory stores ONLY bits.

Interpretation depends on signed/unsigned.

===============================================================================
PLACEMENT PERSPECTIVE
===============================================================================

★★★★★
AND
LEFT SHIFT
RIGHT SHIFT

★★★★☆
OR
NOT

Master these thoroughly before moving to:
- XOR (^)
- Toggle bit
- Count set bits
- Power of 2 checks
- Brian Kernighan Algorithm
- Bit Masks
- Subset Enumeration
===============================================================================
*/



/*===============================================================================
INTERPRETING THE RESULT OF THE NOT (~) OPERATOR
===============================================================================

IMPORTANT:
The ~ operator ALWAYS flips the STORED bits.
It NEVER converts a negative number back to positive before flipping.

Example:

5

Stored bits:
00000101

Apply ~

11111010

Now ask:
"Is this positive or negative?"

Check the MSB (Most Significant Bit):

11111010
^

MSB = 1

=> The result is DEFINITELY NEGATIVE (for signed integers).

At this point we DON'T know which negative number it is,
we only know that it is negative.

Now decode the two's complement:

11111010

Flip
00000101

Add 1
00000110 = 6

Attach '-'

Answer = -6

Therefore:

~5 = -6

-------------------------------------------------------------------------------

Example 2:

-5

Stored bits:
11111011

Apply ~

00000100

Check MSB:

00000100
^

MSB = 0

=> Result is POSITIVE.

Read normally:

00000100 = 4

Therefore:

~(-5) = 4

-------------------------------------------------------------------------------

MENTAL PROCESS

1. Apply ~ (flip every stored bit).

2. Check the leftmost bit (MSB).

   MSB = 0
   -> Positive
   -> Convert normally using powers of 2.

   MSB = 1
   -> Negative
   -> Decode two's complement:
        Flip bits
        Add 1
        Attach '-'

-------------------------------------------------------------------------------

KEY POINT

You NEVER convert a negative number from two's complement before applying ~.

Correct order:

Stored Bits
      ↓
Apply ~
      ↓
Check MSB
      ↓
Positive? -> Read normally.
Negative? -> Decode (Flip + Add 1).

===============================================================================
*/