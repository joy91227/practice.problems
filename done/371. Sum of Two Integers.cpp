#include <stdlib.h> /* abs */

class Solution
{
public:
    int getSum(int a, int b)
    {
        int mask = ~(1 << 31);
        if (a == 0)
        {
            return b;
        }
        if (b == 0)
        {
            return a;
        }
        if (a > 0 && b > 0) //both positive
        {
            return binAddition(a, b);
        }

        if (a < 0 && b < 0)
        { //both negative
            int c = binAddition(a & mask, b & mask);
            return c |= 1UL << 31;
        }
        //one positive and one negative
        if (b < 0)
        {
            return binSubtracton(a, abs(b));
        }

        return binSubtracton(b, abs(a));
    }

    // function for Binary Addition
    int binAddition(int a, int b)
    {
        int c; //carry
        while (b != 0)
        {
            //find carry and shift it left
            c = (a & b) << 1;
            //find the sum
            a = a ^ b;
            b = c;
        }
        return a;
    }

    // function for Binary Subtraction
    int binSubtracton(int a, int b)
    {
        int borrow;
        while (b != 0)
        {
            //find carry and shift it left
            borrow = (~a) & b;
            //find the sum
            a = a ^ b;
            b = borrow << 1;
        }
        return a;
    }
};