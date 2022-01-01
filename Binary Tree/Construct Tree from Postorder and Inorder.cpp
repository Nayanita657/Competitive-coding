#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int>* helper(int *postorder,int *inorder,int inS,int inE,int postS,int postE)
{
    if(inS > inE)
        return NULL;
    
    int rootData = postorder[postE];
    int rootIndex = -1;
    for(int i = inS; i <= inE; i++)
    {
        if(inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    
    int LinS = inS;
    int LinE = rootIndex - 1;
        
    int LpostS = postS;
    int LpostE = postS + (LinE - LinS);
        
    int RpostS = LpostE + 1;
    int RpostE = postE - 1;
        
    int RinS = rootIndex + 1;
    int RinE = inE;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = helper(postorder,inorder,LinS,LinE,LpostS,LpostE);
    root->right = helper(postorder,inorder,RinS,RinE,RpostS,RpostE);
    
    return root;
        
}



BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    int inS = 0;
    int inE = inLength - 1;
    int postS = 0;
    int postE = postLength - 1;
    
    return helper(postorder,inorder,inS,inE,postS,postE);
    
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}