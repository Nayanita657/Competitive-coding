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

int height(BinaryTreeNode* root)
{
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left) , height(root->right));
}

int diameter(BinaryTreeNode* root)
{
    if(root == NULL)
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    
    return max(option1,max(option2,option3));
}





int main()
{
    //BinaryTreeNode *root = takeInput();
    BinaryTreeNode *root = takeInputLevelwise();
    
    printTree(root);
    cout<<endl;
    
    cout<<"diameter : "<<diameter(root);

    return 0;
}