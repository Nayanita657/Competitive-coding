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

Node *reverLL(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *temp = reverLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
}

int main()
{
    Node *head = insertNode();
    print(head);
    cout<<"\nReversing linked list print:\n";
    head = reverLL(head);
    print(head);
}