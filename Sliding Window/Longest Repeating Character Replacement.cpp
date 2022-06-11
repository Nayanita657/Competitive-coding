https://leetcode.com/problems/longest-repeating-character-replacement/

***************************************************SOLUTION**********************************************

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int start = 0;
        int end = 0;
        int max_frequency = INT_MIN;
        int max_length = INT_MIN;
        unordered_map<char,int> map;
        while(end < s.length())
        {
            map[s[end]]++;
            if(max_frequency < map[s[end]])
            {
                max_frequency = map[s[end]];
            }
            if((end - start + 1) - max_frequency == k)
            {
                if(max_length < (end - start + 1))
                    max_length = end - start + 1;
                end++;
            }
            else if((end - start + 1) - max_frequency < k)
            {
                end++;
            }
            else if((end - start + 1) - max_frequency > k)
            {
                while((end - start + 1) - max_frequency > k)
                {
                    if(map.find(s[start]) != map.end())
                    {
                        map[s[start]]--;
                        max_frequency = 0;
                        unordered_map<char,int> :: iterator itr;
                        for(itr = map.begin(); itr != map.end(); itr++)
                        {
                            if(max_frequency < itr->second)
                                max_frequency = itr->second;
                        }
                    }
                    start++;
                }
                if((end - start + 1) - max_frequency == k)
                {
                    if(max_length < (end - start + 1))
                        max_length = end - start + 1;
                }
                end++;
            }
        }
        if(max_length == INT_MIN)
            return s.length();
        else
            return max_length;
    }
};
