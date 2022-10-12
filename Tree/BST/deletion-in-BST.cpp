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
private:
    int find_predecessor(TreeNode* root){
        TreeNode* temp = root;
        while(temp->right != NULL){
            temp = temp->right;
        }
        return temp->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case
        if(root == NULL){
            return root;
        }
        
        // Found the data
        if(root->val == key){ 
            // Deletion code
            // 0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            
            
            // 1 child
                // LEFT CHILD
                if(root->left != NULL && root->right == NULL){
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                // RIGHT CHILD
                if(root->left == NULL && root->right != NULL){
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
            
            
            // 2 children
            if(root->left != NULL && root->right != NULL){
                int in_predecessor = find_predecessor(root->left);
                root->val = in_predecessor;
                root->left = deleteNode(root->left, in_predecessor);
                return root;
            }
        }
        
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }
        root->right = deleteNode(root->right,key);
        return root;
    }
};
