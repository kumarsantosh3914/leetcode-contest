class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
    {
        // Get the Size of an Array
        int n = a.size();

        // Create frequency array which will store the running frequency
        // of each integer in both the arrays together. Since, they
        // are permutations, the frequency of the each element will
        // reach 2 at max at any point during the iterations.
        vector<int> aux(n + 1, 0);

        // Answer array
        vector<int> ans(n, 0);

        // cmn will store the number of elements found to be common yet.
        int cmn = 0;
        for (int i = 0; i < n; i++)
        {
            // Increment frequency of element a[i], if frequency becomes 2 then
            // increment the cmn counter.
            aux[a[i]]++;
            if (aux[a[i]] == 2)
                cmn++;
            // Increment frequency of element b[i], if frequency becomes 2 then
            // increment the cmn counter.
            aux[b[i]]++;
            if (aux[b[i]] == 2)
                cmn++;

            // Because we are moving in one direction the common elements
            // will not be changed infact the count will remain same or increase
            // but will never get reduced and hence at index 'i' the number of
            // common elements will be 'cmn'
            ans[i] = cmn;
        }
        return ans;
    }
};