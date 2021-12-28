#include <iostream>
using namespace std;

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



Node *evenAfterOdd(Node *head)
{
	Node *oddH = NULL;
    Node *oddT = NULL;
    Node *evenH = NULL;
    Node *evenT = NULL;
    
    while(head != NULL)
    {
        if((head->data % 2) != 0)
        {
            if(oddH == NULL)
            {
                oddH = head;
                oddT = head;
            }
            else
            {
                oddT->next = head;
                oddT = oddT->next;
            }
        }
        
        else
        {
            if(evenH == NULL)
            {
                evenH = head;
                evenT = head;
            }
            else
            {
                evenT->next = head;
                evenT = evenT->next;
            }
        }
        head = head->next;
    }
    
    if(oddT != NULL && evenT != NULL)
    {
        oddT->next = evenH;
        evenT->next=NULL;
        return oddH;
    }
    else if(oddT == NULL && evenT != NULL)
    {
        evenT->next=NULL;
        return evenH;
    }
    else if(evenT == NULL && oddT != NULL)
    {
        oddT->next=NULL;
        return oddH;
    }
    else
    {
        return NULL;
    }
    
}


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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}