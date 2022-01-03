#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>

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

pair<int,bool> heightBalance(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        pair<int,bool> p1;
        p1.first = 0; //height
        p1.second = true; //balance
        return p1;
    }
    
    pair<int,bool> leftAns = heightBalance(root->left);
    pair<int,bool> rightAns = heightBalance(root->right);
    
    int lh = leftAns.first;
    int rh = rightAns.first;
    
    int lbalance = leftAns.second;
    int rbalance = rightAns.second;
    
    int height = 1 + max(lh,rh);
    bool isBalance;
    
    if(lbalance == true && rbalance == true)
    {
        if(abs(lh - rh) <= 1)
            isBalance = true;
        else
            isBalance = false;
    }
    else
    {
        isBalance = false;
    }
    
    pair<int,bool> result;
    result.first = height;
    result.second = isBalance;
    
    return result;
}

bool isBalanced(BinaryTreeNode<int> *root) 
{
	// Write your code here
	
	pair<int,bool> FinalAns;
	FinalAns = heightBalance(root);
	
	return FinalAns.second;
    
    
    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}