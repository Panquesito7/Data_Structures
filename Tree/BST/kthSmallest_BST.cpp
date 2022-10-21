//APPROACH 1:
/*
INORDER OF BST IS ALWAYS SORTED
*/
class Solution {
private:
    void inorder(TreeNode* root,vector<int>& v){
         if(root == NULL){
              return ;
         }
         inorder(root->left, v);
         v.push_back(root->val);
         inorder(root->right ,v);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        return v[k-1];
    }
};
