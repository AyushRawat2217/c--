#include <bits/stdc++.h>
using namespace std;

class Node{ //initialising double linked list
    public:
        int data;
        Node*next;
        Node*prev;

  /**Imp regarding constructors
 * @brief Node constructor using default arguments.
 * * This design handles 1, 2, or 3 parameters seamlessly:
 * - Pass 1 arg (val): Creates an isolated node (next and prev default to NULL).
 * - Pass 2 args (val, nextPtr): Links forward; prev defaults to NULL.
 * - Pass 3 args (val, nextPtr, prevPtr): Fully links the node in both directions.
 * * Note: If you frequently need to pass ONLY (val, prevPtr), reorder the parameters
 * to (int val, Node* prevPtr = NULL, Node* nextPtr = NULL).
 */
    
 Node(int val , Node*nextPtr=NULL, Node*prevPtr=NULL){
        data=val;
        next=nextPtr;
        prev=prevPtr;
    }


};

vector<pair<int, int>>pairWithSumKBf(Node*head , int k){
    if(head==NULL)return {};
    if(head->next==NULL)return {};

    vector<pair<int ,int>>pairVec({});

    Node*mover=head;

    while(mover && mover->next){
        Node*mover2=mover->next;
        while(mover2){
            if((mover->data + mover2->data) ==k)pairVec.push_back({mover->data ,mover2->data});
            mover2=mover2->next;
        }
        mover=mover->next;
    }

    return pairVec;

}

vector<pair<int, int>>pairWithSumKBr(Node*head , int k){
    if(head==NULL)return {};
    if(head->next==NULL)return {};

    vector<pair<int ,int>>pairVec({});

    Node*mover=head;
    unordered_set<int>st;

    while(mover){
        int nr=k-mover->data;
        if(st.find(nr)!=st.end()){
            pairVec.push_back({nr , mover->data});
        }
        else{
            st.insert(mover->data);
        }
        mover=mover->next;
    }

    return pairVec;

}

vector<pair<int, int>>pairWithSumKOpt(Node*head , int k){
    if(head==NULL)return {};
    if(head->next==NULL)return {};

    vector<pair<int ,int>>pairVec({});

    Node*mover=head;
    Node*tail=head;
    while(tail && tail->next){
        tail=tail->next;
    }

    /*simple sa fundaa
    jo 2 ptr ka funda pdha tha ki 
    agr sum bada hora toh kamm kro left side ptr lejakr
    agr jyada hora h toh bdhao right side ki trf*/

    /* Use two pointers on the sorted DLL:
    - left pointer starts from head.
    - right pointer starts from tail.

    Compare the sum of their values:
    - If sum < k, move left forward to increase the sum.
    - If sum > k, move right backward to decrease the sum.
    - If sum == k, store the pair and move both pointers.

    Continue until the pointers meet or cross each other.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
    while(mover->prev!=tail && mover!=tail  ){
        int data1=mover->data;
        int data2=tail->data;

        if(data1+data2 <k)mover=mover->next;
        else if(data1+data2==k){
            pairVec.push_back({data1 , data2});
            mover=mover->next;
            tail=tail->prev;
        }
        else tail=tail->prev;

    }

    /* doubt i got why for decreaing sum we dont mover->prev why tail->prev
    Since the DLL is sorted:

    - Moving the left pointer forward increases the sum.
    - Moving the right pointer backward decreases the sum.

    Therefore:
    - If sum < k, move left forward to get a larger sum.
    - If sum > k, move right backward to get a smaller sum.

    We never move left backward or right forward because that would
    revisit already processed elements and break the two-pointer logic.
*/
    

    

    return pairVec;

}


int main() {
    
    return 0;
}