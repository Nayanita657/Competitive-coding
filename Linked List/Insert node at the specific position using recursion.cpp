#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *insertNode()
{
    int data;
    cout<<"\nEnter data:";
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout<<"\nEnter data:";
        cin>>data;
        
    }
    return head;
    
}

void print(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* insertNode(Node *head, int i, int data) 
{
    //base case
    if(head == NULL)
    {
        return head;
    }
   
    
    else
    {
         if(i == 1)
    	{
        	Node *newNode = new Node(data);
        	Node *temp = head->next;
           
       	 	head->next= newNode;
        	newNode->next = temp;
        	//return head;
    	}
    
    	if(i == 0)
    	{
        	Node *newNode = new Node(data);
        	newNode->next = head;
        	head = newNode;
        	//return head;
    	}
        insertNode(head->next,i-1,data);
        return head;
    }
	
}


int main()
{
    Node *head = insertNode();
    print(head);
    int pos, data;
    cout<<"\nenter position:";
    cin >> pos;
    cout<<"\nEnter data:";
    cin>>data;
    head = insertNode(head, pos, data);
    print(head);
   
    
   
    
}