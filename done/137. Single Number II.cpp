class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0, setBits, bitMask;
        // count each bit
        for (int i = 0; i < 32; i++)
        {
            setBits = 0;
            bitMask = 1 << i;
            // go through all numbers in the list, adding one to setBits if we see a set bit
            for (int n = 0; n < nums.size(); n++)
            {
                if (nums[n] & bitMask)
                    setBits++;
            }
            // set the bit of the end result accordingly
            if (setBits % 3 != 0)
            {
                result |= bitMask;
            }
        }
        return result;
    }
};