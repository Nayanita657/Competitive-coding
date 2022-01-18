#include <iostream>
#include <vector>
using namespace std;
#include <queue>
class QueueUsingArray 
{
	int *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

	public :
	QueueUsingArray(int s) 
	{
		data = new int[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	/*int getSize() 
	{
		return size;
	}*/

	bool isEmpty() 
	{
		return size == 0;
	}

	// insert element
	void enqueue(int element) 
	{
		if(size == capacity) 
		{
			int *newData = new int[2 * capacity];
			int j = 0;
			for(int i = firstIndex; i < capacity; i++) 
			{
				newData[j] = data[i];
				j++;
			}
			for(int i = 0; i < firstIndex; i++) 
			{
				newData[j] = data[i];
				j++;
			}
			delete [] data;
			data = newData;
			firstIndex = 0;
			nextIndex = capacity;
			capacity *= 2;
			
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity;
		if(firstIndex == -1) 
		{
			firstIndex = 0;
		}
		size++;
	}
	
	int front() 
	{
		if(isEmpty()) 
		{
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	int dequeue() 
	{
		if(isEmpty()) 
		{
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		int ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) 
		{
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}
};
int buyTicket(int *arr, int n, int k) 
{
    // Write your code here
    int cost = 0;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    //inserting elements in queue;
    QueueUsingArray q(n);
    for(int i = 0; i < n; i++)
    {
        q.enqueue(i);
    }
    while(1)
    {
        int max_priority = pq.top();
        int current_priority = arr[q.front()];
        if(current_priority >= max_priority)
        {
            if(q.front() == k)
            {
                cost++;
                break;
            }
            else
            {
                pq.pop();
                cost++;
                int temp = q.dequeue();
            }
            
        }
        else
        {
            //remove the element from the front of queue and place it at the end
            int removing_ele = q.dequeue();
            q.enqueue(removing_ele);
        }
        
    }
    return cost;
}










int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}