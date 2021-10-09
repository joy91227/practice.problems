class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majorityElement;
        int count = 0;
        int size = nums.size() / 2;
        for (int num : nums)
        {
            if (count == 0)
            {
                majorityElement = num;
                count++;
            }
            else if (majorityElement == num)
            {
                count++;
                if (count > size)
                    return majorityElement;
            }
            else
            {
                count--;
            }
        }
        return majorityElement;
    }
};