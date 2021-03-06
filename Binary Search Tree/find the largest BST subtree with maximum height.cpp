#include <iostream>
#include <bits/stdc++.h>
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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

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

class IsBSTreturn{
  	public:
    bool isBST;
    int minimum;
    int maximum;
    int height_largestBST;
};

IsBSTreturn helper(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        IsBSTreturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.height_largestBST = 0;
        return output;
    }
    else
    {
        IsBSTreturn leftOutput = helper(root->left);
        IsBSTreturn rightOutput = helper(root->right);
        IsBSTreturn output;
        output.minimum = min(root->data , min(leftOutput.minimum,rightOutput.minimum));
        output.maximum = max(root->data , max(leftOutput.maximum,rightOutput.maximum));
        if((root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST)
        {
            output.isBST = true;
        }
        else
        {
            output.isBST = false;
        }
        
        if(output.isBST == true)
        {
            output.height_largestBST = max(leftOutput.height_largestBST , rightOutput.height_largestBST) + 1;
        }
        else
        {
            output.height_largestBST = max(leftOutput.height_largestBST , rightOutput.height_largestBST);
        }
    	return output;
    
    }
}


int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    IsBSTreturn finaloutput = helper(root);
    return finaloutput.height_largestBST;
    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}