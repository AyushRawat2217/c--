#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
        int key;
        int value;
        int freq;
        Node*next;
        Node*prev;

        Node(int val1, int val2 , int val3=1, Node*nextPtr=NULL , Node*prevPtr=NULL){//constructor
            key=val1;
            value=val2;
            freq=val3;
            next=nextPtr;
            prev=prevPtr;
        }
};

class DLL {//let me create separate dll having head and tails both
public:
    Node* head;
    Node* tail;

    DLL() {
        head = new Node(-1, -1, -1);
        tail = new Node(-1, -1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        Node* prevPtr = tail->prev;

        prevPtr->next = node;
        node->prev = prevPtr;

        node->next = tail;
        tail->prev = node;
    }

    void removeNode(Node* node) {
        Node* prevPtr = node->prev;
        Node* nextPtr = node->next;

        prevPtr->next = nextPtr;
        nextPtr->prev = prevPtr;
    }

    Node* removeLRU() {//see whe cap is above max we have to remove least frquently used node
        //if least freq used node has more than one node , then we have to remove lru in it
        if (head->next == tail) {
        return NULL;
             }

         Node* node = head->next;
        removeNode(node);
         return node;
    }


};

//multiple small linked lists, one per frequency, is the right design.
class lfuCache{
    map<int , DLL*>freqNodeMap;
    map<int , Node*>keyNodeMap;
    int capacity;
    int size;
    int minFreq;
    
    public:

        lfuCache(int cap){
            capacity = cap;
            size = 0;
            minFreq = 0;
         }
    
