
   
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <queue>



template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL)
        return;
    else
    {
        
        queue<BinaryTreeNode<int>*> pendingNodes;
        pendingNodes.push(root);
        
        while(!pendingNodes.empty())
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            cout<<front->data<<":";
            pendingNodes.pop();
            if(front->left != NULL)
            {
                cout<<"L:"<<front->left->data<<",";
                pendingNodes.push(front->left);
            }
                
            else
                cout<<"L:-1"<<",";
            
            
            
            if(front->right != NULL)
            {
                cout<<"R:"<<front->right->data;
                pendingNodes.push(front->right);
            }
                
            else
                cout<<"R:-1";
            
            cout<<endl;
            
        }
    }
}

class IsBSTreturn{
    public:
    bool isBst;
    int minimum;
    int maximum;
};

IsBSTreturn checkBST2(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        IsBSTreturn output;
        output.isBst = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    else{
        IsBSTreturn leftOutput = checkBST2(root->left);
        IsBSTreturn rightOutput = checkBST2(root->right);
        IsBSTreturn output;
        
        output.minimum = min(root->data , min(leftOutput.minimum , rightOutput.minimum));
        output.maximum = max(root->data , max(leftOutput.maximum , rightOutput.maximum));
        
        if((root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBst && rightOutput.isBst)
            output.isBst = true;
        else
            output.isBst = false;
        
        return output;
    }
}




int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    IsBSTreturn final_output = checkBST2(root);
    cout<<final_output.isBst;
}
