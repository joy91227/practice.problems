class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> output(rowIndex + 1, 1);
        // build continuously on top of the array
        for (int i = 1; i <= rowIndex; i++)
        {
            int prev = 1, j, k;
            // because pascal's triangle is symmetrical, we only have to compute one half
            for (j = 1, k = i - 1; j <= k; j++, k--)
            {
                int temp = output[j];
                output[j] += prev;
                output[k] = output[j];
                prev = temp;
            }
        }
        return output;
    }
};