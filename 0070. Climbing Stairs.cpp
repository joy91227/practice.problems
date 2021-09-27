class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n ==2)
            return 2;
        if (n==3)
            return 3;
        int secondLast = 2;
        int last = 3;
        for (int i=3; i<n; i++) {
            int temp = last;
            last += secondLast;
            secondLast = temp;
        }
        return last;
    }
};

