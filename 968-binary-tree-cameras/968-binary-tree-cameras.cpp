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
    int cameras=0;
    int solve( TreeNode* root)
    {
         if(root == NULL) return 1;
         
        int left = solve( root->left);
        int right = solve(root->right);
        
        if( left == -1 || right == -1 ) 
        {
             cameras++;
            return 0;
        }
         if( left == 0 || right == 0)
              return 1;
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
    
         if(solve(root) == -1) 
         {
              cameras++;
         }
         return cameras;
    }
};

//  3 condition are possible if node 
//   . node has camera  
//   . node need camera  
//   . any of its child has camera 
//    so if the subtree needs camera it will return -1
//    if the current node has camera it will return 0
//    and if any of its children have camera it will return 1
       
  