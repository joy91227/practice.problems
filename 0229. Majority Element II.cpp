class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int num1=0, num2=0, count1=0, count2 = 0, size = nums.size() / 3;
        for (int num : nums)
        {
            if (num1 == num )
            {
                count1 += 1;
            }
            else if (num2 == num)
            {
                count2 += 1;
            }
            else if (count1 == 0)
            {
                num1 = num;
                count1 += 1;
            }
            else if (count2 == 0)
            {
                num2 = num;
                count2 += 1;
            }
            else
            {
                count1 -= 1;
                count2 -= 1;
            }
        }

        count1 = count2 = 0;
        for (int n : nums)
        {
            if (n == num1)
                count1++;
            if (n == num2)
                count2++;
        }

        vector<int> majorityElements;

        if (count1 > size)
            majorityElements.push_back(num1);
        if (count2 > size && num1 != num2)
            majorityElements.push_back(num2);

        return majorityElements;
    }
};