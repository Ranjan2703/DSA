/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void  solve(TreeNode* root, unordered_map<int,int> &m)
    {
         if(!root) return ;
         m[root->val]++;
        solve(root->left, m);
        solve(root->right, m);
    }
    vector<int> findMode(TreeNode* root) {
        
          unordered_map<int,int> m;
        
        solve(root, m);
        
        int maxi = -1;
        
        vector<int> res;
        
        for(auto it :m)
        {
             if( it.second > maxi)
             {
                  maxi = it.second;
                  res = { it.first};
             }
            else if( it.second == maxi)
                res.push_back(it.first);
        }
        
        return res;
    }
};