class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() == 0 && nums2.size() == 0)
            return 0;

        // find middle index
        int totalLen = nums1.size() + nums2.size();
        int mid = totalLen / 2;
        if (totalLen % 2)
        {
            // odd
            if (nums1.size() == 0)
                return nums2[mid];
            if (nums2.size() == 0)
                return nums1[mid];
        }
        else
        {
            // even
            if (nums1.size() == 0)
                return (double)(nums2[mid] + nums2[mid - 1]) / 2;
            if (nums2.size() == 0)
                return (double)(nums1[mid] + nums1[mid - 1]) / 2;
        }

        //iterate through the longer one
        int index = 0;
        int nums1Idx = -1;
        int nums2Idx = -1;
        int leadingList = nums1[0] <= nums2[0] ? nums1[0] : nums2[0];
        int current = 0;
        int prev = 0;
        while (index <= mid)
        {
            int next1 = nums1Idx + 1;
            int next2 = nums2Idx + 1;
            prev = current;
            if (next1 >= nums1.size() && next2 < nums2.size())
            {
                nums2Idx++;
                current = nums2[nums2Idx];
            }
            else if (next2 >= nums2.size() && next1 < nums1.size())
            {
                nums1Idx++;
                current = nums1[nums1Idx];
            }
            else if (next1 < nums1.size() && next2 < nums2.size())
            {
                if (nums1[next1] <= nums2[next2])
                {
                    // advance nums1
                    nums1Idx++;
                    current = nums1[nums1Idx];
                }
                else
                {
                    // advance nums2
                    nums2Idx++;
                    current = nums2[nums2Idx];
                }
            }
            index++;
        }
        if (totalLen % 2)
        {
            // odd
            return current;
        }
        else
        {
            return (double)(current + prev) / 2;
        }
    }
};