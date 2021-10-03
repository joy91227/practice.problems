class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        const char *typeOfWhitespaces = " \t\n\r\f\v";
        s.erase(s.find_last_not_of(typeOfWhitespaces) + 1);
        return s.length() - s.find_last_of(typeOfWhitespaces);
    }
};