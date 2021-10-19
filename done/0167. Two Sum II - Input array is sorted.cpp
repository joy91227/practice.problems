class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        /**
         * because the array is sorted, adding numbers[i-1] will always be smaller than adding numbers[i]
         * because the array is sorted, adding numbers[i] will always be greater than adding numbers[i-1]
         * use the above quality to apply sliding window technique to acheive one-pass
         * */ 
        vector<int> toReturn(2, 0);
        int low = 0, high = numbers.size() - 1;
        int sum = numbers[low] + numbers[high];
        while (sum != target)
        {
            if (sum > target)
                high--;
            else
                low++;
            sum = numbers[low] + numbers[high];
        }
        toReturn[0] = low + 1;
        toReturn[1] = high + 1;
        return toReturn;
    }
};