/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> umap; // to store and check if copy is created or not
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;
        
        if(umap.find(node) == umap.end()) // if copy is not persent
        {
             
            umap[node] = new Node(node->val ,{}); // creating a copy of node
            
                for(auto it  : node->neighbors) // travers through all its adjacent nodes 
                {
                    umap[node] -> neighbors.push_back(cloneGraph(it)); //add copy
                }
        }
        return umap[node];
        
    }
};