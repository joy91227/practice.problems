class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascals(numRows);
        vector<int> first(1, 1);
        pascals[0] = first;
        for (int i=1; i<numRows; i++) {
            vector<int> temp(i+1, 1);
            for(int n=1; n<i; n++){                
                temp[n] = pascals[i-1][n-1]+pascals[i-1][n];                 
            }
            pascals[i] = temp;
        }
        return pascals;
    }
};