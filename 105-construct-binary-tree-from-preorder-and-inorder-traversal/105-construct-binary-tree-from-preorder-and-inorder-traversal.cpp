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
    TreeNode* solvefunc(vector<int> &pre, int startpre, int endpre, vector<int>&in, int startin, int endin,unordered_map<int,int> &umap)
    {
        if(startpre> endpre || startin > endin) return nullptr;
        
        TreeNode *root = new TreeNode(pre[startpre]);
        
        int rootind= umap[root->val];
        
        root->left = solvefunc(pre, startpre+1 , startpre+rootind-startin, in, startin, rootind-1,umap);
        root->right = solvefunc(pre,startpre+rootind-startin+1, endpre , in, rootind+1, endin,umap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> umap;
        int n = preorder.size();
        int m = inorder.size();
        
        for(int i =0;i<m;i++)
        {
             umap[inorder[i]]= i;
        }
        return solvefunc(preorder,0,n-1,inorder,0,m-1,umap);
    }
};