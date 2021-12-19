#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int GetLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;
    int count = 0;
    //length of linked list
    int length = GetLength(head);
    
    //if linked list is empty then do nothing
    if(length == 0)
    {
        return head;
    }
    //delete the first element
    if(pos == 0)
    {
        temp = temp->next;
        head = temp;
        return head;
    }
    //delete the last element
    if(pos == length-1)
    {
        while(count < pos-1)
        {
            temp = temp->next;
            count++;
        }
        free(temp->next);
        temp->next = NULL;
        
        return head;
    }
    //delete the element that lie between start and end index
    else if(pos <= length-1)
    {
        while(count < pos-1)
    	{
        	temp = temp->next;
        	count++;
    	}
		//deleting the node
    	Node *q = temp->next->next;
    	free(temp->next);
    	temp->next = q;
    
    	return head;
        
    }
    //if the given position is greater than the list length then do nothing
    else
    {
        return head;
    }
    
    
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}