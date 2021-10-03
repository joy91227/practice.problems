class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        // Assuming string can have characters
        // a-z, this has 32 bits set to 0
        int checker = 0;
        
        // iterate through each string
        for (int a = 0; a < arr.size(); a++)
        {
            string str = arr[a];
            for (int i = 0; i < str.length(); i++)
            {

                int bitAtIndex = str[i] - 'a';

                // if that bit is already set in
                // checker, return false
                if ((checker & (1 << bitAtIndex)) > 0)
                {
                    return false;
                }

                // otherwise update and continue by
                // setting that bit in the checker
                checker = checker | (1 << bitAtIndex);
            }
        }
        // no duplicates encountered, return true
        return true;
    }
};