class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]))
            {
                int idx = map.at(nums[i]);
                if (0 < abs(idx - i) && abs(idx - i) <= k)
                    return true;
                else
                    map[nums[i]] = i;
            }
            else
            {
                map.insert({{nums[i], i}});
            }
        }
        return false;
    }
};