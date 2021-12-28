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
Node *swapNodes(Node *head, int i, int j)
{
	if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    else
    {
        Node *temp1 = head;
        Node *temp2 = head;
        int count1 = 0;
        int count2 = 0;
        
        while(count1 != i)
        {
            temp1 = temp1->next;
            count1++;
        }
        
        while(count2 != j)
        {
            temp2 = temp2->next;
            count2++;
        }
        
        //swap data;
        
        int data = temp1->data;
        temp1->data = temp2->data;
        temp2->data = data;
        
        return head;
    }
    
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}