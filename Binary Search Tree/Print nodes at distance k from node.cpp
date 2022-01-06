#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void nodesAtDistanceK_down(BinaryTreeNode<int> *root, int distance)
{
    if(root == NULL)
        return;
        
    else
    {
        if(distance == 0)
        {
            cout<<root->data<<"\n";
        }
        else
        {
            nodesAtDistanceK_down(root->left, distance - 1);
            nodesAtDistanceK_down(root->right, distance - 1);
        }
            
    }
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
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
        
        vector<int>* leftAns = getPath(root->left,data);
        if(leftAns != NULL)
        {
            leftAns->push_back(root->data);
            leftAns->push_back(0);
            return leftAns;
        }
        else
        {
            vector<int>* rightAns = getPath(root->right,data);
            if(rightAns != NULL)
            {
                rightAns->push_back(root->data);
                rightAns->push_back(1);
                return rightAns;
            }
            else
            {
                return NULL;
            }
        }
    }
}

BinaryTreeNode<int> *Find_address(BinaryTreeNode<int> *root,int data)
{
    if(root == NULL)
        return NULL;
    else
    {
        if(root->data == data)
            return root;
        
        BinaryTreeNode<int> *Left_Ans = Find_address(root->left,data);
        if(Left_Ans == NULL)
        {
            BinaryTreeNode<int> *Right_Ans = Find_address(root->right,data);
            if(Right_Ans == NULL)
                return NULL;
            else
                return Right_Ans;
        }
        else
            return Left_Ans;
    }
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int targetNode, int k) {
    // Write your code herez
    
    vector<int> *output = getPath(root, targetNode);
    
    //find address of a node in binary tree;
    BinaryTreeNode<int> *node_Add = Find_address(root,targetNode);
    nodesAtDistanceK_down(node_Add,k);
    
    int count = 1;
    for(int i = 1; i < output->size(); i = i + 2)
    {
        targetNode = output->at(i);
        int left_right = output->at(i+1);
        BinaryTreeNode<int> *node_Add = Find_address(root,targetNode);
        int current_distace = k - count;
        if(current_distace == 0)
            cout<<node_Add->data<<endl;
        else
        {
            if(left_right == 0)
                nodesAtDistanceK_down(node_Add->right,current_distace - 1);
            if(left_right == 1)
                nodesAtDistanceK_down(node_Add->left,current_distace - 1);
        
        }
        
        count++;
    }
   
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    
    delete root;
}