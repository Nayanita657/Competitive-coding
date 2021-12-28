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

Node *midPoint(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    else if(head->next == NULL)
    {
        return head;
    }
    Node *fast_ptr = head->next;
    Node *slow_ptr = head;
    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
    
}

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

Node *mergeSort(Node *head)
{
    if(head == NULL)
    {
        return head;
    }
	//base case
    if(head->next == NULL)
    {
        return head;
    }
    
    Node *midpoint = midPoint(head);
    Node *first_head = head;
    Node *second_head = midpoint->next;
    midpoint->next = NULL;
    first_head = mergeSort(first_head);
    second_head = mergeSort(second_head);
    head = mergeTwoSortedLinkedLists(first_head,second_head);
    return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}