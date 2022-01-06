#include <iostream>
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

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

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
    if (root == NULL) {
        return;
    }
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

vector<int>* getPath_helper(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root == NULL)
        return NULL;
    else
    {
        if(root->data == data)
        {
            vector<int>* output = new vector<int>();
            output->push_back(root->data);
            return output;
        }
        
        vector<int>* leftAns = getPath_helper(root->left,data);
        if(leftAns != NULL)
        {
            leftAns->push_back(root->data);
            return leftAns;
        }
        else
        {
            vector<int>* rightAns = getPath_helper(root->right,data);
            if(rightAns != NULL)
            {
                rightAns->push_back(root->data);
                return rightAns;
            }
            else
            {
                return NULL;
            }
        }
    }
}

void getPath(BinaryTreeNode<int> *root, int node)
{
    vector<int>* output = getPath_helper(root,node);
    for(int i = 0; i < output->size(); i++)
    {
        cout<<output->at(i)<<" ";
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    cout<<"Enter the node : ";
    int node;
    cin>>node;
    cout<<"Path from root to node "<<node<<" is : ";
    getPath(root,node);
    delete root;
}