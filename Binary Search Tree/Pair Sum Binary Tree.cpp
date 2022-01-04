#include <iostream>
#include <queue>
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

#include <vector>

void PREOrder(BinaryTreeNode<int> *root,vector<int> &v)
{
    if(root == NULL)
        return;
    else
    {
        v.push_back(root->data);
        PREOrder(root->left,v);
        PREOrder(root->right,v);
    }
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int> v;
    PREOrder(root,v);
    
    sort(v.begin(),v.end());
    
    int i = 0;
    int j = v.size() - 1;
    
    while(i < j)
    {
        int temp = v[i] + v[j];
        if(temp > sum)
            j--;
        else if(temp < sum)
            i++;
        else
            {
                cout<<v[i]<<" "<<v[j]<<endl;
                i++;
                j--;
            }
    }
    
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}