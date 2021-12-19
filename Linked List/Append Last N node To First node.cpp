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
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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

int Getlength(Node *head)
{
    Node *temp = head;
    int ln = 0;
    while(temp != NULL)
    {
        ln++;
        temp = temp->next;
    }
    return ln;
}

Node *appendLastNToFirst(Node *head, int n)
{
    int pos = 0;
    Node *temp = head;
    int length = Getlength(head);
    
    if(length == 0)
    {
        return head;
    }
    if(n == 0)
    {
        return head;
    }
    
    int rem_node = length - n;
    for(int i=0;i<rem_node-1;i++)
    {
        temp = temp->next;
    }
    Node *p = temp->next;
    temp->next = NULL;
    
    
    Node *q = p;
    while(q->next != NULL)
    {
        q = q->next;
    }
    q->next = head;
    head = p;
    return head;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}