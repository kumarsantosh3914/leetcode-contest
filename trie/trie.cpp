#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    // checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // creating reference trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // setting flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }

    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    // Initialize your data structure here.
    Trie()
    {
        root = new Node();
    }

    // Inserts a word into the trie
    void insert(string word)
    {
        // initializing dummy node pointing to root initailly
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // moves to reference trie
            node = node->get(word[i]);
        }
        node->isEnd();
    }

    // Returns if the word is in the trie
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    // returns if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{

    return 0;
}