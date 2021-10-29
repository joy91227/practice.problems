class Solution {
public:
    void rotate(vector<int>& nums, int k) {        
        int rotates = k % nums.size();
        int size = nums.size();
        vector<int> temp(nums.end()-rotates, nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
        nums.resize(size);               
    }
};