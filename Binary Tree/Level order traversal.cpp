#include <iostream>
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

using namespace std;
#include "solution.h"

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

void printLevelWise(BinaryTreeNode<int> *root) 
{
    // Write your code here
 	queue<BinaryTreeNode<int> *> pendingQueue;
    pendingQueue.push(root);
    pendingQueue.push(NULL);
    
    while(!pendingQueue.empty())
    {
        BinaryTreeNode<int> *front = pendingQueue.front();
        pendingQueue.pop();
        if(front == NULL && pendingQueue.empty())
        {
            break;
        }
        
        else if(front == NULL && !pendingQueue.empty())
        {
            cout<<"\n";
            pendingQueue.push(NULL);
        }
        else
        {
            cout<<front->data<<" ";
            if(front->left != NULL)
                pendingQueue.push(front->left);
            if(front->right != NULL)
                pendingQueue.push(front->right);
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}