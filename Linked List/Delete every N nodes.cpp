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

Node *skipMdeleteN(Node *head, int M, int N)
{
    if(M == 0)
    {
        return NULL;
    }
    else if(N == 0)
    {
        return head;
    }
    else
    {
        Node *temp1 = head;
    	while(temp1 != NULL)
    	{
        	int c1 = 1;
        	//program to keep element
        	while(c1 != M && temp1->next != NULL)
        	{
            	temp1 = temp1->next;
            	c1++;
        	}
        	//checking if eleemts are kept for deleting
        	if(temp1->next == NULL)
        	{
            	return head;
       	 	}
        	//if elements are there to delete then delete them
        	else
        	{
            	Node *temp2 = temp1->next;
            	int c2 = 1;
            	while(c2 != N && temp2->next != NULL)
            	{
                	temp2 = temp2->next;
                	c2++;
            	}
            	temp1->next = temp2->next;
            	temp1 = temp1->next;
        	}
    	}
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}