        void put(int key , int value){
            if(keyNodeMap.find(key)==keyNodeMap.end()){//agr present nhi hai toh last mai daal do isko

                 if (size == capacity) {
                    DLL* list = freqNodeMap[minFreq];
                    Node* nodeToDelete = list->removeLRU();
                    keyNodeMap.erase(nodeToDelete->key);
                    delete nodeToDelete;
                    size--;
             }

               Node*newNode=new Node(key , value );

               if(freqNodeMap.find(1)==freqNodeMap.end()){
                    freqNodeMap[1]=new DLL();
               }
               freqNodeMap[1]->addNode(newNode);
               keyNodeMap[key] = newNode;
               size++;
               minFreq=1;


            }

            
            else{//already present
               

                freqNodeMap[keyNodeMap[key]->freq]->removeNode(keyNodeMap[key]);
                keyNodeMap[key]->freq++;

                if(freqNodeMap.find(keyNodeMap[key]->freq)==freqNodeMap.end()){
                    freqNodeMap[keyNodeMap[key]->freq]=new DLL();
               }

               freqNodeMap[keyNodeMap[key]->freq]->addNode(keyNodeMap[key]);

            }
     }

int get(int key) {

    // Key doesn't exist
    if (keyNodeMap.find(key) == keyNodeMap.end()) {
        return -1;
    }

    // Get the node
    Node* node = keyNodeMap[key];
    // Remove from current frequency DLL
    freqNodeMap[node->freq]->removeNode(node);
    

    // If this was the minimum frequency
    // and that DLL is now empty
    //now minfreq is next minimum freq , because the last one got empty as we removed the node
    if (node->freq == minFreq &&
        freqNodeMap[node->freq]->head->next ==
        freqNodeMap[node->freq]->tail) {
        minFreq++;
    }

    // Increase frequency
    node->freq++;

    // Create DLL for new frequency if it doesn't exist
    if (freqNodeMap.find(node->freq) == freqNodeMap.end()) {
        freqNodeMap[node->freq] = new DLL();
    }

    // Add node to new frequency DLL
    freqNodeMap[node->freq]->addNode(node);

    // Return value
    return node->value;
}

};


/*VERY IMP
======================================================================
                         LFU CACHE — CONCEPT
======================================================================

WHAT IS LFU?
------------
LFU = Least Frequently Used.

When the cache becomes full and we need to remove something:

    1. Find the key that has been used the LEAST number of times.
    2. If multiple keys have the same frequency, remove the one
       that was used the LEAST RECENTLY.

Example:

    A → frequency 3
    B → frequency 1
    C → frequency 1
    D → frequency 2

    B and C have the lowest frequency (1).

    Therefore, we remove whichever of B and C was used less recently.

So LFU actually has TWO rules:

    PRIMARY RULE:
        Lowest frequency gets removed.

    TIE-BREAKER:
        Among equal frequencies, least recently used gets removed.


======================================================================
                         WHY DO WE NEED NODE?
======================================================================

Each cache entry is represented by one Node.

A Node stores:

    key
        Which key is this?

    value
        What value belongs to this key?

    freq
        How many times has this key been used?

    next / prev
        Pointers needed to put this Node inside a Doubly Linked List.

Example:

    Node:
        key   = 10
        value = 100
        freq  = 3

The frequency belongs to the Node because every key can have a
different usage frequency.


======================================================================
                    WHY DO WE NEED A DLL?
======================================================================

A Doubly Linked List is used to maintain RECENCY.

Suppose several nodes have the same frequency:

    frequency 2:

    HEAD <-> A <-> B <-> C <-> TAIL

Here:

    A = least recently used
    C = most recently used

Why?

Whenever a node is added to this frequency list, we put it at the
BACK.

Therefore:

    FRONT  = oldest / least recently used
    BACK   = newest / most recently used


The DLL allows us to:

    1. Remove a particular Node quickly.
    2. Add a Node quickly.
    3. Remove the least recently used Node quickly.

The Node itself contains prev and next, so it can move from one
frequency list to another.


======================================================================
                WHY DO WE NEED MULTIPLE DLLs?
======================================================================

This is the main idea of LFU.

In LRU, we only needed ONE DLL because we only cared about recency.

In LFU, we care about frequency FIRST.

Therefore we create a separate DLL for EACH frequency.

For example:

    Frequency 1:
        HEAD <-> A <-> B <-> TAIL

    Frequency 2:
        HEAD <-> C <-> D <-> TAIL

    Frequency 3:
        HEAD <-> E <-> TAIL


Each DLL contains ONLY nodes having that frequency.

So:

    Frequency 1 DLL
        contains nodes whose freq = 1

    Frequency 2 DLL
        contains nodes whose freq = 2

    Frequency 3 DLL
        contains nodes whose freq = 3


A node belongs to exactly ONE frequency DLL at a time.


======================================================================
                  WHY DO WE NEED freqNodeMap?
======================================================================

We need some way to find the DLL belonging to a frequency.

Therefore:

    frequency → DLL

For example:

    1 → DLL containing all freq-1 nodes
    2 → DLL containing all freq-2 nodes
    3 → DLL containing all freq-3 nodes

This is what freqNodeMap represents.

IMPORTANT:

    freqNodeMap is NOT:

        frequency → Node

    It is:

        frequency → DLL


Why?

Because there can be MANY nodes with the same frequency.

Example:

    frequency 2:

        A
        B
        C

So frequency 2 must point to an entire DLL:

    2 → [DLL containing A, B, C]


======================================================================
                    WHY DO WE NEED keyNodeMap?
======================================================================

The other map has a different job.

We need to quickly find a Node when someone gives us a key.

Therefore:

    key → Node

For example:

    10 → Node A
    20 → Node B
    30 → Node C

This lets us immediately find the Node belonging to a key.

Without this map, we would have to search through the DLLs to find
the Node.

That would be inefficient.


So remember:

    keyNodeMap:
        key → Node

        Answers:
        "Where is this key's Node?"

    freqNodeMap:
        frequency → DLL

        Answers:
        "Which DLL contains nodes having this frequency?"


These two maps solve TWO DIFFERENT problems.


======================================================================
                         WHY DUMMY HEAD/TAIL?
======================================================================

Every DLL has:

    HEAD <-> TAIL

where HEAD and TAIL are dummy nodes.

They don't represent actual cache entries.

They make insertion and deletion easier.

An empty DLL looks like:

    HEAD <-> TAIL

If we add A:

    HEAD <-> A <-> TAIL

If we add B:

    HEAD <-> A <-> B <-> TAIL


Because the dummy nodes always exist, we don't have to constantly
handle special cases involving NULL.


======================================================================
                         ADDING A NODE
======================================================================

When a Node enters a frequency DLL, it is placed at the BACK.

Example:

    Before:

        HEAD <-> A <-> B <-> TAIL

    Add C:

        HEAD <-> A <-> B <-> C <-> TAIL

Therefore:

    A = oldest
    C = newest

This gives us LRU ordering inside that frequency.


======================================================================
                        REMOVING A NODE
======================================================================

When a Node's frequency changes, it cannot stay in its old frequency
DLL.

Example:

    Frequency 1:

        HEAD <-> A <-> B <-> TAIL

Suppose A is accessed.

Its frequency changes:

    1 → 2

A must first be removed from the frequency-1 DLL:

    HEAD <-> B <-> TAIL

Then its frequency is increased:

    A.freq = 2

Then A is added to the frequency-2 DLL:

    Frequency 2:

        HEAD <-> ... <-> A <-> TAIL


Therefore, changing frequency means:

    OLD DLL
       ↓
    remove Node
       ↓
    increase frequency
       ↓
    NEW DLL
       ↓
    add Node


This movement is the CORE operation of LFU.


======================================================================
                              GET
======================================================================

get(key) means:

    "Give me the value of this key."

If the key doesn't exist:

    return -1


If the key exists:

    1. Find the Node using keyNodeMap.
    2. Remember its current frequency.
    3. Remove it from its current frequency DLL.
    4. Increase its frequency by 1.
    5. Create the new frequency DLL if necessary.
    6. Add the Node to the BACK of the new frequency DLL.
    7. Return the Node's value.


Why does GET increase frequency?

Because accessing a key means the key has been used.

Example:

    A.freq = 2

    get(A)

    A.freq becomes 3.


======================================================================
                              PUT
======================================================================

put(key, value) has TWO completely different cases.


CASE 1: KEY ALREADY EXISTS
---------------------------

If the key already exists:

    1. Find its Node.
    2. Update its value.
    3. Remove it from its current frequency DLL.
    4. Increase its frequency by 1.
    5. Create the new frequency DLL if necessary.
    6. Add the Node to the BACK of the new frequency DLL.

The size of the cache DOES NOT increase.

Why?

Because we didn't create a new cache entry.

We only updated an existing entry.


CASE 2: KEY DOES NOT EXIST
---------------------------

If the key is new:

    1. Check whether the cache is full.
    2. If full, evict one Node.
    3. Create the new Node.
    4. New Nodes start with frequency 1.
    5. Put the Node into the frequency-1 DLL.
    6. Add key → Node to keyNodeMap.
    7. Increase cache size.
    8. Set minimum frequency to 1.

Why is the new Node frequency 1?

Because it has just been inserted and has not been used before.


======================================================================
                            EVICTION
======================================================================

Eviction happens when:

    size == capacity

We need to remove ONE Node.

LFU says:

    First choose the LOWEST FREQUENCY.

This is why we maintain minFreq.

Example:

    freq 1 → A, B
    freq 2 → C
    freq 3 → D

    minFreq = 1

Therefore we only need to look inside:

    frequency-1 DLL


But there may be multiple nodes in that DLL.

Example:

    freq 1:

    HEAD <-> A <-> B <-> C <-> TAIL

All three have frequency 1.

LFU now uses its tie-breaker:

    Remove the LEAST RECENTLY USED node.

Because the DLL is ordered from oldest to newest:

    A = LRU
    C = MRU

Therefore:

    A gets evicted.


So eviction is:

    Find minFreq
          ↓
    Find that frequency's DLL
          ↓
    Take the LRU node
          ↓
    Remove it from the DLL
          ↓
    Remove its key from keyNodeMap
          ↓
    Delete the Node
          ↓
    Decrease cache size


======================================================================
                           minFreq
======================================================================

minFreq stores the LOWEST FREQUENCY currently present in the cache.

Example:

    freq 1 → A, B
    freq 2 → C
    freq 4 → D

    minFreq = 1


Why do we need it?

Without minFreq, when the cache is full we would have to search
through all frequencies to find the lowest one.

minFreq tells us immediately where to look.


IMPORTANT:

When a Node is moved from minFreq to minFreq + 1, the old
minimum-frequency DLL might become empty.

Example:

    minFreq = 1

    freq 1:
        HEAD <-> A <-> TAIL

    freq 2:
        HEAD <-> B <-> TAIL

Access A.

A moves:

    1 → 2

After removing A:

    freq 1:
        HEAD <-> TAIL

    freq 2:
        HEAD <-> B <-> A <-> TAIL

Frequency 1 is now empty.

Therefore:

    minFreq becomes 2.


Why can we simply increase minFreq by 1 here?

Because the Node's frequency always increases by EXACTLY 1.

If the old minimum was 1, the moved Node becomes frequency 2.

So frequency 2 definitely exists after the move.

The same logic applies:

    2 → 3
    3 → 4
    etc.


======================================================================
                     COMPLETE MENTAL MODEL
======================================================================

Think of the whole LFU cache like this:

                         LFU CACHE
                             |
              ┌──────────────┴──────────────┐
              ↓                             ↓
        keyNodeMap                     freqNodeMap
        key → Node                    freq → DLL
              |                             |
              ↓                    ┌────────┼────────┐
            Node                   ↓        ↓        ↓
        ┌──────────┐             FREQ 1  FREQ 2  FREQ 3
        │ key      │               ↓        ↓        ↓
        │ value    │              DLL      DLL      DLL
        │ freq     │               ↓        ↓        ↓
        │ prev     │             A ↔ B    C ↔ D      E
        │ next     │
        └──────────┘


keyNodeMap answers:

    "Find this key's Node."


freqNodeMap answers:

    "Find the DLL for this frequency."


DLL answers:

    "Maintain recency among nodes with this frequency."


minFreq answers:

    "Which frequency should eviction start from?"


Node answers:

    "What is this key's value, frequency, and position
     inside its current DLL?"


======================================================================
                         THE CORE MOVEMENT
======================================================================

Whenever a key is USED:

        Node
          ↓
    current frequency
          ↓
    remove from old DLL
          ↓
    frequency + 1
          ↓
    add to new frequency DLL


Whenever the cache is FULL:

        minFreq
           ↓
    corresponding DLL
           ↓
    least recently used Node
           ↓
        evict


Therefore the entire LFU design is based on:

    KEY
      ↓
    keyNodeMap
      ↓
    NODE
      ↓
    NODE'S FREQUENCY
      ↓
    freqNodeMap
      ↓
    FREQUENCY DLL
      ↓
    RECENCY ORDER


======================================================================
                       ONE SENTENCE SUMMARY
======================================================================

LFU uses:

    keyNodeMap
        to find a Node quickly,

    freqNodeMap
        to find the DLL for a frequency,

    multiple DLLs
        to maintain LRU order within each frequency,

    Node.freq
        to know how frequently a key has been used,

    minFreq
        to know which frequency should be evicted from.

The eviction rule is:

    LOWEST FREQUENCY first,
    and if tied,
    LEAST RECENTLY USED.
======================================================================
*/
int main() {
    
    return 0;
}