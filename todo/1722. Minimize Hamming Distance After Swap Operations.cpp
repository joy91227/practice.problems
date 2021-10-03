class Solution
{
public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        if (allowedSwaps.size() == 0)
            return hammingDistance(source, target);
        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] != target[i]) {
                // see if element at i can be swapped
                
                // swap if the other element also contributes to hamming dist
            }
                
        }
    }

    int hammingDistance(vector<int> &source, vector<int> &target)
    {
        int diffs = 0;
        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] != target[i])
                diffs++;
        }
        return diffs;
    }
};