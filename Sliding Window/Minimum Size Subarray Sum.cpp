https://leetcode.com/problems/minimum-size-subarray-sum/

******************************************************SOLUTION**************************************************

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int window_size = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        while(end < nums.size())
        {
            sum = sum + nums[end];
            if(sum < target)
                end++;
            else if(sum == target)
            {
                int curr_window_size = end - start + 1;
                if(window_size > curr_window_size)
                    window_size = curr_window_size;
                end++;
            }
            else if(sum > target)
            {
                
            }
        }
        if(window_size == INT_MAX)
            return 0;
        
        else
            return window_size;
    }
};
