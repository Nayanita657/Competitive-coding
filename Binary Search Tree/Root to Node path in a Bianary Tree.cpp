#include <vector>
#include <queue>
#include <iostream>

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
};

BinaryTreeNode* TakeInputLevelwise()
{
    int rootdata;
    cout<<"Enter root data : ";
    cin>>rootdata;
    if(rootdata == -1)
        return NULL;
    else
    {
        BinaryTreeNode* root = new BinaryTreeNode(rootdata);
        queue<BinaryTreeNode*> pendinNodes;
        pendinNodes.push(root);
        
        while(!pendinNodes.empty())
        {
            BinaryTreeNode* front = pendinNodes.front();
            pendinNodes.pop();
            cout<<"Enter left child of "<<front->data<<" : ";
            int LeftChildData;
            cin>>LeftChildData;
            if(LeftChildData != -1)
            {
                BinaryTreeNode* child = new BinaryTreeNode(LeftChildData);
                front->left = child;
                pendinNodes.push(child);
            }
            
            cout<<"Enter right child of "<<front->data<<" : ";
            int rightChildData;
            cin>>rightChildData;
            if(rightChildData != -1)
            {
                BinaryTreeNode* child = new BinaryTreeNode(rightChildData);
                front->right = child;
                pendinNodes.push(child);
            }
        }
        return root;
    
    }    
}

vector<int>* getRootTonodepath(BinaryTreeNode* root,int key)
{
    if(root == NULL)
        return NULL;
    else
    {
        if(root->data == key)
        {
            vector<int>* output = new vector<int>();
            output->push_back(root->data);
            return output;
        }
        
        vector<int>* leftAns = getRootTonodepath(root->left,key);
        if(leftAns != NULL)
        {
            leftAns->push_back(root->data);
            return leftAns;
        }
        
        vector<int>* rightAns = getRootTonodepath(root->right,key);
        if(rightAns != NULL)
        {
            rightAns->push_back(root->data);
            return rightAns;
        }
        
        else{
            return NULL;
        }
        
        
    }
}

int main()
{
    BinaryTreeNode* root = TakeInputLevelwise();
    cout<<"Enter key node for which path from root to be returned : ";
    int keydta;
    cin>>keydta;
    
    vector<int>* v = new vector<int>();
    v = getRootTonodepath(root,keydta);
    for(int i = 0; i < v->size(); i++)
    {
        cout<<v->at(i)<<" ";
    }

    return 0;
}
