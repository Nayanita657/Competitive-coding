#include <iostream>
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

#include <queue>

class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
    
    private:
    BinaryTreeNode<int>* Insert_helper(int data, BinaryTreeNode<int> *root)
    {
        if(root == NULL)
        {
            root = new BinaryTreeNode<int>(data);
            return root;
        }
        else
        {
            if(root->data > data)
            {
                 root->left = Insert_helper(data,root->left);
                return root;
            }
            else if(root->data < data)
            {
                root->right = Insert_helper(data,root->right);
                return root;
            }
            else
            {
                root->left = Insert_helper(data,root->left);
                return root;
            }
        }
    }
    
    void print_helper(BinaryTreeNode<int> *root)
    {
        if(root == NULL)
            return;
        else
        {
            cout<<root->data<<":";
            if(root->left != NULL)
            {
                cout<<"L:"<<root->left->data<<",";
            }
            if(root->right != NULL)
            {
                cout<<"R:"<<root->right->data;
            }
            cout<<endl;
            print_helper(root->left);
            print_helper(root->right);
        }
    }
    
    bool search_helper(int data,BinaryTreeNode<int>* root)
    {
        if(root == NULL)
            return false;
        else
        {
            if(root->data == data)
                return true;
            else if(root->data > data)
                return search_helper(data,root->left);
            else
                return search_helper(data,root->right);
        }
    }
    
    int Find_min_rightSubtree(BinaryTreeNode<int>* root)
    {
        if(root == NULL) 
        {  
         	return 0;  
    	}  
    	else
    	{  
        	int leftMin, rightMin;  
         	int min = root->data; 
            
          	if(root->left != NULL)
            {  
            	leftMin = Find_min_rightSubtree(root->left);  
            	min = (min > leftMin) ? leftMin : min;  
        	}  
        
          	if(root->right != NULL)
            {  
            	rightMin = Find_min_rightSubtree(root->right);  
            	min = (min > rightMin) ? rightMin : min;  
        	}  
    	return min;  
    	}  
	}  

        
    
    BinaryTreeNode<int>* delete_helper(int data, BinaryTreeNode<int> *root)
    {
        //base case
        if(root == NULL)
            return root;
        
        else
        {
            if(root->data > data)
                root->left = delete_helper(data,root->left);
            if(root->data < data)
                root->right = delete_helper(data,root->right);
            if(root->data == data)
        	{
            	if(root->left == NULL && root->right == NULL)
            	{
                    delete root;
                	return NULL;
            	}
            	else if(root->left != NULL && root->right == NULL)
            	{
                    BinaryTreeNode<int> *temp = root->left;
                    root->left = NULL;
                    delete root;
                	return temp;
            	}
            	else if(root->left == NULL && root->right != NULL)
            	{
                    BinaryTreeNode<int> *temp = root->right;
                    root->right = NULL;
                    delete root;
                	return temp;
            	}
            	else
            	{
                	int min_element = Find_min_rightSubtree(root->right);
                    root->right = delete_helper(min_element,root->right);
                    root->data = min_element;
                    return root;
            	}
        	}
        }
        
    }

   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
        root = delete_helper(data,root);
    }

    void print() { 
        // Implement the print() function
        print_helper(root);
    }
    
    
    void insert(int data) { 
        // Implement the insert() function 
        root = Insert_helper(data,root);
        
    }

    bool search(int data) {
		// Implement the search() function 
        return search_helper(data,root);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}