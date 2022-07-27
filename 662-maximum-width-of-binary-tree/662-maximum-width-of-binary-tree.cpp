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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
             int sz = q.size();
            int min_idx = q.front().second;
            
            int first_idx, last_idx;
            
            for(int i =0;i<sz;i++)
            {
                long long curr_idx= q.front().second - min_idx;
                TreeNode *node = q.front().first;
                q.pop();
                
                if(i== 0) first_idx = curr_idx;
                if(i == sz-1) last_idx = curr_idx;
                
                if(node->left)
                     q.push({node->left, curr_idx*2+1});
                if(node->right)
                     q.push({node->right, curr_idx*2+2});
            }
            ans = max(ans, last_idx-first_idx+1);
        }
         return ans;
    }
};