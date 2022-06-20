 struct Node{
     Node* links[26];
     bool flag = false;
     
     // check if refrence trie is presen or not 
     bool containsKey(char ch)
     {
         return (links[ch -'a'] != NULL);
     }
     
     // creating a refrense trie
     void put(char ch, Node* node)
     {
         links[ch-'a']= node;
     }
     
     //to get the net node for traversal of trie
     Node *get(char ch)
     {
          return links[ch-'a'];
     }
     
     // set the end true if word is over
     void setEnd()
     {
          flag = true;
     }
     
     //checking if the last node is true or not
     bool isEnd()
     {
          return flag;
     }
     
     
 };
class Trie {
private : Node* root;
public:
    
    Trie() {
        root= new Node();
    }
    
    // insert word in trie
    void insert(string word) {
        Node * node = root;              // pointer poniting to root node
        
        for(int i=0;i<word.size();i++)
        {
             if( ! node ->containsKey(word[i]))     // check if trie doesnot contains that word put it 
             {                                      // and create a refrence node
                   node ->put(word[i],new Node());
             }
            
              node =  node->get(word[i]);          // get that refrence node of that word
        }
        
        
        node->setEnd();                // word is over set the end true 
    }
    
    
    // searching for a word 
    
    bool search(string word) {
        
        Node* node = root;           // pointer pointing to root 
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))  // if node doesnot contians that word return false
            {
                return false;
            }
            
            node= node->get(word[i]);      //if word is present get the refrence node
        }
        
        return node->isEnd();            // if end is true word present else not present 
    }
    
    bool startsWith(string prefix) {
        Node* node = root;              
        
        for(int i=0;i<prefix.size();i++)
        {
             if(!node->containsKey(prefix[i]))  // if node doesnot contians that word return false
                 return false;
            
            node = node->get(prefix[i]);        // getting is refrence node
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