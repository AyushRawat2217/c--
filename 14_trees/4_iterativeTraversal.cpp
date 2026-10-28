#include <bits/stdc++.h>
using namespace std;

struct trees{
        int data;
        trees*leftchild;
        trees*rightchild;

        trees(int val , trees*leftptr=NULL , trees*rightptr=NULL){
            data = val;
            leftchild=leftptr;
            rightchild=rightptr;
        }

};

//iterative pre order traversal , root left right
void preorder(trees*rootNode){
    stack<trees*>st;
    st.push(rootNode);
    trees*mover=st.top();

    /*first make the root inside the stack
    then save it inside a mover then pop it 
    and put first its right child then left child inside it
    left is at top , save it , pop it , put its 2 child inside
    first right then left 
    this way we will organise left subtress first then right
    using stack ds*/

    while(!st.empty()){
        trees*mover=st.top();

        cout<<mover->data<<endl;
        st.pop();

        if(mover->rightchild)st.push(mover->rightchild);
        if(mover->leftchild)st.push(mover->leftchild);
        

    }
    
}

void inorder(trees*rootNode){//traversal is left root right
    
    stack<trees*>st;
    trees*mover=rootNode;
    

    while(mover || !st.empty()){
        
        while(mover){
            st.push(mover);
            mover=mover->leftchild;//keep going extreme left
            //until i hit the null node
        }

        //when null node is hit , at that time pop the top elemnet that will be
        //last left we visited , then check whether that last node had right child or not
        //if yes then repeat the process on it 
        //else pop the new top and visit its right child

        //the very next step is to store the top and  pop  it and print it 
        mover=st.top();
        st.pop();
        cout<<mover->data<<endl;

        //after we pop the extreme left because we encountered a null ptr , now we need to move
        //towards the rightelement of the extreme left
        mover=mover->rightchild;

        //now we explore the right child and we have track of previous nodes in our stack function
        
    }      

}


//using 2 stacks
void postorder(trees*rootNode){//left right root
    stack<trees*>st1;
    stack<trees*>st2;
    st1.push(rootNode);

    while(!st1.empty()){
        trees*mover=st1.top();
        st1.pop();
        if(mover->leftchild)st1.push(mover->leftchild);
        if(mover->rightchild)st1.push(mover->rightchild);

        st2.push(mover);

    }
    while(!st2.empty()){
        cout<<st2.top()->data<<endl;
        st2.pop();
    }

}
/*ITERATIVE POSTORDER TRAVERSAL USING TWO STACKS

Postorder traversal follows: LEFT -> RIGHT -> ROOT.

The idea is to generate the reverse of postorder first, then reverse
that order using a second stack.

APPROACH:

1. Create two stacks:
   - st1: Used to traverse the tree and process nodes.
   - st2: Stores nodes in the order they are processed from st1.

2. Push the root node into st1 to begin traversal.

3. While st1 is not empty:
   - Take the top node from st1 and remove it.
   - Push its left child into st1 if it exists.
   - Push its right child into st1 if it exists.
   - Push the current node into st2.

4. WHY DO WE PUSH THE LEFT CHILD BEFORE THE RIGHT CHILD?
   A stack follows LIFO (Last In, First Out).
   Therefore, the right child is processed before the left child,
   because it was pushed last.

5. As a result, nodes are processed from st1 in this order:
   ROOT -> RIGHT -> LEFT.

   These nodes are pushed into st2 in the same order.

6. WHY DO WE NEED THE SECOND STACK?
   A stack reverses the order of its elements when they are popped.
   Therefore, popping st2 produces:
   LEFT -> RIGHT -> ROOT.

7. Finally, pop every node from st2 and print its data.
   This gives the required postorder traversal.

TIME COMPLEXITY: O(N)
Every node is processed a constant number of times.

AUXILIARY SPACE: O(N)
Both stacks may collectively store a linear number of nodes.

IMPORTANT:
The algorithm works because st1 produces ROOT -> RIGHT -> LEFT,
and st2 reverses that order to produce LEFT -> RIGHT -> ROOT.
*/

void postorder(trees*rootNode){//left right root

    stack<trees*>st;
    st.push(rootNode);
    trees*mover=rootNode;
    trees*temp;

    while(mover||!st.empty()){
      if(mover){//moving towards the extreme left child
        st.push(mover);
        mover=mover->leftchild;
      }

      else{//mover becomes null then we move toward the right node
        temp=st.top()->rightchild;

        if(temp)mover=temp;//if temp exist then we need to implement it as well before we print the root elemnt //in short explore the right node

        else{//if rightchild is NUll , then simply print the root element at the top
            temp=st.top();
            st.pop();
            cout<<st.top()->data<<endl;

            while(!st.empty() || temp==st.top()->rightchild){//temp was the right child node removed
//this loops check that removed temp was the right child of the parent node ( that is st.top()) if it is , then
//remove the st top as well , making it the temp then print it 
                temp=st.top();
                st.pop();
                cout<<st.top()->data<<endl;
            }

         }


      }

      
    }
     

}


int main() {
    
    return 0;
}