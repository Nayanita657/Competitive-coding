https://leetcode.com/problems/fruit-into-baskets/

***************************************SOLUTION*****************************************


class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        //return 0;
        unordered_map<int,int> map;
        int start = 0;
        int end = 0;
        int fruit_count = INT_MIN;
        while(end < fruits.size())
        {
            map[fruits[end]]++;
            if(map.size() < 2)
                end++;
            else if(map.size() == 2)
            {
                int count = 0;
                unordered_map<int,int> :: iterator itr;
                for(itr = map.begin(); itr != map.end(); itr++)
                {
                    count = count + itr->second;
                }
                if(fruit_count < count)
                    fruit_count = count;
                end++;
            }
            else if(map.size() > 2)
            {
                //remove start element from map
                while(map.size() > 2)
                {
                    map[fruits[start]]--;
                    if(map[fruits[start]] == 0)
                        map.erase(fruits[start]);
                    start++;
                }
                if(map.size() == 2)
                {
                    int count = 0;
                    unordered_map<int,int> :: iterator itr;
                    for(itr = map.begin(); itr != map.end(); itr++)
                    {
                        count = count + itr->second;
                    }
                    if(fruit_count < count)
                        fruit_count = count;
                
                }
                end++;
            }
        }
        if(fruit_count == INT_MIN)
            return fruits.size();
        else
            return fruit_count;
    }
};
