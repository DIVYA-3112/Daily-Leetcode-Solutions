class Trie {
public:
    
    Trie* data[26];
    bool flag;
    // Trie* root;
    
    Trie() {
        // root = this;
        flag = false;
        for(int i=0; i<26; i++) data[i] = NULL;
    }
    
    void insert(string s) {
        int n = s.size();
        Trie* temp = this;
        for(int i=0; i<n; i++)
        {
            // check if letter exist;
            if(temp->data[s[i] - 'a'] != NULL)
            {
                temp = temp->data[s[i] - 'a'];
            }
            else
            {
                temp->data[s[i] - 'a'] = new Trie();
                temp = temp->data[s[i] - 'a'];
            }
        }
        temp->flag = true;
    }
    
    bool search(string s) {
        Trie* temp = this;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            // check
            if(temp->data[s[i] - 'a'] == NULL) return false;
            else temp = temp->data[s[i] - 'a'];
        }
        if(temp->flag == true) return true;
        else return false;
    }
    
    bool startsWith(string s) {
        Trie* temp = this;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            // check
            if(temp->data[s[i] - 'a'])
            {
                temp = temp->data[s[i] - 'a'];
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */