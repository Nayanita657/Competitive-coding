#include <iostream>
using namespace std;
#include <queue>

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


BinaryTreeNode<int>* helper(int *preorder,int pres,int pree,int *inorder,int ins,int ine)
{
    if(pres > pree || ins > ine)
        return NULL;
    
    int rootval = preorder[pres];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootval);
    
    int k =0;
    for(int i=ins;i<=ine;i++)
    {
        if(rootval == inorder[i])
        {
            k = i;
            break;
        }
    }
    
            int inorder_Left_S = ins;
        int inorder_Left_E = k - 1;
        
        int preorder_Left_S =pres+1;
    	// int preorder_Left_E = preorder_Left_S + (inorder_Left_E - inorder_Left_S);
        int preorder_Left_E =pres + (k-ins);
        
        int inorder_Right_S = k + 1;
        int inorder_Right_E = ine;
        // int preorder_Right_S = preorder_Left_E + 1;
        // int preorder_Right_E = preorder_E;
        
        int preorder_Right_S = pres+(k-ins)+1;
        int preorder_Right_E = pree;
                                                 
        root->left = helper(preorder,preorder_Left_S,preorder_Left_E,inorder,inorder_Left_S,inorder_Left_E);
		root->right = helper(preorder,preorder_Right_S,preorder_Right_E,inorder,inorder_Right_S,inorder_Right_E);

    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) 
{
    // Write your code here
    int preorder_S = 0;
    int preorder_E = preLength - 1;
    int inorder_S = 0;
    int inorder_E = inLength - 1;
    
    
    BinaryTreeNode<int>* root = helper(preorder,preorder_S,preorder_E,inorder,inorder_S,inorder_E);
    return root;
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}