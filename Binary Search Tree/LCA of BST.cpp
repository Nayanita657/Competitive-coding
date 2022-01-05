#include <iostream>
#include <queue>

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(root == NULL)
        return -1;
    else
    {
        if(root->data == val1)
            return root->data;
        else if(root->data == val2)
            return root->data;
        else
        {
            int Left_Ans = -1;
            int Right_Ans = -1;
            if(root->data < val1 && root->data < val2)
            	Right_Ans = getLCA(root->right,val1,val2);
            
            else if(root->data > val1 && root->data > val2)
            	Left_Ans = getLCA(root->left,val1,val2);
            
            else
            {
                Left_Ans = getLCA(root->left,val1,val2);
                Right_Ans = getLCA(root->right,val1,val2);
            }
            
            if(Left_Ans == -1 && Right_Ans == -1)
                return -1;
            else if(Left_Ans == -1 && Right_Ans != -1)
                return Right_Ans;
            else if(Left_Ans != -1 && Right_Ans == -1)
                return Left_Ans;
            else
                return root->data;
            
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}