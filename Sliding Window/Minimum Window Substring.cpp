https://leetcode.com/problems/minimum-window-substring/

*****************************************SOLUTION************************************

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int ans = INT_MAX;
        int start = 0;
        int i = 0;
        int j = 0;
        unordered_map<char,int> map;
        for(int i = 0; i < t.length(); i++)
        {
            map[t[i]]++;
        }
        int count = map.size();
        while(j < s.length())
        {
            if(map.find(s[j]) != map.end())
            {
                map[s[j]]--;
                if(map[s[j]] == 0)
                    count--;
            }
            if(count == 0)
            {
                while(count == 0)
                {
                    if(ans > j - i + 1)
                    {
                        ans = j - i + 1;
                        start = i;
                    }
                    if(map.find(s[i]) != map.end())
                    {
                        map[s[i]]++;
                        if(map[s[i]] == 1)
                            count++;
                        
                    }
                    i++;
                }
                
            }
            j++;
        }
        if(ans == INT_MAX)
            return "";
        else
            return s.substr(start,ans);
    }
};
