#include <iostream>
#include <climits>
using namespace std;

#include "solution.h"

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() 
    {
        // Write your code here
        if(isEmpty())
            return INT_MIN;
        int last_index = getSize() - 1;
        int swapping_element = pq[last_index];
        //swapping the element with root and swapping element;
        int temp = pq[0];
        pq[0] = swapping_element;
        pq.pop_back();
        int heap_size = getSize();
        
        //implementing Down heapify
        int parent_index = 0;
        int left_child_index = (2 * parent_index) + 1;
        int right_child_index = (2 * parent_index) + 2;
        
        while(left_child_index < heap_size)
        {
            int min_index;
            //ode is having left and right child both
            if(left_child_index < heap_size && right_child_index < heap_size)
            {
                if(pq[parent_index] < pq[left_child_index] && pq[parent_index] < pq[right_child_index])
            		break;
        		if(pq[left_child_index] < pq[parent_index] && pq[left_child_index] < pq[right_child_index])
            		min_index = left_child_index;
        		if(pq[right_child_index] < pq[parent_index] && pq[right_child_index] < pq[left_child_index])
            		min_index = right_child_index;
        		
            	//swapping the parent element with min_index element
            	int data = pq[parent_index];
            	pq[parent_index] = pq[min_index];
            	pq[min_index] = data;
            	
                parent_index = min_index;
        		left_child_index = (2 * parent_index) + 1;
        		right_child_index = (2 * parent_index) + 2;
            }
            else
            {
                if(pq[parent_index] < pq[left_child_index])
            	break;
                else
                {
                    min_index = left_child_index;
                    //swapping the parent element with min_index element
            		int data = pq[parent_index];
            		pq[parent_index] = pq[min_index];
            		pq[min_index] = data;
                    
                    parent_index = min_index;
                    left_child_index = (2 * parent_index) + 1;
        			right_child_index = (2 * parent_index) + 2;
                    
                }
            }
    	}
         return temp;
    }
};

int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}