#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) 
{
    //creatiing vector
    vector<Node<int>*> v;
    
    if(root == NULL)
        return v;
    
    queue<BinaryTreeNode<int>*> pendingQueue;
    pendingQueue.push(root);
    pendingQueue.push(NULL);
    
    Node<int>* head = NULL;
    
    while(!pendingQueue.empty())
    {
        BinaryTreeNode<int> *front = pendingQueue.front();
        pendingQueue.pop();
        if(front == NULL && pendingQueue.empty())
        {
            break;
        }
        
        else if(front == NULL && !pendingQueue.empty())
        {
            //cout<<"\n";
            head = NULL;
            pendingQueue.push(NULL);
        }
        else
        {
            //cout<<front->data<<" ";
            if(head == NULL)
            {
               head = new Node<int>(front->data);
               Node<int>* per_head = head;
               v.push_back(per_head);
            }
            else
            {
                //Node<int>* temp = head;
                while(head->next != NULL)
                {
                    head = head->next;
                }
                Node<int>* temp = new Node<int>(front->data);
                head->next = temp;
                
            }
            if(front->left != NULL)
                pendingQueue.push(front->left);
            if(front->right != NULL)
                pendingQueue.push(front->right);
        }
    }
    return v;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}