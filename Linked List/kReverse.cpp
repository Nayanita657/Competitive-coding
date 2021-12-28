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
Node *reverseLinkedList(Node *head) {
    if(head == NULL)
    {
        return NULL;
    }
    else if(head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}

Node *kReverse(Node *head, int k)
{
	if(k == 0)
    {
        return head;
    }
    else if(head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *temp = head;
       
        while(temp != NULL)
        {
            Node *r_head = temp;
            Node *r_tail = temp;
            int count = 1;
            while(count < k && r_tail->next != NULL)
            {
                r_tail = r_tail->next;
                count++;
            }
           
            
            Node *temp2 = r_tail->next;
            r_tail->next = NULL;
            //updated 
            r_tail = r_head;
            r_head = reverseLinkedList(r_head);
            
            
            
            r_tail->next = kReverse(temp2,k);
            return r_head;
            
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}