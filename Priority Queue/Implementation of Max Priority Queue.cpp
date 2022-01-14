#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#include <vector>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int child_index = pq.size() - 1;
        while(child_index > 0)
        {
            int parent_index = (child_index - 1)/2;
            if(pq[child_index] > pq[parent_index])
            {
                int temp = pq[child_index];
                pq[child_index] = pq[parent_index];
                pq[parent_index] = temp;
            }
            else
            {
                break;
            }
            child_index = parent_index;
        }
         
    }

    int getMax() {
        // Implement the getMax() function here
        return pq[0];
        
    }

    int removeMax() {
        // Implement the removeMax() function here
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
            int max_index;
            //ode is having left and right child both
            if(left_child_index < heap_size && right_child_index < heap_size)
            {
                if(pq[parent_index] > pq[left_child_index] && pq[parent_index] > pq[right_child_index])
            		break;
        		if(pq[left_child_index] > pq[parent_index] && pq[left_child_index] > pq[right_child_index])
            		max_index = left_child_index;
        		if(pq[right_child_index] > pq[parent_index] && pq[right_child_index] > pq[left_child_index])
            		max_index = right_child_index;
        		
            	//swapping the parent element with min_index element
            	int data = pq[parent_index];
            	pq[parent_index] = pq[max_index];
            	pq[max_index] = data;
            	
                parent_index = max_index;
        		left_child_index = (2 * parent_index) + 1;
        		right_child_index = (2 * parent_index) + 2;
            }
            else
            {
                if(pq[parent_index] > pq[left_child_index])
            	break;
                else
                {
                    max_index = left_child_index;
                    //swapping the parent element with min_index element
            		int data = pq[parent_index];
            		pq[parent_index] = pq[max_index];
            		pq[max_index] = data;
                    
                    parent_index = max_index;
                    left_child_index = (2 * parent_index) + 1;
        			right_child_index = (2 * parent_index) + 2;
                    
                }
            }
    	}
         return temp;
        
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        if(getSize())
            return false;
        else 
            return true;
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
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
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