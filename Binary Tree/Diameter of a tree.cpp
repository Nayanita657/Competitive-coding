#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void printTree(BinaryTreeNode *root)
{
    //base case
    if(root == NULL)
        return;
    cout<<root->data<<":";
    if(root->left != NULL)
    {
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right != NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode *takeInputLevelwise()
{
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;
    
    if(rootData == -1)
    {
        return NULL;
    }
    else
    {
        BinaryTreeNode *root = new BinaryTreeNode(rootData);
        queue<BinaryTreeNode *> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty())
        {
            BinaryTreeNode *front = pendingNodes.front();
            pendingNodes.pop();
            
            cout<<"Enter left child of "<<front->data <<" : ";
            int leftChildData;
            cin>>leftChildData;
            if(leftChildData != -1)
            {
                BinaryTreeNode *child = new BinaryTreeNode(leftChildData);
                front->left = child;
                pendingNodes.push(child);
            }
            cout<<"Enter right child of "<<front->data<<" : ";
            int rightChildData;
            cin>>rightChildData;
            if(rightChildData != -1)
            {
                BinaryTreeNode *child = new BinaryTreeNode(rightChildData);
                front->right = child;
                pendingNodes.push(child);
            }
            
        }
        return root;
    }
}


pair<int,int> heightDiameter(BinaryTreeNode *root)
{
    if(root == NULL)
    {
        pair<int,int> p1;
        p1.first = 0;
        p1.second = 0;
        return p1;
    }
    else
    {
        pair<int,int> leftAns = heightDiameter(root->left);
        pair<int,int> rightAns = heightDiameter(root->right);
        
        int lh = leftAns.first;
        int rh = rightAns.first;
        int ld = leftAns.second;
        int rd = rightAns.second;
        
        int height = 1 + max(lh,rh);
        int diameter = max((lh + rh),max(ld,rd));
        
        pair<int,int> ans;
        ans.first = height;
        ans.second = diameter;
        
        return ans;
    }
}



int main()
{
    //BinaryTreeNode *root = takeInput();
    BinaryTreeNode *root = takeInputLevelwise();
    
    printTree(root);
    cout<<endl;
    
    pair<int,int> ans = heightDiameter(root);
    cout<<"Tree diameter : "<<ans.second;
    cout<<"\nTree height : "<<ans.first;

    return 0;
}