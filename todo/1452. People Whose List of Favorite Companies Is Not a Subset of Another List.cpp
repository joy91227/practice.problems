class Solution
{
public:
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
    {
        int size = favoriteCompanies.size();
        vector<int> result(size);
        vector<vector<int>> hashedCompanies(size);
        // hash all lists
        for (int i = 0; i < size; i++)
        {
            // prep the result array
            result[i] = i;
            // hash list
            vector<string> currentCompany = favoriteCompanies[i];
            vector<int> hashedCompany(currentCompany.size());
            for (int s = 0; s < currentCompany.size(); s++)
            {
                hashedCompany[s] = hash(currentCompany[s]);
            }
            hashedCompanies[i] = hashedCompany;
        }
        // iterate through lists
        // curr.size() < toCompare.size(), check if curr is a subset of toCompare, if yes, then delete curr's index from results array
        // curr.size() > toCompare.size(), check if toCompare is a subset of curr, if yes, then delete toCompare's index from results array
        for (int j = 0; j < hashedCompanies.size(); j++)
        {
            for (int k = 0; k < hashedCompanies.size(); k++)
            {
                
            }
        }
    }
};