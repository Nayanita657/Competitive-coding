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



Node *removeDuplicates(Node *head)
{
  	
   Node *temp = head;
   if(temp == NULL)
   {
       return head;
   }
   while(temp->next != NULL)
   {
       int data1 = temp->data;
       int data2 = temp->next->data;
       if(data1 == data2)
       {
           //removing duplicate
           Node *q = temp->next->next;
           free(temp->next);
           temp->next = q;
       
       }
       else
       {
           temp = temp->next;
       }
       
   }
    return head;
   
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}