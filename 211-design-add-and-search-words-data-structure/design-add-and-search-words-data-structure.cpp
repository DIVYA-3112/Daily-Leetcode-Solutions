class WordDictionary {
public:

    bool flag;
    WordDictionary* data[26];

    WordDictionary() {
        flag = false;
        for(int i=0; i<26; i++) data[i] = NULL;
    }
    
    void addWord(string word) {
        // insert word
        WordDictionary* temp = this;
        int n = word.size();
        for(int i=0; i<n; i++)
        {
            if(temp->data[word[i] - 'a'] == NULL)
            {
                temp->data[word[i] - 'a'] = new WordDictionary();
            }
            temp = temp->data[word[i] - 'a'];
        }
        temp->flag = true;
    }

    bool search(string word)
    {
        int n = word.size();
        WordDictionary *temp = this;
        return helper(word, 0, temp);
    }

    bool helper(string word, int ind, WordDictionary* temp)
    {
        // base case
        if(ind == word.size()) return temp->flag;

        // conditions;
        if(word[ind] != '.')
        {
            if(temp->data[word[ind] - 'a'] == NULL) return false;
            return helper(word, ind+1, temp->data[word[ind] - 'a']);
        }
        else if(word[ind] == '.')
        {
            for(int i=0; i<26; i++)
            {
                if(temp->data[i])
                {
                    if(helper(word, ind+1, temp->data[i])) return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */