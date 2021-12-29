#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class TreeNode{
    public:
    int data;
    vector<TreeNode *> children;
    
    TreeNode(int data)
    {
        this->data = data;
    }
};
TreeNode *takeInputLevelwise()
{
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;
    
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> pendingNode;
    pendingNode.push(root);
    
    while(pendingNode.size() != 0)
    {
        TreeNode *front = pendingNode.front();
        pendingNode.pop();
        cout<<"Enter the num of child of "<<front->data <<": ";
        int numChild;
        cin>>numChild;
        
        for(int i = 0; i < numChild ; i++)
        {
            int childData;
            cout<<"Enter the "<<i<<"th child of "<<front->data<<" : ";
            cin>>childData;
            TreeNode *child = new TreeNode(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}
void printInputLevelwise(TreeNode *root)
{
    if(root == NULL)
        return;
    else
    {
        //cout<<root->data<<": ";
        queue<TreeNode *> pendingNode;
        pendingNode.push(root);
        
        
        while(pendingNode.size() != 0)
        {
            TreeNode *front = pendingNode.front();
            cout<<front->data<<":";
            pendingNode.pop();
            int no_child = front->children.size();
            if(no_child != 0)
            {
                int i = 0;
                for(; i < no_child - 1 ; i++)
                {
                    cout<<front->children[i]->data<<",";
                    //TreeNode *childNode = fornt->children[i];
                    pendingNode.push(front->children[i]);
                
                }
                cout<<front->children[i]->data;
                pendingNode.push(front->children[i]);
            }
            
            cout<<endl;
        }
    }
    
}

int main()
{
    TreeNode *root = takeInputLevelwise();
    printInput(root);
    cout<<"------------------"<<endl;
    printInputLevelwise(root);
    return 0;
}