class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        vector<int> toReturn(nums.size());
        for (int i = toReturn.size()-1; i >=0 ; i--)
        {
            int l = pow(nums[left], 2), r = pow(nums[right], 2);
            if(l >= r) {
                toReturn[i] = l;
                left++;
            } else {
                toReturn[i] = r;
                right--;
            }
        }
        
        return toReturn;
    }
};