struct Node{
     Node* links[26];
     bool flag = false;
    
    bool containsKey(char ch)
    {
         return(links[ch-'a'] != NULL);
    }
    
    Node *get(char ch)
    {
         return links[ch-'a'];
    }
    
    void put(char ch, Node* node)
    {
         links[ch-'a']= node;
    }
    
    bool isEnd()
    {
         return flag;
    }
    
    void setEnd()
    {
         flag = true;
    }
    
};
class WordDictionary {
private :Node* root;
    
public:
    WordDictionary() {
        root = new Node();
        
    }
    
    void addWord(string word) {
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
             if(!node->containsKey(word[i]))
             {
                  node->put(word[i], new Node());
             }
             
            node= node->get(word[i]);
        }
        
            node->setEnd();
    }
    
    bool search(string word)
    {
        return advanceSearchHelper(word, 0, root);
    }
    
    bool advanceSearchHelper(string &word, int i, Node *dummy)
    {
        if (word.size() == i)
        {
            return dummy->isEnd();
        }
        if (word[i] != '.')
        {
            if (dummy->containsKey(word[i]))
            {
                if (advanceSearchHelper(word, i + 1, dummy->get(word[i])))
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            for (auto node : dummy->links)
            {
                if (node)
                {
                    if (advanceSearchHelper(word, i + 1, node))
                    {
                        return true;
                    };
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