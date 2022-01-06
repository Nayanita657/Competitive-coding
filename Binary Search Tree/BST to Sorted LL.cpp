#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

pair<Node<int>* , Node<int>*> helper(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        pair<Node<int>* , Node<int>*> p2;
        p2.first = NULL;
        p2.second = NULL;
        return p2;
    }
    
    else
    {
        pair<Node<int>* , Node<int>*> lAns = helper(root->left);
        pair<Node<int>* , Node<int>*> rAns = helper(root->right);
        
        Node<int> *lHead = lAns.first;
        Node<int> *rHead = rAns.first;
        
        Node<int> *lTail = lAns.second;
        Node<int> *rTail = rAns.second;
        
        Node<int>* root_head = new Node<int>(root->data);
        
        pair<Node<int>* , Node<int>*> final_ans;
        
        if(lHead == NULL && rHead == NULL)
        {
            final_ans.first = root_head;
            final_ans.second =root_head;
        }
        
        else if(lHead == NULL && rHead != NULL)
        {
            root_head->next = rHead;
            final_ans.first = root_head;
            final_ans.second =rTail;
        }
        
        else if(lHead != NULL && rHead == NULL)
        {
            lTail->next = root_head;
            final_ans.first = lHead;
            final_ans.second = root_head;
        }
        else
        {
            lTail->next = root_head;
            root_head->next = rHead;
            final_ans.first = lHead;
            final_ans.second =rTail;
        }
        return final_ans;
    }
    
    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	
	pair<Node<int>* , Node<int>* > p1;
	p1 = helper(root);
	return p1.first;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}