class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) 
            return 0;
        int n = x / 2;
        while ((long) n*n > x) {
            n /= 2;
        }

        while ((long) n*n <= x) {
            n++;
        }
        return n - 1;
    }
};





