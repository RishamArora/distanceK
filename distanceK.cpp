/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k);
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
void nodesAtDistanceKdown(BinaryTreeNode<int> *root, int k){
    if(root==NULL)
    {
        return;
}
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
     nodesAtDistanceKdown(root->left,k-1);
     nodesAtDistanceKdown(root->right,k-1);
    
}
int nodesAtDistanceKhelper(BinaryTreeNode<int> *root, int target, int k){
    if(root==NULL)return -1;
    if(root->data==target){
        nodesAtDistanceKdown(root,k);
        return 0;
    }
    int leftd = nodesAtDistanceKhelper(root->left,target,k);
    if(leftd!=-1){
        if(leftd+1==k){
            cout<<root->data<<endl;
        }
        else{
            nodesAtDistanceKdown(root->right,k-leftd-2);
        }
        return 1+leftd;
    }
    int rightd = nodesAtDistanceKhelper(root->right,target,k);
    if(rightd!=-1){
        if(rightd+1==k){
            cout<<root->data<<endl;
        }
        else{
            nodesAtDistanceKdown(root->left,k-rightd-2);
        }
        return 1+rightd;
    }
   return -1; 
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
   nodesAtDistanceKhelper(root,node,k);
}
