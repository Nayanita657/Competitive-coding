#include <iostream>
#include <queue>
#include <stack>

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


void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
    	cout<<"";
    
    else
    {
        queue<BinaryTreeNode<int> *> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        
        int level = 0;
        stack<int> Nodes_stack;
        
        while(!pendingNodes.empty())
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            
            if(front == NULL && !pendingNodes.empty())
            {
                level++;
                while(!Nodes_stack.empty())
                {
                    cout<<Nodes_stack.top()<<" ";
                    Nodes_stack.pop();
                }
                cout<<"\n";
                pendingNodes.push(NULL);
            }
            
            else if(front == NULL && pendingNodes.empty())
            {
                while(!Nodes_stack.empty())
                {
                    cout<<Nodes_stack.top()<<" ";
                    Nodes_stack.pop();
                }
                break;
            }
            
            else
            {
                if(level % 2 == 0)
                {
                    cout<<front->data<<" ";
                }
                else
                {
                    Nodes_stack.push(front->data);
                }
            
                if(front->left != NULL)
                    pendingNodes.push(front->left);
                
                if(front->right != NULL)
                    pendingNodes.push(front->right);
            }
            

        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}