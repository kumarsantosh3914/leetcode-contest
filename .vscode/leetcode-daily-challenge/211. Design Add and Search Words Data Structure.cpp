class WordDictionary
{
private:
    bool IsMatch(const string &existingWord, const string &targetWord)
    {
        for (int i = 0; i < existingWord.size(); i++)
        {
            if (targetWord[i] != '.' && existingWord[i] != targetWord[i])
                return false;
        }

        return true;
    }

public:
    unordered_map<int, unordered_set<string>> m_words;

    WordDictionary()
    {
    }

    void addWord(string word)
    {
        int size = word.size();
        if (m_words.find(size) != m_words.end())
            m_words[size].insert(word);
        else
            m_words[size] = {word};
    }

    bool search(string word)
    {
        int size = word.size();

        if (m_words.find(size) == m_words.end())
            return false;

        if (word.find('.') == string::npos)
            return m_words[size].find(word) != m_words[size].end();
        for (const auto &w : m_words[size])
            if (IsMatch(w, word))
                return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */