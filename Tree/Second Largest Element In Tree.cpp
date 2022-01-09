#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

#include <bits/stdc++.h>

class Max_secondMax{
    public:
    int max;
    int second_max;
};

int helper1(int x, int y, int z, int R_max)
{
    if(x > y)
    {
        if(x != R_max)
        {
            x = x;
        }
        else
        {
            x = y;
        }
    }
    else
    {
        if(y != R_max)
        {
            x = y;
        }
    }
    
    if(x > z)
    {
        if(x != R_max)
        {
            x = x;
        }
        else
        {
            x = z;
        }
    }
    else
    {
        if(z != R_max)
        {
            x = z;
        }
    }
    
    return x;
}

Max_secondMax helper(TreeNode<int>* root)
{
    if(root->children.size() == 0)
    {
        Max_secondMax output;
        output.max = root->data;
        output.second_max = INT_MIN;
        return output;
    }
    else
    {
        int root_max = root->data;
        int root_secondMax = INT_MIN;
        for(int i = 0; i < root->children.size(); i++)
        {
            Max_secondMax child = helper(root->children[i]);
            
            if(child.max > root_max)
            {
                int discard = root_max;
                root_max = child.max;
                root_secondMax = helper1(root_secondMax , discard, child.second_max, root_max);
            }
            else if(child.max < root_max)
            {
                root_secondMax = helper1(root_secondMax , child.max, child.second_max, root_max);
            }
            else
            {
                int discard = root_max;
                root_secondMax = helper1(root_secondMax , discard, child.second_max, root_max);
            }
        }
        Max_secondMax output;
        output.max = root_max;
        output.second_max = root_secondMax;
        return output;
    }
}


TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) 
{
    // Write your code here
    Max_secondMax final_output = helper(root);
    root->data = final_output.second_max;
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}