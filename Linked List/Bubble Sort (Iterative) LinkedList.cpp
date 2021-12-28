//bubble sort iterative
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



Node *bubbleSort(Node *head)
{
    
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
	Node *ptr1 = head;
    Node *ptr2 = NULL;
    int swap = 0;
    while(ptr2 != head)
    {
        while(ptr1->next != ptr2)
        {
            if(ptr1->data > ptr1->next->data)
            {
                swap = 1;
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
            }
            ptr1 = ptr1->next;
        }
        //if the elements are already sorted in ascending order then do nothing
        if(swap == 0)
        {
            return head;
        }
        ptr2 = ptr1;
        ptr1 = head;
    }
    return head;
}
int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}