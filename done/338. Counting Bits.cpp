// 0 --> 00 => 0
// 1 --> 01 => 1
// 2 --> 10 => 1
// 3 --> 11 => 2

// 4 --> 100 => 1
// 5 --> 101 => 2
// 6 --> 110 => 2
// 7 --> 111 => 3

// 8 --> 1000 => 1
// 9 --> 1001 => 2
// 10 --> 1010 => 2
// 11 --> 1011 => 3
// 12 --> 1100 => 2
// 13 --> 1101 => 3
// 14 --> 1110 => 3
// 15 --> 1111 => 4

// 16 --> 10000 => 1
// 17 --> 10001 => 2
// 18 --> 10010 => 2
// 19 --> 10011 => 3
// 20 --> 10100 => 2
// 21 --> 10101 => 3
// 22 --> 10110 => 3
// 23 --> 10111 => 4
// 24 --> 11000 => 2
// 25 --> 11001 => 3
// 26 --> 11010 => 3
// 27 --> 11011 => 4
// 28 --> 11100 => 3
// 29 --> 11101 => 4
// 30 --> 11110 => 4
// 31 --> 11111 => 5

//From the above, numbers are separated into ranges by powers of two, eg. 2^0, 2^1, 2^2...
//At each divider x (number that is power of two), the next x numbers including itself, will have one more number of 1's compared to the previous x numbers.

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> toReturn(n + 1);
        for (int i = 1; i < n + 1; i = i * 2)
        {
            for (int j = 0; j < i && j + i < n + 1; j++)
            {
                toReturn[i + j] = toReturn[j] + 1;
            }
        }
        return toReturn;
    }


    vector<int> countBitsOptimized(int n)
    {
        vector<int> toReturn(n + 1, 0);
        //offset to corresponding previous value stays constant within each group of numbers separated by power of 2
        //offset is also the number of times we multiply by two
        int offset = 1;
        for (int i = 1; i < n + 1; i++)
        {
            // multiply offset by two when we reach the end of group
            offset = (i == offset * 2) ? i : offset;
            toReturn[i] = toReturn[i - offset] + 1;
        }
        return toReturn;
    }
};