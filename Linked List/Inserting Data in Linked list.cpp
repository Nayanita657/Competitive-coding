/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Node{
  public:
  int data;
  Node *next;
  
  
  Node(int data)
  {
      this->data = data;
      next = NULL;
  }
};

Node *Takeinput()
{
    int data;
    cout<<"Enter data:";
    cin>>data;
    
    Node *head = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = newNode;
        }
        cout<<"\nEnter data:";
        cin>>data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}


int main()
{
    Node *head = Takeinput();
    print(head);
    return 0;
}
