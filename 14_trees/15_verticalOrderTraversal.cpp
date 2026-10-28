#include <bits/stdc++.h>
using namespace std;

//1219
struct trees{
        int data;
        trees*left;
        trees*right;

        trees(int val , trees*leftptr=NULL , trees*rightptr=NULL){
            data = val;
            left=leftptr;
            right=rightptr;
        }
};

//iterative pre order traversal , root left right
map<int , map<int , multiset<int>>> preorder(trees*rootNode){
    stack<pair<trees* , pair<int , int> > >st;//the pair stores row and column
    st.push({rootNode ,{0,0}});
   
    
    map<int , map<int , multiset<int>>>mpp;
    /*outer map stores the int , which contains the column nr 
    and inside map int stores the row and multiset stores the node data
    multiset is used because it sorts the order as set property and keep duplicate
    elemnts as well inside it 
    */

     mpp[0][0].insert(rootNode->data);
     
   
    while(!st.empty()){
        auto mover=st.top();//auto sets the data type on its own
        int row=mover.second.first;
        int col=mover.second.second;
        
        st.pop();

        if(mover.first->right){
            mpp[row+1][col+1].insert(mover.first->right->data);
        }

        if(mover.first->left){
            mpp[row+1][col-1].insert(mover.first->left->data);
        }
        
    }

    return mpp;
    /*now simply print the first column elemnt
    then next then next , if column same print the smaller */
    
}

void vot(trees*root ){
    
}

int main() {
    
    return 0;
}