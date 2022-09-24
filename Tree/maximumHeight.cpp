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

// 3 line Solution:
class Solution {    
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left) ,maxDepth(root->right))+1;
    }
};

// Code for better understanding
class Solution {    
public:
    int maxDepth(TreeNode* root) {
        // Base Case
        if(root == NULL){
            // If no node in tree return 0 as height
            return 0;
        }
        // Recursion will find max depth of left subtree
        int max_depth_left = maxDepth(root->left);
        
        // Recursion will find max depth of right subtree
        int max_depth_right = maxDepth(root->right);
        
        // Our job is to add root to max height
        int max_depth = max(max_depth_left, max_depth_right);
        int ans = max_depth + 1; 
        
        return ans;
    }
};
