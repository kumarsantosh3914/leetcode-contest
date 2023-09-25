class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> umap;
        for(char &ch: s) {
            umap[ch]++;
        }

        for(char &ch: t) {
            umap[ch]--;
            if(umap[ch] < 0) {
                return ch;
            }
        }
        return 's';
    }
};