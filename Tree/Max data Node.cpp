#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#include<algorithm>

TreeNode<int>* maxDataNode(TreeNode<int>* root) 
{
    // Write your code here
	if(root->children.size() == 0)
        return root;
    else
    {
        int maxNode = root->data;
        TreeNode<int>* maxDataNode1 = root;
        for(int i = 0; i < root->children.size(); i++)
        {
            if(maxNode < root->children[i]->data)
            {
                maxNode = root->children[i]->data;
                maxDataNode1 = root->children[i];
            }
        }
        
        for(int j = 0; j < root->children.size(); j++)
        {
            TreeNode<int>* temp = maxDataNode(root->children[j]);
            if(maxNode < temp->data)
            {
                maxDataNode1 = temp;
                maxNode = temp->data;
            }
        }
        
        return maxDataNode1;
    }
}

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }
}