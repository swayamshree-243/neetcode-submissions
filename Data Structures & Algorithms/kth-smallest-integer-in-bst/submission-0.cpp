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
    int ans = -1;
    void find(TreeNode* root, int k, int& n){
        if(!root) return;
        if(ans != -1) return;
        
        find(root->left, k, n);
        n++;
        if(n == k){
            ans = root->val;
            return;
        } 
        find(root->right, k, n);
    }
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        find(root, k, n);
        return ans;
    }
};
