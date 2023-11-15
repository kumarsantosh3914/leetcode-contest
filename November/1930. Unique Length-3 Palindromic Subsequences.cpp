class Solution
{
public:
    int countPalindromicSubsequence(string inputString)
    {
        vector<int> minExist(26, INT_MAX);
        vector<int> maxExist(26, INT_MIN);

        // Populate minExist and maxExist arrays
        for (int i = 0; i < inputString.size(); i++)
        {
            int charIndex = inputString[i] - 'a';
            minExist[charIndex] = min(minExist[charIndex], i);
            maxExist[charIndex] = max(maxExist[charIndex], i);
        }

        int uniqueCount = 0;
        // Iterate over each character in the alphabet
        for (int charIndex = 0; charIndex < 26; charIndex++)
        {
            // Check if the character has occurred in the input string
            if (minExist[charIndex] == INT_MAX || maxExist[charIndex] == INT_MIN)
            {
                continue;
            }

            unordered_set<char> uniqueCharsBetween;
            for (int j = minExist[charIndex] + 1; j < maxExist[charIndex]; j++)
            {
                uniqueCharsBetween.insert(inputString[j]);
            }
            uniqueCount += uniqueCharsBetween.size();
        }
        return uniqueCount;
    }
};