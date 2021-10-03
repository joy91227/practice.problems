class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return helper(nums, target, 0);
    }

    int helper(vector<int> &nums, int target, int startingIdx)
    {
        if (nums.size() == 1)
        {
            // base case, return index
            if (target <= nums[0])
                return startingIdx;
            else
                return startingIdx + 1;
        }
        // split the array in half and evaluate which half to search
        int index = nums.size() / 2;
        if (target == nums[index])
            return index + startingIdx;
        else if (target < nums[index])
        {
            nums.resize(index);
            return helper(nums, target, startingIdx);
        }
        else
        {
            nums.erase(nums.begin(), nums.begin() + index);
            return helper(nums, target, startingIdx + index);
        }
    }
};