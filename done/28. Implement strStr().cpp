class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            int ended = true;
            for (int n = 0; n < needle.size(); n++)
            {
                if (needle[n] != haystack[i+n]) {
                    ended = false;
                    break;
                }
            }
            if (ended) 
                return i;
        }
        return -1;
    }
};