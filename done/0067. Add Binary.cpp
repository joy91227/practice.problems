class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a == "0")
        {
            return b;
        }
        string result = "";

        string longer, shorter;
        if (a.length() >= b.length())
        {
            longer = a;
            shorter = b;
        }
        else
        {
            longer = b;
            shorter = a;
        }

        int carry = 0;
        int s_idx = shorter.length() - 1;
        int l_idx = longer.length() - 1;

        while (s_idx >= 0)
        {
            int first = shorter[s_idx] == '1' ? 1 : 0;
            int second = longer[l_idx] == '1' ? 1 : 0;
            int sum = first + second + carry;
            if (sum >= 2)
            {
                carry = 1;
                sum -= 2;
            }
            else
            {
                carry = 0;
            }
            result.insert(0, to_string(sum));
            s_idx -= 1;
            l_idx -= 1;
        }

        while (l_idx >= 0)
        {
            int second = longer[l_idx] == '1' ? 1 : 0;
            int sum = second + carry;
            if (sum >= 2)
            {
                carry = 1;
                sum -= 2;
            }
            else
            {
                carry = 0;
            }
            result.insert(0, to_string(sum));
            l_idx -= 1;
        }
        if (carry > 0)
            result.insert(0, to_string(carry));
        return result;
    }
};