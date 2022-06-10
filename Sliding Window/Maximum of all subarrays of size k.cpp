https://www.interviewbit.com/problems/sliding-window-maximum/

***********************************************SOLUTION********************************************

#include <list>
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    int start = 0;
    int end = 0;
    vector<int> result;
    list<int> temp;
    while(end < A.size())
    {
        int window_size = end - start + 1;
        if(window_size < B)
        {
            if(temp.size() == 0)
                temp.push_back(A[end]);
            else
            {
                while(temp.back() < A[end] && temp.size() != 0)
                {
                    temp.pop_back();
                }
                temp.push_back(A[end]);
            }
            end++;
        }
        else if(window_size > B)
        {
            if(temp.front() == A[start])
                temp.pop_front();
            start++;
        }
        else
        {
            if(temp.size() == 0)
                temp.push_back(A[end]);
            else
            {
                while(temp.back() < A[end] && temp.size() != 0)
                {
                    temp.pop_back();
                }
                temp.push_back(A[end]);
            }

            result.push_back(temp.front());
            end++;
        }
    }
    return result;
}
