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

void printIthNode(Node *head, int i)
{
    Node *temp = head;
    int length = 0;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    temp = head;
    
    
    if(i < length)
    {
        if(temp != NULL)
    	{
        	for(int j=0;j<i;j++)
    		{
        		temp = temp->next;
    		}
    		cout<<temp->data;
    	}
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
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}