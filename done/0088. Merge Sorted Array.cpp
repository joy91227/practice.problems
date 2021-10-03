class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // iterate backwards to avoid allocating additional space by making use of the empty space in nums1
        int toInsert = m+n-1;
        int firstIdx = m-1;
        int secondIdx = n-1;
        // merge nums2 into nums1. Put the tracker on nums2 to avoid overflow when m>n. We can ignore the remaining m-n elements in nums1 since it's already sorted.
        // Put a guard firstIdx>=0 to prevent overflow when n>m.
        while (secondIdx >=0)
        {
            nums1[toInsert--] = firstIdx>=0 && nums1[firstIdx] >= nums2[secondIdx] ? nums1[firstIdx--] : nums2[secondIdx--];
        }
    }
};