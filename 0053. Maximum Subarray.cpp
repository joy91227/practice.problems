class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int greatest = nums[0];
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int sum = prev + nums[i];
            if (sum >= nums[i])
            {
                prev = sum;
            }
            else
            {
                prev = nums[i];
            }
            // try to update greatest
            if (greatest < prev)
                greatest = prev;
        }
        return greatest;
    }
};