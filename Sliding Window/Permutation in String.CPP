https://leetcode.com/problems/permutation-in-string/

***********************************SOLUTION*****************************************

class Solution {
public:
    bool checkInclusion(string s, string p) 
    {
        unordered_map<char, int> mp;
        vector<int> result;
        bool valid_anagram = false;
        //storing the occ. of string p in the map
        for (auto &x : s)
        {
            mp[x]++;
        }

        int count = mp.size();
        int k = s.size();
        int i=0, j=0;

        while (j < p.size())
        {
            //calculation part
            if (mp.find(p[j]) != mp.end())
            {
                mp[p[j]]--;
                if (mp[p[j]] == 0)
                {
                    count--;
                }
            }

            //window length not achived yet
            if (j-i+1 < k)
            {
                j++;
            }

            //window length achived, find ans and slide the window
            else if (j-i+1 == k)
            {
                //finding the ans
                if (count == 0)
                {
                    //result.push_back(i);
                    valid_anagram = true;
                    return valid_anagram;
                }
                if (mp.find(p[i]) != mp.end())
                {
                    mp[p[i]]++;
                    if (mp[p[i]] == 1)
                    {
                        count++;
                    }
                }

                //slide the window
                i++;
                j++;
            }
        }
        return valid_anagram;
    }
};
