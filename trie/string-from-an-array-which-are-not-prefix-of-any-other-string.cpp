/***
 * Given an array of strings, the task is to print the strings from the array
 * which are not prefix of any other string from the same array.
 *
 * arr[] = {'apple', 'app', 'there', 'the', 'like'}
 *
 * o/p = apple, like, there
 */

#include <bits/stdc++.h>
using namespace std;

// brute force approach
vector<string> nonPrefixString(const vector<string> &nums)
{
    vector<string> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        bool isPrefix = false;

        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j && nums[j].find(nums[i]) == 0)
            {
                isPrefix = true;
                break;
            }
        }
        if (!isPrefix)
        {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

const int ALPHABET_SIZE = 26;

// Trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// Function to insert a string into trie
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        // While inerting a word make
        // each isEndOfWord as false
        pCrawl->isEndOfWord = false;
        pCrawl = pCrawl->children[index];
    }
    int i;

    // Check if this word is prefix of
    // some already inserted word
    // If it is then don't insert this word
    for (i = 0; i < 26; i++)
    {
        if (pCrawl->children[i])
        {
            break;
        }
    }
    // If present word is not prefix of
    // any other word then insert it
    if (i == 26)
    {
        pCrawl->isEndOfWord = true;
    }
}

// Function to display words in Trie
void display(struct TrieNode *root, char str[], int level)
{
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (root->isEndOfWord)
    {
        str[level] = '\0';
        cout << str << endl;
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {

        // If NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

// Driver code
int main()
{
    string keys[] = {"apple", "app", "there",
                     "the", "like"};
    int n = sizeof(keys) / sizeof(string);

    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    char str[100];
    display(root, str, 0);

    return 0;
}
