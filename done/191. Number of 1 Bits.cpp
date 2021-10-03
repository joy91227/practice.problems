class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hammingWeight = 0;
        while(n>0) {          
            hammingWeight+=(n%2);
            n = n >> 1;
        }
        return hammingWeight;
    }
};