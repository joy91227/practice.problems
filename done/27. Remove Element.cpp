class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // keep a pointer on the first occurence of val in nums
        // swap with next value that is not equal to val
        int toSwap = -1;
        int len = nums.size();
        // find the first instance of val
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == val)
            {
                toSwap = i;
                break;
            }
        }
        // if there is no occurence, return
        if (toSwap == -1)
            return len;
        // otherwise, iterate through the rest
        for (int i = toSwap + 1; i < len; i++)
        {
            if (nums[i] != val)
            {
                nums[toSwap] = nums[i];
                toSwap++;
            }
        }
        return toSwap;
    }
};