#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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

#include <bits/stdc++.h>

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if(root->children.size() == 0 && root->data > x)
        return root;
    if(root->children.size() == 0 && root->data < x)
        return NULL;
    else
    {
        int result = 0;
        TreeNode<int>* ResultN = NULL;
        int diff = INT_MAX;
        if(root->data > x)
        {
            result = root->data;
            ResultN = root;
            diff = root->data - x;
        }
        for(int i = 0; i < root->children.size(); i++)
        {
            TreeNode<int>* temp = getNextLargerElement(root->children[i],x);
            if(temp != NULL)
            {
                int new_diff = temp->data - x;
                if(new_diff < diff)
                {
                    diff = new_diff;
                    result = temp->data;
                    ResultN = temp;
                }
            }
        }
        return ResultN;
    }
}

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
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}