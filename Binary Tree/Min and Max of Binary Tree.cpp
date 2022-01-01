#include <iostream>
#include <queue>
using namespace std;
#include <algorithm>
#include <bits/stdc++.h>

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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int helper_max(BinaryTreeNode<int> *root)
{
    if(root == NULL)
        return INT_MIN;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    
    else
    {
        int max_ele = root->data;
        int temp1 = helper_max(root->left);
        int temp2 = helper_max(root->right);
        return max(max_ele,max(temp1,temp2));
    }
}

int helper_min(BinaryTreeNode<int> *root)
{
    if(root == NULL)
        return INT_MAX;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    

    else
    {
        int min_ele = root->data;
        int temp1 = helper_min(root->left);
        int temp2 = helper_min(root->right);
        return min(min_ele,min(temp1,temp2));
    }
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    int min = helper_min(root);
    int max = helper_max(root);
    
    pair<int, int> pair1;
    pair1.first = min;
    pair1.second = max;
    return pair1; 
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}