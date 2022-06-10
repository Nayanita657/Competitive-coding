https://leetcode.com/problems/longest-substring-without-repeating-characters/

*******************************************SOLUTION**************************************************************

class Solution {
public:
   int lengthOfLongestSubstring(string s) 
    {
       if(s.length() == 0)
           return 0;
       
        int start = 0;
        int end = 0;
        int max_length = INT_MIN;
        unordered_map<char,int> map;
        while(end < s.length())
        {
            int window_size = end - start + 1;
            map[s[end]]++;
            if(map.size() == window_size)
            {
                int temp = map.size();
                if(max_length < temp)
                {
                    max_length = temp;
                }
                    
                end++;
    
            }
            else if(map.size() < window_size)
            {
                while(map.size() != (end - start + 1))
                {
                    map[s[start]]--;
                    if(map[s[start]] == 0)
                        map.erase(s[start]);
                    start++;
                }
                int temp = map.size();
                if(max_length < temp)
                {
                    max_length = temp;
                }
                    
                end++;
            }
        }
        return max_length;
    }
};
