#include <bits/stdc++.h>
using namespace std;

/*class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};*/

TrieNode *solution::deleteWord(TrieNode *root, string word)
{
    // Write your code here
    // base case
    if (word.size() == 0)
    {
        root->isEnd = false;
        return root;
    }

    TrieNode *child;
    int idx = word[0] - 'a';
    if (root->children[idx] != NULL)
    {
        child = root->children[idx];
        return deleteWord(child, word.substr(1));
    }
    else
    {
        return root;
    }

    if (child->isEnd == false)
    {
        for (int i = 0; i < 26; i++)
        {
            if (child->children[i] != NULL)
            {
                return child;
            }
        }
        delete child;
        root->children[idx] = NULL;
    }
    return child;
};
