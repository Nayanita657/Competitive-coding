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



Node *midFind(Node *head)
{
    Node *fast_ptr = head;
    Node *slow_ptr = head;
    
    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    //cout<<slow_ptr->data;
    return slow_ptr;
    
}

int GetLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *reverLL(Node *head)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return temp;
}


bool isPalindrome(Node *head)
{
    Node *temp = head;
    int length = GetLength(head);
    
    if(length == 0 || length == 1)
    {
        return true;
    }
    
    if(length == 2)
    {
        int data1 = temp->data;
        int data2 = temp->next->data;
        if(data1 == data2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    if(length % 2 == 0) // code for even
    {
        Node *list2 = midFind(head);
        //reversing the first half
        while(temp->next != list2)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        Node *list1 = reverLL(head);
        
        /*cout<<"\n Printing List1:\n";
        print(list1);
        cout<<"\nPrinting List2:\n";
        print(list2);*/
        
        //checking isPalindrome
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->data == list2->data)
            {
                list1 = list1->next;
                list2 = list2->next;
            }
            else
            {
                return false;
            }
            
        }
        return true;
        
    }
    else //code for odd
    {
        Node *list2 = midFind(head);
        
        //reversing the first half
        while(temp->next != list2)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        Node *list1 = reverLL(head);
        
        list2 = list2->next;
        
        /*cout<<"\n Printing List1:\n";
        print(list1);
        cout<<"\nPrinting List2:\n";
        print(list2);*/
        
         //checking isPalindrome
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->data == list2->data)
            {
                list1 = list1->next;
                list2 = list2->next;
            }
            else
            {
                return false;
            }
            
        }
        return true;
        
        
    }
    
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}