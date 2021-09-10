class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int diffs = 0;
        int greater = max(x, y);
        int smaller = min(x, y);
        while (smaller > 0)
        {
            if ((smaller & 1) != (greater & 1))
                diffs++;
            smaller >>= 1;
            greater >>= 1;
        }

        while (greater > 0)
        {
            if (greater & 1)
                diffs++;
            greater >>= 1;
        }

        return diffs;
    }
};