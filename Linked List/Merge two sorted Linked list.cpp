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




Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *first_head = NULL;
    Node *first_tail = NULL;
    
    //if both list is empty then do nothing
    if(head1 == NULL && head2 == NULL)
    {
        return head1;
    }
    
    //if one of the list is empty then simply return the n
    if(head1 != NULL && head2 == NULL)
    {
        return head1;
    }
    
    if(head2 != NULL && head1 == NULL)
    {
        return head2;
    }
    
    //placing the first head to the min element element of those list
    if(head1->data < head2->data)
    {
        first_head = head1;
        first_tail = head1;
        head1 = head1->next;
    }
    else
    {
        first_head = head2;
        first_tail = head2;
        head2 = head2->next;
    }
    
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            first_tail->next = head1;
            first_tail = head1;
            head1 = head1->next;
        }
        else
        {
            first_tail->next = head2;
            first_tail = head2;
            head2 = head2->next;
        }
    }
    
    if(head2 == NULL)
    {
        first_tail->next = head1;
    }
    else
    {
        first_tail->next = head2;
    }
    return first_head;
}

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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}